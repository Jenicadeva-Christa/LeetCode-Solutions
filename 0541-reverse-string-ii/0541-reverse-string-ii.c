#include <string.h>

void reverseSegment(char* s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    
    for (int i = 0; i < len; i += 2 * k) {
        int left = i;
        int right = (i + k - 1 < len) ? (i + k - 1) : (len - 1);
        
        reverseSegment(s, left, right);
    }
    
    return s;
}
