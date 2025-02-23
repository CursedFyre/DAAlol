#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

int t[MAX_LENGTH + 1][MAX_LENGTH + 1];

void lcsAlgo(char S1[], char S2[]) {
    int m = strlen(S1);
    int n = strlen(S2);

    // Filling 0's in the matrix
    for (int i = 0; i <= m; i++)
        t[i][0] = 0;
    for (int i = 0; i <= n; i++)
        t[0][i] = 0;

    // Building the matrix in bottom-up way
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                t[i][j] = t[i - 1][j - 1] + 1;
            } else if (t[i - 1][j] >= t[i][j - 1]) {
                t[i][j] = t[i - 1][j];
            } else {
                t[i][j] = t[i][j - 1];
            }
        }
    }

    // Finding LCS
    int index = t[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        } else if (t[i - 1][j] > t[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Printing the sequences
    printf("S1: %s\nS2: %s\n", S1, S2);
    printf("LCS: %s\n", lcsAlgo);
}

int main() {
    char S1[MAX_LENGTH], S2[MAX_LENGTH];
    printf("Enter the first string: ");
    fgets(S1, MAX_LENGTH, stdin);
    S1[strcspn(S1, "\n")] = '\0';  // Removing newline character

    printf("Enter the second string: ");
    fgets(S2, MAX_LENGTH, stdin);
    S2[strcspn(S2, "\n")] = '\0';  // Removing newline character

    lcsAlgo(S1, S2);
    return 0;
}

