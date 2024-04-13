#include "util.h"


void move_file(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 2)
    {
        fprintf(stderr, "missing src or dest\n");
        return;
    }

    char *source_path = build_path(&args[0], 1);
    char *destination_path = build_path(&args[1], 1);

    if (rename(source_path, destination_path) != 0)
    {
        perror("Unable to move file");
        return;
    }
}