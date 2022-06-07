#include <iostream>
#include "RBT.h"
#include "Node.h"

using namespace std;

char* left_trace; // needs to be allocaded with size
char* right_trace; // needs to be allocaded with size


void print_BST(Node *root, int depth,char prefix){
    if( root == nullptr ) return;
    if( root->left != nullptr ){
        print_BST(root->left, depth+1, '/');
    }
    if(prefix == '/') left_trace[depth-1]='|';
    if(prefix == '\\') right_trace[depth-1]=' ';
    if( depth==0) printf("-");
    if( depth>0) printf(" ");
    for(int i=0; i<depth-1; i++)
        if( left_trace[i]== '|' || right_trace[i]=='|' ) {
            printf("| ");
        } else {
            printf("  ");
        }
    if( depth>0 ) printf("%c-", prefix);
    printf("[%d]\n", root->get_key());
    left_trace[depth]=' ';
    if( root->right != nullptr ){
        right_trace[depth]='|';
        print_BST(root->right, depth+1, '\\');
    }
}


int main() {
    int size = 10;
    left_trace= new char[size];
    right_trace= new char[size];
    for(int i=0; i<=size; i++){
        left_trace[i]=' ';
        left_trace[i]=' ';
    }
    RBT rbt = RBT(2);
    rbt.insert(1);
    rbt.insert(4);
    rbt.insert(6);
    rbt.insert(8);
    rbt.insert(10);
    rbt.insert(12);
    rbt.insert(14);
    rbt.insert(16);
    rbt.insert(18);

    print_BST(rbt.root, 0, '-');


    return 0;
}
