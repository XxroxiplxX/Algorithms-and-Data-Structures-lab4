//
// Created by piotrkali on 6/1/22.
//

#include "BST.h"

BST::BST(int key) : root(new Node(key)){}

BST::~BST() {

}

void BST::insert(int key) {
    Node *z = new Node(key);
    Node *y = nullptr;
    Node *x = this->root;
    while (x != nullptr) {
        y = x;
        if (z->get_key() < x->get_key()) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        this->root = z;
    } else if (z->get_key() < y->get_key()) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void BST::delete_node(int key) {

}

int BST::height() {
    return 0;
}

Node *BST::search(int key) const {
    Node *x = this->root;
    while (x != nullptr and key != x->get_key()) {
        if (key < x->get_key()) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

Node *BST::minimum(Node *x) {
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}

Node *BST::maximum(Node *x) {
    while (x->right != nullptr) {
        x = x->right;
    }
    return x;
}

Node *BST::succressor(Node *x) {
    if (x->right != nullptr) {
        return minimum(x->right);
    }
    Node *y = x->parent;
    while (y != nullptr and x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
}
