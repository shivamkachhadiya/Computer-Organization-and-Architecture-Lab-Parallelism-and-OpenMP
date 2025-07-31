#pragma once
#include<stdio.h>
#include<omp.h>
#include "helloworld_srl.h"
#include "helloworld_prl.h"
#include <cstdlib>

int fn_mndrvprog_010_parallel_construct() {
	int choice;
	while (1) {
		printf("\n\n********************************************************************\n\n\t\tList Of Choices\n\n\t0: Exit\t\t1:Serial Program\t2: Parallel Program\n\n********************************************************************\n");
		printf("\nEnter your choice:\t");		scanf_s("%d", &choice);
		switch (choice) {
		case 1:	printf("\n\nThis is output of Hello world serial program.\n");
			fn_helloworld_srl();
			break;
		case 2:	printf("\n\nThis is output of Hello world parallel program.\n");
			fn_helloworld_prl();
			break;
		case 0: printf("\n\nExiting program\n\n********************************************************************");
			exit(0);
		default:printf("\n\nOpted wrong choice\n");

		}
	}
	return 0;
}
