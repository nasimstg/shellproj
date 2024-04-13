#include "src.h"

int main()
{
    printf("\n                  aSPY//YASa\n");
    printf("             apyyyyCY//////////YCa          /\n");
    printf("            sY//////YSpcs scpCY//Pp         / Welcome to myShell\n");
    printf("  ayp ayyyyyyySCP//Pp           syY//C      / Version 2.4.3\n");
    printf("  AYAsAYYYYYYYY///Ps              cY//S     /\n");
    printf("          pCCCCY//p          cSSps y//Y     / https://github.com/<user>\n");
    printf("          SPPPP///a          pP///AC//Y     /\n");
    printf("                A//A           cyP////C     / Have fun!\n");
    printf("                p///Ac            sC///a    /\n");
    printf("                P////YCpc           A//A    / Craft packets like it is your last\n");
    printf("            scccccp///pSP///p       p//Y    / day on earth.\n");
    printf("           sY/////////y   caa       S//P    /                       -- Lao-Tze\n");
    printf("            cayCyayP//Ya           pY/Ya    /\n");
    printf("             sY/PsY////YCc        aC//Yp\n");
    printf("              sc sccaCY//PCypaapyCP//YSs\n");
    printf("                      spCPY//////YPSps\n");
    printf("                           ccaacs\n");
    printf("                                          using\n");

    char *line = NULL;

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