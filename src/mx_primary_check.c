#include <fcntl.h>
#include <unistd.h>

void mx_printerr(int case_err);

void mx_primary_check (int argc, char *argv[]) {
    char buffer;
    int fd_check = open(argv[1], O_RDONLY);
    int rd_check = read(fd_check, &buffer, 4);
    if (argc != 6)
        mx_printerr(0); // case error 0 - usage error
    if (fd_check < 0)
        mx_printerr(1); // case error 1 - map does not exist
    if (rd_check <= 0)
        mx_printerr(1);
}
