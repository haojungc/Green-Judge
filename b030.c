/* b030: 隨選視訊
 * url: http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=b030 */

/* References:
 * 1. 背包問題（Knapsack Problem）:
 *    https://openhome.cc/Gossip/AlgorithmGossip/KnapsackProblem.htm
 * 2. 0-1 Knapsack Problem | DP-10:
 *    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/ */

#include <stdio.h>

#define MAX_LENGTH 110
#define MAX_TOTAL_TIME 1010
#define EMPTY -1

typedef struct {
    int length;       // default value: 0
    int satisfaction; // default value: 0
} Video;

void find_max_satisfaction(int, int);
void update_satisfaction(int, int);
void update_index_queue(int);

Video video[MAX_LENGTH];
int satisfaction[MAX_TOTAL_TIME]; // default value: 0
int index_queue[MAX_TOTAL_TIME];  // default value: 0

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &video[i].length, &video[i].satisfaction);

    find_max_satisfaction(n, m);

    printf("%d\n", satisfaction[m]);

    return 0;
}

void find_max_satisfaction(int total_videos, int max_length) {
    /* Adds a new video each time and updates satisfaction array */
    for (int i = 0; i < total_videos; i++) {
        update_satisfaction(i, max_length);

        /* Test output */
        /*printf("Add video %d (length: %d, satisfaction: %d)\n", i + 1, video[i].length,
               video[i].satisfaction);
        printf("%-8s", "length:");
        for (int j = 0; j <= max_length; j++)
            printf("%4d", j);
        printf("\n%-8s", "max:");
        for (int j = 0; j <= max_length; j++)
            printf("%4d", satisfaction[j]);
        printf("\n\n");*/
    }
}

void update_satisfaction(int index, int max_length) {
    int video_length       = video[index].length;
    int video_satisfaction = video[index].satisfaction;

    update_index_queue(max_length);

    for (int i = 0; index_queue[i] != EMPTY; i++) {
        int total_length         = index_queue[i] + video_length;
        int current_satisfaction = satisfaction[index_queue[i]];
        int total_satisfaction   = current_satisfaction + video_satisfaction;

        if (total_length <= max_length && total_satisfaction > satisfaction[total_length]) {
            /* Updates satisfaction array starting from index = total_length */
            for (int j = total_length; j <= max_length; j++) {
                if (satisfaction[j] > total_satisfaction)
                    break;
                satisfaction[j] = total_satisfaction;
            }
        }
    }
}

void update_index_queue(int max_length) {
    int current = satisfaction[max_length];
    int count   = 0;

    /* This loop finds the indices which their values are updated in the previous
     * update_satisfaction(), indices found in this loop will become the new starting points in
     * update_satisfaction() */
    for (int i = max_length; i > 0; i--) {
        if (satisfaction[i - 1] != current) {
            index_queue[count++] = i;
            current              = satisfaction[i - 1];
        }
    }

    /* Lets index_queue become {..., 0, EMPTY} */
    index_queue[count++] = 0;     // Index 0 is also a starting point in update_satisfaction()
    index_queue[count]   = EMPTY; // EMPTY: -1
}
