/* b027: 小綠人的城堡 */
/* url: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b027 */

#include <stdio.h>

#define MAX_LENGTH 110

int land[MAX_LENGTH][MAX_LENGTH];
int dp[MAX_LENGTH][MAX_LENGTH];

int min(int a, int b, int c) {
    int min = a;

    min = b < min ? b : min;
    min = c < min ? c : min;

    return min;
}

void initialize_dp(int h, int w) {
    /* Initializes the first column */
    for (int x = 0; x <= h; x++)
        dp[x][0] = 0;
    /* Initializes the first row */
    for (int y = 0; y <= w; y++)
        dp[0][y] = 0;
}

void input_land(int h, int w) {
    for (int x = 1; x <= h; x++)
        for (int y = 1; y <= w; y++)
            scanf("%d", &land[x][y]);
}

void invert_land(int h, int w) {
    /* 0 -> 1; 1 -> 0 */
    for (int x = 1; x <= h; x++)
        for (int y = 1; y <= w; y++)
            land[x][y] = land[x][y] == 0 ? 1 : 0;
}

int get_max_edge(int w, int h) {
    int max_edge = 0;

    for (int x = 1; x <= h; x++)
        for (int y = 1; y <= w; y++)
            max_edge = dp[x][y] > max_edge ? dp[x][y] : max_edge;

    return max_edge;
}

int get_max_area(int h, int w) {
    /* Dynamic programming */
    for (int x = 1; x <= h; x++)
        for (int y = 1; y <= w; y++)
            if (land[x][y] == 1)
                dp[x][y] =
                    1 + min(dp[x][y - 1], dp[x - 1][y], dp[x - 1][y - 1]);

    int max_edge = get_max_edge(h, w);

    return max_edge * max_edge;
}

int main() {
    int h, w, max_area;

    scanf("%d %d", &h, &w);

    initialize_dp(h, w);
    input_land(h, w);
    invert_land(h, w); /* 0 -> 1; 1 -> 0 */

    max_area = get_max_area(h, w);

    printf("%d\n", max_area);

    return 0;
}