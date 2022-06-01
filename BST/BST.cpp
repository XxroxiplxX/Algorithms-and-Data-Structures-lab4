//
// Created by piotrkali on 6/1/22.
//

#include "BST.h"

BST::BST(int key) {

}

BST::~BST() {

}

void BST::insert(int key) {

}

void BST::delete_node(int key) {

}

int BST::height() {
    return 0;
}

Node *BST::search(int key) {
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
