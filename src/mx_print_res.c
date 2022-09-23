#include "../inc/header.h"

void mx_print_res(t_maze *info, t_crd *coords) {
    mx_write_to_file(info);
    mx_printstr("dist=");
    mx_printint(mx_lee_max(info, coords));
    mx_printstr("\n");
    mx_printstr("exit=");
    mx_printint(info->length);
    mx_printstr("\n");
}
