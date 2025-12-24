#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

int main() {
    FILE *input;
    fopen_s(&input, "december-4.in", "r");


    int rows = 0;
    int cols = 0;
    char grid[MAX_SIZE][MAX_SIZE];
    while (fgets(grid[rows], MAX_SIZE, input)) {
        size_t len = strlen(grid[rows]);
        if (len > 0 && grid[rows][len-1] == '\n') {
            grid[rows][len-1] = '\0';
            len--;
        }

        if (len == 0) break;

        if (cols == 0) {
            cols = len;
        }

        rows++;
    }

    int accessible = 0, count = 0;

    // Direction vectors for 8 adjacent positions
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '@') {
                    // Count adjacent rolls
                    int adjacent_count = 0;

                    for (int d = 0; d < 8; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        // Check bounds
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            if (grid[ni][nj] == '@' || grid[ni][nj] == 'x') {
                                adjacent_count++;
                            }
                        }
                    }

                    // Can be accessed if fewer than 4 adjacent rolls
                    if (adjacent_count < 4) {
                        grid[i][j] = 'x';
                        accessible++;
                    }
                }
            }
        }

        count += accessible;

        printf("accessible: %d\n", accessible);
        if (accessible == 0) {
            break;
        }

        accessible = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'x') grid[i][j] = '.';
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
