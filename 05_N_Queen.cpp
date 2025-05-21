#include <iostream>
#include <vector>
using namespace std;

void printSoln(vector<vector<char>>& board, int n){
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++ ){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board,int n){
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

    //upper left diagonal k liye 
     i= row;
     j= col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    //bottom left diagonal 
    i= row;
    j= col;
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }
    //kahin pr bhi queen nahi mili 
    //iska mtlb yeah position safe hai bhaiya 
    //toh return trueee kr do bhaiya 
    return true;

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
    int n=5 ;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col=0;
    //Q -> queen at the cell
    //- -> empty cell
    solve(board,col,n);
    return 0;

}