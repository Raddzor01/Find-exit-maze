#include "../inc/header.h"

int mx_lee_max(t_maze *info, t_crd *coords) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool stop = false;
    int max;
    info->int_maze2[coords[0].y][coords[0].x] = 0;
    for (int d = 0, flag = 1; !stop || flag; d++, flag = 0) {
        stop = true;
        for (int y = 0; y < info->row; y++)  {
            for (int x = 0; x < info->column; x++) {
                if (info->int_maze2[y][x] == d) {
                    for (int k = 0; k < 4; k++) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < info->row && ix >= 0 && ix < info->column &&
                            info->int_maze2[iy][ix] == -2) {
                            stop = false;
                            info->int_maze2[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }
    }
    max = info->int_maze2[0][0];
    for (int i = 0; i < info->row; i++) {
        for (int j = 0; j < info->column; j++) {
            if (info->int_maze2[i][j] > max)
                max = info->int_maze2[i][j];
        }
    }
    for (int i = 0; i < info->row; i++) {
        for (int j = 0; j < info->column; j++) {
            if (info->int_maze2[i][j] == max) {
                if (info->str_maze[i][j] == '*') {
                    info->str_maze[i][j] = 'X';
                }
                else {
                    info->str_maze[i][j] = 'D';
                }
            }
        }
    }
    return max;
}
