#include "util.h"
#include <stdio.h>

#define BUF_SIZE 1024

void copy_file(char **args)
{
    // Count the number of arguments
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 2)
    {
        fprintf(stderr, "copy_file: missing argument\n");
        return;
    }

    char *source_path = build_path(&args[0], 1);
    char *destination_path = build_path(&args[1], 1);

    FILE *source, *destination;
    char buf[BUF_SIZE];
    size_t bytes_read, bytes_written;

    // Open source file for reading
    source = fopen(source_path, "r");
    if (source == NULL)
    {
        fprintf(stderr, "Unable to open source file.\n");
        return;
    }

    // Open destination file for writing
    destination = fopen(destination_path, "w");
    if (destination == NULL)
    {
        fclose(source);
        fprintf(stderr, "Unable to open destination file.\n");
        return;
    }

    // Copy file
    while ((bytes_read = fread(buf, 1, BUF_SIZE, source)) > 0)
    {
        bytes_written = fwrite(buf, 1, bytes_read, destination);
        if (bytes_written != bytes_read)
        {
            fclose(source);
            fclose(destination);
            fprintf(stderr, "Error writing to destination file.\n");
            return;
        }
    }

    // Close files
    fclose(source);
    fclose(destination);
}