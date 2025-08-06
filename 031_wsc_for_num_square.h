#pragma once
#include <stdio.h>
#include <omp.h>

#define N 20

// Function to initialize array
void fn_initializearray(int a[]) {
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
}

// Serial computation of square with timing
void fn_computesquare_srl(int a[], int square[]) {
    for (int i = 0; i < N; i++) {
        square[i] = a[i] * a[i];
        printf("Square of a[%d]: %d * %d = %d\n", i, a[i], a[i], square[i]);
    }
}

// Display array
void fn_display(int square[]) {
    printf("\nSquared Result (Serial):\n");
    for (int i = 0; i < N; i++) {
        printf("square[%d] = %d\n", i, square[i]);
    }
}

// Main function for serial execution with time tracking
void fn_num_square_serial() {
    int a[N], square[N];
    double start, end, time_serial;

    fn_initializearray(a);

    start = omp_get_wtime();
    fn_computesquare_srl(a, square);
    end = omp_get_wtime();

    fn_display(square);

    time_serial = end - start;
    printf("\nTotal time for serial execution: %f seconds\n", time_serial);
}

// Parallel version with performance metrics
void fn_perf_square_parallel() {
    int a[N], square[N];
    double start, end, time_parallel, time_serial = 0.00569; // default sample, can be updated
    double speedup, efficiency;

    fn_initializearray(a);

    start = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        square[i] = a[i] * a[i];
        printf("Squared[%d] = %d printed by Thread no : %d\n", i, square[i], omp_get_thread_num());
    }

    end = omp_get_wtime();
    time_parallel = end - start;

    printf("\nTotal time for parallel execution: %f seconds\n", time_parallel);

    // Performance calculation
    speedup = time_serial / time_parallel;
    efficiency = (speedup * 100.0) / omp_get_max_threads();

    printf("\n//-------------Performance------------------//\n");
    printf("Speedup     = %f\n", speedup);
    printf("Efficiency  = %f\n", efficiency);
}
