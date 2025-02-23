#include <stdio.h>
#include <stdlib.h>

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int ns = n / 2;
	int A11[ns][ns], A12[ns][ns], A21[ns][ns], A22[ns][ns];
	int B11[ns][ns], B12[ns][ns], B21[ns][ns], B22[ns][ns];
	int C11[ns][ns], C12[ns][ns], C21[ns][ns], C22[ns][ns];
	int P1[ns][ns], P2[ns][ns], P3[ns][ns], P4[ns][ns];
	int P5[ns][ns], P6[ns][ns], P7[ns][ns];
	int temp1[ns][ns], temp2[ns][ns];

    // Divide matrices A and B into 4 submatrices each
    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < ns; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + ns];
            A21[i][j] = A[i + ns][j];
            A22[i][j] = A[i + ns][j + ns];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + ns];
            B21[i][j] = B[i + ns][j];
            B22[i][j] = B[i + ns][j + ns];
        }
    }

    // Compute seven products recursively
    strassen(ns, A11, B11, P1);
    strassen(ns, A12, B21, P2);
    strassen(ns, A11, B12, P3);
    strassen(ns, A12, B22, P4);
    strassen(ns, A21, B11, P5);
    strassen(ns, A22, B21, P6);
    strassen(ns, A21, B12, P7);

    // Compute submatrices of result matrix C
    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < ns; j++) {
            C11[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P2[i][j] + P4[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    // Combine submatrices into result matrix C
    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < ns; j++) {
            C[i][j] = C11[i][j];
            C[i][j + ns] = C12[i][j];
            C[i + ns][j] = C21[i][j];
            C[i + ns][j + ns] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter the elements of matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}