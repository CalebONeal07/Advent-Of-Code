#include <stdio.h>
#include <stdlib.h>
#define LENGTH 4
#define MAX_SIZE 20000

int main() {
    FILE *input;
    fopen_s(&input, "december-6.in", "r");

    int operands[MAX_SIZE][LENGTH];

    char line[MAX_SIZE];

    for (int line_num = 0; line_num < LENGTH; line_num++) {
        line[0] = ' ';
        fgets(line + 1, MAX_SIZE, input);

        int i = 0;
        for (int cur = 0; line[cur] != '\0'; cur++) {
            if (line[cur - 1] == ' ' && line[cur] != ' ') {
                operands[i][line_num] = atoi(&line[cur]);
                i++;
            }
        }
    }

    unsigned long long sum = 0;

    int i = 0;
    fgets(line, MAX_SIZE, input);

    for (int cur = 0; line[cur] != '\0'; cur++) {
        if (line[cur] == '*') {
            unsigned long long val = 1;

            for (int j = 0; j < LENGTH; j++) {
                printf("%d\t", operands[i][j]);
                val *= operands[i][j];
            }
            printf("*= %llu\n", val);

            sum += val;
            i++;
        } else if (line[cur] == '+') {
            unsigned long long val = 0;

            for (int j = 0; j < LENGTH; j++) {
                printf("%d\t", operands[i][j]);
                val += operands[i][j];
            }
            printf("+= %llu\n", val);

            sum += val;
            i++;
        }
    }

    printf("Sum: %lld", sum);

    return 0;
}
