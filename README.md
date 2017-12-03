# POSD2017F Homework

## Homework assignment 7

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this time, you have to design your tests for the iterator of `Struct` and `List`. A structure contains several terms, it can be expanded into a tree structure like the picture below. We will make two kinds of way to traverse the structure, the first is [deep-first search](https://en.wikipedia.org/wiki/Depth-first_search), and the second is [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). When traversing the structure, iterator gets each item in structure orderly.

You need to design the tests to test your iterator, the function signature of iterator and its usage must follow the way that defined on the course. There is also ours tests to test your program on the CI server (.ut job). 

## Chagne history

12/03

first() in our example should return bigmac not combo1.

![Imgur](https://i.imgur.com/v1GyjBX.png)

#### Assignment requirement

  1. Redo the creation of iterator, use aggregate(e.g. `Struct`) to create iterator instead of client, and re-write the test of that.

  2.  As we can handle difference type on function through *template\<T>*, make the template on `Iterator` so it can handle the type other than `Term`.

  3. Design test for the iterator by yourself. The function signature and usage is not allow to change. 
     
     * Two kind of way for traversing: Deep-first search, Breadth-first search, so there will be two methods on the aggregate: `createBFSIterator`, `createDFSIterator`.

     * You need to design 2 test data for each type, `Struct` and `List`, and use BFS and DFS to traverse each test data. So it totally has 8 tests.
 
  4. Write the corresponding makefile to generate executable file which named `hw7`. Note that it is the executable name, not the test file name.

  5. Make sure your CI job is passed before deadline.

#### Marks

  You totally have 12 tests, include the test written on the course. Each one is 5 points.
  And we will have 8 tests, each one is also 5 points.
  The sum score of assignment is 100 points.

#### Deadline

  Fri Dec 8 2017 23:59:59

#### Note

  * Try to read building information in console log and fix the hw problem by yourself as possible as you can.