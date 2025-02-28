
#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100
#define MAX_NUMBER 10000
#define MIN_NUMBER -100

class STACK {


public:
    STACK();

    static void pushBack(STACK* stack, int data);

    static void getTop(STACK* stack);

    static void pop(STACK* stack);

    static void printStack(STACK * stack);

    int findMax(STACK* stack);

    int findMin(STACK* stack);
private:

    class elem {
    public:
        int data;
        int curr_max;
        int curr_min;
    };

    int top;

    elem* stack[STACK_SIZE];

};

#endif //STACK_H
