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
    if ((mt[0][0] != '\0' && mt[0][0] == mt[1][1] && mt[1][1] == mt[2][2]) ||
    (mt[0][2] != '\0' && mt[0][2] == mt[1][1] && mt[1][1] == mt[2][0])) { //check each diagonal if it have 3 identical not-null characters
        printGameBoard();
        cout << "The player " << playerTurn() << " won!" << "\n";
        gameOver = 1;
    }
    else {
        for (int i = 0, j = 0; i < 3 && gameOver == 0; ++i) { //iterate through matrix to check if a line or a column have 3 identical not-null characters
            if (mt[i][i] != '\0') { //move over only if at least one element from current line or column is not null
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

void insertCharacter() {
    if (mt[i][j] == '\0') {
        mt[i][j] = player;
        playerTurn();
        ++noOfCharacters;
        checkCase();
    }
    else {
        cout << "This box is not empty!\n";
    }
}

void command() {
    char nextCommand = pressKey();
    if (nextCommand == 'q') { //insert into the game board the character X or O when the 'q' key is pressed
        insertCharacter();
    }
    else if (nextCommand == 'w' && i > 0) { //before move the cursor, check if the next position it will be inside the game board
        --i;
    }
    else if (nextCommand == 'a' && j > 0) {
        --j;
    }
    else if (nextCommand == 's' && i < 2) {
        ++i;
    }
    else if (nextCommand == 'd' && j < 2) {
        ++j;
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
        command();
    }
    return 0;
}
