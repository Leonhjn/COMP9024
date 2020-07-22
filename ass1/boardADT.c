#include "boardADT.h"

struct board
{
	int length;
	int *number;
	int N;
};

Board creatboard(char *line)
{
	Board b = malloc(sizeof(struct board));
	b->length=0;
	b->number=NULL;
	char *p=strtok(line," ");
	b->number=malloc(RAM * sizeof(int));
	while (p != NULL){
		if ((strcmp(p, "b") == 0) || (strcmp(p, "b\n") == 0)){
			*(b->number+b->length)=0;
		}
		else{
			if (atoi(p)==0){
				printf("tile errors\n");
				exit(EXIT_FAILURE);
			}
			else{
				*(b->number+b->length)=atoi(p);}
		}
		p=strtok(NULL," ");
		b->length++;
	}
	b->N=(int) sqrt(b->length);
	return b;
}

int incorrectboard(Board b1, Board b2)
{
	if (b1->length != b2->length) return 3;
	if ((b1->N * b1->N) != (b1->length)){
		return 0;
	}
	if ((b2->N * b2->N) != (b2->length)){
		return 0;
	}
	for (int i=0; i < b1->length; i++){
		if ((*(b1->number+i) > b1->length) || (*(b2->number+i) > b2->length)){
			return 1;
		}
	}
	for (int i=0; i < b1->length; i++){
		for (int j=i+1; j<b1->length;j++){
			if ((*(b1->number+i) == *(b1->number+j)) || (*(b2->number+i) == *(b2->number+j))){
				return 1;
			}
		}

	}
	return 2;
}

int solvableboard(Board stboard, Board goboard)
{
	int disorder_start = 0;
	int disorder_goal=0;
    for (int i = 0; i < stboard->length; i++) {
        if (*(stboard->number + i) == 0) {
            if (stboard->N % 2 == 0)
                disorder_start += i / stboard->N + 1;
            } else {
                for (int j = i + 1; j < stboard->length; j++){
                    if (*(stboard->number + j) != 0) {
                    	if (*(stboard->number+i) > *(stboard->number + j)){
                    	disorder_start ++;
                    	};
                    }
                }
        }
    }
    for (int i = 0; i < goboard->length; i++) {
        if (*(goboard->number + i) == 0) {
            if (goboard->N % 2 == 0)
                disorder_goal += i / goboard->N + 1;
        	} else {
            	for (int j = i + 1; j < goboard->length; j++){
              		if (*(goboard->number + j) != 0) {
                    	if (*(goboard->number+i) > *(goboard->number + j)){
                    	disorder_goal ++;	
                    	};
                	}
            	}
        }
    }
    if ((disorder_start % 2) != (disorder_goal % 2)){
    	return 0;
    }
    else{
    	return 1;
    }
}
void free_board(Board b) {
    if (b != NULL) {
        if (b->number != NULL) {
            free(b->number);
        }
        free(b);
    }
}
