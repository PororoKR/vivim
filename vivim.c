#include <ncurses.h>
#include <time.h>
#include <unistd.h>

int modeC();
int modeN();
int modeI();
int moveCur();
int drawUI();
int openFile();
int quit();

int mode=1;
int maxY,maxX;
char cmd[300];
int curY,curX;
char keyPress;
char filename[256];
int isWritable=1;
FILE* fp;

int main(void){
    initscr();
    clear();
    getmaxyx(stdscr, maxY, maxX);
    drawUI();
    //code
    endwin();
}

int modeC(void){
    initscr();
    move(maxY-1, 0);
    printw(":");
    refresh();
    getstr(cmd);
    //code: do cmd...
    endwin();
}

int drawUI(void){
    initscr();
    for(int i=2;i<maxY;i++){
        move(i,1);
        printw("~");
        refresh();
    }
    move(2,0);
    endwin();
}

int modeN(void){
    initscr();
    noecho();
    keyPress=getch();
    switch(keyPress){
        case 'h': moveCur();
                  break;
        case 'j': moveCur();
                  break;
        case 'k': moveCur();
                  break;
        case 'l': moveCur();
                  break;
        case ':': modeC();
                  break;
        case 'i': modeI();
                  break;
        default: break;
    }
}

int moveCur(void){
    //code
}

int modeI(void){
    //code
}

int openFile(void){
    initscr();
    fp=fopen(filename,"r+");
    if(fp==NULL){
        fp=fopen(filename, "r");
        if(fp==NULL){
            move(maxY-1,0);
            printw("Unable to open file.");
            refresh();
        }
    }
    endwin();
}

int quit(void){
    initscr();
    fclose(fp);
    endwin();
}
