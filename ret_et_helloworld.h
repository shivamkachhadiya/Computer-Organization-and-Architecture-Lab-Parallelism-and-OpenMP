#pragma once
#include<stdio.h>
#include<omp.h>

void fn_ret_et_helloworld_srl()
{
	double start, end;
	start = omp_get_wtime(); // this function captures the time when the statement is started
	printf("Hello World Serial\n");
	end = omp_get_wtime();
	printf("Execution Time of Serial Program: %f ms\n", end - start);
}

void fn_ret_et_helloworld_prl()
{
	double start, end;
	start = omp_get_wtime(); // this function captures the time when the statement is started
#pragma omp parallel
	printf("Hello World Parallel\n");
	end = omp_get_wtime();
	printf("Execution Time of Parallel Program: %f ms\n", end - start);
}
