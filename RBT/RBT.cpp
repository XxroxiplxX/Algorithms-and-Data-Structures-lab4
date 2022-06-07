//
// Created by piotrkali on 6/7/22.
//

#include "RBT.h"

static Node *nil = nullptr;


void RBT::insert(int key) {
    Node *z = new Node(key);
    z->change_color('r');
    Node *y = nullptr;
    Node *x = root;

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
        root = z;
    } else if (z->get_key() < y->get_key()) {
        y->left = z;
    } else {
        y->right = z;
    }
    if (z->parent == nullptr) {
        z->change_color('b');
        return;
    }
    if (z->parent->parent == nullptr) {
        return;
    }
    insert_fixup(z);
}

Node *RBT::search(int key) {
    return nullptr;
}

void RBT::left_rotate(Node *x) {
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

void RBT::insert_fixup(Node *k) {
    Node *u = nullptr;
    while (k->parent->get_color() == 'r') {
        if (k->parent == k->parent->parent->left) {
            u = k->parent->parent->right;
            if (check_color(u) == 'r') {
                u->change_color('b');
                k->parent->change_color('b');
                k->parent->parent->change_color('r');
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    left_rotate(k);
                }
                k->parent->change_color('b');
                k->parent->parent->change_color('r');
                right_rotate (k->parent->parent);
            }
        } else if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (check_color(u) == 'r') {
                u->change_color('b');
                k->parent->change_color('b');
                k->parent->parent->change_color('r');
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    right_rotate(k);
                }
                k->parent->change_color('b');
                k->parent->parent->change_color('r');
                left_rotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->change_color('b');
}



RBT::~RBT() {

}

void RBT::dellete_fixup(Node *x) {
    Node *w = nullptr;
    while (x != root and x->get_color() == 'b') {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w != nullptr and w->get_color() == 'r') {
                w->change_color('b');
                x->parent->change_color('r');
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if (w->left != nullptr and w->right != nullptr and w->left->get_color() == 'b' and w->right->get_color() == 'b') {
                w->change_color('r');
                x = x->parent;
            } else if (w->right == nullptr or w->right->get_color() == 'b') {
                w->left->change_color('r');
                w->change_color('r');
            }
        }
    }
}

RBT::RBT(int key) {
    root = new Node(key);
}


char RBT::check_color(Node *x) {
    if (x == nullptr) {
        return 'b';
    } else return x->get_color();
}


