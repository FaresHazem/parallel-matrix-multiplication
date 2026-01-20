# Parallel Matrix Multiplication (OpenMP)

**Author:** Fares Hazem  
**Program:** Master’s Student, Faculty of Science, Alexandria University  
**Course:** High Performance Computing (HPC)  
**Date:** December 2025

---

## 📝 Overview
This project explores **parallel computing** using OpenMP in C++. It implements matrix multiplication in both sequential and parallel versions to analyze performance gains on multi-core processors.

The project calculates key HPC metrics, including **Speedup**, **Efficiency**, and **Cost**, while ensuring the accuracy of the parallel computation through a verification step.

## 🚀 Key Features
*   **Sequential Implementation:** Baseline single-threaded multiplication.
*   **Parallel Implementation:** Multi-threaded execution using OpenMP (PRAM-style).
*   **Performance Analytics:** Automated calculation of Speedup and Efficiency.
*   **Verification:** Cross-checks the parallel result against the sequential result for accuracy.

---

## 📂 Project Structure
```text
Matrix-Multiplication/
│
├── matrix_pram.cpp    # C++ source code (Sequential & Parallel logic)
└── README.md          # Project documentation
```

---

## 🛠 Prerequisites
To run this project, you need:
*   A C++ compiler (GCC/MinGW recommended).
*   OpenMP libraries (included with most modern GCC distributions).

---

## 💻 How to Compile and Run

### Windows (using MSYS2/MinGW) or Linux
1. Open your terminal or PowerShell.
2. Navigate to the project directory:
   ```bash
   cd "/c/Users/Fares Hazem/Desktop/Matrix Multiplication"
   ```
3. Compile the code with the `-fopenmp` flag:
   ```bash
   g++ -O2 -fopenmp matrix_pram.cpp -o matrix_pram
   ```
4. Run the executable:
   ```bash
   ./matrix_pram
   ```

---

## 📊 Understanding the Output
The program will display the following metrics:

| Metric | Description |
| :--- | :--- |
| **Sequential Time** | Time taken using a single thread (seconds). |
| **Parallel Time** | Time taken using multiple threads (seconds). |
| **Speedup** | Ratio of Sequential Time to Parallel Time ($T_s / T_p$). |
| **Efficiency** | How well the processors are utilized ($Speedup / Threads$). |
| **Cost** | Total processor time spent ($Parallel Time \times Threads$). |
| **Verification** | Displays `PASS` if the parallel result is 100% correct. |

---

## ⚙️ Configuration
You can adjust the number of threads and matrix size directly within the `matrix_pram.cpp` file:
*   **Modify `P`**: Change the number of threads.
*   **Modify Matrix Dimensions**: Adjust the row/column constants for larger scale testing.

---

**Note:** Ensure your hardware supports the number of threads defined in the code to see optimal efficiency.