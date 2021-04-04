#include "DrawTool.h"

void printInstructions(void)
{
    printf("\n\nDraw commands start with\n\n\n\n");
    printf("\tP for a single point\n"); 
    printf("\tH for a horizontal line\n"); 
    printf("\tV for a vertical line\n\n\n\n");

    printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark\n");
    printf("enclosed in () and seperated by commas and then the character for the mark.\n");
    printf("'X' will be used if a mark is not entered. For example,\n\n\n");    

    printf("\tP(2,3,1)*\tstart at point 2,3 in the array and mark one spot\n\t\t\twith an *. For P, the 3rd parameter is ignored.\n\n\n");    
    printf("\tV(1,2,3)$\tstart at point 1,2 in the array and mark the next\n\t\t\t3 spots down from the current position with $\n\n\n");    
    printf("\tH(4,6,7)#\tstart at point 4,6 in the array and mark the next\n\t\t\t7 spots to the right with #\n\n\n");

    printf("Coordinates out of range and lines drawn past the borders are not allowed.\n\n\n");
    printf("Enter Q at the draw command prompt to quit\n\n\n");    
}

void initializeMap(char map[MAX][MAX], int *ptrSize)
{
    int i, j;
    int mapSize = 0; 
    char *mapPtr; 
    char backChar; 

    //creating a do while loop to have user enter a value that falls within the bounds. 
    do
    {
        printf("How big is the array? (Enter a value between 1 and 20)  ");
        scanf("%d", ptrSize);  
        getchar(); 
        printf("\n"); 
        
        if(*ptrSize < 1 || *ptrSize > MAX) // checks if the number is out of bounds... if it is iqt will print out this error statement. 
        {
            printf("The value is outside of the max bounds of the array. Please reenter\n\n"); 
        }

    }while(*ptrSize < 1 || *ptrSize > MAX); //checking for out of bounds

    //asking user to enter the background character
    printf("What is the background character? ");
    scanf(" %c", &backChar); 
    getchar();  
    printf("\n"); 

    for(i = 0; i < *ptrSize; i++)
    {
        for(j = 0; j < *ptrSize; j++)
        {
            *(*(map + i) + j) = backChar; 
        }
    }
}

void printMap(char map[MAX][MAX], int mapSize)
{   
    int i, j; 
    for(i = 0; i < mapSize; i++)
    {
        for(j = 0; j < mapSize; j++)
        {
            printf("%c ", *(*(map + i) + j));
        }
        printf("\n"); 
    }
}

void drawLine(char letter, char marker, int row, int col, int size, char map[MAX][MAX])
{
    //filling out the horizontal
    if(letter == 'H' || letter == 'h')
    {
        int i; 
        for(i = 0; i < size; i++)
        {
            *(*(map+row) + (col+i)) = marker; 
        }
    }

    //filling out the vertical
    if(letter == 'V' || letter == 'v')
    {
        int j; 
        for(j = 0; j < size; j++)
        {
            *(*(map+(row+j)) + (col)) = marker; 
        }
    }
}
