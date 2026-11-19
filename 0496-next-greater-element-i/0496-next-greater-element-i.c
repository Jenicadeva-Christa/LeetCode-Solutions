#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    int map[10001];
    for (int i = 0; i < 10001; i++) {
        map[i] = -1;
    }

    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;

    for (int i = 0; i < nums2Size; i++) {
        while (top >= 0 && stack[top] < nums2[i]) {
            map[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = nums2[i];
    }

    for (int i = 0; i < nums1Size; i++) {
        ans[i] = map[nums1[i]];
    }

    free(stack);
    return ans;
}
