//
// Created by piotrkali on 6/7/22.
//

#ifndef RBT_RBT_H
#define RBT_RBT_H

#include "Node.h"
class RBT {
public:
    explicit RBT(int key) : root(new Node(key)) {};
    ~RBT();
    Node * root;
    void insert(int key);
    Node *search(int key);
    void left_roate(Node *x);
    void right_rotate(Node *x);
    void insert_fixup(Node *node);
};


#endif //RBT_RBT_H
