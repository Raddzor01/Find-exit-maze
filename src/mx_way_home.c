#include "../inc/header.h"

int main(int argc, char *argv[]) {
    mx_primary_check(argc, argv);

    t_crd *coords = malloc(sizeof(t_crd) * 2);
    t_maze *info = malloc(sizeof(t_maze));
    mx_init(&coords, &info, argv);
    int path1[info->row * info->column];
    int path2[info->row * info->column];

    if (!mx_lee_path(&info, coords, path1, path2))
        mx_printerr(5);
    for (int i = 0; i < info->length; i++)
        info->str_maze[path2[i]][path1[i]] = '*';
    info->str_maze[coords[1].y][coords[1].x] = '*';
    mx_lee_max(info, coords);

    mx_print_res(info, coords);
    mx_clean(info, coords);
    return 0;
}
