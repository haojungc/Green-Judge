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

typedef struct {
    int length;       // default value: 0
    int satisfaction; // default value: 0
} Video;

void build_max_satisfaction(int, int);
void update_satisfaction(int, int, int);

Video video[MAX_LENGTH];
int satisfaction[MAX_TOTAL_TIME]; // default value: 0

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &video[i].length, &video[i].satisfaction);

    build_max_satisfaction(n, m);

    printf("%d\n", satisfaction[m]);

    return 0;
}

void build_max_satisfaction(int total_videos, int max_length) {
    /* Adds a new video each time and updates satisfaction[] */
    for (int i = 0; i < total_videos; i++) {
        update_satisfaction(video[i].length, video[i].satisfaction, max_length);

        /* Test output */
        // printf("Add video %d (length: %d, satisfaction: %d)\n", i + 1, video[i].length,
        //        video[i].satisfaction);
        // printf("%-8s", "length:");
        // for (int j = 0; j <= max_length; j++)
        //     printf("%4d", j);
        // printf("\n%-8s", "max:");
        // for (int j = 0; j <= max_length; j++)
        //     printf("%4d", satisfaction[j]);
        // printf("\n\n");
    }
}

void update_satisfaction(int video_length, int video_satisfaction, int max_length) {
    /* Updates satisfaction[] in reverse order */
    for (int i = max_length; i >= video_length; i--) {
        int total_satisfaction = satisfaction[i - video_length] + video_satisfaction;

        satisfaction[i] =
            total_satisfaction > satisfaction[i] ? total_satisfaction : satisfaction[i];
    }
}
