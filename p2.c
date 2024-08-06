void reverseWords(char* str) {
    int start = 0;
    int end = 0;
    int length = strlen(str);

    // Remove commas and periods from the string
    for (int i = 0; i < length; i++) {
        if (str[i] == ',' || str[i] == '.') {
            continue;
        }
        str[end++] = str[i];
    }
    str[end] = '\0'; // Add null terminator at the end

    // Reverse the words in the modified string
    while (end <= length) {
        if (str[end] == ' ' || str[end] == '\0') {
            int i;
            for (i = end - 1; i >= start; i--) {
                printf("%c", str[i]);
            }
            if (str[end] != '\0') {
                printf("%c", str[end]);
            }
            start = end + 1;
        }
        end++;
    }
}
