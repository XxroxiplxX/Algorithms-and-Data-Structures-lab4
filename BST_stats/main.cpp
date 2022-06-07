#include <iostream>
#include <random>
#include <fstream>
#include "BST.h"

using namespace std;

void experiment_ascending() {
    ofstream save("data.csv");
    vector<long> comps(10, 0);
    vector<long> reads_and_displacements(10, 0);
    vector<long> reads_and_displacements_delete(10, 0);
    int k = 5;
    int *keys;
    srand(time(nullptr));
    mt19937 generator(rand());
    uniform_int_distribution<int> distribution(0,6);

    int j = 0;
    for (int n = 10000; n <= 100000; n += 10000) {

        int c;
        int c2;
        keys = new int[n];
        uniform_int_distribution<int> indexes(0, n - 1);
        cout << "n = " << n << endl;
        for (int i = 1; i <= k; i++) {
            c2 = 1;
            c = 0;
            BST bst = BST(0);
            keys[0] = 0;
            while (c < n - 1) {
                int tmp = distribution(generator);
                if (tmp == 3) {
                    bst.insert(c2);
                    keys[c + 1] = c2;
                    c++;
                }
                c2++;
            }
            comps[j] += (bst.get_comparisons()/k);
            reads_and_displacements[j] += (bst.get_read_and_displacements()/k);
            bst.reset_stats();
            while (c < n) {
                int tmp = indexes(generator);
                if (keys[tmp] != -1) {
                    bst.delete_node(keys[tmp]);
                    keys[tmp] = -1;
                    c++;
                }
            }
            reads_and_displacements_delete[j] += (bst.get_read_and_displacements()/k);
        }
        delete keys;
        j++;
    }
    for (int i = 0; i < 10; i++) {
        save << (i + 1)*10000 << ";" << comps[i] << ";" << reads_and_displacements[i] << ";" <<  reads_and_displacements_delete[i] << endl;
    }
    save.close();
}

int main() {
    experiment_ascending();

    return 0;
}
