#pragma once
#include <stdio.h>
#include "ret_et_helloworld.h"
#include "ret_tid_helloworld.h"
#include <cstdlib>
int fn_mnudrvprog_020_runtime_environment_routines() {
	int choice;
	while (1) {
		printf("\n\n********************************************************************\n\n\t\tList Of Choices\n\n\0: Run Time Execution for Serial Program\n1: Run Time Execution for Parallel Program\n2: Run Time Execution for Serial Program using Thread\n3: Run Time Execution for Parallel Program using Thread\n4: Exit\n\n********************************************************************\n");
		printf("\nEnter your choice:\t");	
		scanf_s("%d", &choice);
		switch (choice) {
		case 0:	fn_ret_et_helloworld_srl();
			break;
		case 1:	fn_ret_et_helloworld_prl();
			break;
		case 2:	fn_ret_tid_helloworld_srl();
			break;
		case 3:	fn_ret_tid_helloworld_prl();
			break;
		case 4: printf("\n\nExiting program\n\n********************************************************************");
			exit(0);
			break;
		default:printf("\n\nOpted wrong choice\n");
		}
	}

	return 0;
}