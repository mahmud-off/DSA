# Me's patterns
```
#include <math.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <_timeval.h>  
  
#define SIZE 10  
int arr[SIZE] = {5,3,1000,4,-100,1,2,-4,7,9};  
  
void print_array(int* ar, const int size) {  
  
    for(int i = 0; i < size; ++i) {  
        printf("%d ", ar[i]);  
    }  
    printf("\n");  
}  
  
void swap(int *a, int*b) {  
    int c = *a;  
    *a = *b;  
    *b = c;  
}  
  
//bubble sort  
void bubble_sort(int* ar, const int size) {  
    int point = 0;  
    while (1) {  
        int swap_count = 0;  
        for(int i = 0; i < size-1; ++i) {  
            if(ar[i+1] < ar[i]) {  
                swap(&ar[i+1], &ar[i]);  
                ++swap_count;  
            }  
        }  
        if(swap_count == 0)  
            break;  
  
    }  
  
    print_array(ar,SIZE);  
}  
  
// selection sort  
void selection_sort(int* ar, const int size) {  
    for(int i = 0; i < size-1; ++i) {  
        //searching min  
        int point = ar[i];  
        int point_id = i;  
        for(int j = i+1; j < size; ++j) {  
            if(ar[j] < point) {  
                point = ar[j];  
                point_id = j;  
            }  
        }  
        swap(&ar[i], &ar[point_id]);  
    }  
  
    print_array(ar,size);  
}  
  
//insertion sort  
void insert(int* ar,const int old_position, const int new_position) {  
    int point = ar[old_position];  
    // перекид элемента в лево ТОЛЬКО В ЛЕВО!!!  
    for(int i = old_position; i >= new_position; --i) {  
        ar[i] = ar[i-1];  
    }  
  
    ar[new_position] = point;  
  
}  
  
void insertion_sort(int ar[], const int size) {  
    for(int i = 1; i < size; ++i) {  
  
        int j = i;  
  
        while (j > 0 && ar[j-1] > ar[i]) {  
            --j;  
        }  
  
        insert(ar, i, j);  
  
  
    }  
  
    print_array(ar, size);  
}  
  
//counting sort  
void counting_sort(int* ar, const int size) {  
    // finding max/min element O(n)  
    int max_el = ar[0], min_el = ar[0];  
    for(int i = 1; i < size; ++i) {  
        max_el = max_el < ar[i] ? ar[i] : max_el;  
        min_el = min_el > ar[i] ? ar[i] : min_el;  
    }  
  
    // create counting array  
    int range = max_el-min_el+3;  
    int * counter = (int *)calloc(range, sizeof(int));  
  
    //counting  
    for(int i = 0; i < size; ++i) {  
        ++counter[ar[i]-min_el];  
    }  
  
    // finally array  
    int count = 0;  
    for(int i = 0; i < range; ++i) {  
        for(int j = 0; j < counter[i]; ++j) {  
            ar[count] = i+min_el;  
            ++count;  
        }  
    }  
  
    print_array(ar,size);  
    free(counter);  
}  
  
//merge  
void merge(int* arr, int low, int midl, int high, int *buffer) {  
  
    int i = low;  
    int j = midl;  
    while(i < midl && j < high) {  
        if(arr[i] < arr[j]) {  
            buffer[i+j-midl] = arr[i];  
            i++;  
        }  
        else {  
            buffer[i+j-midl] = arr[j];  
            ++j;  
        }  
    }  
  
  
    while(i < midl) {  
        buffer[i+j-midl] = arr[i];  
        i++;  
    }  
    while(j < high) {  
        buffer[i+j-midl] = arr[j];  
        ++j;  
    }  
  
    for(int p = low; p<high; ++p) {  
        arr[p] = buffer[p];  
    }  
}  
  
  
  
// merge sort  
void mergeSort(int* arr,int l, int r,int * buffer) {  
    if(r-l <= 1)  
        return;  
  
    int m = (l+r)/2;  
  
    //зарываемся  
    mergeSort(arr, l, m, buffer);  
    mergeSort(arr, m, r, buffer);  
  
    int i = l;  
    int j = m;  
    while(i < m && j < r) {  
        if(arr[i] < arr[j]) {  
            buffer[i+j-m] = arr[i];  
            i++;  
        }  
        else {  
            buffer[i+j-m] = arr[j];  
            ++j;  
        }  
    }  
  
  
    while(i < m) {  
        buffer[i+j-m] = arr[i];  
        i++;  
    }  
    while(j < r) {  
        buffer[i+j-m] = arr[j];  
        ++j;  
    }  
  
    for(int p = l; p<r; ++p) {  
        arr[p] = buffer[p];  
        //printf("%d\n", buffer[i]);  
    }  
}  
  
  
void swap_el(int * a, int *b) {  
    int point = *a;  
    *a = *b;  
    *b = point;  
}  
  
  
  
  
  
int Lomuto_partition(int * arr, int l, int r) {  
    int i = l;  
    int j = r;  
  
    int pivot = arr[l];  
  
    while(i<j) {  
        do {  
            ++i;  
        }while(arr[i] < pivot);  
        do {  
            --j;  
        }while(arr[j] > pivot);  
        if(i<j)  
            swap_el(&arr[i], &arr[j]);  
    }  
  
  
  
    swap_el(&arr[l], &arr[j]);  
  
    for(int ip = 0; ip < SIZE; ++ip) {  
        printf("%d ", arr[ip]);  
    }  
    printf("\n");  
  
  
    return j;  
}  
  
  
int Hoare_partition(int *arr,int  l, int r) {  
    int i = l;  
    int j = r-1;  
    int id = (i+j)/2;  
    int pivot = arr[id];  
    while(i < j) {  
        while(arr[i] < pivot)++i;  
        while(arr[j] > pivot)--j;  
        if(i < j)  
            swap_el(&arr[i++], &arr[j--]);  
    }  
  
    return j;  
  
}  
  
void QuickSort(int *arr, int l, int r) {  
    if(l>=r)  
        return;  
  
    int pivot = Lomuto_partition(arr, l, r);  
    //int pivot = Hoare_partition(arr, l, r);  
    printf("*%d %d\n", arr[pivot], pivot);  
  
    QuickSort(arr, l, pivot);  
    QuickSort(arr, pivot+1, r);  
  
  
  
  
  
}  
  
// SEARCHING  
  
int arr_2[SIZE] = {1,2,3,4,5,6,7,10,11,14};  
  
//linear search  
int linear_searching(int *arr, int el, int size) {  
    for(int i = 0; i < size; ++i) {  
        if(arr[i] == el)  
            return i;  
    }  
    return -1;  
}  
  
//binary search  
int binary_search(int *arr, int n, int elem) {  
    int l = 0, r = n-1;  
    int m = 0;  
  
    while(l <= r) {  
        m = (l+r)/2;  
        if(arr[m] == elem)  
            return m;  
        if(arr[m] > elem)  
            r = m-1;  
        else  
            l = m+1;  
    }  
  
    return -1;  
  
}  
  
//поиск по ответу, скопированно у Михаила Железина  
int f3(int *a, int m, int k, int n) {  
    int counter = 0;  
    for (int i = 0; i < n; ++i) {  
        counter += a[i] < m;  
    }  
    return counter >= k;  
}  
  
int binary_for_ans_search(int *a, int k, int n, int P) {  
    int l = 0, r = P + 1;  
    while (r - l > 1) {  
        int m = (l + r) / 2;  
        if (f3(a, m, k, n)) {  
            r = m;  
        } else {  
            l = m;  
        }  
    }  
    return r;  
}  
  
//ternarny search скопированно у Михаила Железина  
float func(float x) {  
    return (x - 3) * (x - 3);  
}  
  
float ternary_searh() {  
    float l = 0.0, r = 5.0;  
    while (abs(r - l ) > 1e-3) {  
        float m1 = l +  (r - l) / 3;  
        float m2 = l + 2 * (r - l) / 3;  
        if (func(m1) < func(m2)) {  
            r = m2;  
        } else {  
            l = m1;  
        }  
    }  
    return r;  
}  
  
//lower_bound или первое вхождение числа (через бинарный поиск)  
int lower_bound(int* arr, int elem, int size) {  
    int l = -1, r = size;  
    int m = 0;  
    while(r-l > 1) {  
        m = (r + l) / 2;  
        if(arr[m] < elem)  
            l = m;  
        else  
            r = m;  
    }  
    return r;  
}  
  
//upper_bound  
int upper_bound(int* arr, int elem, int size) {  
    int l = -1, r = size;  
    int m = 0;  
    while(r-l > 1) {  
        m = (r + l) / 2;  
        if(arr[m] <= elem)  
            l = m;  
        else  
            r = m;  
    }  
    return l;  
}  
  
//Экспоненциальный поиск  НЕ ГОТОВ (не видит 2 последних элемента)  
int exponentia_search(int * arr, int last_i, int new_i, int elem, int size) {  
    int k = 2; // кэф  
  
    if(arr[size-1] < elem || arr[0] > elem)  
        return -1;  
  
    while(new_i < size) {  
        //выход  
        if(arr[new_i] == elem)  
            return new_i;  
  
        if(arr[new_i] < elem) {  
            last_i = new_i;  
        }  
        else {  
            return exponentia_search(arr, last_i, new_i, elem, size);  
        }  
        if(new_i * k + 1 <= size - 1)  
            if(new_i > 1)  
                new_i = new_i * k;  
            else  
                ++new_i;  
        else  
            return exponentia_search(arr, new_i, size-1, elem, size);  
    }  
    return -1;  
}  
  
int b[SIZE] = {1,4,2,6,9,3,5,2,6,7};  
  
int main() {  
  
    //print_array(arr, SIZE);  
  
    //bubble_sort(arr,SIZE);  
    //selection_sort(arr,SIZE);  
    //insertion_sort(arr, SIZE);  
    //counting_sort(arr, SIZE);  
    //printf("%d", linear_searching(arr_2, 9, SIZE)); // 8  
    //printf("%d", binary_search(arr_2, SIZE, 15));// -1  
    //printf("%d", lower_bound(arr_2, 45, SIZE));// 10  
    //printf("%d", upper_bound(arr_2, 5, SIZE));// 6  
    //printf("%d", exponentia_search(arr_2, 0, 0, 5, SIZE));// 9  
/*  
    int * buff = (int*)calloc(SIZE, sizeof(int));    mergeSort(arr, 0, SIZE, buff);    print_array(arr, SIZE);  
    free(buff);    */    print_array(arr, SIZE);  
    printf("\n");  
  
    QuickSort(arr, 0, SIZE);  
  
    print_array(arr, SIZE);  
  
    return 0;  
}
```