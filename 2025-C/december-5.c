#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

struct Range {
    unsigned long long lower;
    unsigned long long upper;
};

int main() {
    FILE* input;
    fopen_s(&input, "december-5.in", "r");

    char line[MAX_SIZE];
    struct Range ranges[MAX_SIZE];

    int range_count = 0;
    while (strcmp(fgets(line, MAX_SIZE, input), "\n")) {
        int len = strlen(line);
        int split;
        for (split = 0; split < MAX_SIZE; split++) {
            if (line[split] == '-') break;
        }

        line[split] = '\0';
        ranges[range_count].lower = strtoull(line, NULL, 0);
        ranges[range_count].upper = strtoull(&line[split + 1], NULL, 0);
        printf("%d: %llu - %llu\n", range_count, ranges[range_count].lower, ranges[range_count].upper);

        range_count++;
    }

    // Part 2

    // int count = 0;
    // for (int idx = 0; idx < range_count; idx++) {
    //     unsigned long long lower = fresh_ranges[idx][0];
    //     unsigned long long upper = fresh_ranges[idx][1];
    //     for (unsigned long long id = lower; id <= upper; id++) {
    //         char duplicate = 0;
    //         for (int i = idx + 1; i < range_count; i++) {
    //             if (id >= fresh_ranges[i][0] && id <= fresh_ranges[i][1]) {
    //                 duplicate = 1;
    //                 break;
    //             }
    //         }
    //         if (!duplicate) {
    //             count++;
    //         }
    //         printf("%d\n", count);
    //     }
    // }

    unsigned long long count = 0;
    for (int idx = 0; idx < range_count; idx++) {
        unsigned long long lower = ranges[idx].lower;
        unsigned long long upper = ranges[idx].upper;
        printf("%d: %llu += %llu - %llu + 1\n", idx, count, upper, lower);
        if (upper == 0 || lower == 0)
            continue;
        count += upper - lower + 1;
        for (int i = idx + 1; i < range_count; i++) {
            if (ranges[i].upper <= upper && ranges[i].lower >= lower) {
                ranges[i].lower = 0;
                ranges[i].upper = 0;
            } else if (ranges[i].upper >= upper && ranges[i].lower <= lower) {
                printf("\tCANCELLED: %llu-%llu\n", ranges[i].lower, ranges[i].upper);
                count -= upper - lower + 1;
                break;
            } else if (ranges[i].upper >= lower && ranges[i].lower <= lower)
                ranges[i].upper = lower - 1;
            else if (ranges[i].lower <= upper && ranges[i].upper >= upper)
                ranges[i].lower = upper + 1;
        }
    }

    printf("Count: %llu", count);

    // Part 1
    // int count = 0;
    // while (fgets(line, MAX_SIZE, input)) {
    //     unsigned long long id = strtoull(line, NULL, 0);
    //     printf("%llu\n", id);
    //     for (int i = 0; i < range_count; i++) {
    //         if (id >= fresh_ranges[i][0] && id <= fresh_ranges[i][1]) {
    //             count++;
    //             break;
    //         }
    //     }
    // }


    return 0;
}
