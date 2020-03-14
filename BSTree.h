#ifndef PROGRAM4_BSTREE_H
#define PROGRAM4_BSTREE_H
#include "Movie.h"

/*
 * The BSTree class has the functionality
 * of a binary search tree, with its data
 * being objects of the Movie class. The
 * class can be used to insert movies to the
 * tree, display its contents in sorted order,
 * and search for a specific movie in the tree.
 */
class BSTree {
public:
    BSTree();
    ~BSTree();

    bool insert(Movie* movie);

    bool search(Movie*& movie) const; // if film is found, movie holds pointer to object in BST

    // does inOrder traversal of movies and displays their information
    void display() const;
    void empty();
    bool isTreeEmpty() const;

private:
    struct Node {
        Movie* data;
        Node* left;
        Node* right;
    };

    Node* root;

    bool isEmpty(Node* root) const; // helper method for insert
    void inOrderTraversal(Node* root) const; // helper method for display()
    void remove(); // helper method for empty()
};


#endif //PROGRAM4_BSTREE_H
