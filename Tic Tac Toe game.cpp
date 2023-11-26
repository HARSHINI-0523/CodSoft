#include <iostream>
#include <vector>
void initializeBoard(std::vector<std::vector<char>>& board);
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char player, int row, int col);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkDraw(const std::vector<std::vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    std::cout << "TIC-TAC-TOE GAME\n";

    do {
        displayBoard(board);

        // Player's move
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            makeMove(board, currentPlayer, row, col);
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                break;
            }
            switchPlayer(currentPlayer);
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    } while (true);

    return 0;
}
void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << "\n";
}
bool makeMove(std::vector<std::vector<char>>& board, char player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

