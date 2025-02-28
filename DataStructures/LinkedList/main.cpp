#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* n;
    struct Node* p;
    int value;
};

struct List {
    struct Node* head;
    int len;
};

struct Node* create_node(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->n = node;
    node->p = node;
    return node;
}

struct List* create_list() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = create_node(0);
    list->len = 0;
    return list;
}

void push_back(struct List* list, int data) {
    struct Node* node = create_node(data);
    node->n = list->head; // закольцевал
    node->p = list->head->p; //совединил с предыдущим
    list->head->p = node;// обновил предыдущий
    node->p->n = node; // связал предыдущую и новую
    list->len++;
    return;
}

void push_front(struct List* list, int data) {
    struct Node* node = create_node(data);
    node->n = list->head->n;//соединил с первым эл-м
    node->p = list->head; // соединил с головой
    node->n->p= node; // соединил первый эл-т с новым
    node->p->n= node; // соединил хедер с новым
    list->len++;
    return;
}

void pop_back(struct List* list) {
    if(list->len) {
        struct Node* node = list->head->p;
        node->p->n = list->head;//связал предыдущий и голову
        list->head->p = node->p;//связал голову и преыдущий
        free(node);
        list->len--;
    }
    return;
}

void pop_front(struct List* list) {
    if(list->len) {
        struct Node* node = list->head->n;
        list->head->n = node->n;//голова --> воторой
        node->n->p = list->head;//второй --> голова
        free(node);
        list->len--;
    }
    return;
}

void print_list(struct List* list) {
    struct Node* node = list->head->n;
    while(node != list->head) {
        std::cout << node->value << " ";
        node = node->n;
    }
    std::cout<<"\n";
    return;
}

//удаление по ноде
void delete_node(struct List* list, struct Node* node) {
    node->p->n = node->n;// пред --> некст
    node->n->p = node->p;// некст --> пред
    free(node);
    list->len--;
    return;
}


int find_min(struct List* list) {
    if(list->len) {
        if(list->len==1) {
            return list->head->n->value;
        }
        else {
            int min_value = INT_MAX;
            struct Node* node = list->head->n;
            while(node != list->head) {
                if(node->value < min_value) {
                    min_value = node->value;
                }
                node = node->n;
            }

            return min_value;
        }
    }
    return -1;
}

int find_max(struct List* list) {
    if(list->len) {
        if(list->len==1) {
            return list->head->n->value;
        }
        else {
            int min_value = INT_MIN;
            struct Node* node = list->head->n;
            while(node != list->head) {
                if(node->value > min_value) {
                    min_value = node->value;
                }
                node = node->n;
            }

            return min_value;
        }
    }
    return -1;
}

void swap(int * a, int * b) {
    int  temp = *a;
    *a = *b;
    *b = temp;
    return;
}


int main() {

    struct List * list = create_list();

    push_back(list, 10);
    push_back(list, 4);
    push_back(list, 3);
    push_back(list, 54);
    push_back(list, 2);
    push_back(list, 11);
    push_back(list, 9);

    print_list(list);

    std::cout << find_max(list) << "\n";

    //sort_list(list);

    print_list(list);

    return 0;
}
