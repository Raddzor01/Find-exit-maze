#include "../inc/header.h"

void mx_init(t_crd **coord, t_maze **info, char *argv[]) {
    char *str = mx_strmaze(argv[1]);
    (* coord)[0].x = mx_atoi(argv[2]);
    (* coord)[0].y = mx_atoi(argv[3]);
    (* coord)[1].x = mx_atoi(argv[4]);
    (* coord)[1].y = mx_atoi(argv[5]);
    (* info)->str_maze = mx_strtoarrs(str, &*info);
    (* info)->int_maze1 = mx_strtoarri(str, &*info);
    (* info)->int_maze2 = mx_strtoarri(str, &*info);
    if ((* coord)[0].x >= (* info)->column 
    || (* coord)[1].x >= (* info)->column 
    || (* coord)[0].x < 0 
    || (* coord)[1].x < 0 
    || (* coord)[0].y < 0 
    || (* coord)[1].y < 0 
    || (* coord)[0].y >= (* info)->row 
    || (* coord)[1].y >= (* info)->row) {
        mx_printerr(3);
    }
    free(str);
    str = NULL;
}
