int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int left = 0;
    int right = 0;
    int max_freq = 0;
    int max_len = 0;

    while (s[right] != '\0') {
        count[s[right] - 'A']++;
        if (count[s[right] - 'A'] > max_freq) {
            max_freq = count[s[right] - 'A'];
        }

        if ((right - left + 1) - max_freq > k) {
            count[s[left] - 'A']--;
            left++;
        }

        if ((right - left + 1) > max_len) {
            max_len = right - left + 1;
        }
        right++;
    }

    return max_len;
}
