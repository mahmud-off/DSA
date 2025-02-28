#include "Node.h"
#ifndef BST_H
#define BST_H

class BST {


public:
    BST();
    bool find(int value);
    void insert(int value);

    int min();
    int max();

    void inorderWalk(Node* node);
    void preorderWalk(Node* node);

    Node* successor();
    Node* predecessor();

    void Delete(int value);

    Node* getRoot(){return root;}

private:
    Node* root;
    int size;

};

#endif //BST_H
