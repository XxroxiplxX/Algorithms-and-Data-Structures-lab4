//
// Created by piotrkali on 6/7/22.
//

#include "RBT.h"


void RBT::null_node(Node_t node, Node_t parent) {

}

Node_t RBT::search(Node_t node, int key) {
    if (node == nil || key == node->key) {
        return node;
    }

    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

void RBT::delete_fixup(Node_t x) {
    Node_t s;
    while (x != root && x->color == 'b') {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == 'r') {
                s->color = 'b';
                x->parent->color = 'r';
                left_rotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == 'b' && s->right->color == 'b') {
                s->color = 'r';
                x = x->parent;
            } else {
                if (s->right->color == 'b') {
                    s->left->color = 'b';
                    s->color = 'r';
                    right_rotate(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 'b';
                s->right->color = 'b';
                left_rotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->color == 'r') {
                s->color = 'b';
                x->parent->color = 'r';
                right_rotate(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == 'b' && s->right->color == 'b') {
                s->color = 'r';
                x = x->parent;
            } else {
                if (s->left->color == 'b') {
                    s->right->color = 'b';
                    s->color = 'r';
                    left_rotate(s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 'b';
                s->left->color = 'b';
                right_rotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 'b';
}

void RBT::transplant(Node_t u, Node_t v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RBT::dellete(int key) {
    Node_t z = search(root, key);


    Node_t x, y = z;
    int y_original_color = y->color;
    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == 'b') {
        delete_fixup(x);
    }
}

void RBT::insert_fixup(Node_t k) {
    Node_t u;
    while (k->parent->color == 'r') {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 'r') {
                u->color = 'b';
                k->parent->color = 'b';
                k->parent->parent->color = 'r';
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    right_rotate(k);
                }
                k->parent->color = 'b';
                k->parent->parent->color = 'r';
                left_rotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->color == 'r') {
                u->color = 'b';
                k->parent->color = 'b';
                k->parent->parent->color = 'r';
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    left_rotate(k);
                }
                k->parent->color = 'b';
                k->parent->parent->color = 'r';
                right_rotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = 'b';
}

Node_t RBT::minimum(Node_t node) {
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

Node_t RBT::successor(Node_t x) {
    if (x->right != nil) {
        return minimum(x->right);
    }

    Node_t y = x->parent;
    while (y != nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

void RBT::left_rotate(Node_t x) {
    Node_t y = x->right;
    x->right = y->left;
    if (y->left != nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBT::right_rotate(Node_t x) {
    Node_t y = x->left;
    x->left = y->right;
    if (y->right != nil) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

RBT::RBT() {
    nil = new Node;
    nil->color = 'b';
    nil->left = nullptr;
    nil->right = nullptr;
    root = nil;
}

void RBT::insert(int key) {
    auto node = new Node;
    node->parent = nullptr;
    node->key = key;
    node->left = nil;
    node->right = nil;
    node->color = 'r';

    Node_t y = nullptr;
    Node_t x = this->root;

    while (x != nil) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == nullptr) {
        node->color = 'b';
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    insert_fixup(node);
}

Node_t RBT::get_root() {
    return root;
}

Node_t RBT::get_nil() {
    return nil;
}
