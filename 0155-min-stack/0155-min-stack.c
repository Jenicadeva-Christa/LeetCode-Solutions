#include <stdlib.h>

typedef struct {
    int val;
    int min;
} Node;

typedef struct {
    Node* data;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 30005;
    stack->data = (Node*)malloc(stack->capacity * sizeof(Node));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->data[obj->top].val = val;
    
    if (obj->top == 0) {
        obj->data[obj->top].min = val;
    } else {
        int currentMin = obj->data[obj->top - 1].min;
        obj->data[obj->top].min = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}
