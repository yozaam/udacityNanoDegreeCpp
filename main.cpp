#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//enum
enum class State{kEmpty,kObstacle};

using namespace std;

string CellString(State square){
    if(square == State::kObstacle)return "⛰\t";
    else return "0\t";
}

void PrintBoard(vector<vector<State> > board){
    cout<<"\n";
    for(int i = 0 ; i<board.size() ; i++){
        for(int j = 0 ; j<board[0].size() ;j++)
            cout<<CellString(board[i][j]);
        cout<<"\n";
    }
}

vector<State> ParseLine(string const& line){
    vector<State> parsed;
    int n;
    char c;
    istringstream myStream(line);
    while(myStream>>n>>c && c==','){
        if(n == 0) parsed.push_back(State::kEmpty);
        else parsed.push_back(State::kObstacle);
    }
    return parsed;
}

vector< vector<State> > ReadBoardFile(string const& filepath){
    ifstream myFile(filepath);
    vector<vector<State> > board;

    if(myFile){
        cout<<"\nfile opened :) \n";

        string line;

        while(getline(myFile,line)){
            //cout<<line<<"\n"; // i need to put all ints from here into a vector
            board.push_back(ParseLine(line));
        }
    }else{
        cout<<"\nCould not open file at: "<<filepath;
    }

    return board;
}

int main() {

//    vector<vector<int> > board = {{0, 1, 0, 0, 0, 0},
//                                 {0, 1, 0, 0, 0, 0},
//                                 {0, 1, 0, 0, 0, 0},
//                                 {0, 1, 0, 0, 0, 0},
//                                 {0, 0, 0, 0, 1, 0}};



    PrintBoard(ReadBoardFile("/Users/yohaanvakil/Dev/udacityNanoDegreeCpp/files/1.board"));

//    PrintBoard(board);

    cout << "\nAll good captain!" << endl;
    return 0;
}