int runMove(char [][3], char*, struct _status*, char**); 
char** confirmToPlay();

int playWithPlayer( char board[][3] )
{
    
    char **plyrsName = confirmToPlay(board);
    
    
    printf("\n%s  X", plyrsName [0]);    
    printf("\n%s  O", plyrsName [1]);    
    
    
    struct _status *moves_status = ( struct _status* ) malloc( sizeof( struct _status ) );
    moves_status -> array = (int*) malloc( sizeof(int) * 9);
    moves_status -> len = 0;

    int i = 1, Quit_Play; // Quit_Play means terminate & continue
    while (1)
    {
        Quit_Play = runMove(board, plyrsName[0], moves_status, plyrsName);
        if( Quit_Play )
        {
            //freeing players name container 
            free(plyrsName[0]);
            free(plyrsName[1]);
            free(plyrsName);

            // freeing moves status container
            free(moves_status->array);
            free(moves_status);
            return Quit_Play;
        }

        if(i==5)
            break;

        Quit_Play = runMove(board, plyrsName[1], moves_status, plyrsName);
        if( Quit_Play )
        {
            //freeing players name container 
            free(plyrsName[0]);
            free(plyrsName[1]);
            free(plyrsName);

            // freeing moves status container
            free(moves_status->array);
            free(moves_status);
            return Quit_Play;
        }
        i++;
    }
    system("cls");
    display(board);
    printf("\nDraw Match :");
    
    //freeing players name container 
    free(plyrsName[0]);
    free(plyrsName[1]);
    free(plyrsName);

    // freeing moves status container
    free(moves_status->array);
    free(moves_status);
    
    return _Termi_Conti();
    //printf("\nRun Successful");
}

int runMove(char board[][3], char *_plyr, struct _status *moves_status, char **plyrsName) 
{
    int move, flag;
    while (1)
    {
        system("cls");
        display(board);
        flag = 0;
        SetColor(15);

        printf("\n%s's Move : ", _plyr);
        scanf( "%d", &move);

        if( move >= 1 && move <= 9)
        {
            for (size_t i = 0; i < moves_status -> len ; i++) {
                if( move == moves_status -> array [i] ) {
                    flag = 1;
                    break;
                }
            }
            
            if( flag == 1 )
                continue;
            else
            {
                if( plyrsName [0] == _plyr ) 
                //printf("player 1");
                {
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
                    if(winCon( board,'O' ))
                    {
                        system("cls");
                        display(board);
                        SetColor(15);
                        printf("\n%s won",_plyr);
                        return _Termi_Conti();
                    }
                }
                else
                {
                    switch (move)
                    {
                    case 1:
                        board [0][0] = 'X';
                        break;
                    case 2:
                        board [0][1] = 'X';
                        break;
                    case 3:
                        board [0][2] = 'X';
                        break;
                    case 4:
                        board [1][0] = 'X';
                        break;
                    case 5:
                        board [1][1] = 'X';
                        break;
                    case 6:
                        board [1][2] = 'X';
                        break;
                    case 7:
                        board [2][0] = 'X';
                        break;
                    case 8:
                        board [2][1] = 'X';
                        break;
                    case 9:
                        board [2][2] = 'X';
                        break;
                    }
                    if(winCon(board,'X'))
                    {
                        system("cls");
                        display(board);
                        printf("\n%s won",_plyr);
                        return _Termi_Conti();
                    }
                }
                moves_status -> array[ moves_status -> len] = move;
                moves_status -> len ++;
            }
        return 0;
        }
    }
}

char** confirmToPlay(char board[][3])
{
    SetColor(2);
    char **plyrsName=NULL;
    {
        char name[2][100];
        int nameLen[2];
        fflush(stdin);
        printf("\nPlayer 1 Name : ");
        fgets(name[0],100,stdin);

        printf("\nPlayer 2 Name : ");
        fgets(name[1],100,stdin);

        nameLen[0] = strlen( name [0] );
        nameLen[1] = strlen( name[1] );
        
        // printf("%d   %d\n",nameLen[0], nameLen[1]);
        // printf("\n%s  %s",name[0],name[1]);

        name[0][nameLen[0]-1] = name[0][nameLen[0]];
        name[1][nameLen[1]-1] = name[1][nameLen[1]];

        // nameLen[0] = strlen( name [0] );
        // nameLen[1] = strlen( name[1] );


        // printf("%d   %d\n",nameLen[0], nameLen[1]);
        // printf("\n%s  %s",name[0],name[1]);

        plyrsName = (char**)malloc( sizeof(char*) * 2);

        plyrsName[0] = (char*) malloc ( sizeof(char) * nameLen[0] );
        if(plyrsName[0]==NULL)
            exit(1);

        plyrsName[1] = (char*) malloc ( sizeof(char) * nameLen[1] );
        if(plyrsName[1]==NULL)
            exit(1);

        strcpy( plyrsName[0], name[0] );
        strcpy( plyrsName[1], name[1] );
    }
    SetColor(14);
    printf("\nPress 'ENTER' To Continue");
    printf("\nPress 'E' or 'e' To EXIT\n");

    while (1)
    {
        switch ( getchar() )
        {
        case '\n':
             return plyrsName;

        case 'e':
        case 'E':
            exit(0);
            
        default :
            printf("\nPress Only ( 'E' or 'e' or 'ENTER' )");
        }
        fflush(stdin);
    }
}







