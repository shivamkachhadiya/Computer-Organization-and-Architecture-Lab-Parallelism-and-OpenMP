#pragma once

#include<stdio.h>
#include<omp.h>

void fn_helloworld_prl()// use 'fn' before any function name 
{
#pragma omp parallel
	printf("Hello World Parallel\n");
}
