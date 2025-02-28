#include "BST.h"
#include "Node.h"
#include <iostream>

using namespace std;

bool isLeft(Node* node, Node* parent) {
    if(node->getData() < parent->getData())
        return true;
    return false;
}

BST::BST() {
    root = nullptr;
    size = 0;
}


bool BST::find(int value) {
    //дословно, пока не найдём или пока не лист


    Node* new_Node = root;

    while(new_Node) {

        if(new_Node->getData() == value)
            return true;

        if(new_Node->getData() > value)
            new_Node = new_Node->getLeft();
        else
            new_Node = new_Node->getRight();
    }

    return false;

}

void BST::insert(int value) {

    Node* new_Node;
    new_Node = new Node(value);

    if(!size) {
        root = new Node(value);
        size++;
        return;
    }

    Node* node = root;
    Node* parent = root;

    //доходим до пункта назначения
    while(node) {
        parent = node;
        if(value < node->getData())
            node = node->getLeft();
        else
            node = node->getRight();
    }

    //вставляем
    //проверка на право/лево
    if(isLeft(new_Node, parent)) { //лево
        parent->setLeft(new_Node);
        new_Node->setParent(parent);
        size++;
    }
    else { // право
        parent->setRight(new_Node);
        new_Node->setParent(parent);
        size++;
    }

    return;
}

int BST::min() {
    Node* node = root;
    while(node->getLeft()) {
        node = node->getLeft();
    }
    return node->getData();
}

int BST::max() {
    Node* node = root;
    while(node->getRight()) {
        node = node->getRight();
    }
    return node->getData();
}


void BST::inorderWalk(Node* node) {

    if(node) {
        inorderWalk(node->getLeft());
        cout << node->getData() << " ";
        inorderWalk(node->getRight());
    }

}

void BST::preorderWalk(Node *node) {

    if(node) {
        cout << node->getData() << " ";
        preorderWalk(node->getLeft());
        preorderWalk(node->getRight());
    }
}

Node* BST::successor() {
    if(!root->getRight())
        return nullptr;

    Node* node = root->getRight();
    while(node->getLeft()) {
        node = node->getLeft();
    }
    return node;

}

Node* BST::predecessor() {
    if(!root->getLeft())
        return nullptr;

    Node* node = root->getLeft();
    while(node->getRight()) {
        node = node->getRight();
    }
    return node;

}


Node* delSuccessor(Node* root) {
    if(!root->getRight())
        return nullptr;

    Node* node = root->getRight();
    while(node->getLeft()) {
        node = node->getLeft();
    }
    return node;

}

void BST::Delete(int value) {

    Node* node = root;
    Node* parent = nullptr;
    while(node) {
        if(node->getData() == value)
            break;

        if(node->getData() > value)
            node = node->getLeft();
        else
            node = node->getRight();
    }

    if(!node) // если эелемента нет, то игнорим
        return;

    if(!node->getRight() && !node->getLeft()) { // проверка на лист

        if(isLeft(node, node->getParent())) { // проверка на право/лево
            node->getParent()->setLeft(nullptr);
            delete node;
            size--;
        }
        else {
            node->getParent()->setRight(nullptr);
            delete node;
            size--;
        }
        return;
    }

    if(node->getLeft() && !node->getRight()) { // елси только левый сын

        if(isLeft(node, node->getParent())) { // проверка на право/лево
            node->getLeft()->setParent(node->getParent()); // подвязываем деда к сыну
            node->getParent()->setLeft(node->getLeft()); // подвязываем сына к деду
            delete node;
            size--;
        }
        else {
            node->getLeft()->setParent(node->getParent()); // подвязываем деда к сыну
            node->getParent()->setRight(node->getLeft()); // подвязываем сына к деду
            delete node;
            size--;
        }
        return;
    }

    if(!node->getLeft() && node->getRight()) { //если только правый сын

        if(isLeft(node, node->getParent())) { // проверка на право/лево
            node->getRight()->setParent(node->getParent()); // подвязываем деда к сыну
            node->getParent()->setLeft(node->getRight()); // подвязываем сына к деду
            delete node;
            size--;
        }
        else {
            node->getRight()->setParent(node->getParent()); // подвязываем деда к сыну
            node->getParent()->setRight(node->getRight()); // подвязываем сына к деду
            delete node;
            size--;
        }
        return;
    }

    // тут у нас существует 2 сына (надо поставить successor)

    int successorData = delSuccessor(node)->getData();
    Node* successor = delSuccessor(node);
    // удаляем сам succerssor из дерева

    if(isLeft(successor, successor->getParent())) { // проверка на право/лево
        successor->getParent()->setLeft(nullptr);
        delete successor;
        size--;
    }
    else {
        successor->getParent()->setRight(nullptr);
        delete successor;
        size--;
    }

    //присваиваем ноде значение sucсessor'a.
    node->setData(successorData);
    return;

}
