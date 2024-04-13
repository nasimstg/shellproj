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

    do
    {
        getLocation();

        char *line = NULL;
        size_t len = 0;
        if (getline(&line, &len, stdin) == -1)
        {
            break;
        }

        line[strcspn(line, "\n")] = 0;

        char **tokens = splitArgument(line);
        char **argv1 = tokens;
        char **argv2 = NULL;

        for (int i = 0; tokens[i] != NULL; i++)
        {
            if (strcmp(tokens[i], "|") == 0)
            {
                tokens[i] = NULL;
                argv2 = &tokens[i + 1];
                break;
            }
        }

        if (argv2)
        {
            mypipe(argv1, argv2);
        }
        else
        {
            execmd(argv1[0], &argv1[1]);
        }

        free(tokens);
        free(line);

    } while (1);

    return 0;
}