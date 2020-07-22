#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define RAM 2048

typedef struct board *Board;

Board creatboard(char*);
/*creat new struct*/
int incorrectboard(Board stboard,Board goboard);
/*chect input*/
int solvableboard(Board stboard,Board goboard);

void free_board(Board);


