//Write a serial program & parallel program to print "Hello World", find thread Id as well as execution time and compute Speed up & Efficiency 
#pragma once
#include <stdio.h>
#include <omp.h>
using namespace std;
double fn_rer_practice1_srl()
{
	double start, end, et;
	start = omp_get_wtime();
	printf("Hello World Serial");
	printf("\t\t Thread ID:%d\n", omp_get_thread_num());
	end = omp_get_wtime();
	et = end - start;
	printf("Execution Time of Serial Program: %f ms\n\n", et);
	return et;
}
double fn_rer_practice1_prl(int threads_ip)
{
	double start, end, et;
	omp_set_num_threads(threads_ip);
	start = omp_get_wtime(); // this function captures the time when the statement is started
#pragma omp parallel
	{ printf("Hello World Parallel\t\tThread ID:%d\n", omp_get_thread_num()); }
	end = omp_get_wtime();
	et = end - start;
	printf("Execution Time of Parallel Program: %f ms\n\n", et);
	return et;
}
void ret_practice1(int threads_ip) {
	double srl_et, prl_et, speed_up, efficiency;
	srl_et = fn_rer_practice1_srl();
	prl_et = fn_rer_practice1_prl(threads_ip);
	omp_set_num_threads(threads_ip);
	printf("\nThreads used in parallel block: %d\n", threads_ip);

	speed_up = srl_et / prl_et;
	printf("\n\nSpeed Up : %f\n", speed_up);
	if (threads_ip > 0) {
		efficiency = (speed_up / threads_ip) * 100;
		double eff = speed_up / threads_ip;
		printf("\n\nEfficiency: %f%%\n", efficiency);
		printf("\nEff: %f%\n", eff);
	}
	else {
		printf("\n\nEfficiency: Cannot compute (Thread count is zero)\n");
	}
}