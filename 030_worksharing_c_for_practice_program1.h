#pragma once
#include"stdio.h"
#include"conio.h"
void fn_worksharing_c_for_2constructs() {
	int i;
#pragma omp parallel
	{
		printf("thread %d work sharing start\n",omp_get_thread_num());

#pragma omp for
		for (i = 0; i < 12; i++) {
			printf("hello world in iteration %d by thread ID %d\n", i, omp_get_thread_num());
			//omp_get_thread_num thread id hsow karta h... jitna core hei uske double tak jayega
			//mera core 4 hei to 8 tak jayega
		}
	}
}



void fn_worksharing_c_for_1constructs() {
	int i;


#pragma omp parallel for
		for (i = 0; i < 12; i++) {
			printf("hello world in iteration %d by thread ID %d\n", i, omp_get_thread_num());
			//omp_get_thread_num thread id hsow karta h... jitna core hei uske double tak jayega
			//mera core 4 hei to 8 tak jayega
		}
	}
