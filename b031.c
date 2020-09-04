/* b031: 吃到飽餐廳 */
/* url: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b031 */

#include <stdio.h>

#define MAX_FOOD 110
#define MAX_CAPACITY 1010

typedef struct {
    int portion;
    int value;
} Food;

Food food[MAX_FOOD];
int value[MAX_CAPACITY];

void build_max_value(int total_foods, int total_capacity) {
    /* Adds a food each time */
    for (int i = 0; i < total_foods; i++) {
        /* Updates value[] */
        int portion = food[i].portion;
        for (int j = portion; j <= total_capacity; j++) {
            int total_value = value[j - portion] + food[i].value;

            value[j] = total_value > value[j] ? total_value : value[j];
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &food[i].portion, &food[i].value);

    build_max_value(n, m);

    printf("%d\n", value[m]);

    return 0;
}