#include <stdio.h>
#include <string.h>

int maximumSwap(int num) {
    char str[12];
    sprintf(str, "%d", num);
    int n = strlen(str);
    
    int last[10];
    memset(last, -1, sizeof(last));
    
    for (int i = 0; i < n; i++) {
        last[str[i] - '0'] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int d = 9; d > (str[i] - '0'); d--) {
            if (last[d] > i) {
                char temp = str[i];
                str[i] = str[last[d]];
                str[last[d]] = temp;
                
                int result;
                sscanf(str, "%d", &result);
                return result;
            }
        }
    }
    
    return num;
}
