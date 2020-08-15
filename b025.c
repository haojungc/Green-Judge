/* b025: 棋盤格城市 */
/* url: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b025 */

#include <stdio.h>

long long int count[40][40];

long long int get_answer(int x, int y) {
    /* Index out of range */
    if (x < 0 || y < 0)
        return 0;

    /* Prevents recalculation of known values */
    if (count[x][y] != -1)
        return count[x][y];

    count[x][y] = get_answer(x - 1, y) + get_answer(x, y - 1);

    return count[x][y];
}

int main() {
    /* Initialization */
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++)
            count[i][j] = -1;
    count[0][1] = count[1][0] = 1;

    int x, y;

    scanf("%d %d", &x, &y);

    long long int answer = get_answer(x, y);

    printf("%lld\n", answer);

    return 0;
}