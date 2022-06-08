//
// Created by piotrkali on 6/8/22.
//

#ifndef RBT2_NODE_H
#define RBT2_NODE_H
struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;
    char color;
};
#endif //RBT2_NODE_H
