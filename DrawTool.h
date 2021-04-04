#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DrawTool_h
#define DrawTool_h
#define MAX 20


//Function Prototypes
void printInstructions(); 
void initializeArray(char map[MAX][MAX], int *ptrSize);
void printMap(char map[MAX][MAX], int mapSize);
void drawLine(char letter, char marker, int row, int col, int size, char map[MAX][MAX]);

#endif
