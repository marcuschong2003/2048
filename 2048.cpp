#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace ::std;
int gameBoard[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int gameBoard2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
bool cont=true;
string input;
string getlastfive(string input){
    string result = "";
    int length = input.length();
    for(int q=5;q>=1;q--){
        result = result + input[length-q];
    }
    return result;

}
void PrintGame(){
    for(int x=0;x<=3;x++){
        for(int y=0;y<=3;y++){
            string zeros = "     ";
            string stringtoprint = zeros + to_string(gameBoard[x][y]);
            cout<< getlastfive(stringtoprint);
            cout<< " ";
        }
        cout<<endl;
        cout<<endl;
    }
}
void Duplicate(){
    for(int x=0;x<=3;x++){
        for(int y=0;y<=3;y++){
            gameBoard2[x][y]=gameBoard[x][y];
        }
    }
}
bool CheckDuplicate(){
    bool duplicated = true;
    for(int x =0;x<=3;x++){
        for(int y=0;y<=3;y++){
            if(gameBoard2[x][y]!=gameBoard[x][y]){
                duplicated = false;
            }
        }
    }
    return duplicated;
}
void AddRandomNumber(){
    srand(time(0));
    int randx = (rand()%4);
    int randy = (rand()%4);
    bool add = false;
    int numberToAdd = 2*((rand()%2)+1);
    for(int x=0;x<=3;x++){
        for(int y=0;y<=3;y++){
            if(gameBoard[x][y]==0){
                add = true;
            }
        }
    }
    while(add){
        if(gameBoard[randx][randy]==0){
            gameBoard[randx][randy] = numberToAdd;
            add = false;
        }else{
            randx = (rand()%4);
            randy = (rand()%4);
        }
    }
}
void CheckLost(){
    bool lost = true;
    for(int x=0;x<=3;x++){
        for(int y=0;y<=3;y++){
            if(lost){
                if(gameBoard[x][y]==0){
                    lost = false;
                }
            }
        }
    }
    for(int x=0;x<=3;x++){
        for(int y =0;y<=2;y++){
            if(gameBoard[x][y]==gameBoard[x][y+1]){
                lost = false;
            }
        }
    }
    for(int x=0;x<=2;x++){
        for(int y=0;y<=3;y++){
            if(gameBoard[x][y]==gameBoard[x+1][y]){
                lost =false;
            }
        }
    }
    cont = !lost;
}
int main(){
    AddRandomNumber();
    AddRandomNumber();
    PrintGame();
    while (cont){
        cout<<"Enter 0 to end the game."<<endl;
        cin>>input;
        if(input=="0"){
            cont = false;
            exit(0);
        }
        if(input=="a"){
            Duplicate();
            for(int z=0;z<=2;z++){
                for(int x=0;x<=3;x++){
                    for(int y=0;y<=2;y++){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x][y+1];
                            gameBoard[x][y+1]=0;
                        }
                    }
                }
            }
            for(int x=0;x<=3;x++){
                for(int y=0;y<=2;y++){
                    if(gameBoard[x][y]==gameBoard[x][y+1]){
                        int number = gameBoard[x][y];
                        gameBoard[x][y] = 2*number;
                        gameBoard[x][y+1] = 0;
                    }
                }
            }
            for(int z=0;z<=2;z++){
                for(int x=0;x<=3;x++){
                    for(int y=0;y<=2;y++){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x][y+1];
                            gameBoard[x][y+1]=0;
                        }
                    }
                }
            }
            for(int z=0;z<=3;z++){
                if(gameBoard[z][1]==0){
                    gameBoard[z][1]=gameBoard[z][2];
                    gameBoard[z][2]=gameBoard[z][3];
                    gameBoard[z][3]=0;
                }
            }
            if(!CheckDuplicate()){
                AddRandomNumber();
            }
            PrintGame();
        }else if(input=="d"){
            Duplicate();
            for(int z=0;z<=2;z++){
                for(int x=0;x<=3;x++){
                    for(int y=3;y>=1;y--){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x][y-1];
                            gameBoard[x][y-1]=0;
                        }
                    }
                }
            }
            for(int x=0;x<=3;x++){
                for(int y=3;y>=1;y--){
                    if(gameBoard[x][y]==gameBoard[x][y-1]){
                        int number = gameBoard[x][y];
                        gameBoard[x][y] = 2*number;
                        gameBoard[x][y-1] = 0;
                    }
                }
            }
            for(int z=0;z<=2;z++){
                for(int x=0;x<=3;x++){
                    for(int y=3;y>=1;y--){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x][y-1];
                            gameBoard[x][y-1]=0;
                        }
                    }
                }
            }
            for(int z=0;z<=3;z++){
                if(gameBoard[z][2]==0){
                    gameBoard[z][2]=gameBoard[z][1];
                    gameBoard[z][1]=gameBoard[z][0];
                    gameBoard[z][0]=0;
                }
            }
            if(!CheckDuplicate()){
                AddRandomNumber();
            }
            PrintGame();
        }else if(input=="w"){
            Duplicate();
            for(int z=0;z<=2;z++){
                for(int y=0;y<=3;y++){
                    for(int x=0;x<=2;x++){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x+1][y];
                            gameBoard[x+1][y]=0;
                        }
                    }
                }
            }
            for(int y=0;y<=3;y++){
                for(int x=0;x<=2;x++){
                    if(gameBoard[x][y]==gameBoard[x+1][y]){
                        int number = gameBoard[x][y];
                        gameBoard[x][y] = 2*number;
                        gameBoard[x+1][y]=0;
                    }
                }
            }
            for(int z=0;z<=2;z++){
                for(int y=0;y<=3;y++){
                    for(int x=0;x<=2;x++){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x+1][y];
                            gameBoard[x+1][y]=0;
                        }
                    }
                }
            }
            for(int z=0;z<=3;z++){
                if(gameBoard[1][z]==0){
                    gameBoard[1][z]=gameBoard[2][z];
                    gameBoard[2][z]=gameBoard[3][z];
                    gameBoard[3][z]=0;
                }
            }
            if(!CheckDuplicate()){
                AddRandomNumber();
            }
            PrintGame();
        }else if(input == "s"){
            Duplicate();
            for(int z=0;z<=2;z++){
                for(int y=0;y<=3;y++){
                    for(int x=3;x>=1;x--){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x-1][y];
                            gameBoard[x-1][y]=0;
                        }
                    }
                }
            }
            for(int y=0;y<=3;y++){
                for(int x=3;x>=1;x--){
                    if(gameBoard[x][y]==gameBoard[x-1][y]){
                        int number = gameBoard[x][y];
                        gameBoard[x][y] = 2*number;
                        gameBoard[x-1][y]=0;
                    }
                }
            }
            for(int z=0;z<=2;z++){
                for(int y=0;y<=3;y++){
                    for(int x=3;x<=1;x--){
                        if(gameBoard[x][y]==0){
                            gameBoard[x][y]=gameBoard[x-1][y];
                            gameBoard[x-1][y]=0;
                        }
                    }
                }
            }
            for(int z=0;z<=3;z++){
                if(gameBoard[2][z]==0){
                    gameBoard[2][z]=gameBoard[1][z];
                    gameBoard[1][z]=gameBoard[0][z];
                    gameBoard[0][z]=0;
                }
            }
            if(!CheckDuplicate()){
                AddRandomNumber();
            }
            PrintGame();
        }
        CheckLost();
    }
}