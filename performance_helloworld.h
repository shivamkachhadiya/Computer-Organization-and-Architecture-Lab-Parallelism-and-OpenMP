#pragma once
#include <stdio.h>
#include <omp.h>

// Serial version with execution time
void fn_perf_helloworld_srl() {
    double start, end;
    start = omp_get_wtime();
    printf("Hello World Serial\n");
    end = omp_get_wtime();
    printf("Serial Execution Time: %f ms\n", (end - start) * 1000);
}

// Parallel version with execution time
void fn_perf_helloworld_prl() {
    double start, end;
    start = omp_get_wtime();
#pragma omp parallel
    printf("Hello World Parallel\n");
    end = omp_get_wtime();
    printf("Parallel Execution Time: %f ms\n", (end - start) * 1000);
}
