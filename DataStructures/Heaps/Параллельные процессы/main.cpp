#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


// вечный позор мне, не написал QuickSort


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





// get (min, max)
// insert
// remove (min, max, value);

#define MAX_SIZE 100000
//MIN HEAPFY
typedef struct Heap {
    long long int store[MAX_SIZE];
    long long int size;
}HEAP;

HEAP* createHeap() {
    HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
    heap->size = 0;
    return heap;
}

long long int getMin(HEAP* heap) {
    if(heap->size) {
        return heap->store[0];
    }
    return 0;
}

void swap(long long int* a, long long int * b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void siftUp(HEAP* heap, long long int id) { // если родитель будет больше, чем дочерний эл-т, то свап
    if(heap->size && id) {
        if(heap->store[((id-1)/2)] > heap->store[id]) {
            swap(&heap->store[id], &heap->store[((id-1)/2)]);
            siftUp(heap, ((id-1)/2));
        }
    }
    return;
}

void insert(HEAP* heap, long long int value) {
    if(heap->size >= MAX_SIZE) {
        return;
    }
    heap->store[heap->size] = value;
    siftUp(heap, heap->size);
    heap->size++;
}

void siftDown(HEAP* heap, long long int id) {
    long long int left = 2*id+1;
    long long int right = 2*id+2;
    if(heap->size <= left) { // проверка на существование листьев
        return;
    }
    if(heap->size <= right) {    //проверка на существование правого листа ( левый уже 100% существует )
        if(heap->store[id] > heap->store[left]) {
            swap(&heap->store[id], &heap->store[left]);
            siftDown(heap, left);
        }
        return;
    }
    // тут оба листа существуют (надо выбрать минимальный поставить его выше всех)
    if(heap->store[left] < heap->store[right]) {
        if(heap->store[id] > heap->store[left]) {
            swap(&heap->store[id], &heap->store[left]);
            siftDown(heap, left);
            return;
        }
    }
    else {
        if(heap->store[id] > heap->store[right]) {
            swap(&heap->store[id], &heap->store[right]);
            siftDown(heap, right);
            return;
        }
    }

    return;
}

void removeMIN(HEAP* heap) {
    if(heap->size<=0) {
        return;
    }
    swap(&heap->store[0], &heap->store[heap->size-1]);
    heap->size -= 1;
    siftDown(heap, 0);
}

int main() {

    int n = 0;
    int v = 0, j = 0, k = 0;
    cin >> n;

    vector<Node> arr(n);
    long long int *res = new long long int[n];
    for(int i = 0; i < n; ++i) {
        cin >> v >> j >> k;
        arr[i].data = v;
        res[i] = v;
        arr[i].left_ind = j;
        arr[i].right_ind = k;
    }

    struct Heap* heap = createHeap();

    for (int i = 0; i < n; ++i) {
        insert(heap, res[i]);
    }

    for (int i = 0; i < n; ++i) {
        res[i] = getMin(heap);
        removeMIN(heap);
    }


    string str_2;
    for(int i = 0; i < n; i++) {
        //  cout << res[i];
        str_2 += to_string(res[i]);
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
