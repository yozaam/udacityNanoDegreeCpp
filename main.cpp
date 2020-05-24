#include <fstream>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

void PrintBoard(vector<vector<int>> board){
    for(int i = 0 ; i<board.size() ; i++){
        for(int j = 0 ; j<board[0].size() ;j++)
            cout<<board[i][j];
        cout<<"\n";
    }
}

void ReadBoardFile(string filepath){
    ifstream myFile(filepath);

    if(myFile){
        cout<<"\n file opened :) \n";

        string line;

        while(getline(myFile,line)){
            cout<<line<<"\n";
        }
    }
}

int main() {

    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0}};

    ReadBoardFile("files/1.board");

    PrintBoard(board);

    cout << "Hello, World!" << endl;
    return 0;
}