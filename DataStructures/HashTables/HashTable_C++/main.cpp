#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define MAP_SIZE 100000

class Node {
public:

    string data;
    Node* n;
    Node* p;

    Node() {
        data = "0";
        n = nullptr;
        p = nullptr;
    }

    Node(string value) {
        setData(value);
        n = nullptr;
        p = nullptr;
    }

    void setData(const string& str) {
        data = str;
    }

    string getData() const {
        return data;
    }

};

class MAP {
public:
    Node tabl[MAP_SIZE];

    int hach_func(string value, int m) { //да-да, хач функ
        long long int hach = 0;
        long long int p = 1000000007;
        int x = 263;
        for(int i = 0; i < value.length(); ++i ) {
            hach+=value[i] * pow(x, i);
        }
        hach %= p;

        return hach % m;
    }

    void add_value(string value, int m) {
        if(find(value, m))
            return;

        int hach = hach_func(value, m);
        Node* node = new Node(value);
        if(tabl[hach].data == "0") {
            tabl[hach].setData("1"); // флаг записи числа.
            tabl[hach].n = node;
            tabl[hach].p = node;
            node->n = &tabl[hach];
            node->p = &tabl[hach];
            return;
        }
        tabl[hach].setData("1"); // флаг записи числа.
        node->n = &tabl[hach]; // закольцевал с head'ом
        node->p = tabl[hach].p; // соединил с прежыдущим
        tabl[hach].p = node; // обновил предыдущий / закольцевал
        node->p->n = node; // связал предыдущую и новую
        return;
    }

    void delete_value(string value, int m) {
        int hach = hach_func(value, m);

        if(!find(value, m))
            return;

        if(tabl[hach].data == "1") {
            Node* node = tabl[hach].p;
            node->p->n = &tabl[hach];//связал предыдущий и голову
            tabl[hach].p = node->p;//связал голову и преыдущий
            delete node;
            if(tabl[hach].n == &tabl[hach]) {
                tabl[hach].data = "0";
            }
        }
        return;
    }


    void printString(int i) {
        if(tabl[i].data == "0")
            return;

        if(tabl[i].data != "0") {
            Node* node = tabl[i].n;
            while (node != &tabl[i]) {
                cout << node->data << " ";
                node = node->n;
            }
            cout << "\n";
        }
    }

    bool find(string value,int  m) {
        int hach = hach_func(value, m);
        if(tabl[hach].data == "0")
            return false;

        Node* node = tabl[hach].n;
        while (node != &tabl[hach]) {
            if(node->data == value) {
                return true;
            }
            node = node->n;
        }
        }


    void findString(string value, int m) {
        int hach = hach_func(value, m);
        if(tabl[hach].data != "0") {
            Node* node = tabl[hach].n;
            while (node != &tabl[hach]) {
                if(node->data == value) {
                    cout << "yes\n";
                    return;
                }
                node = node->n;
            }
            cout << "no\n";
        }
    }


};


int main() {


    MAP map;

    int m = 0;
    int n = 0;
    cin >> m >> n;

    string com = "";
    char p;
    for(int i = 0; i < n; ++i) {
        cin>> com;
        p = com[0];
        switch (p) {
            case'a': {
                string str;
                cin >> str;
                map.add_value(str, m);
                break;
            }
            case'd': {
                string str;
                cin >> str;
                map.delete_value(str, m);
                break;
            }
            case'f': {
                string str;
                cin >> str;
                map.findString(str, m);
                break;
            }
            case'c':{
                long int id = 0;
                cin >> id;
                map.printString(id);
                break;
            }
        }
    }

    /*
    map.add_value("Vadim", m);

    //map.delete_value("Vadim");

    map.add_value("Vadim", m);
    map.printString(17);
    map.findString("Vadim", m);

    */
    return 0;
}