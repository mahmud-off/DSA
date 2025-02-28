#include <iostream>
#include <vector>

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

    int data = 0;
    int left_ind = 0;
    int right_ind = 0;
};

void inOrderWalk(vector<Node>& arr, Node* node) {

    if(node->left_ind != -1)
        inOrderWalk(arr, &arr[node->left_ind]);

    cout << node->data << " ";

    if(node->right_ind != -1)
        inOrderWalk(arr, &arr[node->right_ind]);

}

void preOrderWalk(vector<Node>& arr, Node* node) {

    cout << node->data << " ";

    if(node->left_ind != -1)
        preOrderWalk(arr, &arr[node->left_ind]);



    if(node->right_ind != -1)
        preOrderWalk(arr, &arr[node->right_ind]);

}

void postOrderWalk(vector<Node>& arr, Node* node) {

    if(node->left_ind != -1)
        postOrderWalk(arr, &arr[node->left_ind]);


    if(node->right_ind != -1)
        postOrderWalk(arr, &arr[node->right_ind]);

    cout << node->data << " ";


}

int main() {

    int n = 0;
    int v = 0, j = 0, k = 0;
    cin >> n;

    vector<Node> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> v >> j >> k;
        arr[i].data = v;
        arr[i].left_ind = j;
        arr[i].right_ind = k;
    }

    inOrderWalk(arr, &arr[0]);
    cout << "\n";
    preOrderWalk(arr, &arr[0]);
    cout << "\n";
    postOrderWalk(arr, &arr[0]);

    return 0;
}
