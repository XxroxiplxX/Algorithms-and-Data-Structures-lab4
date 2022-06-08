#include <iostream>
#include "Node.h"
#include "RBT.h"
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
    printf("[%d]\n", root->key);
    left_trace[depth]=' ';
    if( root->right != nullptr ){
        right_trace[depth]='|';
        print_BST(root->right, depth+1, '\\');
    }
}

int main() {
    int size = 5;
    left_trace= new char[size];
    right_trace= new char[size];
    for(int i=0; i<=size; i++){
        left_trace[i]=' ';
        left_trace[i]=' ';
    }

    RBT rbt = RBT();
    rbt.insert(1);
    rbt.insert(1);
    rbt.insert(2);
    rbt.insert(3);
    rbt.insert(4);
    rbt.dellete(2);
    rbt.dellete(3);
    rbt.dellete(1);
    print_BST(rbt.get_root(), 5, '-');

    return 0;
}