#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define STACK_SIZE 100000
#define MAX_NUMBER 1000000000
#define MIN_NUMBER -10



struct elem {
    char data;
};

typedef struct Stack {
    elem* stack[STACK_SIZE];
    int top;
}STACK;

STACK* createStack() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    for(int i = 0; i < STACK_SIZE; i++) {
        stack->stack[i] = (elem*)malloc(sizeof(elem));
        stack->stack[i]->data = '\0';
    }
    stack->top = 0;
    return stack;
}

void pushBack(STACK* stack, char data) {
    stack->stack[++stack->top]->data = data;
    //cout << data << " - ";
    //cout << stack->top << " - " << (char)stack->stack[stack->top]->data << "\n";
    return;
}

char last(STACK* stack) {
    return stack->stack[stack->top]->data;
}

char top(STACK* stack) {
    if(stack->top) {
        //std::cout << stack->top << " --> " << stack->stack[stack->top-1]->data << std::endl;
        return stack->stack[stack->top]->data;
    }
}

char pop(STACK* stack) {
    if (stack->top) {
        char point = stack->stack[stack->top]->data;
       // cout << point << " - " << stack->top;
        stack->top--;
        return point;
    }
    return '\0';
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

bool isFunc(char a) {
    switch (a) {
        case'+': {
            return true;
        }
        case'-': {
            return true;
        }
        case'*': {
            return true;
        }
        case'/': {
            return true;
        }
        case'(': {
            return true;
        }
        case')': {
            return true;
        }
        default: {
            return false;
        }
    }
}

int priority(char sym) {
    switch (sym) {
        case'*': {
            return 2;
        }
        case'/': {
            return 2;
        }
        case'+': {
            return 1;
        }
        case'-': {
            return 1;
        }
        case'(': {
            return 0;
        }
        case')': {
            return 0;
        }
    }
}

class Data {
public:
    long double num = 0;
    char sym = '\0';
};

// для расчета резов

struct Elem {
    long double data;
};

typedef struct Stacks {
    Elem* stack[STACK_SIZE];
    int top;
}STACKs;

STACKs* createStacks() {
    STACKs* stack = (STACKs*)malloc(sizeof(STACKs));
    for(int i = 0; i < STACK_SIZE; i++) {
        stack->stack[i] = (Elem*)malloc(sizeof(Elem));
        stack->stack[i]->data = '\0';
    }
    stack->top = 0;
    return stack;
}

void pushBacks(STACKs* stack, long double data) {
    stack->stack[++stack->top]->data = data;
    //cout << data << " - ";
    //cout << stack->top << " - " << (char)stack->stack[stack->top]->data << "\n";
    return;
}

long double pops(STACKs* stack) {
    if (stack->top) {
        long double point = stack->stack[stack->top]->data;
        // cout << point << " - " << stack->top;
        stack->top--;
        return point;
    }

}


long double action(char operation, long double one, long double two) {
    switch (operation) {
        case'+':{
            return one + two;
        }
        case'-':{
            return one - two;
        }
        case'/': {
            return one / two;
        }
        case'*': {
            return one * two;
        }
    }
}

void printStacks(STACKs * stack) {
    if(stack->top) {
        for(int i = stack->top; i >= 1; i--) {
            std::cout << stack->stack[i]->data << std::endl;
        }
    }
    else {
        std::cout << "Stack is empty" << std::endl;
    }
}

int main() {
    STACK* Stack = createStack();

    string s = "";
    cin >> s;
    string output = s;
    string buff = "";

    vector<Data> storage;

    char curr = '\0';

    for(int i = 0; i < s.length(); ++i) {
        curr = s[i];
        //cout << s[i] << "\n";

        if(!isFunc(curr))
            buff.push_back(s[i]);
        else {
            // записали в конечный массив
            if(!buff.empty()) {
                Data num;
                num.num = stold(buff);
                storage.push_back(num);
                buff.clear();
            }
            // обработка операций

            //скобочка
            if(curr == '(') {
                pushBack(Stack, curr);
            }
            else if( curr == ')') {
                while (top(Stack) != '(') {
                    Data sym;
                    sym.sym = pop(Stack);
                    storage.push_back(sym);
                }
                pop(Stack); // удаляем скобку
            }
            else {
                while (Stack->top && priority(top(Stack)) >= priority(curr) && top(Stack) != '(') {
                    Data sym;
                    sym.sym = pop(Stack);
                    storage.push_back(sym);
                }
                pushBack(Stack, curr);
            }
        }
    }

    if(!buff.empty()) {
        Data num;
        num.num = stold(buff);
        storage.push_back(num);
    }

    while(Stack->top) {
        Data sym;
        sym.sym = pop(Stack);
        storage.push_back(sym);
    }

    //cout << storage.size() << "\n";

    vector<Data> RPN = storage;


// считаем рез
    //cout << "\n";

    STACKs* result = createStacks();
    Data val;
    for(int i = 0; i < storage.size(); ++i) {
        val = storage[i];
        if(val.sym == '\0') {
            pushBacks(result, val.num);
        }
        else {
            long double two = pops(result); // Правый операнд
            long double one = pops(result); // Левый операнд
            pushBacks(result, action(val.sym, one, two));
        }
    }

    long double finalResult = pops(result);

    cout << "Expression:" << "\n";
    cout << output << "\n";
    cout << "Reverse Polish Notation:" << "\n";

    for(int k = 0; k < RPN.size(); ++k) {
        if(RPN[k].sym == '\0')
            cout << fixed << setprecision(0) << RPN[k].num << " ";
        else {
            cout << fixed << setprecision(0)<<RPN[k].sym << " ";
        }
    }

    cout << "\nResult:\n";


    cout << std::fixed << std::setprecision(12);
    string number = to_string(finalResult);

    size_t dot = number.find('.');
    if (dot != string::npos) {
        number.erase(number.find_last_not_of('0') + 1);
        if (number.back() == '.') {
            number.pop_back();
        }
    }

    cout << number;

    //printf("\nResult:\n%LF", pops(result));

    /*
        pushBack(Stack, '1');
        pushBack(Stack, '+');
        pushBack(Stack, '2');
        pushBack(Stack, '-');
        pushBack(Stack, '9');

        //printStack(Stack);

        cout << pop(Stack);
        cout << pop(Stack);
        cout << pop(Stack);
        cout << pop(Stack);
        cout << pop(Stack);

    */
    return 0;

    /*
        STACK stack;

        stack.pushBack(&stack, 10);

      */
}