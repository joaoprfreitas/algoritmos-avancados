#include <iostream>
#include <vector>

using namespace std;

#define KEY 131071

int main() {
    string line;
    int remainder = 0;
    while (getline(cin, line)) {
        for (int i = 0; i < (int) line.length(); i++) {
            if (line[i] == '#') {
                cout << (remainder == 0 ? "YES" : "NO") << endl;
                remainder = 0;
            } else if (line[i] == '0') {
                remainder = (remainder * 2) % KEY;
            } else if (line[i] == '1') {
                remainder = (remainder * 2 + 1) % KEY;
            }
        }
    }
    

    return EXIT_SUCCESS;
}