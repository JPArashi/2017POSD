#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "parser.h"
#include "scanner.h"
#include "number.h"
#include "iterator.h"

#include <iostream>
#include <vector>
using namespace ::std;

int main(int argc, char **argv)
{
  string input;
  string allNowInput;
  while (true)
  {
    allNowInput = "";
    cout << "?-";
    while (true)
    {
      getline(cin, input);
      if (input == "halt." &&
          allNowInput == "")
        return 0;
      allNowInput += input;
      if (allNowInput == ""){
        break;
      }
      
      if (allNowInput[allNowInput.length() - 1] == '.')
      {
        Scanner s(allNowInput);
        Parser p(s);
        try
        {
          p.buildExpression();
          Node *expressionTree = p.expressionTree();
          expressionTree->evaluate();
          string result = expressionTree->getResult();
          cout << result << endl;
          break;
        }
        catch (std::string &msg)
        {
          cout << msg << endl;
          break;
        }
      }
      cout << "|   ";
    }
  }
}
