#include <iostream>
#include <vector>

using namespace std;

#define BOARD_SIZE 8

vector<vector<short>> board(BOARD_SIZE, vector<short>(BOARD_SIZE));
pair<short, short> queens[BOARD_SIZE];

bool validPos(int placedQueens, int row, int col);
void search(int &maxSum, int queen);

int main() {
    short boardNumbers;
    cin >> boardNumbers;

    for (int i = 0; i < boardNumbers; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            for (int k = 0; k < BOARD_SIZE; k++)
                cin >> board[j][k];

        int maxSum = 0;
        search(maxSum, 0);
        printf("%5d\n", maxSum);
    }

    return EXIT_SUCCESS;
}

bool validPos(int placedQueens, int row, int col) {
    for (int i = 0; i < placedQueens; i++) {
        if (queens[i].first == row || queens[i].second == col) // exact position or same row or column
            return false;
        if (abs(queens[i].first - row) == abs(queens[i].second - col)) // diagonal
            return false;
    }
    return true;
}

void search(int &maxSum, int queen) {
    if (queen == 8) { // all queens are placed
        int sum = 0;
        for (int i = 0; i < 8; i++)
            sum += board[queens[i].first][queens[i].second];
        maxSum = max(sum, maxSum);
        return;
    }

    for (int row = 0; row < 8; row++) {
        if (validPos(queen, row, queen)) {
            queens[queen] = make_pair(row, queen);
            search(maxSum, queen + 1);
        }
    }
}