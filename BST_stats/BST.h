//
// Created by piotrkali on 6/2/22.
//

#ifndef BST_STATS_BST_H
#define BST_STATS_BST_H
#include "Node.h"

class BST {
    long comparisons;
    long read_and_displacements;
public:
    Node *root;
    explicit BST(int key);
    ~BST();
    void insert(int key);
    void delete_node(int key);
    static int height(Node *x);
    Node * search(int key);
    Node *minimum(Node *x);
    Node *maximum(Node *x);
    Node *successor(Node *x);
    static Node *clean(Node *x);
    int get_comparisons();
    int get_read_and_displacements();
    void reset_stats();
};


#endif //BST_STATS_BST_H
