#include "util.h"

char *build_path(char **args, int num_args)
{
    int total_length = 0;
    for (int i = 0; i < num_args; i++){
        total_length += strlen(args[i]) + 1;
    }

    char *path = malloc(total_length * sizeof(char));
    path[0] = '\0';

    for (int i = 0; i < num_args; i++){
        if (args[i][0] == '"'){
            char *end_quote = strchr(args[i] + 1, '"');
            if (end_quote){
                args[i]++;
                *end_quote = '\0';
            }
        }

        if (i < num_args - 1)
            snprintf(path + strlen(path), total_length - strlen(path), "%s/", args[i]);
        else snprintf(path + strlen(path), total_length - strlen(path), "%s", args[i]);
    }

    return path;
}