/*  b029: 福袋!福袋!
 *  url: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b029 */

/*  References:
 *  1. Understanding The Coin Change Problem With Dynamic Programming:
 *     https://www.geeksforgeeks.org/understanding-the-coin-change-problem-with-dynamic-programming/
 *  2. Coin Change | DP-7:
 *     https://www.geeksforgeeks.org/coin-change-dp-7/ */

#include <stdio.h>

#define MAX_LENGTH 1010

int get_the_number_of_ways(int max_price) {
    int coin[]           = {2, 5, 10, 20, 25};
    int length           = sizeof(coin) / sizeof(coin[0]);
    int ways[MAX_LENGTH] = {0};

    ways[0] = 1;

    /*  1st iteration: Calculates the total number of ways which includes coin[0]
     *  2nd iteration: Adds the total number of ways which includes coin[1]
     *  3rd iteration: Adds the total number of ways which includes coin[2]
     *  4th iteration: Adds the total number of ways which includes coin[3]
     *  and so on... */
    for (int i = 0; i < length; i++) {
        for (int price = 1; price <= max_price; price++) {
            if (price - coin[i] >= 0)
                ways[price] += ways[price - coin[i]];
        }
    }

    return ways[max_price];
}

int main() {
    int price, ans;

    scanf("%d", &price);

    ans = get_the_number_of_ways(price);

    printf("%d\n", ans);

    return 0;
}