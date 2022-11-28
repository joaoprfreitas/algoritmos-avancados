#include <iostream>
#include <vector>
using namespace std;

bool existsWord(vector<vector<char>> board, vector<char> word, int n, int m, int wordSize);
bool searchWord(vector<vector<char>> board, vector<char> word, int i, int j, int n, int m, int wordSize, int letterPos);

int aroundX[4] = {0, 1, 0, -1};
int aroundY[4] = {1, 0, -1, 0};

int main() {
    int n, m, wordSize;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cin >> wordSize;

    vector<char> word(wordSize);
    for (int i = 0; i < wordSize; i++) {
        cin >> word[i];
    }

    if (existsWord(board, word, n, m, wordSize))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return EXIT_SUCCESS;
}

bool existsWord(vector<vector<char>> board, vector<char> word, int n, int m, int wordSize) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (searchWord(board, word, i, j, n, m, wordSize, 0))
                return true;

    return false;
}

bool searchWord(vector<vector<char>> board, vector<char> word, int i, int j, int n, int m, int wordSize, int letterPos) {
    if (letterPos >= wordSize) return true;

    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[letterPos]) return false;

    char temp = board[i][j];
    board[i][j] = ' ';

    for (int k = 0; k < 4; k++) {
        if (searchWord(board, word, i + aroundX[k], j + aroundY[k], n, m, wordSize, letterPos + 1))
            return true;
    }

    board[i][j] = temp;

    return false;
}