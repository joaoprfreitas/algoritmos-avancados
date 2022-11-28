#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int *vec, int vecSize, int target) {
    int left = 0, right = vecSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        } else if (vec[mid] > target && mid > 0 && vec[mid - 1] < target) {
            return mid;
        } else if (vec[mid] < target && mid < vecSize - 1 && vec[mid + 1] > target) {
            return mid + 1;
        } else if (vec[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    int minutesListened[n];
    int moments[m];

    int c, t;
    cin >> c >> t;
    minutesListened[0] = c * t;

    for (int i = 1; i < n; i++) {
        cin >> c >> t;
        minutesListened[i] = minutesListened[i - 1] + c * t;
    }
    
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        moments[i] = a;
    }

    for (int i = 0; i < m; i++) {
        cout << binarySearch(minutesListened, n, moments[i]) + 1 << endl;
    }

    return EXIT_SUCCESS;
}