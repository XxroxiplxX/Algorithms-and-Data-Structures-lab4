//
// Created by piotrkali on 6/7/22.
//

#ifndef RBT2_RBT_H
#define RBT2_RBT_H

#include "Node.h"
typedef Node *Node_t;
class RBT {
private:
    Node_t nil;
    void null_node(Node_t node, Node_t parent);
    Node_t search(Node_t node, int key);
    void delete_fixup(Node_t x);
    void transplant(Node_t u, Node_t v);
    void insert_fixup(Node_t k);
    Node_t minimum(Node_t node);
    Node_t successor(Node_t x);
    void left_rotate(Node_t x);
    void right_rotate(Node_t x);
    Node_t root;
public:
    void insert(int key);
    void dellete(int key);
    explicit RBT();
    Node_t get_root();
    Node_t get_nil();
};


#endif //RBT2_RBT_H
