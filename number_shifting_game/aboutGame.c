void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

void game_rules(int matrix [] [4])
{
    int sortMatrix [4] [4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sortMatrix [i] [j] = matrix [i] [j];
    SetColor(14);
    printf("---- Rule For This Game ----\n");
    SetColor(4);
    printf("1. You can move only 1 step at a time with the arrow key.\n");
    printf("Move Up     :   by up arrow key\n");
    printf("Move down   :   by down arrow key\n");
    printf("Move left   :   by left arrow key\n");
    printf("Move right  :   by right arrow key\n\n");
    printf("2. You can move numbers at an empty position only.\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n\n");
    printf("4. Winning Situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");

  
    sort(sortMatrix);
    display(sortMatrix);
    SetColor(4);
    printf("\n5. You can exit the game at any time by pressing 'E' or 'e'\n");
    SetColor(14);
    printf("So try to win in minimum no of move\n");
    SetColor(14);
    printf("\n\nHappy Gaming , Good Luck\n");
    printf("\n\nPress any key to start....\n");
    printf("Press ( E or e ) to exit....\n");
    
    char ch=getch();
    if(ch=='E'||ch=='e')
        exit(0);
    system("cls");

    // printf("Enter Your Name : ");
    // getch();
}

void sort(int arr[][4]) 
{
	int i, j, temp;

	for (i = 0; i < 4 * 4 - 1; ++i) 
		for (j = 0; j < 4 * 4 - 1 - i; ++j) 
		    if (arr[j / 4][j % 4] > arr[(j + 1) / 4][(j + 1) % 4]) 
            {
		    	temp = arr[(j + 1) / 4][(j + 1) % 4];
		    	arr[(j + 1) / 4][(j + 1) % 4] = arr[j / 4][j % 4];
		    	arr[j / 4][j % 4] = temp;
		    }
}

void display(int matrix[][4])
{
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        SetColor(14);
        printf("   ------------------------------------\n");    
    	for (j = 0; j < 4; ++j) 
    	{
            SetColor(14);
            printf("   |");
            if(matrix[i][j]==' '){
                SetColor(2);
                printf("%5c", matrix [i] [j] );
            }
            else{
                SetColor(2);
                printf("%5d",matrix [i] [j] );
            }
        }
        SetColor(14);
        printf("  |");
    	printf("\n");
    }
    printf("   ------------------------------------\n");    
}


