#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    
    if (k >= len) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }
    
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = 0; 
    
    for (int i = 0; i < len; i++) {

        while (top > 0 && k > 0 && stack[top - 1] > num[i]) {
            top--;
            k--;
        }
        stack[top++] = num[i];
    }
    
    top -= k;
    
    int start = 0;
    while (start < top && stack[start] == '0') {
        start++;
    }
    
    int resultLen = top - start;
    if (resultLen <= 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        free(stack);
        return result;
    }
    
    char* result = (char*)malloc((resultLen + 1) * sizeof(char));
    strncpy(result, stack + start, resultLen);
    result[resultLen] = '\0';
    free(stack);
    return result;
}
