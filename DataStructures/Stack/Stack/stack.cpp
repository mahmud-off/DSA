#include "stack.h"
#include <iostream>
STACK::STACK() {
    
}


void STACK::pushBack(STACK *stack, int data) {
    if(stack->top == 0) {
        stack->stack[stack->top]->curr_max = data;
        stack->stack[stack->top]->curr_min = data;
        stack->stack[stack->top]->data = data;
        stack->top++;
        return;
    }
    else if(stack->top != STACK_SIZE) {
        stack->stack[stack->top]->curr_max = (data > stack->stack[stack->top-1]->curr_max) ? data : stack->stack[stack->top-1]->curr_max;
        stack->stack[stack->top]->curr_min = (data < stack->stack[stack->top-1]->curr_min) ? data : stack->stack[stack->top-1]->curr_min;
        stack->stack[stack->top]->data = data;
        stack->top++;
        return;
    }
    else {
        std::cout << "Stack over flow" << std::endl;
        return;
    }
    return;
}

void STACK::getTop(STACK *stack) {
    if(stack->top) {
        std::cout << stack->top << " --> " << stack->stack[stack->top-1]->data << std::endl;
    }
    else {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    return;
}

void STACK::pop(STACK *stack) {
    if (stack->top) {
        stack->top--;
    }
    else {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    return;
}

void STACK::printStack(STACK *stack) {
    if(stack->top) {
        for(int i = stack->top-1; i >= 0; i--) {
            std::cout << stack->stack[i]->data << std::endl;
        }
    }
    else {
        std::cout << "Stack is empty" << std::endl;
    }
}

int STACK::findMax(STACK *stack) {
    if(stack->top) {
        return stack->stack[stack->top-1]->curr_max;
    }
    else {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
}

int STACK::findMin(STACK *stack) {
    if(stack->top) {
        return stack->stack[stack->top-1]->curr_min;
    }
    std::cout << "Stack is empty" << std::endl;
    return MIN_NUMBER-1;
}
