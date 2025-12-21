#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 12

int main() {
    FILE *input;
    fopen_s(&input, "december-3.in", "r");

    long long output = 0;
    char line[1000];

    while (fgets(line, 1000, input)) {
        char joltage[LEN + 1] = "000000000000\0";
        int max_idx = 0;

        for (int n = 0; n < LEN; n++) {
            for (int idx = max_idx; idx < strlen(line) - (1 + LEN - (n + 1)); idx++) {
                if (line[idx] > joltage[n]) {
                    joltage[n] = line[idx];
                    max_idx = idx;
                }
            }
            max_idx++;
        }
        printf("%s%s\t%lld\n", line, joltage, strtoll(joltage, NULL, 0));

        output += strtoll(joltage, NULL, 0);
    }
    printf("Output: %lld\n", output);
    fclose(input);
}
