int* twoSum(int* nums, int numsSize, int target, int* returnSize) { 
    int l = 0;
    int r; 
    int* a = (int*)malloc(2 * sizeof(int)); 
    while (l < numsSize - 1) {
        r = l + 1;
        while (r < numsSize) {
            if (nums[l] + nums[r] == target) {
                a[0] = l;
                a[1] = r;
                *returnSize = 2;
                return a;
            }
            r++;
        }
        l++;
    }
    *returnSize = 0;
    free(a);
    return NULL; 
}
