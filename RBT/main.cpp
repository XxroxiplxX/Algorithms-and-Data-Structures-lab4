#include <iostream>
#include "RBT.h"
#include "Node.h"
int main() {
    RBT rbt = RBT(3);
    rbt.root->right = new Node(4);
    rbt.root->right->right = new Node(5);
    rbt.left_roate(rbt.root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
