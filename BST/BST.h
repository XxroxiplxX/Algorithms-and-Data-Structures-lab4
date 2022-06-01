//
// Created by piotrkali on 6/1/22.
//

#ifndef BST_BST_H
#define BST_BST_H
#include "Node.h"

class BST {
    public:
    Node *root;
    explicit BST(int key);
    ~BST();
    void insert(int key);
    void delete_node(int key);
    int height();
    Node *search(int key) const;
    static Node *minimum(Node *x);
    static Node *maximum(Node *x);
    static Node *succressor(Node *x);
};


#endif //BST_BST_H
