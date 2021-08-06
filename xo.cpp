#include <iostream>
using namespace std;

char mt[4][4];
char player = 'X';
int gameOver, noOfCharacters, i, j;

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
    char keyValue;
    cin >> keyValue;
    return keyValue;
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
    char nextComand = pressKey();
    if (nextComand == 'q') {//insert into the game board the character X or O when the 'q' key is pressed
        if (mt[i][j] == '\0' || mt[i][j] == '_') {
            mt[i][j] = player;
            playerTurn();
            ++noOfCharacters;
            if ((mt[0][0] != '\0' && mt[0][0] == mt[1][1] && mt[1][1] == mt[2][2]) ||
                     (mt[0][2] != '\0' && mt[0][2] == mt[1][1] && mt[1][1] == mt[2][0])) {//check each diagonal if it have 3 identical not-null characters 
                printGameBoard();
                cout << "The player " << playerTurn() << " won!" << "\n";
                gameOver = 1;
            }
            else {
                for (int i = 0, j = 0; i < 3 && gameOver == 0; ++i) {//iterate through matrix to check if a line or a column have 3 identical not-null characters
                    if (mt[i][i] != '\0') {//move over only if at least one element from current line or column is not null
                        if ((mt[i][j] == mt[i][j + 1] && mt[i][j + 1] == mt[i][j + 2]) ||
                            (mt[j][i] == mt[j + 1][i] && mt[j + 1][i] == mt[j + 2][i])) {
                            printGameBoard();
                            cout << "The player " << playerTurn() << " won!" << "\n";
                            gameOver = 1;
                        }
                    }
                }
                if (noOfCharacters == 9 && gameOver == 0) {
                    printGameBoard();
                    cout << "Draw game!\n";
                    gameOver = 1;
                }
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
        cout << "Outside the game board!\n";
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
