/* b028: 忙碌的超商店員 */
/* url: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b028 */

#include <stdio.h>

#define MAX_LENGTH 110

int coin_count[MAX_LENGTH];

void initialize_coin_count(int n) {
    /* Sets default value to 1e9 */
    for (int i = 1; i <= n; i++)
        coin_count[i] = 1e9;
    coin_count[1] = coin_count[5] = coin_count[10] = coin_count[12] =
        coin_count[16] = coin_count[20] = 1;
}

int get_the_number_of_coins(int n) {
    /* Dynamic programming */
    for (int change = 2; change <= n; change++) {
        int min = 1e9;
        for (int i = 0; i <= change / 2; i++) {
            int tmp = coin_count[i] + coin_count[change - i];
            min     = tmp < min ? tmp : min;
        }
        coin_count[change] = min;
    }

    return coin_count[n];
}

int main() {
    int n, ans;

    scanf("%d", &n);

    initialize_coin_count(n);

    ans = get_the_number_of_coins(n);

    printf("%d\n", ans);

    return 0;
}