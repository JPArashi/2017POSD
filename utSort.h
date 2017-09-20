#ifndef EXP_H
#define EXP_H
#include <list>
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"


TEST (Sort, sortByIncreasingPerimeter) {
    Circle cir(0, 0, 12);
    std::list<Shape *> shapeList;
    shapeList.push_back(&cir);
    Sort::sortByIncreasingPerimeter(&shapeList);

}

TEST (Sort, sortByDecreasingPerimeter) {
    Rectangle rect(0, 0, 8, 9);
    
}

TEST (Sort, sortByIncreasingArea) {

}

TEST (Sort, sortByDecreasingArea) {

}

TEST (Sort, sortByIncreasingCompactness) {

}

#endif
