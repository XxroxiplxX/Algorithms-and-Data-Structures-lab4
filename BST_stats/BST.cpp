//
// Created by piotrkali on 6/2/22.
//

#include <algorithm>
#include <iostream>
#include "BST.h"

BST::BST(int key) : root(new Node(key)){}

BST::~BST() {
    this->root = clean(root);
    std::cout << "Usunieto drzewo" << std::endl;
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
    Node *z = this->search(key);
    Node *y, *x;
    if (z->left == nullptr or z->right == nullptr) {
        y = z;
    } else {
        y = successor(z);
    }
    if (y->left != nullptr) {
        x = y->left;
    } else {
        x = y->right;
    }
    if (x != nullptr) {
        x->parent = y->parent;
    }
    if (y->parent == nullptr) {
        this->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    if (y != z) {
        z->change_key(y->get_key());
    }

    //delete x;
    //delete y;
    //delete z;
}

int BST::height(Node *x) {
    if (x == nullptr) {
        return 0;
    }
    int left_hegith = height(x->left);
    int right_height = height(x->right);
    return std::max(left_hegith, right_height) + 1;
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

Node *BST::successor(Node *x) {
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

Node *BST::clean(Node *x) {
    if (x == nullptr) {
        return nullptr;
    }
    clean(x->left);
    clean(x->right);
    delete x;
    return nullptr;
}
