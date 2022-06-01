//
// Created by piotrkali on 6/1/22.
//

#ifndef BST_NODE_H
#define BST_NODE_H

#include <cstdlib>

class Node {
    int key;
    Node * parent;
    Node * left;
    Node * right;
public:
    explicit Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr){};
    ~Node() {
        free(this);
    }
    int get_key() const;
};

int Node::get_key() const {
    return this->key;
}

#endif //BST_NODE_H
