#include <string>
#include "bst.h"
#include <iostream>
using namespace std;


BinarySearchTree::BinarySearchTree(){
    root = NULL;
};

void BinarySearchTree::insert(int key, string val){
    Node* newNode = new Node();     
    newNode->key = key;
    newNode->val = val;
    newNode->right = newNode->left = NULL;
    if(root == nullptr){
        root = newNode;
    }
    else{
        insertHelper(root, newNode);
    }
};

void BinarySearchTree::insertHelper(Node* parent, Node* new_node){
    if(parent == nullptr){
        
        parent = new_node;
    }
    else if(new_node->key < parent-> key){
        if (parent->left == nullptr){
            parent->left = new_node;
        }
        else{
            insertHelper(parent->left, new_node);
        }
    }
    else{
        if (parent->right == nullptr){
            parent->right = new_node;
        }
        else{
            insertHelper(parent->right, new_node);
        }
    }
};

void BinarySearchTree::printInOrder() const {
    if (root == nullptr){
        cout << "Empty BST" << endl;
    }
    else{
        printInOrderHelper(root);
    }
};

void BinarySearchTree::printInOrderHelper(Node* n) const{
    if (n == nullptr){
        return;
    }
    else{
        printInOrderHelper(n->left);
        cout << n-> key << endl;
        printInOrderHelper(n->right);
    }
};


string BinarySearchTree::find(int key) const {
    Node* currentNode = root;
    while (currentNode != nullptr && currentNode->key != key){
        if (key < currentNode->key)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }
    if (currentNode == nullptr)
    {
        return "";
    }
    else
    {
        return currentNode->val;
    }
};


//Rules of BST
//1. The left subtree of a node contains only nodes with keys lesser than the node's key
//2. The right subtree of a node contains only nodes with keys greater than the node's key
//3. The left and right subtree each must also be a binary tree
//4. No duplicate nodes

/*
BST printInOrderHelper(Node* n) const{
    if (n->left == nullptr && n->right == nullptr){
        cout << n->val << endl;
    }
    else{
        printInOrderHelper(n->left);
        printInOrderHelper(n->right);

    }
}
*/


/*
BST printInOrder() const{
    if (root == nullptr){
        cout << "Empty BST" << endl;
    }
    else{
        printInOrderHelper(root);
    }
}
*/


/*
BST insertHelper(Node* parent, Node* new_node) - Recursively
if(parent == nullptr){
    parrent = newNode;
}
elseif(key < currentNode-> key){
    insertHelper(currentNode->left, newNode);
}
else{
    insertHelper(currentNode->right, newNode);
}
*/

/*
BST Insert(int key, string val) - Recursively
currentNode = root;
Node* newNode; 
newNode->key = key;
newNode->val = val;
if(root == nullptr){
    root = newNode;
}
elseif(key < currentNode-> key){
    insertHelper(currentNode->left, newNode);
}
else{
    insertHelper(currentNode->right, newNode);
}
*/

/*
BST Find(int key) - Iteratively
We need to keep track of the current node and iterate until key is found or end of BST(nullptr)

while (currentNode != nullptr && currentNode != key){
    if key < currentNode->key
        currentNode = currentNode->left
    else
        currentNode = currentNode->right
}
if (currentNode == nullptr){
    cout << "Key was not found in the BST" << endl;
}
else{
    cout << "Key found, value of " << currentNode << endl;
}

*/