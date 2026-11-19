#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

int cmp(const void* a, const void* b) {
    int valA = ((Pair*)a)->val;
    int valB = ((Pair*)b)->val;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

long long countGood(int* nums, int numsSize, int k) {
    Pair* pairs = (Pair*)malloc(sizeof(Pair) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        pairs[i].val = nums[i];
        pairs[i].index = i;
    }
    qsort(pairs, numsSize, sizeof(Pair), cmp);
    
    int* compressed = (int*)malloc(sizeof(int) * numsSize);
    int id = 0;
    compressed[pairs[0].index] = id;
    for (int i = 1; i < numsSize; i++) {
        if (pairs[i].val != pairs[i-1].val) {
            id++;
        }
        compressed[pairs[i].index] = id;
    }
    free(pairs);
    
    int* cnt = (int*)calloc(id + 1, sizeof(int));
    long long ans = 0;
    long long cur = 0;
    int i = 0;
    
    for (int j = 0; j < numsSize; j++) {
        int x = compressed[j];
        cur += cnt[x];
        cnt[x]++;
        
        while (cur - cnt[compressed[i]] + 1 >= k) {
            cnt[compressed[i]]--;
            cur -= cnt[compressed[i]];
            i++;
        }
        
        if (cur >= k) {
            ans += i + 1;
        }
    }
    
    free(compressed);
    free(cnt);
    return ans;
}
