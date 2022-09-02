int evil_comp_move(char [][3], struct _status *);
int* cheating_possibility(char [][3]);

int plyWthEvilComp(char board [][3])
{
    char *plyrName = cnfrmToPlyWthComp();
    struct _status *movesStatus = (struct _status*) malloc( sizeof(struct _status));
    movesStatus -> array = (int*) malloc( sizeof(int) * 9);
    movesStatus -> len = 0;


    int plyr, _evilComp;
    int i=1;
    while (1)
    {
        plyr = player_move(board, movesStatus, plyrName);
        if(i==5 || plyr)
            break;
        _evilComp = evil_comp_move(board, movesStatus);
        if( _evilComp )
            break;
        i++;
    }
    system("cls");
    display(board);

    SetColor(15);
    // Result 
    if( plyr )
        printf("\n%s won :",plyrName);
    else if( _evilComp )
        printf("\nEvil Computer won :");
    else
        printf("\nMatch Draw");

    // for (size_t i = 0; i < movesStatus->len; i++)
    // {
    //     printf("  %d  ",movesStatus->array[i]);
    // }

    // freeing up Dynamically Allocated Memory
    free( plyrName );
    free(movesStatus -> array);
    free( movesStatus );
   
    return _Termi_Conti();

}


int evil_comp_move(char board [][3], struct _status *movesStatus)
{
    int move;
    int flag;
    int _tmove;
    int *_Etmove;
    srand(time(0));
    while (1)
    {
        flag = 0;
        move = (rand() % (9 - 1 + 1)) + 1;   // upper = 9  ----  lower = 1  

        for (size_t i = 0; i < movesStatus -> len; i++) {
            if(move == movesStatus -> array[i]) {
                flag = 1;
                break;
            }
        }
        if(flag)
            continue;
        
        // evil computer cheaking cheating cases 
        _Etmove = cheating_possibility(board) ;
        
        if (_Etmove != NULL)
        {
             
            // right & left L
            if(_Etmove[0] == 5 && _Etmove[1] == 8 )
            {
                board [1][1] = 'X';
                board [2][1] = 'X';

            }
            // grater than >
            else if(_Etmove[0] == 3 && _Etmove[1] == 9 )
            {
                board [0][2] = 'X';
                board [2][2] = 'X';  

            }
            // less than <
            else if(_Etmove[0] == 1 && _Etmove[1] == 7)
            {
                board [0][0] = 'X';
                board [2][0] = 'X';

            }
            // down \/
            else if(_Etmove[0] == 7 && _Etmove[1] == 9)
            {
                board [2][0] = 'X';
                board [2][2] = 'X';

            }
            /* /\ */
            else if(_Etmove[0] == 1 && _Etmove[1] == 3)
            {
                board [0][0] = 'X';
                board [0][2] = 'X';

            }
            else if( _Etmove[0] == 4 && _Etmove[1] == 5 )
            {
                board [1][0] = 'X';
                board [1][1] = 'X';
            }
            else if( _Etmove[0] == 2 && _Etmove[1] == 5 )
            {
                board [0][1] = 'X';
                board [1][1] = 'X';
            }
            else if( _Etmove[0] == 5 && _Etmove[1] == 6 )
            {
                board [1][1] = 'X';
                board [1][2] = 'X';
            }
            else if( _Etmove[0] == 4 && _Etmove[1] == 8 )
            {
                board [1][0] = 'X';
                board [2][1] = 'X';
            }
            else if( _Etmove[0] == 2 && _Etmove[1] == 6 )
            {
                board [0][1] = 'X';
                board [1][2] = 'X';
            }
            else if( _Etmove[0] == 2 && _Etmove[1] == 7 )
            {
                board [0][1] = 'X';
                board [2][0] = 'X';
            } 
            else if(_Etmove[0] == 1 && _Etmove[1] == 8)
            {
                board [0][0] = 'X';
                board [2][1] = 'X';

            }
            else if(_Etmove[0] == 2 && _Etmove[1] == 4)
            {
                board [0][1] = 'X';
                board [1][0] = 'X';

            }
            else if(_Etmove[0] == 6 && _Etmove[1] == 8)
            {
                board [1][2] = 'X';
                board [2][1] = 'X';

            }
            movesStatus -> array [movesStatus -> len] = _Etmove[0];
            movesStatus -> len ++;

            movesStatus -> array [movesStatus -> len] = _Etmove[1];
            movesStatus -> len ++;
           
            free(_Etmove);
        }
        else
        { 
            _tmove = chk_pair_poss(board);

            if(_tmove) 
                move = _tmove; 

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
       
            movesStatus -> array [movesStatus -> len] = move;
            movesStatus -> len ++;
        }

        if( winCon(board, 'X'))
            return 1;
        return 0;
    }
}


int* cheating_possibility(char board [][3])
{
    
    int *position = (int*) calloc(2,sizeof(int));
    /* left L */ 
    if( board [0][2] == board [2][0] && board [2][0] == board [2][2] && board [1][1] != 'X' && board [2][1] != 'X' )
    {
        position[0] = 5;
        position[1] = 8;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    /* right L case 1*/ 
    if(board [0][0] == board [2][0] && board [2][0] == board [2][2] && board [1][1] != 'X' && board [2][1] != 'X' )
    {
        position[0] = 5;
        position[1] = 8;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    /* right L case 2*/ 
    if(board [0][0] == board [2][0] && board [2][0] == board [2][2] && board [1][0] != 'X' && board [1][1] != 'X' )
    {
        position[0] = 4;
        position[1] = 5;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }

    /* greater than '>' */
    if( board [0][0] == board [1][1] && board [0][0] == board [2][0] && board [0][2] != 'X' && board [2][2] != 'X' )
    {
        position[0] = 3;
        position[1] = 9;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }


    /* less than '<' */ 
    if( board [0][2] == board [1][1] && board [0][2] == board [2][2] && board [0][0] != 'X' && board [2][0] != 'X' )
    {
        position[0] = 1;
        position[1] = 7;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }

    /* down '\/'  case 1*/
    if( board [0][0] == board [0][2] && board [0][0] == board [1][1] && board [2][0] != 'X' && board [2][2] != 'X' )
    {
        position[0] = 7;
        position[1] = 9;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
     /* down '\/' case 2*/
    if( board [0][0] == board [0][2] && board [0][0] == board [1][1] && board [2][0] != 'X' && board [0][1] != 'X' )
    {
        position[0] = 2;
        position[1] = 7;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    /* up '/\' case 1*/ 
    if( board [2][0] == board [1][1] && board [2][0] == board [2][2] && board [0][0] != 'X' && board [0][2] != 'X' )
    {
        position[0] = 1;
        position[1] = 3;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    /* up '/\' case 2*/ 
    if( board [2][0] == board [1][1] && board [2][0] == board [2][2] && board [0][0] != 'X' && board [2][1] != 'X' )
    {
        position[0] = 1;
        position[1] = 8;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }

    // right reverse L case 1
    if( board [0][0] == board [2][0] && board [2][0] == board [0][2] && board [0][1] == 'X' && board [1][0] != 'X' && board [1][1] != 'X' )
    {
        position[0] = 4;
        position[1] = 5;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }

    // right reverse L case 2
    if( board [0][0] == board [2][0] && board [2][0] == board [0][2] && board [0][1] != 'X' && board [1][1] != 'X' && board [1][0] == 'X')
    {
        position[0] = 2;
        position[1] = 5;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    /////////////////
    // right L case 3
    if( board [0][0] == board [2][0] && board [2][0] == board [0][2] && board [0][1] != 'X' && board [1][0] != 'X' && board [1][1] == 'X' )
    {
        position[0] = 2;
        position[1] = 4;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    // left L case 2
    if( board [0][2] == board [2][0] && board [2][0] == board [2][2] && board [1][2] != 'X' && board [2][1] != 'X' && board [1][1] == 'X' )
    {
        position[0] = 6;
        position[1] = 8;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    // left reverse L case 1
    if( board [0][0] == board [0][2] && board [0][2] == board [2][2] && board [0][1] == 'X' && board [1][1] != 'X' && board [1][2] != 'X')
    {
        position[0] = 5;
        position[1] = 6;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }
    // left reverse L case 2
    if( board [0][0] == board [0][2] && board [0][2] == board [2][2] && board [1][2] == 'X' && board [0][1] != 'X' && board [1][1] != 'X' )
    {
        position[0] = 2;
        position[1] = 5;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;
    }

    if( board [0][0] == board [2][0] && board [2][0] == board [2][2] && board [1][1] == 'X' && board [1][0] != 'X' && board [2][1] != 'X')
    {
        position[0] = 4;
        position[1] = 8;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;

    }
    if( board [0][0] == board [0][2] && board [0][2] == board [2][2] && board [1][1] == 'X' && board [0][1] != 'X' && board [1][2] != 'X')
    {
        position[0] = 2;
        position[1] = 6;
        // printf("\n---%d   %d---\n",position[0],position[1]);
        //     getch();
        return position;

    }

    // printf("\n---null---\n");
    //         getch();
    free(position);
    return NULL;

}
