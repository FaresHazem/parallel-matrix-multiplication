# README.md

# Parallel Matrix Multiplication Project

**Author:** Fares Hazem
**Program:** Master's Student, Faculty of Science, Alexandria University
**Course:** High Performance Computing (HPC)
**Date:** December 2025

---

## Project Description

This project demonstrates **parallel computing** using OpenMP in C++.
The main goal is to implement **matrix multiplication** in both sequential and parallel versions and to compare their performance.

Key features of this project:

* Sequential matrix multiplication
* Parallel (PRAM-style) matrix multiplication using OpenMP threads
* Timing measurement for sequential and parallel execution
* Calculation of **speedup**, **efficiency**, and **cost**
* Verification that parallel results match the sequential results

This project is designed as a simple experiment to illustrate **parallel programming concepts** and the benefits of using multiple threads for computation.

---

## Project Structure

```
Project Folder/
│
├── matrix_pram.cpp    # C++ source code containing sequential and parallel matrix multiplication
└── README.md          # This file, containing project description and instructions
```

* **matrix_pram.cpp**: Contains the full implementation with timing, speedup, efficiency, and cost calculation.
* **README.md**: Instructions on running the project and project details.

---

## Requirements

* C++ compiler with OpenMP support (GCC recommended)
* Basic terminal/command prompt access

---

## How to Compile and Run

1. Open a terminal (Linux/macOS) or PowerShell/Command Prompt (Windows).
2. Navigate to the project folder where `matrix_pram.cpp` is located.
3. Compile the program with OpenMP support:

### Linux / macOS / Windows (MinGW):

```powershell
search first for: MSYS2 MINGW64
cd "/c/Users/Fares Hazem/Desktop/Matrix Multiplication"
g++ -O2 -fopenmp matrix_pram.cpp -o matrix_pram
./matrix_pram
```

---

## Output

When you run the program, you will see:

* Number of threads used
* Sequential execution time
* Parallel execution time
* Speedup achieved
* Efficiency of parallel execution
* Cost of parallel computation
* Verification if the parallel result matches the sequential result

Example output:

```
Number of threads/processors: 4

Sequential Time: 0.374523 seconds
Parallel Time  : 0.078231 seconds
Speedup        : 4.785x
Efficiency     : 1.196
Cost           : 0.312924 seconds
Verification   : PASS
```

---

## Notes

* You can change the number of threads by modifying the `P` variable in `matrix_pram.cpp` or by setting the environment variable `OMP_NUM_THREADS`.
* Make sure to compile with the `-fopenmp` flag to enable parallel execution.
* This project contains only **matrix_pram.cpp** and **README.md** for simplicity and clarity.

---

## Author Statement

This project was implemented as part of the **High Performance Computing course** for my Master's program.
It is intended for educational purposes to demonstrate **parallel computing concepts using OpenMP**.
