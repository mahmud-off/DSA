#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



class Node {
public:

    Node() {
        int data = 0;
        left_ind = 0;
        right_ind = 0;
    }

    Node(int i, int j, int k) {
        int data = i;
        left_ind = j;
        right_ind = k;
    }

    long long int data = 0;
    long long int left_ind = 0;
    long long int right_ind = 0;
};


string str = "";

void inOrderWalk(vector<Node>& arr, Node* node) {

    if(node->left_ind != -1) {
        if (node->data <= arr[node->left_ind].data) {
            str.push_back('*');
        }
        inOrderWalk(arr, &arr[node->left_ind]);

    }

    str += to_string(node->data);

    if(node->right_ind != -1) {
        if (node->data > arr[node->right_ind].data) {
            str.push_back('*');
        }
        inOrderWalk(arr, &arr[node->right_ind]);
    }
}

int main() {

    int n = 0;
    int v = 0, j = 0, k = 0;
    cin >> n;

    vector<Node> arr(n);
    vector<long long int> res(n);
    for(int i = 0; i < n; ++i) {
        cin >> v >> j >> k;
        arr[i].data = v;
        res[i] = v;
        arr[i].left_ind = j;
        arr[i].right_ind = k;
    }

    sort(begin(res), end(res));
    string str_2;
    for(auto i: res) {
        str_2 += to_string(i);
    }
    //cout << "\n";

    inOrderWalk(arr, &arr[0]);
    //cout << "\n";

    if(str == str_2) {
        cout<< "CORRECT";
        return 0;
    }
    //cout << str << " " << str_2;
    cout << "INCORRECT";
    return 0;
}
