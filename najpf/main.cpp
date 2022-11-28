#include <iostream>
#include <vector>

using namespace std;

void kmpPreProcessamento(int *b, string p){
	int i = 0, j = -1; b[0] = -1;

	while (i < (int) p.length()){
		while (j>=0 && p[i] != p[j]) {
			j = b[j]; 
		}
		i++; j++;
		b[i] = j;
	}
}

void kmp (int *b, string s, string p){
    vector<int> posicoes;

	int i = 0, j = 0;
	while (i < (int) s.length()){     // tem texto para  consumir.....
		while (j >= 0 &&  s[i] != p[j]) {
			j = b[j];
		}
		i++; j++;
		if (j == (int) p.length()) {
            posicoes.push_back(i - j + 1);
			j = b[j];
		}
	}

    if (posicoes.size() == 0) {
        cout << "Not Found" << endl << endl;
        return;
    }
    
    cout << (int) posicoes.size() << endl;
    for (int i = 0; i < (int) posicoes.size(); i++) {
        cout << posicoes[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    int t;
    cin >> t;
    string s, pattern;
    int b[1000000];

    for (int i = 0; i < t; i++) {
        cin >> s >> pattern;

        kmpPreProcessamento(b, pattern);
        
        kmp(b, s, pattern);
    }

    return EXIT_SUCCESS;
}
