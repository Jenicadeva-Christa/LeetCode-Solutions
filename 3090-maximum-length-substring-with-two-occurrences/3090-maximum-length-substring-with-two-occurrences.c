#include <string.h>
int maximumLengthSubstring(char* s) {
    int n = strlen(s);
    int char_count[26] = {0}; 
    int left = 0;
    int max_len = 0;
    for (int right = 0; right < n; right++) {
        int right_char = s[right] - 'a';
        char_count[right_char]++;
        while (char_count[right_char] > 2) {
            int left_char = s[left] - 'a';
            char_count[left_char]--;
            left++;
        }
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    } 
    return max_len;
}
