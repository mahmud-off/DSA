#include <iostream>
#include "BST.h"

using namespace std;

//insert
//find
//min
//max
//inorderWalk
//preorderWalk
//successor
//predecessor
//Delete


int main() {

    BST tree;



    tree.insert(10);
    tree.insert(7);
    tree.insert(9);
    tree.insert(2);
    tree.insert(20);
    tree.insert(32);
    tree.insert(12);


    cout << tree.min() << "\n"; // 2
    cout << tree.max() << "\n"; // 32

    tree.inorderWalk(tree.getRoot()); //2 7 9 10 12 20 32
    cout << "\n";
    tree.preorderWalk(tree.getRoot()); //10 7 2 9 20 12 32
    cout << "\n";

    cout << tree.successor()->getData() << "\n"; // 12
    cout << tree.predecessor()->getData() << "\n"; // 9

    tree.Delete(10);
    tree.inorderWalk(tree.getRoot()); //2 7 9 12 20 32
    cout << "\n";



    return 0;
}


