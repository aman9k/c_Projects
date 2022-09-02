#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Headers.h"
struct _status
{
    int *array;
    int len;
};
#include "common.c"
#include "players.c"
#include "SmartComputer.c"
#include "EvilComputer.c"

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    int Quit_Play = 1;
    char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    int symbol;
    
    while (1)
    {
        SetColor(4);
        printf("\n1. Play With Smart Computer");
        printf("\n2. Play With Evil Computer");
        printf("\n3. Play With Second Player");
        printf("\n4. EXIT");
        printf("\n----------------------------------");
        SetColor(14);
        printf("\n\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            playWthSmrtCom(board);    
        break;
    
        case 2:    
            plyWthEvilComp(board);
        break;

        case 3:
            playWithPlayer(board);
        break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice !....Choose Relevant");
        }
        
        system("cls");
        symbol = 49;
        for (size_t i = 0; i < 3; i++)
            for (size_t j = 0; j < 3; j++)
                board [i][j] = symbol++;
    }
}


