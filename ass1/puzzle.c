#include <stdio.h>
#include <stdlib.h>
#include "boardADT.h"

int main(int argc, char **argv)
{
	char *stline=malloc(sizeof(char)*RAM);
	char *goline=malloc(sizeof(char)*RAM);
	char *printst=malloc(sizeof(char)*RAM);
	char *printgo=malloc(sizeof(char)*RAM);
	fgets(stline, RAM, stdin);
	fgets(goline, RAM, stdin);
	strcpy(printst,stline);
	strcpy(printgo,goline);

	Board stboard=creatboard(stline);
	Board goboard=creatboard(goline);

	switch (incorrectboard(stboard,goboard))
	{
		case 0:{
			printf("Not a N*N board\n");
			return EXIT_FAILURE;
		}

		case 1:{
			printf("tile errors\n");
			return EXIT_FAILURE;
		}
		case 3:
				{
			printf("2 boards are not the same size\n");
			return EXIT_FAILURE;
		}
		case 2:{
            printf("start: %s", printst);
            printf("goal: %s", printgo);
			switch (solvableboard(stboard,goboard)){
				case 1:{
					printf("solvable\n");
					break;
				}
				case 0:{
					printf("unsolvable\n");
					break;
				}
			}
		break;
		}
	}


    free_board(stboard);
    free_board(goboard);
    free(printst);
    free(printgo);
    free(stline);
    free(goline);
}