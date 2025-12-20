#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input;
    fopen_s(&input, "december-1.in", "r");

    int pos = 50;
    int code = 0;

    char line[100];
    while (fgets(line, 100, input)) {
        printf("%s\t", line);
        int step = atoi(line + 1);

        if (line[0] == 'R') {
            while (step > 0) {
                pos++;

                if (pos == 100) {
                    pos = 0;
                }

                if (pos == 0) {
                    code++;
                }

                step--;
            }
        } else if (line[0] == 'L') {
            while (step > 0) {
                pos--;

                if (pos == -1) {
                    pos = 99;
                }

                if (pos == 0) {
                    code++;
                }

                step--;
            }
        }

        printf("%d\t", pos);
        printf("%d\n", code);
    }

    printf("%d", code);

    return 0;
}
