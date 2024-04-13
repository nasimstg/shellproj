#include "util.h"

void logout(char *str)
{
    if (str == NULL)
    {
        exit(0);
    }
    printf("%s\n", str);
    exit(0);
}
