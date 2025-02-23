#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For dynamic memory allocation

void psol(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int **board, int row, int col, int N) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int **board, int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1, N))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

bool nq(int N) {
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        board[i] = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQUtil(board, 0, N)) {
        printf("Solution does not exist");
        return false;
    }

    psol(board, N);

    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);

    return true;
}

int main() {
    int N;
    printf("Enter the board size: ");
    scanf("%d", &N);

    nq(N);
    return 0;
}
