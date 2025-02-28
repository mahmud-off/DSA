#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define STACK_SIZE 4000000
#define MAX_NUMBER 1000000
#define MIN_NUMBER -100



struct elem {
    int data;
    int curr_max;
    int curr_min;
};

typedef struct Stack {
    elem* stack[STACK_SIZE];
    int top;
}STACK;

STACK* createStack() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    for(int i = 0; i < STACK_SIZE; i++) {
        stack->stack[i] = (elem*)malloc(sizeof(elem));
        stack->stack[i]->curr_max = 0;
        stack->stack[i]->curr_min = 0;
        stack->stack[i]->data = 0;
    }
    stack->top = 0;
    return stack;
}

void pushBack(STACK* stack, int data) {
    if(stack->top == 0) {
        stack->stack[stack->top]->curr_max = data;
        stack->stack[stack->top]->curr_min = data;
        stack->stack[stack->top]->data = data;
        stack->top++;
    }
    else if(stack->top != STACK_SIZE) {
        stack->stack[stack->top]->curr_max = (data > stack->stack[stack->top-1]->curr_max) ? data : stack->stack[stack->top-1]->curr_max;
        stack->stack[stack->top]->curr_min = (data < stack->stack[stack->top-1]->curr_min) ? data : stack->stack[stack->top-1]->curr_min;
        stack->stack[stack->top]->data = data;
        stack->top++;
    }

    return;
}

void top(STACK* stack) {
    if(stack->top) {
        std::cout << stack->top << " --> " << stack->stack[stack->top-1]->data << std::endl;
    }
    else {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    return;
}

void pop(STACK* stack) {
    if (stack->top) {
        stack->top--;
    }
}

void printStack(STACK * stack) {
    if(stack->top) {
        for(int i = stack->top-1; i >= 0; i--) {
            std::cout << stack->stack[i]->data << std::endl;
        }
    }
    else {
        std::cout << "Stack is empty" << std::endl;
    }
}

int findMax(STACK* stack) {
    if(stack->top) {
        return stack->stack[stack->top-1]->curr_max;
    }

}

int findMin(STACK* stack) {
    if(stack->top) {
        return stack->stack[stack->top-1]->curr_min;
    }
    else {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
}

int main() {

    STACK* Stack = createStack();

    int N = 0;
    scanf("%d", &N);

    string com = "";
    int value = 0;
    for (int i = 0; i < N; ++i) {
        cin >> com;
        switch ((int)com[1]) {
            case (int)'u': {
                cin >> value;
                //cout << value << "\n";
                pushBack(Stack, value);
                break;
            }
            case(int)'a': {

                cout << findMax(Stack) << "\n";
                break;
            }
            case(int)'o': {
                pop(Stack);
                break;
            }
        }

    }


    return 0;

/*
    STACK stack;

    stack.pushBack(&stack, 10);

  */

}