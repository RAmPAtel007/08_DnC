#include <iostream>
#include <vector>
using namespace std;

void printSoln(vector<vector<char>> board, int n){
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++ ){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> board,int n){
    int i= row;
    int j= col;
    //check krna hai , ki kya main current cell[row][col] pr Queen ko rakh skta hua ya nahi

    //row k liye
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }

    //upper diagonal k liye 
    int i= row;
    int j= col;
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
}

void solve(vector<vector<char>>& board, int col, int n){
    //base case 
    if(col >= n){ //saare queen place ho gaye hai or col==n bur good practice col>=n
        printSoln(board,n);
        return;

    }

    //1 case mera 
    for(int row=0 ; row<n ; row++){
        if(isSafe(row,col,board,n)){
            //rakh do 
            board[row][col]= 'Q';
            //recursion soln lagega 
            solve(board,col+1,n);
            //backtracking 
            board[row][col]='-';

        }
    }
}

int main(){
    int n=4 ;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col=0;
    //Q -> queen at the cell
    //- -> empty cell
    solve(board,col,n);

    
}