#pragma once
#include <stdio.h>
#include <omp.h>
#include "helloworld_srl.h"
#include "helloworld_prl.h"
#include "ret_et_helloworld.h"
#include "ret_tid_helloworld.h"
#include "ret_practice.h"
#include "mnudrvprog_010_parallel_construct.h"
#include "mnudrvprog_020_runtime_environment_routines.h"

int fn_menu_01_parallel_construct() {
    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Serial Hello World\n");
        printf("2. Parallel Hello World (OpenMP)\n");
        printf("3. Return Parallel Execution time\n");
        printf("4. Thread ID Hello World (OpenMP)\n");
        printf("5. Show number of threads(omp_get_num_threads)\n");
        printf("6. Show max threads (omp_get_max_threads)\n");
        printf("7. Show current thread ID(omp_get_thread_num)\n");
        printf("8. Show processor count(omp_get_num_procs)\n");
        printf("9. Measure time using omp_get_wtime\n");
        printf("10. Set number of threads manually\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("This is output of helloworld serial program:\n");
            fn_helloworld_srl();
            break;
        case 2:
            printf("This is output of hello world parallel program:\n");
            fn_helloworld_prl();
            break;
        case 3:
            fn_ret_et_helloworld_prl();
            break;
        case 4:
            fn_ret_tid_helloworld_prl();
            break;
        case 5:
#pragma omp parallel
        {
            printf("Thread %d says total threads: %d\n", omp_get_thread_num(), omp_get_num_threads());
        }
        break;
        case 6:
            printf("Maximum threads available: %d\n", omp_get_max_threads());
            break;
        case 7:
#pragma omp parallel
        {
            printf("Hello from thread ID: %d\n", omp_get_thread_num());
        }
        break;
        case 8:
            printf("Number of processors available: %d\n", omp_get_num_procs());
            break;
        case 9:
        {
            double start = omp_get_wtime();
#pragma omp parallel for
            for (int i = 0; i < 100000000; ++i);
            double end = omp_get_wtime();
            printf("Time taken: %f seconds\n", end - start);
            break;
        }
        case 10:
        {
            int user_threads;
            printf("Enter number of threads to set: ");
            scanf_s("%d", &user_threads);
            omp_set_num_threads(user_threads);
            printf("Number of threads has been set to: %d\n", user_threads);
#pragma omp parallel
            {
                printf("Thread ID: %d out of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
            }
            break;
        }
        case 0:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Opted wrong choice.\n");
            break;
        }
    }
}
