#include "../inc/header.h"

void mx_write_to_file(t_maze *info) {
    int fd = open("path.txt", O_WRONLY);
    if (fd < 0)
        fd = open("path.txt",O_TRUNC | O_CREAT | O_WRONLY | 0777);
    for (int i = 0; i < info->row; i++) {
        for (int j = 0; j < info->column; j++)
            write(fd, &info->str_maze[i][j], 1);
        write(fd, "\n", 1);
    }
}
