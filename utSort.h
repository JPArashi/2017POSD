#ifndef EXP_H
#define EXP_H
#include <list>
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"



#include <iostream>
void setUp(std::list<Shape *> & shapeList){
    shapeList.push_back(new Circle(0, 0, 12, "c1"));
    shapeList.push_back(new Circle(0, 0, 24, "c2"));
    shapeList.push_back(new Circle(0, 0, 20, "c3"));
    shapeList.push_back(new Triangle({0, 0}, {1, 0}, {0, 1}, "t1"));
    shapeList.push_back(new Triangle({0, 0}, {4, 0}, {0, 4}, "t2"));
    shapeList.push_back(new Triangle({0, 0}, {3, 0}, {0, 3}, "t3"));
    shapeList.push_back(new Rectangle(0, 0, 4, 4, "r1"));
    shapeList.push_back(new Rectangle(0, 0, 4, 1, "r2"));
    shapeList.push_back(new Rectangle(0, 0, 9, 2, "r3"));

    // for (std::list<Shape *>::iterator i = shapeList.begin(); i != shapeList.end(); ++i)
    //     std::cout << (*i)->area() / (*i)->perimeter() << std::endl;
}

void tearDown(std::list<Shape *> & shapeList){
    while (!shapeList.empty())
    {
        delete shapeList.back();
        shapeList.pop_back();
    }
}

TEST (Sort, sortByIncreasingPerimeter) {
    std::list<Shape *> shapeList;
    setUp(shapeList);
    Sort::sortByIncreasingPerimeter(&shapeList);
    std::list<Shape *>::iterator i = shapeList.begin();
    ASSERT_EQ("t1", (*i++)->name);
    ASSERT_EQ("r2", (*i++)->name);
    ASSERT_EQ("t3", (*i++)->name);
    ASSERT_EQ("t2", (*i++)->name);
    ASSERT_EQ("r1", (*i++)->name);
    ASSERT_EQ("r3", (*i++)->name);
    ASSERT_EQ("c1", (*i++)->name);
    ASSERT_EQ("c3", (*i++)->name);
    ASSERT_EQ("c2", (*i++)->name);   
    tearDown(shapeList);
}

TEST (Sort, sortByDecreasingPerimeter) {
    std::list<Shape *> shapeList;
    setUp(shapeList);
    Sort::sortByDecreasingPerimeter(&shapeList);
    std::list<Shape *>::iterator i = shapeList.begin();
    ASSERT_EQ("c2", (*i++)->name); 
    ASSERT_EQ("c3", (*i++)->name);
    ASSERT_EQ("c1", (*i++)->name);
    ASSERT_EQ("r3", (*i++)->name);
    ASSERT_EQ("r1", (*i++)->name);
    ASSERT_EQ("t2", (*i++)->name);
    ASSERT_EQ("t3", (*i++)->name);
    ASSERT_EQ("r2", (*i++)->name);
    ASSERT_EQ("t1", (*i++)->name);
    tearDown(shapeList);
}

TEST (Sort, sortByIncreasingArea) {
    std::list<Shape *> shapeList;
    setUp(shapeList);
    Sort::sortByIncreasingArea(&shapeList);
    std::list<Shape *>::iterator i = shapeList.begin();
    ASSERT_EQ("t1", (*i++)->name);
    ASSERT_EQ("r2", (*i++)->name);
    ASSERT_EQ("t3", (*i++)->name);
    ASSERT_EQ("t2", (*i++)->name);
    ASSERT_EQ("r1", (*i++)->name);
    ASSERT_EQ("r3", (*i++)->name);
    ASSERT_EQ("c1", (*i++)->name);
    ASSERT_EQ("c3", (*i++)->name);
    ASSERT_EQ("c2", (*i++)->name);   
    tearDown(shapeList);
}

TEST (Sort, sortByDecreasingArea) {
    std::list<Shape *> shapeList;
    setUp(shapeList);
    Sort::sortByDecreasingArea(&shapeList);
    std::list<Shape *>::iterator i = shapeList.begin();
    ASSERT_EQ("c2", (*i++)->name); 
    ASSERT_EQ("c3", (*i++)->name);
    ASSERT_EQ("c1", (*i++)->name);
    ASSERT_EQ("r3", (*i++)->name);
    ASSERT_EQ("r1", (*i++)->name);
    ASSERT_EQ("t2", (*i++)->name);
    ASSERT_EQ("t3", (*i++)->name);
    ASSERT_EQ("r2", (*i++)->name);
    ASSERT_EQ("t1", (*i++)->name);    
    tearDown(shapeList);
}

TEST (Sort, sortByIncreasingCompactness) {
    std::list<Shape *> shapeList;
    setUp(shapeList);
    Sort::sortByIncreasingCompactness(&shapeList);
    std::list<Shape *>::iterator i = shapeList.begin();
    ASSERT_EQ("t1", (*i++)->name); 
    ASSERT_EQ("r2", (*i++)->name);
    ASSERT_EQ("t3", (*i++)->name);
    ASSERT_EQ("t2", (*i++)->name);
    ASSERT_EQ("r3", (*i++)->name);
    ASSERT_EQ("r1", (*i++)->name);
    ASSERT_EQ("c1", (*i++)->name);
    ASSERT_EQ("c3", (*i++)->name);
    ASSERT_EQ("c2", (*i++)->name);    
    tearDown(shapeList);
}

#endif
