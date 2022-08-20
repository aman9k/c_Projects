void start_game(int matrix [][4])
{
    int t,flag;
    int ch1, ch2;
    char name[20];
    int moves=400;
    printf("Enter Your  Name : ");
    scanf("%s",name);
    while (1)
    {
        SetColor(14);
        system("cls");
        if(moves!=0){
            printf("Hello %s -- Moves remaining : %d\n",name,moves);
            printf("Press  ( E or e ) to Exit\n");
            printf("------------------------------------------------\n\n");
        }
        else{
            printf("You are out of moves....\n");
            printf("You loose ....Try Again\n\n");
            getch();
            exit(0);
        }
        display(matrix);
        ch1 = getch();
        ch2 = 0;
        if (ch1 == 0xE0)
        { 
            // a arrow key was pressed
            ch2 = getch();
            // determine what it was
            switch(ch2)
            {
                case 72:
                    //printf("UP WAS PRESSED\n");
                    flag=0;
                    for (size_t i = 0; i < 4; i++)
                    {
                        for (size_t j = 0; j < 4; j++)
                        {
                            if(matrix [0][j] == ' '){
                                flag=1;
                                break;
                            }
                            else if(matrix [i][j] == ' '){
                                t = matrix [i][j];
                                matrix [i][j] = matrix [i-1][j];
                                matrix [i-1][j] = t;
                                flag=1;
                                break;
                            }
                        }
                        if(flag == 1)
                            break;
                    }
                break;

                case 80:
                    //printf("DOWN WAS PRESSED\n");
                    flag=0;
                    for (size_t i = 0; i < 4; i++)
                    {
                        for (size_t j = 0; j < 4; j++)
                        {
                            if(matrix [3][j] == ' '){
                                flag=1;
                                break;
                            }
                            else if(matrix [i][j] == ' '){
                                t = matrix [i][j];
                                matrix [i][j] = matrix [i+1][j];
                                matrix [i+1][j] = t;
                                flag=1;
                                break;
                            }
                        }
                        if(flag == 1)
                            break;
                    }
                break;

                case 75: 
                    //printf("LEFT WAS PRESSED\n"); 
                    flag=0;
                    for (size_t i = 0; i < 4; i++)
                    {
                        for (size_t j = 0; j < 4; j++)
                        {
                            if(matrix [i] [0] == ' '){
                                flag=1;
                                break;
                            }
                            else if(matrix [i] [j] == ' '){
                                t = matrix[i] [j];
                                matrix[i] [j] = matrix[i] [j-1];
                                matrix[i] [j-1] = t;
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1)
                            break;
                    }
                break;

                case 77:
                    //printf("RIGHT WAS PRESSED\n"); 
                    flag=0;
                    for (size_t i = 0; i < 4; i++)
                    {
                        for (size_t j = 0; j < 4; j++)
                        {
                            if(matrix [i][3] == ' '){
                                flag=1;
                                break;
                            }
                            else if(matrix [i][j] == ' '){
                                t = matrix [i][j];
                                matrix [i][j] = matrix [i][j+1];
                                matrix [i][j+1] = t;
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1)
                            break;                    
                    }
                break; 
            }
        }
        else if(ch1 == 'E' || ch1 == 'e')
            exit(0);
        moves--;
        if(winCon(matrix)){
            system("cls");
            display(matrix);
            printf("\n\n    You Win...Congratulation\n");
            getch();
            exit(0);
        }
    }
}

int winCon(int matrix [][4])
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++)
            if(matrix [i][j] > matrix [i][j+1])
                return 0;
    return 1;    
}

    