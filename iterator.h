#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "struct.h"
#include "list.h"
#include "node.h"
#include <stack>
#include <queue>

using std::queue;
using std::stack;

class Iterator
{
  public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Term *currentItem() const = 0;
    virtual bool isDone() const = 0;
};

class NullIterator : public Iterator
{
  public:
    NullIterator(Term *n) {}
    void first() {}
    void next() {}
    Term *currentItem() const
    {
        return nullptr;
    }
    bool isDone() const
    {
        return true;
    }
};

class StructIterator : public Iterator
{
  public:
    StructIterator(Struct *s) : _index(0), _s(s) {}
    void first()
    {
        _index = 0;
    }

    Term *currentItem() const
    {
        return _s->args(_index);
    }

    bool isDone() const
    {
        return _index >= _s->arity();
    }

    void next()
    {
        _index++;
    }

  private:
    int _index;
    Struct *_s;
};

class ListIterator : public Iterator
{
  public:
    ListIterator(List *list) : _index(0), _list(list) {}

    void first()
    {
        _index = 0;
    }

    Term *currentItem() const
    {
        return _list->args(_index);
    }

    bool isDone() const
    {
        return _index >= _list->arity();
    }

    void next()
    {
        _index++;
    }

  private:
    int _index;
    List *_list;
};

class DFSIterator : public Iterator
{
  public:
    DFSIterator(Node *node) : _node(node) {}

    void first()
    {
        _nowNode = _node;
        while (!_nodes.empty())
        {
            _nodes.pop();
        }

        if (_nowNode->right)
        {
            _nodes.push(_nowNode->right);
        }
        if (_nowNode->left)
        {
            _nodes.push(_nowNode->left);
        }
    }

    Term *currentItem() const
    {
        return _nowNode->term;
    }

    bool isDone() const
    {
        return _nodes.empty();
    }

    void next()
    {
        _nowNode = _nodes.top();
        _nodes.pop();
        if (_nowNode->right)
        {
            _nodes.push(_nowNode->right);
        }
        if (_nowNode->left)
        {
            _nodes.push(_nowNode->left);
        }
    }

  private:
    Node *_node;
    stack<Node *> _nodes;
    Node *_nowNode;
};

class BFSIterator : public Iterator
{
  public:
    BFSIterator(Node *node) : _node(node) {}

    void first()
    {
        _nowNode = _node;
        while (!_nodes.empty())
        {
            _nodes.pop();
        }

        if (_nowNode->left)
        {
            _nodes.push(_nowNode->left);
            std::cout << _nowNode->left->term->symbol() << "|";
        }
        if (_nowNode->right)
        {
            _nodes.push(_nowNode->right);
            std::cout << _nowNode->right->term->symbol() << "|";
        }
    }

    Term *currentItem() const
    {
        return _nowNode->term;
    }

    bool isDone() const
    {
        return _nodes.empty();
    }

    void next()
    {
        _nowNode = _nodes.front();
        _nodes.pop();
        if (_nowNode->left)
        {
            _nodes.push(_nowNode->left);
            std::cout << _nowNode->left->term->symbol() << "|";
        }
        if (_nowNode->right)
        {
            _nodes.push(_nowNode->right);
            std::cout << _nowNode->right->term->symbol() << "|";
        }
    }

  private:
    Node *_node;
    queue<Node *> _nodes;
    Node *_nowNode;
};
#endif