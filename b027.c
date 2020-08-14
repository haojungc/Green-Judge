#include <stdio.h>

#define MAX_LENGTH 110

int land[MAX_LENGTH][MAX_LENGTH];

void input_land(int h, int w) {
    for (int x = 0; x < h; x++)
        for (int y = 0; y < w; y++)
            scanf("%d", &land[x][y]);
}

int get_max_edge(int x_start, int y_start, int h, int w) {
    int edge  = 1;
    int x_end = x_start + edge, y_end = y_start + edge;

    while (x_end < h && y_end < w) {
        int blocked = 0;
        for (int x = x_start; x <= x_end; x++)
            if (land[x][y_end] == 1)
                blocked = 1;
        for (int y = y_start; y <= y_end; y++)
            if (land[x_end][y] == 1)
                blocked = 1;

        if (blocked == 1)
            break;

        edge++;
        x_end++;
        y_end++;
    }

    return edge;
}

int get_max_area(int h, int w) {
    int max_edge = 0;

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            if (land[x][y] == 0) {
                int edge = get_max_edge(x, y, h, w);
                max_edge = edge > max_edge ? edge : max_edge;
            }
        }
    }

    return max_edge * max_edge;
}

int main() {
    int h, w, max_area;

    scanf("%d %d", &h, &w);

    input_land(h, w);

    max_area = get_max_area(h, w);

    printf("%d\n", max_area);

    return 0;
}