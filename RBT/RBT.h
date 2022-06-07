//
// Created by piotrkali on 6/7/22.
//

#ifndef RBT_RBT_H
#define RBT_RBT_H

#include "Node.h"
#include "stdlib.h"
class RBT {
public:
    explicit RBT(int key);
    ~RBT();
    Node *root;
    void insert(int key);
    Node *search(int key);
    void left_rotate(Node *x);
    void right_rotate(Node *x);
private:
    void insert_fixup(Node *node);
    void dellete_fixup(Node *node);
    static char check_color(Node *x);
};


#endif //RBT_RBT_H
