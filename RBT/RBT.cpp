//
// Created by piotrkali on 6/7/22.
//

#include "RBT.h"

void RBT::insert(int key) {
    Node *z = new Node(key);
    z->change_color('r');

}

Node *RBT::search(int key) {
    return nullptr;
}

void RBT::left_roate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBT::right_rotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->left = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RBT::insert_fixup(Node *node) {

}

RBT::~RBT() {

}
