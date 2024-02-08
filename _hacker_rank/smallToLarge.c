#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct triangle {
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle *tr, int n) {
    triangle tempTr;
    float *areas = malloc(n * sizeof(float)), p, tempArea;

    for (int i = 0; i < n; i++) {
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        areas[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (areas[j] > areas[j + 1]) {
                tempArea = areas[j];
                areas[j] = areas[j + 1];
                areas[j + 1] = tempArea;

                tempTr = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = tempTr;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%d\t:\t%d,\t%d,\t%d\t:\t%f\n", i, tr[i].a, tr[i].b, tr[i].c, areas[i]);
    // }
}

int main() {
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    // printf("Sorted Areas : \n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    // }
    return 0;
}