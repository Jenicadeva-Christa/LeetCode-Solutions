#include <stdlib.h>

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* count = (int*)malloc(heightsSize * sizeof(int));
    *returnSize = heightsSize;
    int* stack = (int*)malloc(heightsSize * sizeof(int));
    int top = -1;
    for (int i = heightsSize - 1; i >= 0; i--) {
        int visible_count = 0;
        while (top >= 0 && stack[top] < heights[i]) {
            visible_count++;
            top--; 
        }   
        if (top >= 0) {
            visible_count++;
        }
        count[i] = visible_count;
        stack[++top] = heights[i];
    }
    free(stack);
    return count;
}
