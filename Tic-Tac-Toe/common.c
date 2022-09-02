
void display(char board[][3])
{
    SetColor(14);
    printf("\n");
    printf(" ___________\n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t k = 0; k < 4; k++)
            printf("|   ");

        printf("\n");
        for (size_t j = 0; j < 3; j++)
        {
            SetColor(14);
            printf("| ");
            SetColor(15);
            printf("%c ",board[i][j]);
        }
   
        SetColor(14);
        printf("|");
        printf("\n");

        for (size_t k = 0; k < 3; k++)
            printf("|___");
        printf("|");
        printf("\n");
    }
}

int winCon( char board[][3], char mark )
{
    for (size_t i = 0; i < 3; i++)
    {   
        if( 
            mark == board [i][0] && mark == board [i][1] && mark == board [i][2] 
            ||
            mark == board [0][i] && mark == board [1][i] && mark == board [2][i]
            ||
            mark == board [0][0] && mark == board [1][1] && mark == board [2][2]
            ||
            mark == board [0][2] && mark == board [1][1] && mark == board [2][0] 
        ) 
        return 1;
    }
    return 0;
}

int _Termi_Conti()  // terminate & continue
{
    SetColor(10); 
    while (1)
    {
        printf("\n\nPlay Again : Press 'Y'   or   QUIT : Press 'E'     : ");
        fflush(stdin);
        switch (getchar())
        {
        case 'e':
        case 'E':
            exit(0);
        case 'y':
        case 'Y':
            return 1;
        }
    }  
}

char* cnfrmToPlyWthComp() // confirm to play with smart computer or Evil computer 
{
    SetColor(2);
    char *plyrName=NULL;
    {
        char name[100];
        int nameLen;
        fflush(stdin);
        printf("\nPlayer Name : ");
        fgets(name,100,stdin);

        nameLen = strlen( name );
        name[nameLen-1] = name[nameLen];
        plyrName = (char*)malloc( sizeof(char) * nameLen);
        if(plyrName == NULL)
            exit(1);
        //nameLen = strlen( name );

        strcpy( plyrName, name );
    }
    SetColor(14);
    printf("\nPress 'ENTER' To Continue");
    printf("\nPress 'E' or 'e' To EXIT\n");

    while (1)
    {
        switch ( getchar() )
        {
        case '\n':
             return plyrName;
        case 'e':
        case 'E':
            exit(0);
            
        default :
            printf("\nPress Only ( 'E' or 'e' or 'ENTER' )");
        }
        fflush(stdin);
    }
}

int player_move(char board [][3], struct _status *movesStatus, char *plyrName)
{
    int move;
    int flag;
    while (1)
    {
        system("cls");
        display(board);
        SetColor(15);
        flag = 0;
        printf("\n%s's Move : ",plyrName);  
        scanf( "%d", &move);
        if( move >= 1 && move <= 9)
        {
            for (size_t i = 0; i < movesStatus -> len ; i++) {
                if( move == movesStatus -> array [i] ) {
                    flag = 1;
                    break;
                }
            }
            
            if( flag )
                continue;
            
            switch (move)
            {
            case 1:
                board [0][0] = 'O';
                break;
            case 2:
                board [0][1] = 'O';
                break;
            case 3:
                board [0][2] = 'O';
                break;
            case 4:
                board [1][0] = 'O';
                break;
            case 5:
                board [1][1] = 'O';
                break;
            case 6:
                board [1][2] = 'O';
                break;
            case 7:
                board [2][0] = 'O';
                break;
            case 8:
                board [2][1] = 'O';
                break;
            case 9:
                board [2][2] = 'O';
                break;
            }
            if ( winCon(board, 'O') )
                return 1; 
            movesStatus -> array[movesStatus -> len] = move;
            movesStatus -> len ++;
            return 0;
        }
    }
    // printf("\nLoop Broken");
}

int chk_pair_poss(char board [][3]) // cheking pair possibility
{
    // first row
    if( board [0][0] == board [0][1] && board [0][1] != board [0][2] && board [0][2] != 'O' && board [0][2] != 'X' ) 
        return 3;
    // reverse first row
    if( 'X' != board [0][0] && 'O' != board [0][0] && board [0][0] != board [0][1] && board [0][1] == board [0][2] ) 
        return 1;
    // second row
    if( board [1][0] == board [1][1] && board [1][1] != board [1][2] && board [1][2] != 'O'  && board [1][2] != 'X' ) 
        return 6;
    // reverse second row 
    if( 'X' != board [1][0] && 'O' != board [1][0] && board [1][0] != board [1][1] && board [1][1] == board [1][2] ) 
        return 4;
    // third row
    if( board [2][0] == board [2][1] && board [2][1] != board [2][2] && board [2][2] != 'O' && board [2][2] != 'X' )  
        return 9;
    // reverse third row 
    if( 'X' != board [2][0] && 'O' != board [2][0] && board [2][0] != board [2][1] && board [2][1] == board [2][2] ) 
        return 7;


    // first column 
    if( board [0][0] == board [1][0] && board [1][0] != board [2][0] && board [2][0] != 'O' && board [2][0] != 'X' ) 
        return 7;
    // reverse first column 
    if( board [2][0] == board [1][0] && board [1][0] != board [0][0] && board [0][0] != 'O' && board [0][0] != 'X' ) 
        return 1;
    // second column 
    if( board [0][1] == board [1][1] && board [1][1] != board [2][1] && board [2][1] != 'O' && board [2][1] != 'X' ) 
        return 8;
    // reverse second column 
    if( board [2][1] == board [1][1] && board [1][1] != board [0][1] && board [0][1] != 'O' && board [0][1] != 'X' ) 
        return 2;
    // third column 
    if( board [0][2] == board [1][2] && board [1][2] != board [2][2] && board [2][2] != 'O' && board [2][2] != 'X' ) 
        return 9;
    // reverse third column 
    if( board [2][2] == board [1][2] && board [1][2] != board [0][2] && board [0][2] != 'O' && board [0][2] != 'X' ) 
        return 3;


    // right diagonally  
    if( board [0][0] == board [1][1] && board [1][1] != board [2][2] && board [2][2] != 'O' && board [2][2] != 'X' ) 
        return 9;
    // reverse right diagonally
    if( board [2][2] == board [1][1] && board [1][1] != board [0][0] && board [0][0] != 'O' && board [0][0] != 'X' ) 
        return 1;


    // left diagonally
    if( board [0][2] == board [1][1] && board [1][1] != board [2][0] && board [2][0] != 'O' && board [2][0] != 'X' ) 
        return 7;
    // reverse left diagonally
    if( board [2][0] == board [1][1] && board [1][1] != board [0][2] && board [0][2] != 'O' && board [0][2] != 'X' ) 
        return 3;
    

    // in between first row
    if( board [0][0] != board [0][1] && board [0][1] != 'O' && board [0][1] != 'X' && board [0][0] == board [0][2] ) 
        return 2;
    
    // in between second row
    if( board [1][0] != board [1][1] && board [1][1] != 'O' && board [1][1] != 'X' && board [1][0] == board [1][2] ) 
        return 5;

    // in between third row
    if( board [2][0] != board [2][1] && board [2][1] != 'O' && board [2][1] != 'X' && board [2][0] == board [2][2] ) 
        return 8;

    
    // in between first column
    if( board [0][0] != board [1][0] && board [1][0] != 'O' && board [1][0] != 'X' && board [0][0] == board [2][0] ) 
        return 4;

    // in between second column
    if( board [0][1] != board [1][1] && board [1][1] != 'O' && board [1][1] != 'X' && board [0][1] == board [2][1] ) 
        return 5;

    // in between third column
    if( board [0][2] != board [1][2] && board [1][2] != 'O' && board [1][2] != 'X' && board [0][2] == board [2][2] ) 
        return 6;

    // in between left diagonally
    if( board [0][2] != board [1][1] && board [1][1] != 'O' && board [1][1] != 'X' && board [0][2] == board [2][0] ) 
        return 5;

    // in between right diagonally
    if( board [0][0] != board [1][1] && board [1][1] != 'O' && board [1][1] != 'X' && board [0][0] == board [2][2] ) 
        return 5;

    return 0;
}

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

