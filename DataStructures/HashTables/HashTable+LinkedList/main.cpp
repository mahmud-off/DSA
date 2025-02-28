#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAP_SIZE 2


// КТО ПРОСИТАЛ, ТОТ СЧИТАЕТ, ЧТО "ГРОКАЕМ АЛГОРИТМЫ" ЛУЧШЕ КОРМЕНА!!!)))



class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node() {
        data = "";
        next = nullptr;
        prev = nullptr;
    }

    Node(string value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class MAP {
public:
    vector<pair<string, Node*>> table[MAP_SIZE];

    long long int hash_func(const string& value, long long int m = MAP_SIZE) {
        const long long int p = 1000000007;
        const int X = 31;
        long long int hach = 0;
        long long int iter = 1;

        for (int i = 0; i < value.length(); i++) {
            hach = ((hach%p) + (value[i] * iter) % p) % p;
            iter = ((iter%p) * (X%p)) % p;
        }
        return hach % m;
    }

    void add(const string& key, Node* node) {
        long long int h = hash_func(key);
        for (auto& pair : table[h]) {
            if (pair.first == key) {
                pair.second = node;
                return;
            }
        }
        table[h].emplace_back(key, node);
    }

    Node* get(const string& key) {
        long long int h = hash_func(key);
        for (const auto& pair : table[h]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return nullptr;
    }

    void remove(const string& key) {
        long long int h = hash_func(key);
        for (auto it = table[h].begin(); it != table[h].end(); ++it) {
            if (it->first == key) {
                table[h].erase(it);
                return;
            }
        }
    }
};

class LL {
public:
    MAP map;
    Node* head;
    int len;


    LL() {
        head = new Node();
        len = 0;
    }

    void push_back(const string& value) {
        Node* node = new Node(value);
        map.add(value, node);

        if (head->next == nullptr) {
            head->next = node;
            head->prev = node;
            node->next = nullptr;
            node->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            head->prev = node;
        }
        len++;
    }

    void delete_node(const string& value) {
        Node* node = map.get(value);
        if (node == nullptr) {
            cout << "-1\n";
            return;
        }

        Node* prev = node->prev;
        Node* next = node->next;

        if (prev != head) {
            prev->next = next;
        }

        if (next != nullptr) {
            next->prev = prev;
        }

        if (node == head->prev) {
            head->prev = prev;
        }

        map.remove(value);
        delete node;
        len--;
    }

    void printNext(const string& value) {
        Node* node = map.get(value);
        if (node == nullptr || node->next == nullptr) {
            cout << "-1\n";
        } else {
            cout << node->next->data << "\n";
        }
    }
};

int main() {
    LL list;
    long long int n, q;
    cin >> n >> q;

    string str;

    for (long long int i = 0; i < n; ++i) {
        cin >> str;
        list.push_back(str);
    }

    string com = "";
    for (int i = 0; i < q; ++i) {
        cin >> com;
        if (com == "1") {
            cin >> str;
            list.delete_node(str);
        } else if (com == "2") {
            cin >> str;
            list.printNext(str);
        }
    }


    /*
        list.push_back("Vadim");
        list.push_back("+");
        list.push_back("Veronika");

        list.delete_node("+");
        list.pintNext("ab");
        list.print_list();

        list.print_list();

    */
    return 0;
}