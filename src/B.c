#include "src.h"

void logout(char *str)
{
    if (str == NULL)
    {
        exit(0);
    }
    printf("%s\n", str);
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


    path = build_path(args, num_args);

    if (chdir(path) != 0)
    {
        perror("cd");
    }
}


#define BUF_SIZE 1024

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

    char *source_path = build_path(&args[0], 1);
    char *destination_path = build_path(&args[1], 1);

    FILE *source, *destination;
    char buf[BUF_SIZE];
    size_t bytes_read, bytes_written;

    source = fopen(source_path, "r");
    destination = fopen(destination_path, "w");

    while ((bytes_read = fread(buf, 1, BUF_SIZE, source)) > 0)
    {
        bytes_written = fwrite(buf, 1, bytes_read, destination);
        if (bytes_written != bytes_read)
        {
            fclose(source);
            fclose(destination);
            return;
        }
    }

    fclose(source);
    fclose(destination);
}