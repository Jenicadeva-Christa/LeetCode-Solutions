#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void maxSubarray(int* nums, int numsSize, int selectSize, int* out) {
    int top = -1;
    int remaining = numsSize;
    for (int i = 0; i < numsSize; i++) {
        while (top >= 0 && out[top] < nums[i] && (top + 1 + remaining > selectSize)) {
            top--;
        }
        if (top + 1 < selectSize) {
            out[++top] = nums[i];
        }
        remaining--;
    }
}

bool compare(int* nums1, int size1, int idx1, int* nums2, int size2, int idx2) {
    while (idx1 < size1 && idx2 < size2) {
        if (nums1[idx1] != nums2[idx2]) {
            return nums1[idx1] > nums2[idx2];
        }
        idx1++;
        idx2++;
    }
    return idx1 < size1;
}

void merge(int* sub1, int size1, int* sub2, int size2, int* out) {
    int i = 0, j = 0, r = 0;
    while (i < size1 || j < size2) {
        if (compare(sub1, size1, i, sub2, size2, j)) {
            out[r++] = sub1[i++];
        } else {
            out[r++] = sub2[j++];
        }
    }
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    *returnSize = k;
    int* best = (int*)calloc(k, sizeof(int));
    
    int* sub1 = (int*)malloc(k * sizeof(int));
    int* sub2 = (int*)malloc(k * sizeof(int));
    int* candidate = (int*)malloc(k * sizeof(int));

    int start = k - nums2Size > 0 ? k - nums2Size : 0;
    int end = k < nums1Size ? k : nums1Size;

    bool first_candidate = true;

    for (int i = start; i <= end; i++) {
        int j = k - i;
        maxSubarray(nums1, nums1Size, i, sub1);
        maxSubarray(nums2, nums2Size, j, sub2);
        merge(sub1, i, sub2, j, candidate);

        if (first_candidate || compare(candidate, k, 0, best, k, 0)) {
            memcpy(best, candidate, k * sizeof(int));
            first_candidate = false;
        }
    }

    free(sub1);
    free(sub2);
    free(candidate);
    return best;
}
