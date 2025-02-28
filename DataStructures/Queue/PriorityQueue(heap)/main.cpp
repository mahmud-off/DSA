#include <iostream>

//Created // очередь на связном списке - push_back == enqueue and pop_front == dequeue; всё - O(1) // O(1)
// очредь на массиве - добавляем как в обычный массив O(1), забираем с первой позиции со сдвигом всего что было O(n) до (либо добавляем со сдвигом за O(n), но забираем за O(1)); // O(n)
//Created may be no working// на двух стеках - создаём 1 стек, складываем всё в него где каждая за O(1), потом перекладываем за O(n) в другой стек и на выход получаем элементы в порядкед добавления (очереди) за О(1) // O(n)

#define Queue_LL

#ifdef Queue_LL
struct Node {
    struct Node* n;
    struct Node* p;
    int value;
};

typedef struct List {
    struct Node* head;
    int len;
}QUEUE;

struct Node* create_node(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->n = node;
    node->p = node;
    return node;
}

struct List* create_Queue() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = create_node(0);
    list->len = 0;
    return list;
}

void Enqueue(struct List* list, int data) { //  нужно всего лишь найти куда вставлять, можно сделать linear search, O(n)
    struct Node* node = create_node(data);
    node->n = list->head; // закольцевал
    node->p = list->head->p; //совединил с предыдущим
    list->head->p = node;// обновил предыдущий
    node->p->n = node; // связал предыдущую и новую
    list->len++;
    return;
}

void Dequeue(struct List* list) {
    if(list->len) {
        struct Node* node = list->head->n;
        list->head->n = node->n;//голова --> воторой
        node->n->p = list->head;//второй --> голова
        free(node);
        list->len--;
    }
    return;
}

void print_queue(struct List* list) {
    struct Node* node = list->head->n;
    while(node != list->head) {
        std::cout << node->value << " ";
        node = node->n;
    }
    std::cout<<"\n";
    return;
}

class Receiver {
public:
    int id = 0;
    int start = 0;
    int time = 0;
    Receiver(int i, int s, int t) {
        id = i;
        start = s;
        time = t;
    }
    void UpDate(int t) {
        start += time;
        time = t;
    }
};

int main() {

    QUEUE *queue = create_Queue();



    Enqueue(queue, 10);
    Enqueue(queue, 12);
    Dequeue(queue);
    return 0;
}
#endif Queue_LL

#ifdef Queue_STACK

#define STACK_SIZE 3

struct elem {
    int data;
};

typedef struct Stack_1 {
    elem* stack[STACK_SIZE];
    int top;
}STACK;

typedef struct queue {
    STACK* input_stack;
    STACK* output_stack;
}QUEUE;


STACK* createStack() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    for(int i = 0; i < STACK_SIZE; i++) {
        stack->stack[i] = (elem*)malloc(sizeof(elem));
        stack->stack[i]->data = 0;
    }
    stack->top = 0;
    return stack;
}

QUEUE * createQueue() {
    QUEUE * queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->input_stack = createStack();
    queue->output_stack = createStack();
    return queue;
}

void pour(STACK* in_stack, STACK* out_stack) {
    while (in_stack->top) {
        out_stack->stack[ STACK_SIZE-in_stack->top ]->data = in_stack->stack[ in_stack->top-1 ]->data;
        in_stack->top--;
        out_stack->top++;
    }
    return;
}

void Enqueue(QUEUE* queue, int data) {
    if(queue->input_stack->top != STACK_SIZE) {
        queue->input_stack->stack[queue->input_stack->top]->data = data;
        queue->input_stack->top++;
    }
    else {
        // первый стек заполнен ,переливаем
        pour(queue->input_stack, queue->output_stack);
        queue->input_stack->stack[queue->input_stack->top]->data = data;
        queue->input_stack->top++;
        return;
    }
    return;
}

void Dequeue(QUEUE* queue) {
    if (queue->output_stack->top) {
        queue->output_stack->top--;
    }
    else {
        std::cout << "Stack_2 is empty" << std::endl;
        return;
    }
    return;
}


int main() {

    QUEUE * queue = createQueue();

    Enqueue(queue, 10);
    Enqueue(queue, 11);
    Enqueue(queue, 12);
    Enqueue(queue, 13);
    Enqueue(queue, 14);
    Enqueue(queue, 15);
    Enqueue(queue, 16);
    Dequeue(queue);
    return 0;
}

#endif Queue_STACK