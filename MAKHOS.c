 #include<stdio.h>

int FirstHOS;
int FirstDisplay(char table[8][8],int turn){
    TableSharp(table);
}
int Display(char table[8][8],int turn){
    if(turn%2==1){
        TableSharp(table);
        TableAt(table);
    }
    else if(turn%2==0){
        TableAt(table);
        TableSharp(table);
    }
}
int TableSharp(char table[8][8]){
    printf("\n");
    for(int k=0;k<8;k++){
        printf("   +---+---+---+---+---+---+---+---+\n");
        printf("   |");
            for(int l=0;l<8;l++){
                printf(" %c |",table[k][l]);
            }printf("  %d\n",k);
    }
    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("     a   b   c   d   e   f   g   h\n\n");
    sleep(1);
}
int TableAt(char table[8][8]){
    printf("\n");
    for(int k=0;k<8;k++){
        printf("   +---+---+---+---+---+---+---+---+\n");
        printf("   |");
        for(int l=0;l<8;l++){
            printf(" %c |",table[7-k][7-l]);
        }printf("  %d\n",7-k);
    }
    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("     h   g   f   e   d   c   b   a\n\n");
    sleep(1);
}
    typedef struct xy{
        int y;
        int x;
    };
    struct xy way1,way2,way3,way4;
    typedef struct way{
        struct xy way1;
        struct xy way2;
        struct xy way3;
        struct xy way4;
    };
    struct way allway[8][8];
int CheckEat(char table[8][8],int turn,int *Eatval,int x1,int y1,int x2,int y2){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(turn%2==1){
                if(table[i][j]=='#'){
                    if((table[i-1][j-1]=='@'||table[i-1][j-1]=='&')&&table[i-2][j-2]==' '&&i-2>=0&&i-2<=7&&j-2>=0&&j-2<=7){
                        allway[i][j].way1.y=i-2;
                        allway[i][j].way1.x=j-2;
                        *Eatval=1;
                    }
                    else if((table[i-1][j+1]=='@'||table[i-1][j+1]=='&')&&table[i-2][j+2]==' '&&i-2>=0&&i-2<=7&&j+2>=0&&j+2<=7){
                        allway[i][j].way2.y=i-2;
                        allway[i][j].way2.x=j+2;
                        *Eatval=1;
                    }
                }
                else if(table[i][j]=='$'){
                    for(int m=1;m<9;m++){
                        if((table[i+m][j+m]=='@'||table[i+m][j+m]=='&')&&table[i+m+1][j+m+1]==' '&&i+m+1>=0&&i+m+1<=7&&j+m+1>=0&&j+m+1<=7){
                            allway[i][j].way1.y=i+m+1;
                            allway[i][j].way1.x=j+m+1;
                            *Eatval=1;
                        }
                        if((table[i+m][j-m]=='@'||table[i+m][j-m]=='&')&&table[i+m+1][j-m-1]==' '&&i+m+1>=0&&i+m+1<=7&&j-m-1>=0&&j-m-1<=7){
                            allway[i][j].way2.y=i+m+1;
                            allway[i][j].way2.x=j-m-1;
                            *Eatval=1;
                        }
                        if((table[i-m][j+m]=='@'||table[i-m][j+m]=='&')&&table[i-m-1][j+m+1]==' '&&i-m-1>=0&&i-m-1<=7&&j+m+1>=0&&j+m+1<=7){
                            allway[i][j].way3.y=i-m-1;
                            allway[i][j].way3.x=j+m+1;
                            *Eatval=1;
                        }
                        if((table[i-m][j-m]=='@'||table[i-m][j-m]=='&')&&table[i-m-1][j-m-1]==' '&&i-m-1>=0&&i-m-1<=7&&j-m-1>=0&&j-m-1<=7){
                            allway[i][j].way4.y=i-m-1;
                            allway[i][j].way4.x=j-m-1;
                            *Eatval=1;
                        }
                    }
                }
            }
            else if(turn%2==0){
                if(table[i][j]=='@'){
                    if((table[i+1][j-1]=='#'||table[i+1][j-1]=='$')&&table[i+2][j-2]==' '&&i+2>=0&&i+2<=7&&j-2>=0&&j-2<=7){
                        allway[i][j].way1.y=i+2;
                        allway[i][j].way1.x=j-2;
                        *Eatval=1;
                    }
                    else if((table[i+1][j+1]=='#'||table[i+1][j+1]=='$')&&table[i+2][j+2]==' '&&i+2>=0&&i+2<=7&&j+2>=0&&j+2<=7){
                        allway[i][j].way2.y=i+2;
                        allway[i][j].way2.x=j+2;
                        *Eatval=1;
                    }
                }
                else if(table[i][j]=='&'){
                    for(int m=1;m<9;m++){
                        if((table[i+m][j+m]=='#'||table[i+m][j+m]=='$')&&table[i+m+1][j+m+1]==' '&&i+m+1>=0&&i+m+1<=7&&j+m+1>=0&&j+m+1<=7){
                            allway[i][j].way1.y=i+m+1;
                            allway[i][j].way1.x=j+m+1;
                            *Eatval=1;
                        }
                        if((table[i+m][j-m]=='#'||table[i+m][j-m]=='$')&&table[i+m+1][j-m-1]==' '&&i+m+1>=0&&i+m+1<=7&&j-m-1>=0&&j-m-1<=7){
                            allway[i][j].way2.y=i+m+1;
                            allway[i][j].way2.x=j-m-1;
                            *Eatval=1;
                        }
                        if((table[i-m][j+m]=='#'||table[i-m][j+m]=='$')&&table[i-m-1][j+m+1]==' '&&i-m-1>=0&&i-m-1<=7&&j+m+1>=0&&j+m+1<=7){
                            allway[i][j].way3.y=i-m-1;
                            allway[i][j].way3.x=j+m+1;
                            *Eatval=1;
                        }
                        if((table[i-m][j-m]=='#'||table[i-m][j-m]=='$')&&table[i-m-1][j-m-1]==' '&&i-m-1>=0&&i-m-1<=7&&j-m-1>=0&&j-m-1<=7){
                            allway[i][j].way4.y=i-m-1;
                            allway[i][j].way4.x=j-m-1;
                            *Eatval=1;
                        }
                    }
                }
            }
        }
    }
    if(*Eatval==1){
        ForceEat(table,allway,*Eatval,x1,y1,x2,y2,turn);
    }
    else if(*Eatval!=1){
        ValidMove(table,*Eatval,x1,y1,x2,y2,turn);
    }
}
int ForceEat(char table[8][8],struct way allway[8][8],int Eatval,int x1,int y1,int x2,int y2,int turn){
    int Validstart=0,Validstop=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(((x2==allway[i][j].way1.x)&&(y2==allway[i][j].way1.y))||((x2==allway[i][j].way2.x)&&(y2==allway[i][j].way2.y))||((x2==allway[i][j].way3.x)&&(y2==allway[i][j].way3.y))||((x2==allway[i][j].way4.x)&&(y2==allway[i][j].way4.y))){
                Validstop=1;
            }
            if(x1==j&&y1==i){
                Validstart=1;
            }
        }
    }
    if(Validstart==1&&Validstop==1){
        Eat(table,Eatval,x1,y1,x2,y2,turn);
        return 1;
    }
    else if(Validstart==0||Validstop==0){
        printf("\nForce to eat");
        return 0;
    }
}
int Eat(char table[8][8],int Eatval,int x1,int y1,int x2,int y2,int turn){
    if(x1>x2&&y1>y2){
        table[y2+1][x2+1]=' ';
    }
    else if(x1>x2&&y2>y1){
        table[y2-1][x2+1]=' ';
    }
    else if(x2>x1&&y2>y1){
        table[y2-1][x2-1]=' ';
    }
    else if(x2>x1&&y1>y2){
        table[y2+1][x2-1]=' ';
    }
    Walk(table,Eatval,x1,y1,x2,y2,turn);
}
int ValidMove(char table[8][8],int Eatval,int x1,int y1,int x2,int y2,int turn){
    int movevalid=1;
    if((table[y1][x1]!='#'&&table[y1][x1]!='$')&&(turn%2==1)){
        movevalid=0;
    }
    if((table[y1][x1]!='@'&&table[y1][x1]!='&')&&(turn%2==0)){
        movevalid=0;
    }
    if(x1>7||x1<0||x2>7||x2<0||y1>7||y1<0||y2>7||y2<0){
        movevalid=0;
    }
    if(table[y2][x2]!=' '){
        movevalid=0;
    }
    if(table[y1][x1]=='$'||table[y1][x1]=='&'){
        movevalid=ValidMoveHos(x1,y1,x2,y2);
    }
    else if(((x1>x2)&&(x1-x2!=1))||((x2>x1)&&(x2-x1!=1))||(x1==x2)){
        movevalid=0;
    }
    else if(((y1>y2)&&(y1-y2!=1))||((y2>y1)&&(y2-y1!=1))||(y1==y2)){
        movevalid=0;
    }
    if(movevalid==1){
        Walk(table,Eatval,x1,y1,x2,y2,turn);
        return 1;
    }

    else if(movevalid==0){
        printf("\nInvalid Move");
        return 0;
    }
}
int ValidMoveHos(int x1,int y1,int x2,int y2){
if(y1-y2!=x1-x2&&y1-y2!=x2-x1){
    return 0;
}
else if(x1==x2||y1==y2){
    return 0;
}
}
int Walk(char table[8][8],int Eatval,int x1,int y1,int x2,int y2,int turn){
    if(table[y1][x1]=='#'){
        table[y2][x2]='#';
    }
    else if(table[y1][x1]=='@'){
        table[y2][x2]='@';
    }
    else if(table[y1][x1]=='&'){
        table[y2][x2]='&';
    }
    else if(table[y1][x1]=='$'){
        table[y2][x2]='$';
    }
    table[y1][x1]=' ';
    CheckHos(table,Eatval,x1,y1,x2,y2,turn);
}
int CheckEatStreak(char table[8][8],int turn){
    int Eatval=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(turn%2==1){
                if(table[i][j]=='#'){
                    if((table[i-1][j-1]=='@'||table[i-1][j-1]=='&')&&table[i-2][j-2]==' '&&i-2>=0&&i-2<=7&&j-2>=0&&j-2<=7){
                        Eatval=1;
                    }
                    else if((table[i-1][j+1]=='@'||table[i-1][j+1]=='&')&&table[i-2][j+2]==' '&&i-2>=0&&i-2<=7&&j+2>=0&&j+2<=7){
                        Eatval=1;
                    }
                }
                else if(table[i][j]=='$'){
                    for(int m=1;m<9;m++){
                        if((table[i+m][j+m]=='@'||table[i+m][j+m]=='&')&&table[i+m+1][j+m+1]==' '&&i+m+1>=0&&i+m+1<=7&&j+m+1>=0&&j+m+1<=7){
                            Eatval=1;
                        }
                        if((table[i+m][j-m]=='@'||table[i+m][j-m]=='&')&&table[i+m+1][j-m-1]==' '&&i+m+1>=0&&i+m+1<=7&&j-m-1>=0&&j-m-1<=7){
                            Eatval=1;
                        }
                        if((table[i-m][j+m]=='@'||table[i-m][j+m]=='&')&&table[i-m-1][j+m+1]==' '&&i-m-1>=0&&i-m-1<=7&&j+m+1>=0&&j+m+1<=7){
                            Eatval=1;
                        }
                        if((table[i-m][j-m]=='@'||table[i-m][j-m]=='&')&&table[i-m-1][j-m-1]==' '&&i-m-1>=0&&i-m-1<=7&&j-m-1>=0&&j-m-1<=7){
                            Eatval=1;
                        }
                    }
                }
            }
            else if(turn%2==0){
                if(table[i][j]=='@'){
                    if((table[i+1][j-1]=='#'||table[i+1][j-1]=='$')&&table[i+2][j-2]==' '&&i+2>=0&&i+2<=7&&j-2>=0&&j-2<=7){
                        Eatval=1;
                    }
                    else if((table[i+1][j+1]=='#'||table[i+1][j+1]=='$')&&table[i+2][j+2]==' '&&i+2>=0&&i+2<=7&&j+2>=0&&j+2<=7){
                        Eatval=1;
                    }
                }
                else if(table[i][j]=='&'){
                    for(int m=1;m>9;m++){
                        if((table[i+m][j+m]=='#'||table[i+m][j+m]=='$')&&table[i+m+1][j+m+1]==' '&&i+m+1>=0&&i+m+1<=7&&j+m+1>=0&&j+m+1<=7){
                            Eatval=1;
                        }
                        if((table[i+m][j-m]=='#'||table[i+m][j-m]=='$')&&table[i+m+1][j-m-1]==' '&&i+m+1>=0&&i+m+1<=7&&j-m-1>=0&&j-m-1<=7){
                            Eatval=1;
                        }
                        if((table[i-m][j+m]=='#'||table[i-m][j+m]=='$')&&table[i-m-1][j+m+1]==' '&&i-m-1>=0&&i-m-1<=7&&j+m+1>=0&&j+m+1<=7){
                            Eatval=1;
                        }
                        if((table[i-m][j-m]=='#'||table[i-m][j-m]=='$')&&table[i-m-1][j-m-1]==' '&&i-m-1>=0&&i-m-1<=7&&j-m-1>=0&&j-m-1<=7){
                            Eatval=1;
                        }
                    }
                }
            }
        }
    }
    if(Eatval==1){
        return 0;
    }
    else if(Eatval!=1){
        return 1;
    }
}
int CheckHos(char table[8][8],int Eatval,int x1,int y1,int x2,int y2,int turn){
    if(turn%2==1&&y2==0){
        table[y2][x2]='$';
        FirstHOS=1;
    }
    else if(turn%2==0&&y2==7){
        table[y2][x2]='&';
        FirstHOS=1;
    }
    Display(table,turn);
}
int CheckEndGame(char table[8][8]){
    int countsharp=0,countat=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(table[i][j]=='#'||table[i][j]=='$'){
                countsharp++;
            }
            else if(table[i][j]=='@'||table[i][j]=='&'){
                countat++;
            }
        }
    }
    if(countsharp==0){
        return 1;
    }
    else if(countat==0){
        return 2;
    }
}
int main(){
    char table[8][8];
    int turn=1;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(((i+j)%2==1)){
                table[i][j]=' ';
            }
            else{
                table[i][j]=' ';
            }
        }
    }
    table[0][1]='@'; table[0][3]='@'; table[0][5]='@'; table[0][7]='@';
    table[1][0]='@'; table[1][2]='@'; table[1][4]='@'; table[1][6]='@';
    table[6][1]='#'; table[6][3]='#'; table[6][5]='#'; table[6][7]='#';
    table[7][0]='#'; table[7][2]='#'; table[7][4]='#'; table[7][6]='#';
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   __MAKHOS THAI TWO PLAYERS__");
    printf("\n\n\n\n\t\t\t\t        Press __SPACEBAR__to start the game");
    for( ;; ){
        int a=getche();
    if(a==32){
        break;
    }
    }
    FirstDisplay(table,turn);
    Play:
    for( ;; ){
    int x1,x2,y1,y2;
    int Invalidity=1,Streakval=1;
    int wincondition=0;
    int Eatval=0;
    if(turn%2==1){
        printf("\n# AND $ turn");
    }
    else if(turn%2==0){
        printf("\n@ AND & turn");
    }
    printf("\nInitial Position :");
    x1=getche()-97;
    y1=getche()-48;
    printf("\nTO :");
    x2=getche()-97;
    y2=getche()-48;
    if(x1>7||x2>7||y1>7||y2>7||x1<0||x2<0||y1<0||y2<0){
        printf("\nInvalid move");
        printf("\nExample input\nb6c5,a1b2,c5d4");
        goto Play;
    }
    Invalidity=CheckEat(table,turn,&Eatval,x1,y1,x2,y2);
    if(Eatval==1&&Invalidity!=0&&FirstHOS!=1){
    Streakval=CheckEatStreak(table,turn);
    }
    if(Invalidity==0||Streakval==0){
        turn--;
        if(Streakval==0){
            if(turn%2==0){
                TableSharp(table);
            }
            if(turn%2==1){
                TableAt(table);
            }
            printf("Eat Streak");
        }
    }
    turn++;
    wincondition=CheckEndGame(table);
    if(wincondition==1){
        printf("Congratulation for AT player");
        break;
    }
    else if(wincondition==2){
        printf("Congratulation for SHARP player");
        break;
    }
    FirstHOS=0;
    }
}

