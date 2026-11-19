void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int num1 = m - 1;     
    int num2 = n - 1;    
    int num3 = m + n - 1;  
    while (num1 >= 0 && num2 >= 0) {
        if (nums1[num1] > nums2[num2]) {
            nums1[num3] = nums1[num1];
            num1--;
        } else {
            nums1[num3] = nums2[num2];
            num2--;
        }
        num3--;
    }
    while (num2 >= 0) {
        nums1[num3] = nums2[num2];
        num2--;
        num3--;
    }
}
