#include <string.h>

int minimumRecolors(char* blocks, int k) {
    int n = strlen(blocks);
    int current_w = 0;
    
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') {
            current_w++;
        }
    }
    
    int min_w = current_w;
    
    for (int i = k; i < n; i++) {
        if (blocks[i - k] == 'W') {
            current_w--;
        }
        if (blocks[i] == 'W') {
            current_w++;
        }
        
        if (current_w < min_w) {
            min_w = current_w;
        }
    }
    
    return min_w;
}
