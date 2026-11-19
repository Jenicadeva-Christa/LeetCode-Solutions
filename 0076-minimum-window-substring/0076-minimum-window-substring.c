#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    if (m == 0 || n == 0 || m < n) {
        return "";
    }
    
    int t_freq[128] = {0};
    int window_freq[128] = {0};
    
    for (int i = 0; i < n; i++) {
        t_freq[(unsigned char)t[i]]++;
    }
    
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (t_freq[i] > 0) {
            required++;
        }
    }
    
    int left = 0, right = 0;
    int formed = 0;
    
    int min_len = INT_MAX;
    int start_idx = 0;
    
    while (right < m) {
        char c = s[right];
        window_freq[(unsigned char)c]++;
        
        if (t_freq[(unsigned char)c] > 0 && window_freq[(unsigned char)c] == t_freq[(unsigned char)c]) {
            formed++;
        }
        
        while (left <= right && formed == required) {
            c = s[left];
            
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }
            
            window_freq[(unsigned char)c]--;
            if (t_freq[(unsigned char)c] > 0 && window_freq[(unsigned char)c] < t_freq[(unsigned char)c]) {
                formed--;
            }
            
            left++;
        }
        
        right++;
    }
    
    if (min_len == INT_MAX) {
        return "";
    }
    
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + start_idx, min_len);
    result[min_len] = '\0';
    
    return result;
}
