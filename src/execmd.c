#include "src.h"

void execmd(char *cmd, char **args)
{
    if (cmd == NULL)
    {
        return;
    }
    else if (strcmp(cmd, "exit") == 0)
    {
        logout(args[0]);
    }
    else if (strcmp(cmd, "cd") == 0)
    {
        cd(args);
    }
    else if (strcmp(cmd, "cp") == 0)
    {
        copy_file(args);
    }
    else if (strcmp(cmd, "mv") == 0)
    {
        move_file(args);
    }
    else if (strcmp(cmd, "delete") == 0)
    {
        delete_file(args);
    }
    else if (strcmp(cmd, "echo") == 0)
    {
        echo(args);
    }
    else if (strcmp(cmd, "read") == 0)
    {
        read_file(args);
    }
    else if (strcmp(cmd, "wc") == 0)
    {
        word_line_count(args);
    }

    else
    {
        printf("Command Not avilable...\n");
    }
}