#include <iostream>

using namespace std;

long long mergeSort(int *vet, int *tmp, int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    long long inv_count = mergeSort(vet, tmp, l, mid) + mergeSort(vet, tmp, mid + 1, r);

    int i = l, j = mid + 1, pos = l;
     
    while (i <= mid && j <= r) {
        if (vet[i] < vet[j]) {
            tmp[pos++] = vet[i++];
            inv_count += (j - (mid + 1));
        } else {
            tmp[pos++] = vet[j++];
        }
    }

    while (i <= mid) {
        tmp[pos++] = vet[i++];
        inv_count += (j - (mid + 1));
    }

    while (j <= r) {
        tmp[pos++] = vet[j++];
    }

    for (i = l; i <= r; i++) {
        vet[i] = tmp[i];
    }

    return inv_count;
}

long long reversePairs(int *vet, int n) {
    int tmp[n] = {0};
    return mergeSort(vet, tmp, 0, n-1);
}


int main() {
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int vet[n];

        for (int i = 0; i < n; ++i)
            cin >> vet[i];

        cout << reversePairs(vet, n) << endl;
    }

	return EXIT_SUCCESS;
}