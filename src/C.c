#include "src.h"

void delete_file(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    if (num_args < 1)
    {
        fprintf(stderr, "Missing source\n");
        return;
    }

    char *path = path_builder(args, num_args);

    if (remove(path) != 0)
    {
        perror("Unable to delete file");
        return;
    }
}


void mypipe(char **argv1, char **argv2)
{

    char *cmd1 = argv1[0];
    char **args1 = &argv1[1];
    
    char *cmd2 = argv2[0];
    
    char **args2 = &argv2[1];
    
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        execmd(cmd1, args1);

        exit(EXIT_FAILURE);
    }

    pid2 = fork();

    if (pid2 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {                                        
        
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        char *new_args2[] = { cmd2, args2[0], NULL };
        execvp(cmd2, new_args2);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    close(pipefd[0]);
    close(pipefd[1]);

    int status1, status2;
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
}