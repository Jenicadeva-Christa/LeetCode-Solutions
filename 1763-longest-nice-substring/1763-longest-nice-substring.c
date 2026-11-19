#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* helper(char* s, int start, int end) {
    if (end - start < 1) return "";

    bool has_lower[26] = {false};
    bool has_upper[26] = {false};

    for (int i = start; i <= end; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            has_lower[s[i] - 'a'] = true;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            has_upper[s[i] - 'A'] = true;
        }
    }

    for (int i = start; i <= end; i++) {
        char c = s[i];
        bool is_nice = false;
        if (c >= 'a' && c <= 'z') {
            is_nice = has_upper[c - 'a'];
        } else if (c >= 'A' && c <= 'Z') {
            is_nice = has_lower[c - 'A'];
        }

        if (!is_nice) {
            char* left = helper(s, start, i - 1);
            char* right = helper(s, i + 1, end);

            if (strlen(left) >= strlen(right)) {
                return left;
            } else {
                return right;
            }
        }
    }

    int len = end - start + 1;
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(result, s + start, len);
    result[len] = '\0';
    return result;
}

char* longestNiceSubstring(char* s) {
    return helper(s, 0, strlen(s) - 1);
}
