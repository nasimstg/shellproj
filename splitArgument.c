#include "util.h"

char **splitArgument(char *line)
{
    char **args = malloc(100 * sizeof(char *));
    int i = 0;

    char *line_copy = strdup(line);
    char *start = line_copy;
    char *end = start;
    int in_quotes = 0;

    while (*end != '\0') {
        if (*end == '\"') {
            in_quotes = !in_quotes;
        } else if ((*end == ' ' || *end == '\t' || *end == '\n') && !in_quotes) {
            *end = '\0';
            args[i++] = start;
            start = end + 1;
        }
        end++;
    }
    args[i++] = start;
    args[i] = NULL;

    return args;
}