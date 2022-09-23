#pragma once

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef struct crd {
    int x;
    int y;
}   t_crd;

typedef struct s_maze {
    int row;
    int column;
    int length;
    char **str_maze;
    int **int_maze1;
    int **int_maze2;
}   t_maze;

int mx_atoi(const char *str);
void mx_clean(t_maze *info, t_crd *coords);
void mx_init(t_crd **coord, t_maze **info, char *argv[]);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_lee_max(t_maze *info, t_crd *coords);
bool mx_lee_path(t_maze **info, t_crd *coords, int *path_n, int *path_m);
void mx_primary_check (int argc, char *argv[]);
void mx_print_res(t_maze *info, t_crd *coords);
void mx_printchar(char c);
void mx_printerr(int case_err);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strlen(const char *s);
char *mx_strmaze(const char *file_name);
char *mx_strnew(const int size);
int **mx_strtoarri(char *result, t_maze **info);
char **mx_strtoarrs(char *result, t_maze **info);
void mx_write_to_file(t_maze *info);
