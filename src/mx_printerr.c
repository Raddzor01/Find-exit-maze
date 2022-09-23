#include <unistd.h>
#include <stdlib.h>

int mx_strlen(const char *s);

void mx_printerr(int case_err) {
    if (case_err == 0) {
        write(2, "usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n", 50);
        exit(-1);
    } else if (case_err == 1) {
        write(2, "map does not exist\n", 19);
        exit(-1);
    } else if (case_err == 2) {
        write(2, "map error\n", 10);
        exit(-1);
    } else if (case_err == 3){
        write(2, "points are out of map range\n", 28);
        exit(-1);
    } else if (case_err == 4) {
        write(2, "entry point cannot be an obstacle\n", 34);
        exit(-1);
    } else if (case_err == 5) {
        write(2, "route not found\n", 16);
        exit(-1);
    } else {
        write(2, "error\n", 6);
        exit(-1);
    }
}
