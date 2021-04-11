#include <stdio.h>

void startBoard();
void verifyBoard();
void updateBoard(const char squareOnBoard, const char player);
void humanPlay(const char player);
void computerPlay();

int board[3][3], gameCount, playAgain;
char playAgainScan, playerXO1, playerXO2, singleMultiPlayer, boardViewXO[9], boardViewNum[9];

int main() { 

    playAgain = 1;

    startBoard();  

    while(playAgain != 0) {
        
        if(gameCount%2 == 0) {
            
            humanPlay(1);

        }else {
            
            if( singleMultiPlayer == 'm' || singleMultiPlayer == 'M') {
                
                 humanPlay(2);

            }else {

                //computerPlay();

            }
            
        }

        if(board[2][2] != 0){

            printf("Do you want to play again?(Y/N) \n");
            scanf("%c", &playAgainScan);
            getchar();
            
            if(playAgainScan == 'n' || playAgainScan == 'N') {

                playAgain = 0;

            }else {

                playAgain++;
                startBoard();

            }

        }  

    }
 
    printf("Thanks for playing! \n");
    system("pause");

    return 0;
}

void startBoard() {
    
    int i, j;

    gameCount = 0;

    if(playAgain == 1){
        
        playerXO1 = 0;

    }

    for(i = 0; i < 3; i++) {
        
        for(j = 0; j < 3; j++) {
            
            board[i][j] = 0;

        }
    }

    for(i = 0; i < 6; i++){

        boardViewXO[i] = '_';
        boardViewNum[i] = (i + 1) + '0';
    }

    for(i = 6; i < 9; i++){

        boardViewXO[i] = ' ';
        boardViewNum[i] = (i + 1) + '0';
    }

    system("cls");
    printf("\nNew Game start!\n");
    
    if(playerXO1 == 0) {
        
        while(playerXO1 == 0) {

            printf("Is thes game Single(S) or Multiplayer(M)? \n");  
            scanf("%c", &singleMultiPlayer);
            getchar();

            if(singleMultiPlayer == 's' || singleMultiPlayer == 'S' || singleMultiPlayer == 'm' || singleMultiPlayer == 'M'){
                
                while(playerXO1 == 0){   
                    printf("Are you chose X or O?\n");
                    scanf("%c", &playerXO1);
                    getchar();

                    if(playerXO1 == 'x' || playerXO1 == 'X'){
                        
                        playerXO1 = 'X';
                        playerXO2 = 'O';

                    }else if(playerXO1 == 'o' || playerXO1 == 'O') {
                        
                        playerXO1 = 'O';
                        playerXO2 = 'X';

                    }else {

                        printf("Input a valid value\n");
                        playerXO1 = 0;
                        
                    }
                }

            }else {
                
                printf("Input a valid value\n");
                
            }
            
        } 

    }

    updateBoard(0, 0);
    printf("\nHave a good game!\n");
    
    return;

}

void updateBoard(const char squareOnBoard, const char player) {

    if(player == 1){

        switch (squareOnBoard) {
            case 1:

                boardViewXO[0] = playerXO1;
                boardViewNum[0] = '_';

            break;

            case 2:

                boardViewXO[1] = playerXO1;
                boardViewNum[1] = '_';

            break;

            case 3:

                boardViewXO[2] = playerXO1;
                boardViewNum[2] = '_';

            break;

            case 4:

                boardViewXO[3] = playerXO1;
                boardViewNum[3] = '_';

            break;

            case 5:

                boardViewXO[4] = playerXO1;
                boardViewNum[4] = '_';

            break;

            case 6:

                boardViewXO[5] = playerXO1;
                boardViewNum[5] = '_';

            break;

            case 7:

                boardViewXO[6] = playerXO1;
                boardViewNum[6] = ' ';

            break;

            case 8:

                boardViewXO[7] = playerXO1;
                boardViewNum[7] = ' ';

            break;

            case 9:

                boardViewXO[8] = playerXO1;
                boardViewNum[8] = ' ';

            break;
        }

    } else if(player == 2){

        switch (squareOnBoard) {
            case 1:

                boardViewXO[0] = playerXO2;
                boardViewNum[0] = '_';

            break;

            case 2:

                boardViewXO[1] = playerXO2;
                boardViewNum[1] = '_';

            break;

            case 3:

                boardViewXO[2] = playerXO2;
                boardViewNum[2] = '_';

            break;

            case 4:

                boardViewXO[3] = playerXO2;
                boardViewNum[3] = '_';

            break;

            case 5:

                boardViewXO[4] = playerXO2;
                boardViewNum[4] = '_';

            break;

            case 6:

                boardViewXO[5] = playerXO2;
                boardViewNum[5] = '_';

            break;

            case 7:

                boardViewXO[6] = playerXO2;
                boardViewNum[6] = ' ';

            break;

            case 8:

                boardViewXO[7] = playerXO2;
                boardViewNum[7] = ' ';

            break;

            case 9:

                boardViewXO[8] = playerXO2;
                boardViewNum[8] = ' ';

            break;
        }
        
    }

    system("cls");

    printf("_%c_|_%c_|_%c_      _%c_|_%c_|_%c_\n", boardViewXO[0], boardViewXO[1], boardViewXO[2], boardViewNum[0], boardViewNum[1], boardViewNum[2]);
    printf("_%c_|_%c_|_%c_      _%c_|_%c_|_%c_\n", boardViewXO[3], boardViewXO[4], boardViewXO[5], boardViewNum[3], boardViewNum[4], boardViewNum[5]);
    printf(" %c | %c | %c        %c | %c | %c \n", boardViewXO[6], boardViewXO[7], boardViewXO[8], boardViewNum[6], boardViewNum[7], boardViewNum[8]);

}

void verifyBoard() {

}

void humanPlay(const char player) {

    int play = 0;
    if(player == 1){

        printf("Player 1 chose a number for your play: \n");
        scanf("%d", &play);
        getchar();

    }else {

        printf("Player 2 chose a number for your play: \n");
        scanf("%d", &play);
        getchar();

    }
    
    gameCount++;

    switch(play) {
        
        case 1:
            if(board[0][0] == 0){

                board[0][0] = player;
                updateBoard(1, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");
                    
            }
        break;

        case 2:
            if(board[0][1] == 0){

                board[0][1] = player;
                updateBoard(2, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            }     
        break;

        case 3:
            if(board[0][2] == 0){

                board[0][2] = player;
                updateBoard(3, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            }                
        break;

        case 4:
               if(board[1][0] == 0){

                board[1][0] = player;
                updateBoard(4, player); 

            }else {

                gameCount--;
                printf("This square have been used!\n");

            } 
        break;

        case 5:
            if(board[1][1] == 0){

                board[1][1] = player;
                updateBoard(5, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            } 
        break;

        case 6:
            if(board[1][2] == 0){

                board[1][2] = player;
                updateBoard(6, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            }     
        break;

        case 7:
            if(board[2][0] == 0){

                board[2][0] = player;
                updateBoard(7, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            } 
        break;

        case 8:
            if(board[2][1] == 0){

                board[2][1] = player;
                updateBoard(8, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            }    
        break;

        case 9:
            if(board[2][2] == 0){

                board[2][2] = player;
                updateBoard(9, player);

            }else {

                gameCount--;
                printf("This square have been used!\n");

            }
        break;

    }

    return;
}