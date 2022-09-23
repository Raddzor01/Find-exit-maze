#include "../inc/header.h"

bool mx_lee_path(t_maze **info, t_crd *coords, int *path_n, int *path_m) {
	if ((* info)->int_maze1[coords[0].y][coords[0].x] == -1)
		mx_printerr(4);
	if ((* info)->int_maze1[coords[1].y][coords[1].x] == -1)
		mx_printerr(4);
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	bool stop;
	(* info)->int_maze1[coords[0].y][coords[0].x] = 0;
	for (int d = 0; true; d++) {
		stop = true;
		for (int y = 0; y < (* info)->row; y++)
			for (int x = 0; x < (* info)->column; x++)
				if ((* info)->int_maze1[y][x] == d)
					for (int k = 0; k < 4; k++) {
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < (* info)->row && ix >= 0 && ix < (* info)->column &&
						    (* info)->int_maze1[iy][ix] == -2) {
							stop = false;
							(* info)->int_maze1[iy][ix] = d + 1;
						}
					}
		if (stop || (* info)->int_maze1[coords[1].y][coords[1].x] != -2)
			break;
	}
	if ((* info)->int_maze1[coords[1].y][coords[1].x] == -2)
		return false;
	(* info)->length = (* info)->int_maze1[coords[1].y][coords[1].x];
	int x = coords[1].x;
	int y = coords[1].y;
	int d = (* info)->length;
	for (; d > 0;) {
		path_n[d] = x;
		path_m[d] = y;
		d--;
		for (int k = 0; k < 4; k++) {
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < (* info)->row && ix >= 0 && ix < (* info)->column &&
			    (* info)->int_maze1[iy][ix] == d) {
				x = x + dx[k];
				y = y + dy[k];
				break;
			}
		}
	}
	path_n[0] = coords[0].x;
	path_m[0] = coords[0].y;
	return true;
}
