#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to perform matrix multiplication
void matrixMultiplication(int **A, int **B, int **C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    const int N = 3;

    // Initialize matrices A, B, and C with random values
    int **A = new int*[N];
    int **B = new int*[N];
    int **C = new int*[N];

    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Measure execution time of matrix multiplication
    auto start = high_resolution_clock::now();

    // Perform matrix multiplication
    matrixMultiplication(A, B, C, N);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Print the execution time in milliseconds
    cout << "Matrix multiplication took " << duration.count() / 1e6 << " milliseconds." << endl;

    // Deallocate memory (as before)

    return 0;
}
