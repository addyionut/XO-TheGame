#include <iostream>
using namespace std;

char mt[4][4];
char player = 'X';
char nextComand;
int noOfCharacters;
int gameOver = 0;
int i = 1, j = 1;

char playerTurn() {
    if (player == 'X') {
        player = 'O';
        return player;
    }
    player = 'X';
    return player;
}

char pressKey() {
    cout << "It's " << player << "'s turn\n";
    char key;
    cin >> key;
    return key;
}

void printGameBoard() {
    cout << "\n------\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
           cout << mt[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------\n\n";
}

void checkCase() {
    nextComand = pressKey();
    if (nextComand == 'q') {//insert into the game board the character X or O when the q key is pressed
        if (mt[i][j] == '_' || mt[i][j] == '\0') {
            mt[i][j] = player;
            playerTurn();
            ++noOfCharacters;
            if ((mt[0][0] != '\0' && (mt[0][0] == mt[1][0] && mt[1][0] == mt[2][0])) ||
            (mt[1][0] != '\0' && (mt[1][0] == mt[1][1] && mt[1][1] == mt[1][2])) ||
            (mt[2][0] != '\0' && (mt[2][0] == mt[2][1] && mt[2][1] == mt[2][2])) ||
            (mt[0][0] != '\0' && (mt[0][0] == mt[0][1] && mt[0][1] == mt[0][2])) ||
            (mt[0][1] != '\0' && (mt[0][1] == mt[1][1] && mt[0][1] == mt[2][1])) ||
            (mt[0][2] != '\0' && (mt[0][2] == mt[1][2] && mt[1][2] == mt[2][2])) ||
            (mt[0][0] != '\0' && (mt[0][0] == mt[1][1] && mt[1][1] == mt[2][2])) ||
            (mt[0][2] != '\0' && (mt[0][2] == mt[1][1] && mt[1][1] == mt[2][0]))) {
                printGameBoard();
                cout << "The player " << playerTurn() << " won!" << "\n";
                gameOver = 1;
            }
            else if (noOfCharacters == 9 && gameOver == 0) {
                gameOver = 1;
                printGameBoard();
                cout << "Draw!\n";
            }
        }
        else {
            cout << "This box is not empty!\n";
        }
    }
    else if (nextComand == 'w' && i > 0) {
        if (mt[i][j] == '_') {//delete the previous cursor position indicator
            mt[i][j] = '\0';
        }
        --i;
        if (mt[i][j] == '\0') {//insert the underscore character to see the current cursor position
            mt[i][j] = '_';
        }
    }
    else if (nextComand == 'a' && j > 0) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        --j;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
    }
    else if (nextComand == 's' && i < 2) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        ++i;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
    }
    else if (nextComand == 'd' && j < 2) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        ++j;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
    }
    else {
        cout << "Out of game board!\n";
    }
    if (gameOver == 0) {
        printGameBoard();
    }
}


int main() {
    while (noOfCharacters < 9 && gameOver == 0) {
        checkCase();
    }
    return 0;
}
