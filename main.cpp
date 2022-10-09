#include <iostream>
#include "bits/stdc++.h"
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
    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            if(j==3 || j==6){
                cout<<" | ";
            }
            cout<<board[i][j]<<" ";
        }
        if(i == 2 || i == 5){
            cout<<endl;
            cout<<"-----------------------";
        }
        cout<<endl;
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
            val = 0;
            row = 0;
            col = 0;
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
bool numExistInCol(vector<vector<int>> board, int col, int val){
    for(int i =0; i<board.size();i++){
        if(board[i][col]==val){
            return true;
        }
    }
    return false;
}
bool numExistInRow(vector<vector<int>> board, int row, int val){
    for(int j=0; j<board.size();j++){
        if(board[row][j]==val){
            return true;
        }
    }
    return false;
}
bool numExistInBox(vector<vector<int>> board, int curRow, int curCol, int val){
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            if(board[i+curRow][j+curCol]==val){
                return true;
            }
        }
    }
    return false;
}
bool isEmptySpot(vector<vector<int>> board, int& row, int& col){
    for(row=0; row<board.size();row++){
        for(col=0; col<board[row].size();col++){
            if(board[row][col]==0){
                return true;
            }
        }
    }
    return false;
}
bool isValidSpot(vector<vector<int>> board, int row, int col ,int val){
    return !numExistInBox(board,row-row%3,col-col%3,val) && !numExistInCol(board,col,val) &&
    !numExistInRow(board,row,val);
}
bool solveSudoku(vector<vector<int>>& board){
    int row, col;
    if(!isEmptySpot(board,row,col)){
        return true;
    }
    for(int val = 1; val<=9; val++){
        if(isValidSpot(board,row,col,val)){
            board[row][col]=val;
            if(solveSudoku(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}
int main() {
    //vector<vector<int>> board(9,vector<int>(9));
    vector<vector<int>> board= {{0,9,0,1,0,0,2,0,4},{0,0,2,0,0,0,0,8,0},{0,0,0,0,4,0,0,6,0,},
                                {0,0,6,0,1,0,5,0,7},{0,0,0,0,0,0,0,4,0},{3,0,0,9,0,0,0,0,0},
                                {0,0,5,0,7,0,1,0,2},{0,6,0,0,0,5,0,0,0},{0,0,0,0,0,0,8,0,0}};
    //initialize_Board(board);
    /*string input;
    cout<<"Enter in the starting board using this style (row,col:val):  ";
    cin>> input;
    insert_board(board,input);*/


    cout<<endl<<endl;
    //Printing Board
    print_Board(board);
    cout<<endl;
    cout<<"============================================="<<endl;

    if(solveSudoku(board)){
        print_Board(board);
    }
    else{
        cout<<"Solution does not exist";
    }
    return 0;

}

/*String Input style:
 * (row,col:val)(row,col:val)
 * 0 1 2 3 4 5 6 7
 *
 * test input: (0,1:6)(0,2:7)(0,4:5)(0,5:4)(1,0:1)(1,6:2)(2,3:6)(2,4:1)(2,7:4)(3,5:5)(3,7:6)(4,1:1)(4,2:2)(4,3:8)(4,6:4)(5,0:6)(5,2:3)(5,6:8)(5,7:7)(6,5:7)(6,7:2)(6,8:3)(7,0:7)(7,1:2)(7,2:9)(7,3:3)(7,4:6)(7,7:8)(7,8:4)(8,0:4)(8,2:6)(8,3:5)(8,4:8)(8,5:2)(8,7:9)(8,8:1)
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