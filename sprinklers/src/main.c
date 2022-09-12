/*
 * João Pedro Rodrigues Freitas
 * NUSP: 11316552
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define min 1e-8

typedef struct data_st {
    double left, right;
} data_t;

int compare(const void *a, const void *b) {
    data_t *da = (data_t *)a;
    data_t *db = (data_t *)b;
    return (da->left > db->left);
}

int main() {
    int n, l, w, r;
    data_t data[10002];

    while (scanf("%d %d %d\r\n", &n, &l, &w) != EOF) {
        bool found = false;
        int count = 0, ans = 0, d;
        double e = 0, s = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d\r\n", &d, &r);

            if (r < w/2.0) continue; // skip if radius is smaller than half of width

            double range = sqrt(r*r - w*w/4.0); // transform circle to rectangle
            data[count].left = d - range;
            data[count].right = d + range;
            count++;
        }

        qsort(data, count, sizeof(data_t), compare);
        
        for (int i = 0; i < count; i++) {
            if (data[i].right > e) {
                for (int j = i; j < count && data[j].left - s < min; j++) {
                    if (e - data[j].right < -min)
                        e = data[j].right;
                }
                ans++;
                if (e >= l) {
                    found = true;
                    break;
                }
                s = e;
            }
        }

        (found) ? printf("%d\n", ans) : printf("-1\n");
    }

    return EXIT_SUCCESS;
}