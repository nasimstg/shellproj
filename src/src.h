#ifndef SRC_H
    #define SRC_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sched.h>
#include <sys/wait.h>
#include <fcntl.h>



#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"


void getLocation();
void printWelcome();
void logout(char *str);
char *path_builder(char **args, int num_args);
void cd(char **args);
void copy_file(char **args);
void move_file(char **args);
void delete_file(char **args);
void echo(char **args);
void read_file(char **args);
void word_line_count(char **args);
void mypipe(char **argv1, char **argv2);
char **splitArgument(char *line);
void execmd(char *cmd, char **args);