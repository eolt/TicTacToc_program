//
//  main.cpp
//  TicTacToe
//
//  Created by Edgar Olvera on 10/19/19.
//
//  This program excutes a regular TicTacToe game with a user inputted X and O players.
//  The program should be able to print the board and update it with user inputs.
//  The program should ask the users for a row, column number.
//  Then program should check to see if the choice hasn't already been made or is out of range. If so the program should allow the user to try again.
//  The program will check for a winner by finding a matching row, column, or diagonal. And either print a statement telling who won or there is a tie; if spaces are full.
//
//

#include <iostream>

using namespace std;


void printMenu(char* map){
    cout << map[0] << "|" << map[1] << "|" << map[2] << endl;
    cout << "-" << "-" << "-" << "-" << "-" << endl;
    cout << map[3] << "|" << map[4] << "|" << map[5] << endl;
    cout << "-" << "-" << "-" << "-" << "-" << endl;
    cout << map[6] << "|" << map[7] << "|" << map[8] << endl;
}

bool isUsed(char* map, int x, int y, char symb){
    //  Checks first row for empty space, if so assign space to player symbol and return false
    if(x == 1 && y == 1 and map[0] == ' ') {
        map[0] = symb;
        return false;
    }
    else if(x == 1 && y == 2 and map[1] == ' '){
        map[1] = symb;
        return false;
    }
    else if(x == 1 && y == 3 and map[2] == ' '){
        map[2] = symb;
        return false;
    }
    
    //  Checks second row for empty space, if so assign space to player symbol and return false
    if(x == 2 && y == 1 and map[3] == ' ' ) {
        map[3] = symb;
        return false;
    }
    else if(x == 2 && y == 2 and map[4] == ' ' ){
        map[4] = symb;
        return false;
        
    }
    else if(x == 2 && y == 3 and map[5] == ' ' ) {
        map[5] = symb;
        return false;
    }
    
    //  Checks third row for empty space, if so assign space to player symbol and return false
    if(x == 3 && y == 1 and map[6] == ' ' ) {
        map[6] = symb;
        return false;
    }
    else if(x == 3 && y == 2 and map[7] == ' ' ) {
        map[7] = symb;
        return false;
    }
    else if(x == 3 && y == 3 and map[8] == ' ' ) {
        map[8] = symb;
        return false;
    }
    
    //  If space is full print message to user and return true
    cout << "Position is use. Try again." << endl;
    return true;
}

bool checkWin(char* map, char symb){
    
    //  Checks matching horizontal row,
    if(map[0] == symb && map[1] == symb  && map[2] == symb)
        return true;
    if(map[3] == symb  && map[4] == symb && map[5] == symb)
        return true;
    if(map[6] == symb && map[7] == symb && map[8] == symb)
        return true;
    
    //  Checks matching vertical column
    if(map[0] == symb && map[3] == symb && map[6] == symb)
        return true;
    if(map[1] == symb && map[4] == symb && map[7] == symb)
        return true;
    if(map[2] == symb && map[5] == symb && map[8] == symb)
        return true;
    
    //  Check matching diagonal row
    if(map[0] == symb && map[4] == symb && map[8] == symb)
        return true;
    if(map[6] == symb && map[4] == symb && map[2] == symb)
        return true;
    
    //  if there are no matching rows, columns, or diagonals
    return false;
}

void user_input(int& x, int& y){
    
    while((x <= 0 or x >= 4) or (y <= 0 or y >= 4)){       //   Run while inputs is out of range
        cout << "Enter row #: ";
        cin >> x;
        if(x <= 0 or x >= 4){                                       //  if input is out of range print message and run loop
            cout << "Input will not work. Try again." << endl;
            continue;
        }
        
        cout << "Enter column #: ";
        cin >> y;
        if(y <= 0 or y >= 4){                                       //  if input is out of range print message and run loop
            cout << "Input will not work. Try again." << endl;
            continue;
        }
    }
}

int main(int argc, const char * argv[]) {
    // assign board as char array with empty spaces, and variables
    char map[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int x{}, y{}, tries{};
    printMenu(map);
    //  Since there are 9 spaces in total once the number of turns exceeds 9, the game will close regardless of a winner
    while(tries < 9){
        cout << endl;               //  Spacing for readability
        cout << "Player 1's Turn:" << endl;
        
        do{
            x = 0;
            y = 0;
            user_input(x, y);                                 //  Asks user for input
        }while(isUsed(map, x, y, 'X'));                      // if input has been previosly been made, loop to ask again
    
        printMenu(map);
        if(checkWin(map, 'X')){
            cout << "Player 1 Wins!" << endl;
            break;
        }
        
        cout << endl;               //  Spacing for readability
        cout << "Player 2's Turn:" << endl;
        do{
            x = 0;
            y = 0;
            user_input(x, y);                               //  Asks user for input
        }while(isUsed(map, x, y, 'Y'));                     // if input has been previosly been made, loop to ask again

        printMenu(map);
        if(checkWin(map, 'O')){
            cout << "Player 2 Wins!" << endl;
            break;
        }
        tries++;
    }
    
    if(tries == 8)          //  if tries exceeds 9, print Tie
        cout << "TIE" << endl;
    return 0;
}
