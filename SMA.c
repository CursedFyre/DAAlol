/*
smack my ass
*/

#include <stdio.h>
#include <string.h>

#define d 256  // Number of characters in the input alphabet
#define prime 101  // A prime number

void search(char pattern[], char text[], int prime_value) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%prime_value"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % prime_value;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % prime_value;
        t = (d * t + text[i]) % prime_value;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern.
        // If the hash values match, then only check for characters one by one
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % prime_value;
            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + prime_value);
        }
    }
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline character

    search(pattern, text, prime);
    return 0;
}