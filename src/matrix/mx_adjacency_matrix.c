#include "pathfinder.h"

//---
static void print_intarr(long **arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            mx_printint(arr[i][j]);
            write(1, "\t", 1);
        }
	write(1, "\n", 1);
    }
} //---

static int get_isl_index(char *island, t_islands *isl) {
    for (int j = 0; isl->unique_isl[j]; j++)
        if (mx_strcmp(island, isl->unique_isl[j]) == 0)
            return j;
    return 0;
}

void mx_adjacency_matrix(t_islands *isl, t_matrix *matrix) {
    int row;
    int col;

    for (int i = 0; isl->isl_dist[i]; i += 3) {
        row = get_isl_index(isl->isl_dist[i], isl);
        col = get_isl_index(isl->isl_dist[i + 1], isl);
        matrix->adj_matrix[row][col] = mx_atoi(isl->isl_dist[i + 2]);
        matrix->adj_matrix[col][row] = matrix->adj_matrix[row][col];
    }
//---------------------------------------------
    write(1, "\n", 1);
    mx_printstr("--- init paths ---\n");
    print_intarr(matrix->adj_matrix, isl->count_unique_isl);
//---------------------------------------------
}
