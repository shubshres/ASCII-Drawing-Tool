#include "DrawTool.h"

int main(void)
{   
    //initializing variables
    //declaring the 2D array
    char map[MAX][MAX] = {}; 

    int *ptrSize = NULL; 
    int mapSize;
    char backChar;
    char *BufferPtr; 
    ptrSize = &mapSize; 
    char delims[] = "(,)"; 

    //calling function to print the instructions to the user... DONE
    printInstructions();

    //calling function to initialize the map... DONE
    initializeMap(map, ptrSize); 

    mapSize = *ptrSize; 

    //calling function to print the map... done
    printMap(map, mapSize); 


    //MEAT OF THE BONES
    //initializing quit boolean
    int quit = 0; 
    while(quit == 0)
    {
        char Buffer[MAX] = {}; 
        printf("\n\nEnter draw command (enter Q to quit)\t");
        BufferPtr = fgets(Buffer, MAX-1, stdin); 

        //initializing variables
        char letter; 
        char *letterPtr; 

        char row; 
        char *rowPtr; 

        char col; 
        char *colPtr; 

        char size; 
        char *sizePtr; 

        char marker; 
        char *markerPtr; 

        //letter
        letterPtr = strtok(Buffer,delims); 
        letter = *letterPtr; 

        if(letter == 'Q' || letter == 'q')
        //if(*token == 'Q' || *token == 'q')
        {
            quit = 1; 
        }
        else
        {   
            //row
            rowPtr = strtok(NULL,delims);
            row = atoi(rowPtr); 
            

            //col
            colPtr = strtok(NULL,delims);
            col = atoi(colPtr); 
            

            //size
            sizePtr = strtok(NULL,delims);
            size = atoi(sizePtr); 
            

            //marker
            markerPtr = strtok(NULL,delims);
            marker = *markerPtr; 

            //making it so if the marker is not entered (or NULL) it is set to X by comparing the marker value to the ascii value of 10 which is -- LF (NL line feed, new line)
            if(*markerPtr == 10)
            {
                marker = 'X';
            }
            
            //checking the letter and seeing if it is an actual drawline command
            if(!((letter == 'P') || (letter == 'p') || (letter == 'h') || (letter == 'H') || (letter == 'V') || (letter == 'v') || (letter == 'Q') || (letter == 'q')))
            {
                printf("That draw command is unknown\n\n");
            }
            
            //checking for out of bounds errors
            if(row < 0 || col < 0 || row >= mapSize || col >= mapSize)
            {
                printf("\nThe draw command is out of range\n\n"); 
            }
            else
            {   
                //checking the Point parameters
                if(letter == 'P' || letter == 'p')
                {
                    //needs to be in pointer notation
                    *(*(map + row) + col) = marker; 
                }
                //checking the vertical parameters
                if(letter == 'V' || letter == 'v')
                {
                    if((row+size) > mapSize)
                    {
                        printf("\nThe draw command is out of range\n\n");
                    }
                    else
                    {
                        drawLine(letter, marker, row, col, size, map); 
                    }
                }
                //checking the horizontal parameters
                if(letter == 'H' || letter == 'h')
                {
                    if((col+size) > mapSize)
                    {
                        printf("\nThe draw command is out of range\n\n");

                    }
                    else
                    {
                        drawLine(letter, marker, row, col, size, map);  
                    }
                }
            }

            //print statements used to check if the values were correctly stored or not
            /*
            printf("Letter: %c\n",letter);
            printf("Row: %d\n",row);
            printf("Column: %d\n",col);
            printf("Size: %d\n",size);
            printf("Marker: %c\n",marker);
            */

            printf("\n\n"); 
            //reprinting the marked map to the user
            printMap(map, mapSize); 
        }
    } 
    return 0; 
}
