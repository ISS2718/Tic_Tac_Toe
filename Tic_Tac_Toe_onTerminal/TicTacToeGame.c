#include <stdio.h>

void startBoard();
void verifyBoard();
void humanPlay(const char player);
void computerPlay();
 

int Board[3][3];
int gameCount;
char XorO = 0, players;

int main() { 
    
    startBoard();
    printf("%c\n", players);
    printf("%c\n", XorO);
    printf("%d\n", gameCount);
    printf("%d\n", gameCount);

    while(Board[2][2] == 0){
        
        humanPlay(1);
        printf("%d\n", gameCount);

    }
    return 0;
}

void startBoard(){
    
    gameCount = 0;

    for(int i = 0; i < 2; i++){
        
        for(int j = 0; j < 2; j++){
            
            Board[i][j] = 0;

        }
    }

    system("cls");
    printf("\nNew Game start!\n");
    
    if(XorO == 0){
        
        while(XorO == 0){

            printf("Is thes game Single(S) or Multiplayer(M)? \n");  
            scanf("%c", &players);
            getchar();

            if(players == 's' || players == 'S' || players == 'm' || players == 'M'){
                
                while(XorO == 0){   
                    printf("Are you chose X or O?\n");
                    scanf("%c", &XorO);
                    getchar();

                    if(XorO == 'x' || XorO == 'X' || XorO == 'o' || XorO == 'O'){
                        XorO = XorO;
                    }else {
                        XorO = 0;
                    }
                }

            }else {
                printf("Input a valid value\n");
            }
            
        } 

    }

    system("cls");

    printf("___|___|___      _1_|_2_|_3_\n");
    printf("___|___|___      _4_|_5_|_6_\n");
    printf("   |   |          7 | 8 | 9 \n");
    printf("\nHave a good game!\n");
    
    return;

}

void verifyBoard(){

}

void humanPlay(const char player){

    int play = 0;
    printf("Chose a number for your play: \n");
    scanf("%d", &play);
    
    gameCount++;
    
    if(player == 1){
        switch(play){
        
            case 1:
                if(Board[0][0] == 0){

                    Board[0][0] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");
                    
                }
            break;

            case 2:
                if(Board[0][1] == 0){

                    Board[0][1] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }     
            break;

            case 3:
                if(Board[0][2] == 0){

                    Board[0][2] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }                
            break;

            case 4:
                if(Board[1][0] == 0){

                    Board[1][0] = 1; 

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                } 
            break;

            case 5:
                if(Board[1][1] == 0){

                    Board[1][1] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                } 
            break;

            case 6:
                if(Board[1][2] == 0){

                    Board[1][2] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }     
            break;

            case 7:
                if(Board[2][0] == 0){

                    Board[2][0] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                } 
            break;

            case 8:
                if(Board[2][1] == 0){

                    Board[2][1] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }    
            break;

            case 9:
                if(Board[2][2] == 0){

                    Board[2][2] = 1;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
            break;

        }
    
    }else if(player == 2){
        switch(play){
        
            case 1:
                if(Board[1][1] == 0){

                    Board[1][1] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
            break;

            case 2:
                if(Board[1][2] == 0){

                    Board[1][2] = 2;
                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }     
            break;

            case 3:
                if(Board[1][3] == 0){

                    Board[1][3] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }              
            break;

            case 4:
                if(Board[2][1] == 0){

                    Board[2][1] = 2; 

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
             break;

            case 5:
                if(Board[2][2] == 0){

                    Board[2][2] = 2;
                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
            break;

            case 6:
                if(Board[2][3] == 0){

                    Board[2][3] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");
                    
                }
            break;

            case 7:
                if(Board[3][1] == 0){

                    Board[3][1] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
            break;

            case 8:
                if(Board[3][2] == 0){

                    Board[3][2] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
            break;

            case 9:
                if(Board[3][3] == 0){

                    Board[3][3] = 2;

                }else {

                    gameCount--;
                    printf("This square have been used!\n");

                }
            break;

        }
    
    }

    return;
}