#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 100000


// мой гитхаб: https://github.com/mahmud-off
// ну просто, по приколу вкинул, ха хахх ах

class elem {
public:
    int first = 0;
    int second = 0;
};

class PR_QUEUE {
public:

    void setStorage(int *arr, int size) {
        this->size = size;
        for(int i = 0; i < size; ++i) {
            storage[i] = arr[i];
        }
    }

    void makeHeap() {
        for(int i = size; i >= 0; --i) {
            siftDown(i);
            //cout << "&";
        }
    }


    int max() {
        if(size)
            return storage[0];

        return -10; // ха - ха , посхалка да да посхалочка, если вы, не дай бог, читаете это сообщение, это полностью соя программа, как и стек! (Просто после прохождения темы я пишу алгоритмы)
    }

    void siftUp(int id) {
        if(size && id) {
            if(storage[(int)((id-1)/2)] < storage[id]) {
                swap(&storage[id], &storage[(int)((id-1)/2)]);
                siftUp(((id-1)/2));
            }
        }
        return;
    }

    void insert(int value) {
        if(size >= MAX_SIZE) {
            return;
        }
        storage[size] = value;
        siftUp(size);
        size++;
    }

    void siftDown(int id) { // обычный сифт довн, находим мин из 3-х и ставим наверх, потомпрсеиваем вниз дальше
        int min_ind = id;
        int left = 2*id+1;
        int right = 2*id+2;
        if(size <= left) { // проверка на существование листьев
            return;
        }

        if (left < size && storage[left] < storage[min_ind]) {
            min_ind = left;
        }

        if (right < size && storage[right] < storage[min_ind]) {
            min_ind = right;
        }

        if (id != min_ind) {
            swap(&storage[id], &storage[min_ind]);
            ++counter;

            elem* swapS = new elem;
            swapS->first = id;
            swapS->second = min_ind;

            arr.push_back(swapS);

            //cout << id << " " << min_ind << "\n";
            siftDown(min_ind);
        }
    }

    void removeMax() {
        if(size<=0) {
            return;
        }
        cout << storage[0] << "\n";
        swap(&storage[0], &storage[size-1]);
        size -= 1;
        siftDown(0);
    }

    int getSwapsCount()const{return counter;}


    void getStorege() {
        for(int i = 0; i < size; i++) {
            cout << storage[i] << " ";
        }
        cout << "\n";
    }

    void printSwaps() {
        for(int i = 0; i < arr.size(); ++i) {
            cout << arr[i]->first << " " << arr[i]->second << "\n";
        }
    }

private:
    int storage[MAX_SIZE]{0};
    int size = 0;
    int counter = 0;
    vector<elem*> arr;


    void swap(int* a, int * b) {
        int temp = *a;
        *a = *b;
        *b = temp;
        return;
    }

};


int main()
{
    PR_QUEUE queue;

    int n = 0;
    cin >> n;
    int* arr = new int[n];
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }

    queue.setStorage(arr, n);
    //queue.getStorege();
    queue.makeHeap();
    //cout<<"\n";
    cout << queue.getSwapsCount();
    cout<<"\n";
    queue.printSwaps();
    //queue.getStorege();
    //std::cout << "\nHeap Sort!!!" << std::endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
