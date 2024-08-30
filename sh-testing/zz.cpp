void error_output(const char *msg) {
    write(STDERR_FILENO, msg, _strlen(msg));
}

void success_output(const char *msg) {
    write(STDOUT_FILENO, msg, _strlen(msg));
}

size_t _strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int _strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}
