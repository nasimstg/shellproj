#include "util.h"

void cd(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 1)
    {
        fprintf(stderr, "Missing Arg(s)\n");
        return;
    }

    char *path = NULL;


    path = build_path(args, num_args);

    if (chdir(path) != 0)
    {
        perror("cd");
    }
}