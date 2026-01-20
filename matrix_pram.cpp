#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

// Sequential matrix multiplication
void multiplySequential(const vector<vector<double>>& A,
                        const vector<vector<double>>& B,
                        vector<vector<double>>& C,
                        int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Parallel matrix multiplication using OpenMP
void multiplyParallel(const vector<vector<double>>& A,
                      const vector<vector<double>>& B,
                      vector<vector<double>>& C,
                      int N) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Timing helper
double measureTime(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}

int main() {
    int N = 600;               // Matrix size
    int P = 4;                 // Number of threads to use

    // Set number of OpenMP threads
    omp_set_num_threads(P);

    // Print number of threads/processors
    int max_threads = omp_get_max_threads();

    // Allocate matrices
    vector<vector<double>> A(N, vector<double>(N));
    vector<vector<double>> B(N, vector<double>(N));
    vector<vector<double>> C_seq(N, vector<double>(N));
    vector<vector<double>> C_par(N, vector<double>(N));

    // Initialize matrices with random numbers
    srand(0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    // Sequential multiplication
    double t_seq = measureTime([&]() {
        multiplySequential(A, B, C_seq, N);
    });

    // Parallel multiplication
    double t_par = measureTime([&]() {
        multiplyParallel(A, B, C_par, N);
    });

    // Compute speedup, cost, efficiency
    double speedup = t_seq / t_par;
    double cost = P * t_par;
    double efficiency = t_seq / cost;

    // Print results
    cout << fixed << setprecision(6);
    cout << "\nNumber of threads/processors: " << max_threads << "\n";
    cout << "Sequential Time: " << t_seq << " seconds\n";
    cout << "Parallel Time  : " << t_par << " seconds\n";
    cout << "Speedup        : " << speedup << "x\n";
    cout << "Efficiency     : " << efficiency << "\n";
    cout << "Cost           : " << cost << " seconds\n";

    // Verify results match
    bool correct = true;
    for (int i = 0; i < N && correct; i++)
        for (int j = 0; j < N && correct; j++)
            if (abs(C_seq[i][j] - C_par[i][j]) > 1e-6)
                correct = false;

    cout << "Verification   : " << (correct ? "PASS" : "FAIL") << endl;

    return 0;
}
