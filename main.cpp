#include <iostream>
#include <bits/stdc++.h>
#include "function.h"
using namespace std;

void initialize_Board(vector<vector<int>>& board){
    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            board[i][j]=0;
        }
    }
}
void print_Board(vector<vector<int>> board){
    cout<<"___________________________________"<<endl;
    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size(); j++){
            cout<<board[i][j]<<" | ";
        }
        cout<<endl<<"-----------------------------------"<<endl;
    }
}
void insert_board(vector<vector<int>>& board, const string& input){
    int row, col, val, i = 0;
    char pick;
    while(i < input.size()){
        if(input[i] == '('){
            pick = 'r';
            i++;
            continue;
        }
        else if(input[i] == ','){
            pick = 'c';
            i++;
            continue;
        }
        else if (input[i] == ':'){
            pick = 'v';
            i++;
            continue;
        }
        else if(input[i] == ')') {
            board[row][col] = val;
            row, col, val = 0;
            i++;
            continue;
        }
        switch(pick){
            case 'r':
                row = input[i] - '0';
                break;
            case 'v':
                val = input[i] - '0';
                break;
            case 'c':
                col = input[i] - '0';
                break;
            default:
                break;
        }
        i++;
    }


}

int main() {
    vector<vector<int>> board(9,vector<int>(9));
    initialize_Board(board);
    string input;
    cout<<"Enter in the intitial board using this style (row,col:val):  ";
    cin>> input;
    insert_board(board,input);

    cout<<endl<<endl;
    //Printing Board
    print_Board(board);
    return 0;

}
/*String Input style:
 * (row,col:val)(row,col:val)
 * 0 1 2 3 4 5 6 7
 *
 *
 *
 * Board:
 * _______________________________________
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * ______________________________________
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * ______________________________________
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * | 0 | 0 | 0 || 0 | 0 | 0 || 0 | 0 | 0 |
 * _______________________________________
 */