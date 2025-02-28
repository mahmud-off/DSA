//
// Created by Admin on 16.02.2025.
//

#ifndef NODE_H
#define NODE_H
class Node {
public:
    Node(int value) {data = value;}

    //геттеры
    Node* getLeft()const{return left;}
    Node* getRight()const{return right;}
    Node* getParent()const{return parent;}
    int getData()const {return data;}

    //сеттеры
    void setLeft(Node* l){left = l;}
    void setRight(Node* r){right = r;}
    void setParent(Node* p){parent = p;}
    void setData(int d){data = d;}
private:
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

#endif //NODE_H
