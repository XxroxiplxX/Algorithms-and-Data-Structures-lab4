//
// Created by piotrkali on 6/2/22.
//

#ifndef BST_STATS_NODE_H
#define BST_STATS_NODE_H

#include <cstdlib>

class Node {
    int key;
public:
    Node *parent;
    Node *left;
    Node *right;
    explicit Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr){};
    ~Node() {
        //free(this);
    }
    int get_key() const {
        return this->key;
    };
    int change_key(int key) {
        this->key = key;
    }
};

#endif //BST_STATS_NODE_H
