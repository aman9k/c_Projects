int computer_move(char [][3], struct _status *);

int playWthSmrtCom(char board [][3])
{


    char *plyrName = cnfrmToPlyWthComp();
    struct _status *movesStatus = (struct _status*) malloc( sizeof(struct _status));
    movesStatus -> array = (int*) malloc( sizeof(int) * 9);
    movesStatus -> len = 0;
    
    int plyr, comp;
    int i=1;
    while (1)
    {
        plyr = player_move(board, movesStatus, plyrName);
        if(i==5 || plyr)
            break;
        comp = computer_move(board, movesStatus);
        if( comp )
            break;
        i++;
    }

    // for (size_t i = 0; i < movesStatus->len; i++)
    // {
    //     printf("  %d  ",movesStatus->array[i]);
    // }
    
    system("cls");
    display(board);

    SetColor(15);
    // Result 
    if( plyr )
        printf("\n%s won :",plyrName);
    else if( comp )
        printf("\nSmartComputer won :");
    else
        printf("\nMatch Draw");

    // freeing up Dynamically Allocated Memory
    free( plyrName );
    free(movesStatus -> array);
    free( movesStatus );

    return _Termi_Conti();    

}


int computer_move(char board [][3], struct _status *movesStatus)
{
    int move;
    int flag;
    int _tmove;
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


        _tmove = chk_pair_poss(board);

        if(_tmove )
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
        if( winCon(board, 'X'))
            return 1;
        movesStatus -> array [movesStatus -> len] = move;
        movesStatus -> len ++;
        return 0;
    }
}

