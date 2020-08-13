#include <stdio.h>

#define MAX_LENGTH 110

int change[MAX_LENGTH];

void input_change(int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &change[i]);
}

int get_max_change(int n) {
    /* Dynamic programming */
    int max_change = 0, current_change = 0;

    for (int i = 0; i < n; i++) {
        int tmp = current_change + change[i];
        if (tmp < 0) {
            current_change = 0;
            continue;
        }
        current_change = tmp;
        max_change = current_change > max_change ? current_change : max_change;
    }

    return max_change;
}

int main() {
    int n, max_change;

    scanf("%d", &n);

    input_change(n);

    max_change = get_max_change(n);

    printf("%d\n", max_change);

    return 0;
}