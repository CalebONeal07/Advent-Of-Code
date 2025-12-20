#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *input;
    fopen_s(&input, "december-1.in", "r");

    int pos = 50;
    int code = 0;

    char line[100];
    while (fgets(line, 100, input)) {
        if (line[0] == 'R') {
            pos += atoi(line + 1);
        } else if (line[0] == 'L') {
            pos -= atoi(line + 1);
        }

        pos = pos % 100;
        if (pos == 0) {
            code++;
        }
    }

    printf("%d", code);

    return 0;
}
