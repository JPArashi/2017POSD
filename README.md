# POSD2017F Homework

## Homework assignment 6

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this assignment, you are required to implement the complete matching like `X=1.` through parser. And for test, you don't need to write the test by yourself, we will provide the test to you. Therefore on the CI server, you will only have one job. Please follow the test to implement the necessary class and its interface.

And for the coming Saturday(11/25), there will be two teams need to attend the mob programming. Some adjustment here, please check your name and time, reply to us if you cannot attend the activity on Saturday. And for the demonstration , there is a difference from the previous time, please check [the demonstration  part](https://github.com/posd2017f/homework#demonstration) to get the more information.

### Update

  * Fri Nov 24 2017 10:04:53
  
  1. [Remove the assertion for symtable](https://github.com/posd2017f/homework/commit/044104f7f0cde0602c5034c330aad790eb6233bb#diff-d6ccfd1db8c6193d6118db3625f88da7).
  2. [Add the description for the parser method](https://github.com/posd2017f/homework/blob/master/README.md#assignment-requirement).

#### Assignment requirement

  1. Complete the parser through the test. 
  
      There are some methods different from before, especially the `createTerms` is no longer public and we use `matchings` to make term and pares sentence instead of `createTerms`. Basically it is the difference concept between parsing the complete sentence and parsing a part within the sentence. The `createTerms` should be responsible for getting the arguments if there is a list or structure, therefore it should be named `getArgs` rather then `createTerms`.
      
      We create a new method called `matchings` to parse the whole sentence. It take the sentence as the input, and __generates all terms in the sentence and make the corresponding tree__ to ready to do the real matching. The matching will call the `createTerm` method in serval times, and if it meets a list or structure, it will call `createTerms`(getArgs) to get the arguments for that.

      After `matchings`, the client will get __the root node of the tree by `expressionTree`__, and __do the real matching through the `evaluate` method of the root node__. And after `evaluate` the whole tree, client will get the final status of the matching. E.g. `X=1.`, the X will be the number 1 after the process.

  2. Implement the new class `Node` and its interface. The `Node` class is used to create the expression tree, and the tree represents the structure of a sentence. Each node is an operator or an operand, so you need to visit the whole tree to do the real matching.
  ![tree](https://i.imgur.com/JYVvY2s.png)
  The class has the `two constructors` to generate an node or connect two child nodes, and the `evaluate` method is used to evaluate that when to do the matching.
  
  3. Write the corresponding makefile to generate executable file which named `hw6`. Note that it is the executable name, not the test file name.
  
  4. Make sure your CI job is passed before deadline.

#### Marks

  You totally have 11 tests, each one is 9 points.
  And for easier calculating, the sum score of assignment is 100 points.

#### Deadline

  Wed Nov 29 2017 23:59:59

#### Note

  * Try to read building information in console log and fix the hw problem by yourself as possible as you can.