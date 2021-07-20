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
    char key;
    cin >> key;
    cout << "It's " << player << "'s turn\n";
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
    if (nextComand == 'q') {//insert into the game board the character X or O when pressed q key
        if (mt[i][j] == '_' || mt[i][j] == '\0') {
            mt[i][j] = player;
            playerTurn();
            ++noOfCharacters;
            printGameBoard();
            if (noOfCharacters == 9 && gameOver == 0) {
                gameOver = 1;
                cout << "Draw!\n";
            }
        }
        else {
            cout << "This box is not empty!\n";
        }
    }
    else if (nextComand == 'w' && i > 0) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        --i;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
        printGameBoard();
    }
    else if (nextComand == 'a' && j > 0) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        --j;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
        printGameBoard();
    }
    else if (nextComand == 's' && i < 2) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        ++i;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
        printGameBoard();
    }
    else if (nextComand == 'd' && j < 2) {
        if (mt[i][j] == '_') {
            mt[i][j] = '\0';
        }
        ++j;
        if (mt[i][j] == '\0') {
            mt[i][j] = '_';
        }
        printGameBoard();
    }
    else {
        cout << "Out of the table!\n";
    }
    if ((mt[0][0] != '\0' && (mt[0][0] == mt[1][0] && mt[1][0] == mt[2][0])) ||
    (mt[1][0] != '\0' && (mt[1][0] == mt[1][1] && mt[1][1] == mt[1][2])) ||
    (mt[2][0] != '\0' && (mt[2][0] == mt[2][1] && mt[2][1] == mt[2][2])) ||
    (mt[0][0] != '\0' && (mt[0][0] == mt[0][1] && mt[0][1] == mt[0][2])) ||
    (mt[0][1] != '\0' && (mt[0][1] == mt[1][1] && mt[0][1] == mt[2][1])) ||
    (mt[0][2] != '\0' && (mt[0][2] == mt[1][2] && mt[1][2] == mt[2][2])) ||
    (mt[0][0] != '\0' && (mt[0][0] == mt[1][1] && mt[1][1] == mt[2][2])) ||
    (mt[0][2] != '\0' && (mt[0][2] == mt[1][1] && mt[1][1] == mt[2][0]))) {
        cout << playerTurn() << " won!" << "\n";
        gameOver = 1;
    }
}


int main() {
    while (noOfCharacters < 9 && gameOver == 0) {
        checkCase();
    }
    return 0;
}
