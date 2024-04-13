#include "src.h"

void getLocation()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {/**/}
    else
    {
        perror("getcwd() error");
    }

    char username[1024];
    getlogin_r(username, sizeof(username));

    char hostname[1024];
    gethostname(hostname, sizeof(hostname));

    printf("%s%s%s@%s%s%s:%s%s%s%s$ ", GREEN, BOLD, username, GREEN, BOLD, hostname, BLUE, BOLD, cwd, RESET);
}

#include <string.h>
#include <stdlib.h>

char **splitArgument(char *line)
{
    int bufferSize = 100;
    int position = 0;
    char **tokens = malloc(bufferSize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufferSize) {
            bufferSize += 100;
            tokens = realloc(tokens, bufferSize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}