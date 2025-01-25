#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    BSTNode<T>* root;

    void insert(BSTNode<T>*& node, const T& value) {
        if (!node) {
            node = new BSTNode<T>(value);
        } else if (value.getID() < node->data.getID()) { 
            insert(node->left, value);
        } else if (value.getID() > node->data.getID()) {
            insert(node->right, value);
        }
    }

    bool search(BSTNode<T>* node, int ID) const {
        if (!node) return false;
        if (node->data.getID() == ID) return true;
        if (ID < node->data.getID()) return search(node->left, ID);
        return search(node->right, ID);
    }

    void inOrderTraversal(BSTNode<T>* node) const {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->data.getID() << " " << node->data.getBrand() << " " << node->data.getModel() << endl;
            inOrderTraversal(node->right);
        }
    }

    void clear(BSTNode<T>*& node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(const T& value) {
        insert(root, value);
    }

    bool search(int ID) const {
        return search(root, ID);
    }

    void inOrderTraversal() const {
        inOrderTraversal(root);
    }

    void clear() {
        clear(root);
    }
};

#endif