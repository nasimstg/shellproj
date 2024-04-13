#include "src.h"

void logout(char *str)
{
    if (str != NULL)
    {
        printf("%s\n", str);
    }
    exit(0);
}

void cd(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    char *path = NULL;


    path = path_builder(args, num_args);

    if (chdir(path) != 0)
    {
        perror("cd");
    }
}


void copy_file(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 2)
    {
        fprintf(stderr, "CP: Missing Arg(s)\n");
        return;
    }

    char *source_path = path_builder(&args[0], 1);
    char *destination_path = path_builder(&args[1], 1);

    FILE *source, *destination;
    int ch;

    source = fopen(source_path, "r");
    if (source == NULL)
    {
        fprintf(stderr, "CP: Unable to open source file\n");
        return;
    }

    destination = fopen(destination_path, "w");
    if (destination == NULL)
    {
        fprintf(stderr, "CP: Unable to open destination file\n");
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
}