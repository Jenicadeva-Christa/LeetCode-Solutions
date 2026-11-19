#include <stdlib.h>

int maximumStrongPairXor(int* nums, int numsSize) {
    int max_xor = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int x = nums[i];
            int y = nums[j];
            int diff = x > y ? x - y : y - x;
            int min_val = x < y ? x : y;
            
            if (diff <= min_val) {
                int current_xor = x ^ y;
                if (current_xor > max_xor) {
                    max_xor = current_xor;
                }
            }
        }
    }
    
    return max_xor;
}
