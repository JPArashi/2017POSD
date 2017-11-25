#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "number.h"
#include "node.h"

#include "utParser.h"

class Parser
{
  public:
    Parser(Scanner scanner) : _scanner(scanner), _terms() {}

    Term *createTerm()
    {
        int token = _scanner.nextToken();
        _currentToken = token;
        if (token == VAR)
        {
            return new Variable(symtable[_scanner.tokenValue()].first);
        }
        else if (token == NUMBER)
        {
            return new Number(_scanner.tokenValue());
        }
        else if (token == ATOM || token == ATOMSC)
        {
            Atom *atom = new Atom(symtable[_scanner.tokenValue()].first);
            if (_scanner.currentChar() == '(')
            {
                return structure();
            }
            else
                return atom;
        }
        else if (token == '[')
        {
            return list();
        }

        return nullptr;
    }

    Term *structure()
    {
        Atom structName = Atom(symtable[_scanner.tokenValue()].first);
        int startIndexOfStructArgs = _terms.size();
        _scanner.nextToken();
        createTerms();
        if (_currentToken == ')')
        {
            vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
            _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
            return new Struct(structName, args);
        }
        else
        {
            throw string("unexpected token");
        }
    }

    Term *list()
    {
        int startIndexOfListArgs = _terms.size();
        createTerms();
        if (_currentToken == ']')
        {
            vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
            _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
            return new List(args);
        }
        else
        {
            throw string("unexpected token");
        }
    }

    vector<Term *> &getTerms()
    {
        return _terms;
    }

    void matchings()
    {
        _tree = buildExpressionTree(NULL);
    }

    Node *buildExpressionTree(Node *root)
    {
        if (_scanner.currentChar() == '.')
            return root;
        Term *term = NULL;
        Node *tempTree = NULL;
        char currentChar = _scanner.currentChar();
        if (!(currentChar == ';' ||
              currentChar == ',' ||
              currentChar == '='))
        {
            term = createTerm();
            currentChar = _scanner.currentChar();
        }
        _scanner.extractChar();
        if (currentChar == ';')
        {
            _subTreeTermsTable.clear();
            tempTree = new Node(SEMICOLON, nullptr, nullptr, nullptr);
            // root priority > comma, root still root.
            if (root && SEMICOLON >= root->payload)
            {
                addNodeToSubTree(root, tempTree);
                return buildExpressionTree(root);
            }
            else
            {
                tempTree->left = root;
                return buildExpressionTree(tempTree);
            }
        }
        else if (currentChar == ',')
        {
            tempTree = new Node(COMMA, nullptr, nullptr, nullptr);
            // root priority > comma, root still root.
            if (root && COMMA >= root->payload)
            {
                addNodeToSubTree(root, tempTree);
                return buildExpressionTree(root);
            }
            else
            {
                tempTree->left = root;
                return buildExpressionTree(tempTree);
            }
        }
        else if (currentChar == '=')
        {
            term = checkTermExistSubTree(term);
            Node *tempNode = new Node(TERM, checkTermExistSubTree(term), nullptr, nullptr);
            _terms.push_back(term);
            tempTree = new Node(EQUALITY, nullptr, tempNode, nullptr);
            term = checkTermExistSubTree(createTerm());
            tempTree->right = new Node(TERM, term, nullptr, nullptr);
            _terms.push_back(term);
            if (root)
            {
                addNodeToSubTree(root, tempTree);
                return buildExpressionTree(root);
            }
            else
            {
                return buildExpressionTree(tempTree);
            }
        }
    }

    void addNodeToSubTree(Node *root, Node *subTree)
    {
        Node *tempNode = root;
        while (tempNode->right)
        {
            //priority bigger than now
            if (subTree->payload < tempNode->right->payload)
            {
                subTree->left = tempNode->right;
                tempNode->right = subTree;
                return;
            }
            tempNode = tempNode->right;
        }

        if (!tempNode->left)
        {
            tempNode->left = subTree;
        }
        else
        {
            tempNode->right = subTree;
        }
    }

    //if term in subtree, return subtree node,else return term
    Term *checkTermExistSubTree(Term *term)
    {
        createExistSubTreeTable(term);
        Variable *v = dynamic_cast<Variable *>(term);
        if (v)
        {
            for (int i = 0; i < (int)_subTreeTermsTable.size(); i++)
            {
                if (_subTreeTermsTable[i]->symbol() == term->symbol())
                {
                    return _subTreeTermsTable[i];
                }
            }
            _subTreeTermsTable.push_back(term);
        }
        return term;
    }

    void createExistSubTreeTable(Term *term)
    {
        Struct *s = dynamic_cast<Struct *>(term);
        if (s)
        {
            for (int i = 0; i < (int)s->arity(); i++)
            {
                createExistSubTreeTable(s->args(i));
            }
        }
        Variable *v = dynamic_cast<Variable *>(term);
        if (v)
        {
            for (int i = 0; i < (int)_subTreeTermsTable.size(); i++)
            {
                if (_subTreeTermsTable[i]->symbol() == term->symbol())
                {
                    _subTreeTermsTable[i]->match(*term);
                    return;
                }
            }
            _subTreeTermsTable.push_back(term);
        }
    }

    Node *expressionTree()
    {
        return _tree;
    }

  private:
    FRIEND_TEST(ParserTest, createArgs);
    FRIEND_TEST(ParserTest, ListOfTermsEmpty);
    FRIEND_TEST(ParserTest, listofTermsTwoNumber);
    FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

    void createTerms()
    {
        Term *term = createTerm();
        if (term != nullptr)
        {
            _terms.push_back(term);
            while ((_currentToken = _scanner.nextToken()) == ',')
            {
                _terms.push_back(createTerm());
            }
        }
    }

    vector<Term *> _terms;
    vector<Term *> _subTreeTermsTable;
    Scanner _scanner;
    int _currentToken;
    Node *_tree;
};
#endif