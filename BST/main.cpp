#include <iostream>
#include <random>
#include "Node.h"
#include "BST.h"

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
    int size = 50;
    left_trace= new char[size];
    right_trace= new char[size];
    for(int i=0; i<=size; i++){
        left_trace[i]=' ';
        left_trace[i]=' ';
    }
    BST bst = BST(0);
    int n = 50;
    srand(time(nullptr));
    cout << "Wstawianie rosnacego ciagu: " << endl;
    cout << "Inicjuje drzewo o korzeniu: 0" << endl;
    std::mt19937 generator(rand());
    std::uniform_int_distribution<int> dis(0, 6);
    std::uniform_int_distribution<int> indexes(0, 49);

    int c = 0;
    int c2 = 1;
    int keys[n];
    while (c < n) {
        int tmp = dis(generator);
        if (tmp == 3) {
            cout << "insert " << c2 << endl;
            bst.insert(c2);
            keys[c] = c2;
            cout << "Stan drzewa po operacji: " << endl;
            print_BST(bst.root, 0, '-');
            c++;
        }
        c2++;
    }
    cout << endl;
    cout << "Usuwam losowo ciag kluczy z drzewa: " << endl;
    c = 0;
    while (c < n) {
        int tmp = indexes(generator);
        if (keys[tmp] != -1) {
            cout << "delete " << keys[tmp] << endl;
            bst.delete_node(keys[tmp]);
            cout << "Stan drzewa po operacji: " << endl;
            print_BST(bst.root, 0, '-');
            keys[tmp] = -1;
            c++;
        }
    }




    return 0;
}
