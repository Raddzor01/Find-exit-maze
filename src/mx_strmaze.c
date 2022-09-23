#include "../inc/header.h"

char *mx_strmaze(const char *file) {
    int fd = open(file, O_RDONLY);
    char buffer[1];
    int read_file = read(fd, buffer, 1);
    int count = 0;
    int row_act = 0;
    bool is_first_line = 1;
    int row_first = 0;
    while (read_file > 0) {
        if (buffer[0] == '.' || buffer[0] == '#' || buffer[0] == '\n') {
            count++;
        } else if (buffer[0] != ',')
            mx_printerr(2); // case error 2 - map error
        if (buffer[0] != '\n') {
            if (is_first_line == 1)
                row_first += 1;
            else
                row_act += 1;
        } else {
            if (is_first_line == 0)
                if (row_first != row_act)
                    mx_printerr(2);
            row_act = 0;
            is_first_line = 0;
        }
        read_file = read(fd, buffer, 1);
    }
    close(fd);
    fd = open(file, O_RDONLY);
    char *res = (char *)malloc(count + 1);
    read_file = read(fd, buffer, 1);
    for (int i = 0; i < count && read_file > 0; read_file = read(fd, buffer, 1))
        if (buffer[0] == '.' || buffer[0] == '#' || buffer[0] == '\n') {
            res[i] = buffer[0];
            i++;
        }
    res[count] = '\0';
    close(fd);
    return res;
}
