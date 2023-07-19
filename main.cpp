#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <string>

using namespace std;

void show();
void reset();
void oneMove();
bool Win();
string intToValue(int x);
void lookForANumber(int number, int& row, int& col);

int M[4][4];
int x; //The number which should we move
int row0;
int col0;

int main()
{
    srand(time(NULL));
    reset();

    show();
    while (true){
        cout << " Which number should we move: ";
        cin >> x;

        oneMove();
        show();
        if (Win()){
            cout << "You are clever!" << endl;
            break;
        }
    }
    cout << "Game over!" << endl;

    return 0;
}

void oneMove(){
    int rowX = -1;
    int colX = -1;

    lookForANumber(x, rowX, colX);

    swap(M[row0][col0], M[rowX][colX]);
    row0 = rowX;
    col0 = colX;
}

void reset(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            M[i][j] = 0;
        }
    }
    for (int x=1; x<=15; x++){
        int i = rand()%4;
        int j = rand()%4;
        while (M[i][j]!=0)
        {
            i = rand()%4;
            j = rand()%4;
        }
        M[i][j] = x;
    }
    lookForANumber(0, row0, col0);
}

void show(){
    system("CLS");
    cout << "+----+----+----+----+" << endl;
    cout << "| "<< intToValue(M[0][0]) << " ";
    cout << "| "<< intToValue(M[0][1]) << " ";
    cout << "| "<< intToValue(M[0][2]) << " ";
    cout << "| "<< intToValue(M[0][3]) << " |" << endl;
    cout << "+----+----+----+----+" << endl;
    cout << "| "<< intToValue(M[1][0]) << " ";
    cout << "| "<< intToValue(M[1][1]) << " ";
    cout << "| "<< intToValue(M[1][2]) << " ";
    cout << "| "<< intToValue(M[1][3]) << " |" << endl;
    cout << "+----+----+----+----+" << endl;
    cout << "| "<< intToValue(M[2][0]) << " ";
    cout << "| "<< intToValue(M[2][1]) << " ";
    cout << "| "<< intToValue(M[2][2]) << " ";
    cout << "| "<< intToValue(M[2][3]) << " |" << endl;
    cout << "+----+----+----+----+" << endl;
    cout << "| "<< intToValue(M[3][0]) << " ";
    cout << "| "<< intToValue(M[3][1]) << " ";
    cout << "| "<< intToValue(M[3][2]) << " ";
    cout << "| "<< intToValue(M[3][3]) << " |" << endl;
    cout << "+----+----+----+----+" << endl;
}

string intToValue(int x){
    if (x<=0) return "  ";
    char s[3];
    sprintf(s, "%2d", x);
    return s;
}

void lookForANumber(int number, int& row, int& col){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (M[i][j] == number){
                row = i;
                col = j;
            }
        }
    }
}

bool Win(){
    for (int k=0; k<15; k++){
        int i = k/4; //row
        int j = k%4; //col
        if (M[i][j] != i+1) return false;
    }
    return true;
}
