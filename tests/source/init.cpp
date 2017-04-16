#include <2Lab-5.hpp>
#include <catch.hpp>

SCENARIO("Add") {
    BinarySearchTree<int> r;
    BinarySearchTree<int> *tree;
    int rv = r.Add(10, tree);
    
    REQUIRE( rv == 10);
}
SCENARIO("Print") {
    BinarySearchTree<int> r;
    BinarySearchTree<int> *tree;
    int rv = r.Print(11, tree);
    
    REQUIRE( rv == 11);
}
SCENARIO("Search") {
    BinarySearchTree<int> r;
    BinarySearchTree<int> *tree;
    int rv = r.Search(12, tree);
    
    REQUIRE( rv == 12);
}
SCENARIO("Delete_branch") {
    BinarySearchTree<int> r;
    BinarySearchTree<int> *tree;
    int rv = r.Search(13, tree);
    
    REQUIRE( rv == 13);
}
SCENARIO("FreeTree") {
    BinarySearchTree<int> r;
    BinarySearchTree<int> *tree;
    int rv = r.Search(14, tree);
    
    REQUIRE( rv == 14);
}

