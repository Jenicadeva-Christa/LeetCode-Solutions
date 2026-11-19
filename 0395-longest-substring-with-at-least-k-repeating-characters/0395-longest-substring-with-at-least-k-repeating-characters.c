#include <stdio.h>
#include <string.h>

int longestSubstringHelper(char* s, int start, int end, int k) {
    if (end - start < k) {
        return 0;
    }
    
    int count[26] = {0};
    for (int i = start; i < end; i++) {
        count[s[i] - 'a']++;
    }
    
    for (int i = start; i < end; i++) {
        if (count[s[i] - 'a'] < k) {
            int next_start = i + 1;
            while (next_start < end && count[s[next_start] - 'a'] < k) {
                next_start++;
            }
            
            int left = longestSubstringHelper(s, start, i, k);
            int right = longestSubstringHelper(s, next_start, end, k);
            
            return left > right ? left : right;
        }
    }
    
    return end - start;
}

int longestSubstring(char* s, int k) {
    return longestSubstringHelper(s, 0, strlen(s), k);
}
