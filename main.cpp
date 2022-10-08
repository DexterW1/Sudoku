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
int main() {
    vector<vector<int>> board(9,vector<int>(9));
    initialize_Board(board);

    cout<<endl<<endl;
    //Printing Board
    print_Board(board);
    return 0;

}
/*
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