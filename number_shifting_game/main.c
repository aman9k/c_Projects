#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include "funDeclaration.h"
#include "aboutGame.c"
#include "gameLogic.c"

int main()
{
    // int matrix[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,' ',15}};
    int matrix[4][4]={{2,9,14,8},{3,1,5,7},{4,6,10,13},{12,11,15,' '}};
    display(matrix); 
    printf("\n\n");
    game_rules(matrix);
    system("cls");
    start_game(matrix);
    printf("\n\n");
    return 0;
}







