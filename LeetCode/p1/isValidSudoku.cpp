#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isValidSudoku(vector< vector<char> >& board) {
    vector< map<char, int> > rows(9);
    vector< map<char, int> > columns(9);
    vector< map<char, int> > boxes(9);
    for(int i = 0; i < 9; i++){
        for(int j = 1; j <= 9; j++){
            rows[i][j + '0'] = 0;
            columns[i][j + '0'] = 0;
            boxes[i][j + '0'] = 0;
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char k = board[i][j];
            if(k != '.'){
                rows[i][k]++;
                columns[j][k]++;
                boxes[(i/3)*3+j/3][k]++;
                if(rows[i][k] > 1 || columns[j][k] > 1 || boxes[(i/3)*3+j/3][k] > 1)
                    return false;
            }
        }
    }
    return true;
}


int main(){
    vector< map<char, int> > rows(9);
    for(int i = 0; i < 9; i++){
        for(int j = 1; j < 10; j++){
            rows[i][j + '0'] = 0;
        }
    }
    cout<<rows[0]['1']<<endl;
}