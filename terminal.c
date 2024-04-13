#include "util.h"

int main()
{
    char *line = NULL;

    printWelcome();

    do
    {
        getLocation();

        size_t len = 0;
        getline(&line, &len, stdin);

        line[strcspn(line, "\n")] = 0;

        char **tokens = splitArgument(line);

        int i;
        for (i = 0; tokens[i] != NULL; i++)
        {
            if (strcmp(tokens[i], "|") == 0)
            {
                break;
            }
        }

        if (tokens[i] != NULL)
        {
            tokens[i] = NULL;
            char **argv1 = tokens;
            char **argv2 = &tokens[i + 1];

            mypipe(argv1, argv2);
        }
        else
        {
            char *cmd = tokens[0];
            char **args = &tokens[1];
            execmd(cmd, args);
        }

        free(tokens);

    } while (line != NULL);

    return 0;
}