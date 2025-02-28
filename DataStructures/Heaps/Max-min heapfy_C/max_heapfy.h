//
// Created by Admin on 04.02.2025.
//
/*
#ifndef MAX_HEAPFY_H
#define MAX_HEAPFY_H

#define MAX_SIZE 1000

typedef struct Heap {
    int store[MAX_SIZE];
    int size;
}HEAP;

HEAP* createHeap() {
    HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
    heap->size = 0;
    return heap;
}

int getMax(HEAP* heap) {
    if(heap->size) {
        return heap->store[0];
    }
    return -777;
}

void swap(int* a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void siftUp(HEAP* heap, int id) { // если родитель будет больше, чем дочерний эл-т, то свап
    if(heap->size && id) {
        if(heap->store[(int)((id-1)/2)] < heap->store[id]) {
            swap(&heap->store[id], &heap->store[(int)((id-1)/2)]);
            siftUp(heap, (int)((id-1)/2));
        }
    }
    return;
}

void insert(HEAP* heap, int value) {
    if(heap->size >= MAX_SIZE) {
        return;
    }
    heap->store[heap->size] = value;
    siftUp(heap, heap->size);
    heap->size++;
}

void siftDown(HEAP* heap, int id) {
    int left = 2*id+1;
    int right = 2*id+2;
    if(heap->size <= left) { // проверка на существование листьев
        return;
    }
    if(heap->size <= right) {    //проверка на существование правого листа ( левый уже 100% существует )
        if(heap->store[id] < heap->store[left]) {
            swap(&heap->store[id], &heap->store[left]);
            siftDown(heap, left);
        }
        return;
    }
    // тут оба листа существуют (надо выбрать минимальный поставить его выше всех)
    if(heap->store[left] > heap->store[right]) {
        if(heap->store[id] < heap->store[left]) {
            swap(&heap->store[id], &heap->store[left]);
            siftDown(heap, left);
            return;
        }
    }
    else {
        if(heap->store[id] < heap->store[right]) {
            swap(&heap->store[id], &heap->store[right]);
            siftDown(heap, right);
            return;
        }
    }

    return;
}

void removeMax(HEAP* heap) {
    if(heap->size<=0) {
        return;
    }
    swap(&heap->store[0], &heap->store[heap->size-1]);
    heap->size -= 1;
    siftDown(heap, 0);
}

#endif //MAX_HEAPFY_H
*/