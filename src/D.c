#include "src.h"

void move_file(char **args)
{
    int num_args = 0;
    while (args[num_args] != NULL)
    {
        num_args++;
    }

    char *source_path = path_builder(&args[0], 1);
    char *destination_path = path_builder(&args[1], 1);

    if (rename(source_path, destination_path) != 0)
    {
        perror("Unable to move file");
        return;
    }
}

void echo(char **args)
{
    char *str = malloc(1024);
    str[0] = '\0';

    int i = 0;
    char *mode = "w";

    while (args[i] != NULL)
    {
        if (strcmp(args[i], ">") == 0)
        {
            mode = "w";
            break;
        }
        else if (strcmp(args[i], ">>") == 0)
        {
            mode = "a";
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

    char *path = path_builder(&args[i + 1], 1);

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

void read_file(char **args)
{
    char *path = path_builder(args, 1);

    FILE *fptr;
    fptr = fopen(path, "r");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char c;
    while ((c = fgetc(fptr)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fptr);
    printf("\n");
}


void word_line_count(char **args)
{
    if(strcmp(args[0], "-l") != 0 && strcmp(args[0], "-w") != 0)
    {
        printf("Invalid option\n");
        return;
    }

    char *path = path_builder(&args[1], 1);
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    int lines = 0, words = 0, characters = 0;
    char ch;
    bool in_word = false;

    while ((ch = fgetc(fptr)) != EOF)
    {
        characters++;
        if (ch == '\n')
        {
            lines++;
        }
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            in_word = false;
        }
        else if (!in_word)
        {
            words++;
            in_word = true;
        }
    }

    if (strcmp(args[0], "-l") == 0)
    {
        printf("%d %s\n", lines, path);
    }
    else if (strcmp(args[0], "-w") == 0)
    {
        printf("%d %s\n", words, path);
    }

    fclose(fptr);
}