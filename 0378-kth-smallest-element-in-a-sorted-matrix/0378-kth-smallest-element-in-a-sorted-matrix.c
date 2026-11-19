#include <stdio.h>

int countLessOrEqual(int** matrix, int n, int target) {
    int count = 0;
    int row = n - 1;
    int col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= target) {
            count += (row + 1);
            col++;
        } else {
            row--;
        }
    }
    return count;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int low = matrix[0][0];
    int high = matrix[matrixSize - 1][matrixSize - 1];
    int ans = low;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countLessOrEqual(matrix, matrixSize, mid) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
