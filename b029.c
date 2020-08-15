/* b029: 福袋!福袋! */
/* problem: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b029 */
/* reference: https://www.geeksforgeeks.org/coin-change-dp-7/ */

#include <stdio.h>

#define MAX_LENGTH 1010

int get_the_number_of_combinations(int unit[], int length, int max_price) {
    int table[MAX_LENGTH][length];

    /* Fills the entries for 0 value case (max_price = 0) */
    for (int i = 0; i < length; i++)
        table[0][i] = 1;

    /* Fills the rest of the table entries */
    for (int price = 1; price <= max_price; price++) {
        for (int i = 0; i < length; i++) {
            int with, without;

            with    = (price - unit[i] >= 0) ? table[price - unit[i]][i] : 0;
            without = (i >= 1) ? table[price][i - 1] : 0;

            table[price][i] = with + without;
        }
    }

    return table[max_price][length - 1];
}

int main() {
    int price, ans;
    int unit[] = {2, 5, 10, 20, 25};
    int length = sizeof(unit) / sizeof(unit[0]);

    scanf("%d", &price);

    ans = get_the_number_of_combinations(unit, length, price);

    printf("%d\n", ans);

    return 0;
}