#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxFrequency(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int left = 0;
    int max_freq = 0;
    long long current_sum = 0;
    
    for (int right = 0; right < numsSize; right++) {
        current_sum += nums[right];
        
        while ((long long)nums[right] * (right - left + 1) - current_sum > k) {
            current_sum -= nums[left];
            left++;
        }
        
        int current_window_size = right - left + 1;
        if (current_window_size > max_freq) {
            max_freq = current_window_size;
        }
    }
    
    return max_freq;
}
