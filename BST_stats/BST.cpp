//
// Created by piotrkali on 6/2/22.
//

#include <algorithm>
#include <iostream>
#include "BST.h"

BST::BST(int key) : root(new Node(key)), comparisons(0), read_and_displacements(0){}

BST::~BST() {
    this->root = clean(root);
    std::cout << "Usunieto drzewo" << std::endl;
}

void BST::insert(int key) {
    Node *z = new Node(key);
    Node *y = nullptr;
    Node *x = this->root;
    while (x != nullptr) {
        read_and_displacements++;
        y = x;
        if (z->get_key() < x->get_key()) {
            comparisons++;
            x = x->left;
            read_and_displacements++;
        } else {
            comparisons++;
            x = x->right;
            read_and_displacements++;
        }
    }
    read_and_displacements++;
    z->parent = y;
    read_and_displacements++;
    if (y == nullptr) {
        read_and_displacements++;
        this->root = z;
        read_and_displacements++;
    } else if (z->get_key() < y->get_key()) {
        read_and_displacements++;
        comparisons++;
        y->left = z;
        read_and_displacements++;
    } else {
        read_and_displacements++;
        y->right = z;
        read_and_displacements++;
    }
}

void BST::delete_node(int key) {
    Node *z = this->search(key);
    Node *y, *x;
    if (z->left == nullptr or z->right == nullptr) {
        read_and_displacements += 4;
        y = z;
    } else {
        read_and_displacements += 4;
        y = successor(z);
    }
    if (y->left != nullptr) {
        read_and_displacements += 2;
        x = y->left;
        read_and_displacements++;
    } else {
        read_and_displacements += 2;
        x = y->right;
        read_and_displacements++;
    }
    if (x != nullptr) {
        x->parent = y->parent;
        read_and_displacements += 2;
    }
    read_and_displacements++;
    if (y->parent == nullptr) {
        read_and_displacements += 2;
        this->root = x;
        read_and_displacements++;
    } else if (y == y->parent->left) {
        read_and_displacements += 2;
        read_and_displacements += 3;
        y->parent->left = x;
        read_and_displacements += 2;
    } else {
        read_and_displacements += 2;
        read_and_displacements += 3;
        y->parent->right = x;
        read_and_displacements += 2;
    }
    if (y != z) {
        z->change_key(y->get_key());
    }
    read_and_displacements++;

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

Node * BST::search(int key) {
    Node *x = this->root;
    while (x != nullptr and key != x->get_key()) {
        //read_and_displacements++;
        //comparisons++;
        if (key < x->get_key()) {
            //comparisons++;
            x = x->left;
            //read_and_displacements++;
        } else {
            //comparisons++;
            x = x->right;
            //read_and_displacements++;
        }
    }
    //read_and_displacements++;
    //comparisons++;
    return x;
}

Node *BST::minimum(Node *x) {
    while (x->left != nullptr) {
        read_and_displacements +=2;
        x = x->left;
        read_and_displacements++;
    }
    read_and_displacements++;
    return x;
}

Node *BST::maximum(Node *x) {
    while (x->right != nullptr) {
        x = x->right;
    }
    return x;
}

Node *BST::successor(Node *x) {
    read_and_displacements++;
    if (x->right != nullptr) {
        return minimum(x->right);
    }
    read_and_displacements += 2;
    Node *y = x->parent;
    read_and_displacements++;
    while (y != nullptr and x == y->right) {
        read_and_displacements += 3;
        x = y;
        y = y->parent;
        read_and_displacements++;
    }
    read_and_displacements += 3;

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

int BST::get_read_and_displacements() {
    return read_and_displacements;
}

int BST::get_comparisons() {
    return comparisons;
}

void BST::reset_stats() {
    comparisons = 0;
    read_and_displacements = 0;
}
