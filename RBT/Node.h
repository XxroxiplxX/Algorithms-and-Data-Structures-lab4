//
// Created by piotrkali on 6/7/22.
//

#ifndef RBT_NODE_H
#define RBT_NODE_H
class Node {
    int key;
    char color;
public:
    Node *parent;
    Node *left;
    Node *right;
    explicit Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr), color('B') {};
    ~Node();
    void make_leaf() {
        color = 'b';
    }
    char get_color() const {
        return color;
    }
    void change_color(char color) {
        this->color = color;
    }
    int get_key() const {
        return key;
    }
    void change_key(int key) {
        this->key = key;
    }
};



#endif //RBT_NODE_H
