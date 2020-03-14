#include "BSTree.h"

// default constructor
BSTree::BSTree() {
    root = nullptr;
}

// destructor, deallocate all memory in heap
BSTree::~BSTree() {
    empty(); // empties out tree
}

/*
 * inserts a movie into the BST
 * in sorted order.
 */
bool BSTree::insert(Movie *movie) {
    // check if object is null
    if(movie == nullptr)
        return false;
    else if(isEmpty(root)) { // tree is empty, place node at root
        root = new Node;
        root->data = movie;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        Node* prev = new Node;
        Node* tmp = root;
        while(!isEmpty(tmp)) { // traverse tree for insertion
            prev = tmp;
            if(*tmp->data < *movie)
                tmp = tmp->right;
            else if(*tmp->data > *movie)
                tmp = tmp->left;
            else
                return false; // object is already in tree
        }
        tmp = new Node;
        if(*prev->data < *movie) {
            prev->right = new Node;
            prev->right = tmp;
        }
        else if(*prev->data > *movie) {
            prev->left = new Node;
            prev->left = tmp;
        }
        tmp->data = movie; // add Movie to BST
        tmp->left = nullptr;
        tmp-> right = nullptr;
    }
    return true;
}

// helper method to check if tree/subtree is empty
bool BSTree::isEmpty(Node *root) const {
    return root == nullptr;
}

/*
 * displays each movie's information
 * by calling their display().
 */
void BSTree::display() const {
    if(root == nullptr) // tree is empty
        return;
    // helper method to traverse tree in order
    inOrderTraversal(root);
}

/*
 * precondition: BSTree is not empty.
 * postcondition: traverses the tree
 * in order to output each movie's information.
 */
void BSTree::inOrderTraversal(Node* root) const {
    if(root->left != nullptr)
        inOrderTraversal(root->left);
    root->data->display();
    if(root->right != nullptr)
        inOrderTraversal(root->right);
}

// empties entire tree
void BSTree::empty() {
    while(!isTreeEmpty()) {
        // remove node, one at a time
        remove();
    }
}

// removes smallest node from BSTree
void BSTree::remove() {
    //go as far left as possible
    // check if node is leaf, delete if so
    // else if child, copy child to node and delete child
    Node* tmp = root;
    while(tmp->left != nullptr) // find smallest node
        tmp = tmp->left;
    if(tmp->left == nullptr && tmp->right == nullptr) { // node is a leaf
        delete tmp;
        tmp = nullptr; // no dangling pointer
    }
    else { // node has right child
        tmp->data = tmp->right->data;
        delete tmp->right;
        tmp->right = nullptr; // no dangling pointer
    }
}

// checks if tree is empty
bool BSTree::isTreeEmpty() const {
    return root == nullptr;
}

/*
 * searches for movie in BST and
 * sets Movie* passed in parameter
 * to the Node* pointing to the movie.
 */
bool BSTree::search(Movie *&movie) const {
    // this is nonsense
    Node* tmp = root;
    while(tmp != nullptr) {
        if(*tmp->data == *movie) {
            movie = tmp->data;
            return true;
        }
        else if(*tmp->data < *movie)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    return false; // movie was not found in tree
}
