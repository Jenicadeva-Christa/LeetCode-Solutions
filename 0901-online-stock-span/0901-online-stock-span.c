#include <stdlib.h>

typedef struct {
    int price;
    int span;
} PricePair;

typedef struct {
    PricePair* stack;
    int top;
    int capacity;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* spanner = (StockSpanner*)malloc(sizeof(StockSpanner));
    spanner->capacity = 10005;
    spanner->stack = (PricePair*)malloc(spanner->capacity * sizeof(PricePair));
    spanner->top = -1;
    return spanner;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int currentSpan = 1;

    while (obj->top >= 0 && obj->stack[obj->top].price <= price) {
        currentSpan += obj->stack[obj->top].span;
        obj->top--;
    }

    obj->top++;
    obj->stack[obj->top].price = price;
    obj->stack[obj->top].span = currentSpan;

    return currentSpan;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj);
}
