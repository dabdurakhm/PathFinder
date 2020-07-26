#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>

struct islands_dist {
    char **isl_dist;
    char **unique_isl;
    int digit;
    int count_words;
} islands;


//---error_handling_pack---
void mx_error_handling(int argc, char **argv);

void mx_error_invalid_num_args(int argc);
void mx_error_file_exists(char *argv);
void mx_error_file_empty(char *argv);
char *mx_error_line1_not_digit(int *line_count, char *str);
void mx_error_line_invalid(int *line_count, char *str);
void mx_error_invalid_num_islands(char *str);


#endif
