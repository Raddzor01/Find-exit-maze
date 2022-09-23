#include "../inc/header.h"

void mx_clean(t_maze *info, t_crd *coords) {
    for (int i = 0; i < info->row; i++) {
        free(info->str_maze[i]);
        info->str_maze[i] = NULL;
    }
    free(info->str_maze);
    info->str_maze = NULL;
    for (int i = 0; i < info->row; i++) {
        free(info->int_maze1[i]);
        info->int_maze1[i] = NULL;
    }
    free(info->int_maze1);
    info->int_maze1 = NULL;
    for (int i = 0; i < info->row; i++) {
        free(info->int_maze2[i]);
        info->int_maze2[i] = NULL;
    }
    free(info->int_maze2);
    info->int_maze2 = NULL;
    free(info);
    info = NULL;
    free(coords);
    coords = NULL;
}
