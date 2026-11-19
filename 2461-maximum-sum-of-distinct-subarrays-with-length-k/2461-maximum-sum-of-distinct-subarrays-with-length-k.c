#include <stdio.h>
long long maximumSubarraySum(int* nums, int numsSize, int k) {
    int freq[100001] = {0};
    long long current_sum = 0;
    long long max_sum = 0;
    int unique_count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (freq[nums[i]] == 0) {
            unique_count++;
        }
        freq[nums[i]]++;
        current_sum += nums[i];
        if (i >= k) {
            int out_elem = nums[i - k];
            freq[out_elem]--;
            if (freq[out_elem] == 0) {
                unique_count--;
            }
            current_sum -= out_elem;
        }
        if (i >= k - 1) {
            if (unique_count == k) {
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                }
            }
        }
    }
    return max_sum;
}
