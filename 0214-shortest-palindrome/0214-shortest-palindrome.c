#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* shortestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;
    char* rev = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - 1 - i];
    }
    rev[len] = '\0';
    int patternLen = 2 * len + 1;
    char* pattern = (char*)malloc((patternLen + 1) * sizeof(char));
    sprintf(pattern, "%s#%s", s, rev);
    int* lps = (int*)calloc(patternLen, sizeof(int));
    for (int i = 1; i < patternLen; i++) {
        int j = lps[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lps[i] = j;
    }
    int longestPalindromicPrefixLen = lps[patternLen - 1];

    free(lps);
    free(pattern);


    int charsToAdd = len - longestPalindromicPrefixLen;
    char* result = (char*)malloc((charsToAdd + len + 1) * sizeof(char));
    
    strncpy(result, rev, charsToAdd);
    strcpy(result + charsToAdd, s);

    free(rev);
    return result;
}
