#include "util.h"

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
        printf("Trying to run sys cmd\n");
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork failed");
        }
        else if (pid == 0)
        {
            // This is the child process. Call execvp here.
            execvp(cmd, args);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            // This is the parent process. Wait for the child to finish.
            int status;
            waitpid(pid, &status, 0);
        }
    }
}