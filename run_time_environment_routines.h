#pragma once
#include <stdio.h>
#include <omp.h>

// Thread Management
void fn_rter_omp_set_num_threads() {
    printf("\n[omp_set_num_threads]\n");
    omp_set_num_threads(4);
}

void fn_rter_omp_get_num_threads() {
    printf("\n[omp_get_num_threads]\n");
#pragma omp parallel
    {
        int n = omp_get_num_threads();
#pragma omp critical
        printf("Thread %d sees %d threads\n", omp_get_thread_num(), n);
    }
}

void fn_rter_omp_get_max_threads() {
    printf("\n[omp_get_max_threads]\n");
    printf("Max threads: %d\n", omp_get_max_threads());
}

void fn_rter_omp_get_thread_num() {
    printf("\n[omp_get_thread_num]\n");
#pragma omp parallel
    printf("Thread ID: %d\n", omp_get_thread_num());
}

void fn_rter_omp_get_num_procs() {
    printf("\n[omp_get_num_procs]\n");
    printf("Processors: %d\n", omp_get_num_procs());
}

void fn_rter_omp_in_parallel() {
    printf("\n[omp_in_parallel]\n");
#pragma omp parallel
    {
        if (omp_in_parallel()) {
#pragma omp critical
            printf("Thread %d: In parallel region\n", omp_get_thread_num());
        }
    }
}

void fn_rter_omp_set_dynamic() {
    printf("\n[omp_set_dynamic]\n");
    omp_set_dynamic(1);
}

void fn_rter_omp_get_dynamic() {
    printf("\n[omp_get_dynamic]\n");
    printf("Dynamic threads enabled: %d\n", omp_get_dynamic());
}

void fn_rter_omp_get_cancellation() {
    printf("\n[omp_get_cancellation]\n");
    printf("Cancellation supported: %d\n", omp_get_cancellation());
}

void fn_rter_omp_set_nested() {
    printf("\n[omp_set_nested]\n");
    omp_set_nested(1);
}

void fn_rter_omp_get_nested() {
    printf("\n[omp_get_nested]\n");
    printf("Nested parallelism: %d\n", omp_get_nested());
}

void fn_rter_omp_set_schedule() {
    printf("\n[omp_set_schedule]\n");
    omp_set_schedule(omp_sched_dynamic, 2);
}

void fn_rter_omp_get_schedule() {
    printf("\n[omp_get_schedule]\n");
    omp_sched_t kind;
    int mod;
    omp_get_schedule(&kind, &mod);
    printf("Schedule kind: %d, modifier: %d\n", kind, mod);
}

void fn_rter_omp_get_thread_limit() {
    printf("\n[omp_get_thread_limit]\n");
    printf("Thread limit: %d\n", omp_get_thread_limit());
}

void fn_rter_omp_set_max_active_levels() {
    printf("\n[omp_set_max_active_levels]\n");
    omp_set_max_active_levels(2);
}

void fn_rter_omp_get_max_active_levels() {
    printf("\n[omp_get_max_active_levels]\n");
    printf("Max active levels: %d\n", omp_get_max_active_levels());
}

void fn_rter_omp_get_level() {
    printf("\n[omp_get_level]\n");
#pragma omp parallel
#pragma omp single
    printf("Level: %d\n", omp_get_level());
}

void fn_rter_omp_get_ancestor_thread_num() {
    printf("\n[omp_get_ancestor_thread_num]\n");
#pragma omp parallel
#pragma omp single
    printf("Ancestor thread num (level 0): %d\n", omp_get_ancestor_thread_num(0));
}

void fn_rter_omp_get_team_size() {
    printf("\n[omp_get_team_size]\n");
#pragma omp parallel
#pragma omp single
    printf("Team size (level 0): %d\n", omp_get_team_size(0));
}

void fn_rter_omp_get_active_level() {
    printf("\n[omp_get_active_level]\n");
#pragma omp parallel
#pragma omp single
    printf("Active level: %d\n", omp_get_active_level());
}

void fn_rter_omp_in_final() {
    printf("\n[omp_in_final]\n");
#pragma omp parallel
#pragma omp single
    printf("In final region: %d\n", omp_in_final());
}

void fn_rter_omp_get_proc_bind() {
    printf("\n[omp_get_proc_bind]\n");
#pragma omp parallel
#pragma omp single
    printf("Proc bind policy: %d\n", omp_get_proc_bind());
}

void fn_rter_omp_set_default_device() {
    printf("\n[omp_set_default_device]\n");
    omp_set_default_device(0);
}

void fn_rter_omp_get_default_device() {
    printf("\n[omp_get_default_device]\n");
    printf("Default device: %d\n", omp_get_default_device());
}

void fn_rter_omp_get_num_devices() {
    printf("\n[omp_get_num_devices]\n");
    printf("Available devices: %d\n", omp_get_num_devices());
}

void fn_rter_omp_get_num_teams() {
    printf("\n[omp_get_num_teams]\n");
#pragma omp target teams distribute parallel for
    for (int i = 0; i < 1; i++) {
        printf("Num teams: %d\n", omp_get_num_teams());
    }
}

void fn_rter_omp_get_team_num() {
    printf("\n[omp_get_team_num]\n");
#pragma omp target teams distribute parallel for
    for (int i = 0; i < 1; i++) {
        printf("Team number: %d\n", omp_get_team_num());
    }
}

