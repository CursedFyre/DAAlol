
//Branch and bound

#include <stdio.h>
#include <limits.h>

#define V 4

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations using Heap's algorithm
void generatePermutations(int arr[], int size, int n, int graph[][V], int s, int *min_path) {
    if (size == 1) {
        // Calculate the path weight for the current permutation
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < n; i++) {
            current_pathweight += graph[k][arr[i]];
            k = arr[i];
        }
        current_pathweight += graph[k][s];

        // Update the minimum path weight
        if (current_pathweight < *min_path) {
            *min_path = current_pathweight;
        }
    } else {
        for (int i = 0; i < size; i++) {
            generatePermutations(arr, size - 1, n, graph, s, min_path);
            if (size % 2 == 1) {
                swap(&arr[0], &arr[size - 1]);
            } else {
                swap(&arr[i], &arr[size - 1]);
            }
        }
    }
}

// Implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s) {
    // Store all vertices apart from the source vertex
    int vertex[V - 1];
    int index = 0;
    for (int i = 0; i < V; i++) {
        if (i != s) {
            vertex[index++] = i;
        }
    }

    // Store minimum weight Hamiltonian Cycle
    int min_path = INT_MAX;

    // Generate all permutations of vertex array
    generatePermutations(vertex, V - 1, V - 1, graph, s, &min_path);

    return min_path;
}

// Driver Code
int main() {
    // Matrix representation of graph
    int graph[V][V];
    
    // Input distances for each vertex pair
    printf("Enter distances for %d vertices (%d x %d matrix):\n", V, V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            //printf("Distance from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }
    
    int s = 0; // Starting vertex (e.g., vertex 1)
    printf("Minimum path weight for TSP: %d\n", travllingSalesmanProblem(graph, s));
    
    return 0;
}
