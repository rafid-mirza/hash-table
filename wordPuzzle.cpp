/*
Rafid Mirza
rm2jgk
10/19/21
wordPuzzle.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hashTable.h"
//#include "timer.h"

using namespace std;
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
hashTable h;


void readInDict(string s);
void readInGrid(string e, int& r, int& c);
string getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols);
bool findVec(vector<string> vec, string test);

int main(int argc, char* argv[]){
    //timer timed;
    //timed.start();
	vector<string> vec;
	string output;
	string direction;
	string s(argv[1]);
	string t(argv[2]);
	int rows, cols;
	readInDict(s);
	readInGrid(t,rows,cols);
	for (int y = 0; y<rows; y++) {
		for (int x = 0; x < cols; x++ ){
			for (int i = 0; i < 8; i++){
				for (int z = 1; z < 23; z++){
					string current = getWordInGrid(y, x, i, z, rows, cols);
                    string previous = getWordInGrid(y, x, i, z-1, rows, cols);
				if (current.length() >2 and h.find(current) == true and h.newHash(current)!=h.newHash(previous)){
					output = "";
					if ( i== 0){
						direction = "N ";
					}
					else if ( i== 1){
						direction = "NE ";
					}
					else if ( i== 2){
						direction = "E ";
					}
					else if ( i== 3){
						direction = "SE ";
					}
					else if ( i== 4){
						direction = "S ";
					}
					else if ( i== 5){
						direction = "SW ";
					}
					else if ( i== 6){
						direction = "W ";
					}
					else if ( i== 7){
						direction = "NW ";
					}
					output += direction + "(" + to_string(y) + ", " + to_string(x)+ "): " + current;
                    vec.insert(vec.begin(),output);
				}
				}
			}
		}
    }
    for (int j = 0; j < vec.size(); j++){
			cout << vec.at(j) << endl;
		}
	cout << vec.size() << " words found" << endl;
    //timed.stop();
    //cout << timed.getTime();
  	return 0;
}

bool findVec(vector<string> vec, string test){
	for (int j = 0; j < vec.size(); j++){
			if (test == vec.at(j)){
				return true;
			}
		}
	return false;
}

void readInDict(string s){ //Adapted from: http://www.cplusplus.com/doc/tutorial/files/
    string line;
    int count = 0;
    ifstream myfile (s);
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            count++;
        }
        count = count*2;
        h.newSize(count);
        myfile.close();
    }

    string line2;
    ifstream myfile2 (s);
    if (myfile2.is_open()) {
        while ( getline (myfile2,line2) ) {
            h.insert(line2);
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file"; 
    }

}

void readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
	