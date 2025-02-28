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
//------------
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








/*
class BST {
    struct Node {
        Node *left, *right, *parent;
        int value;
        Node(int x, Node *parent_ = nullptr, Node *left_ = nullptr, Node * right_ = nullptr):
            value(x), parent(parent_), left(left_), right(right_) {
        }
    };

public:
    BST() {
        size = 0;
        root_ = nullptr;
    }

    void Insert(int x) {

        if (!size) {
            root_ = new Node(x);
            size++;
            return;
        }
        Node* node = root_;
        Node* parent = nullptr;
        while (node) {
            parent = node;
            if (isRight(node, x)) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        if (isRight(parent, x)) {
            parent->right = new Node(x, parent);
        } else {
            parent->left = new Node(x, parent);
        }
        size++;
    }

    bool Delete(int x) {
        auto node = findNode(x);
        if (node == nullptr) {
            return false;
        }
        if (!node->left && !node->right) {
            checkAndAssign(node->parent, x, nullptr);
            size--;
            return true;
        }
        if (!node->left) {
            Node* saved_node = node->right;
            checkAndAssign(node->parent, x, saved_node);
            size--;
            return true;
        }
        if (!node->right) {
            Node* saved_node = node->left;
            checkAndAssign(node->parent, x, saved_node);
            return true;
        }
        auto find_local_max = getMax(node->left);
        if (find_local_max->left) {
            if (find_local_max->parent->right == find_local_max) {
                find_local_max->parent->right = find_local_max->left;
            } else {
                find_local_max->parent->left = find_local_max->left;
            }
        }
        node->value = find_local_max->value;
        find_local_max->parent->right = nullptr;
        size--;
        delete find_local_max;
        return true;
    }

    bool Find(int x) {
        return findNode(x) != nullptr;
    }

    void Print() {
        print(root_);
    }

private:
    void print(Node* node) {
        if (node->left) {
            print(node->left);
        }
        printf("%d ", node->value);
        if (node->right) {
            print(node->right);
        }
    }

    Node* getMax(Node* root) {
        if (root->right) {
            return getMax(root->right);
        } else {
            return root;
        }
    }

    void checkAndAssign(Node* parent, int x, Node* new_value) {
        if (isRight(parent, x)) {
            delete parent->right;
            parent->right = new_value;
        } else {
            delete parent->left;
            parent->left = new_value;
        }
    }

    bool isRight(Node* node, int x) {
        return node->value < x;
    }

    Node* findNode(int x) {
        Node* node = root_;
        while (node) {
            if (node->value == x) {
                return node;
            }
            if (node->value < x) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return nullptr;
    }
    Node* root_;
    int size;
};


int main() {
    BST bst;
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(1);
    bst.Insert(6);
    bst.Insert(11);
    bst.Insert(16);
    bst.Print();
    printf("\n");
    bst.Delete(10);
    bst.Print();

}
*/