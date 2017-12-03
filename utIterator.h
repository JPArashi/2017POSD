#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "number.h"
#include "iterator.h"

#include <vector>
using std::vector;

TEST(iterator, DFS_struct_1D)
{
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    Struct s(Atom("s"), v);

    Iterator<Term *> *it = s.createDFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, DFS_struct_3D)
{
    // s2(s(1,a),s1(s(1,a)))
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    Struct s(Atom("s"), v);
    vector<Term *> v1 = {&s};
    Struct s1(Atom("s1"), v1);
    vector<Term *> v2 = {&s, &s1};
    Struct s2(Atom("s2"), v2);

    Iterator<Term *> *it = s2.createDFSIterator();
    it->first();
    ASSERT_EQ("s", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("s1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("s", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, BFS_struct_1D)
{
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    Struct s(Atom("s"), v);

    Iterator<Term *> *it = s.createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, BFS_struct_3D)
{
    // s2(s(1,a),s1(s(1,a)))
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    Struct s(Atom("s"), v);
    vector<Term *> v1 = {&s};
    Struct s1(Atom("s1"), v1);
    vector<Term *> v2 = {&s, &s1};
    Struct s2(Atom("s2"), v2);

    Iterator<Term *> *it = s2.createBFSIterator();
    it->first();
    ASSERT_EQ("s", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("s1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("s", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, DFS_list_1D)
{
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    List l(v);

    Iterator<Term *> *it = l.createDFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, DFS_list_3D)
{
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    List l(v);
    vector<Term *> v1 = {&l};
    List l1(v1);
    vector<Term *> v2 = {&l, &l1};
    List l2(v2);

    Iterator<Term *> *it = l2.createDFSIterator();
    it->first();
    ASSERT_EQ("[]", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("[]", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("[]", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, BFS_list_1D)
{
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    List l(v);

    Iterator<Term *> *it = l.createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, BFS_list_3D)
{
    Number n1(1);
    Atom a1("a");
    vector<Term *> v = {&n1, &a1};
    List l(v);
    vector<Term *> v1 = {&l};
    List l1(v1);
    vector<Term *> v2 = {&l, &l1};
    List l2(v2);

    Iterator<Term *> *it = l2.createBFSIterator();
    it->first();
    ASSERT_EQ("[]", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("[]", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("[]", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("a", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

#endif