#include "util.h"

void echo(char **args)
{
    char *str = malloc(1024);
    str[0] = '\0';

    int i = 0;
    char *mode = "w";

    while (args[i] != NULL)
    {
        if (strcmp(args[i], ">>") == 0)
        {
            break;
        }
        else
        {
            if (strlen(str) + strlen(args[i]) + 1 > 1024)
            {
                str = realloc(str, strlen(str) + strlen(args[i]) + 1);
            }
            strcat(str, args[i]);
            strcat(str, " ");
        }
        i++;
    }

    if (args[i] == NULL)
    {
        printf("Missing file path\n");
        free(str);
        return;
    }

    char *path = build_path(&args[i + 1], 1);

    FILE *fptr;
    fptr = fopen(path, mode);
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        free(str);
        return;
    }
    fprintf(fptr, "%s", str);
    fclose(fptr);

    free(str);
}