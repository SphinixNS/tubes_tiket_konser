
#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void countdownClear(int count)
{

    for (int i = count; i >= 1; i--)
    {
        printf("\r[%s] ", "\\");
        Sleep(250);
        printf("\r[%s] ", "|");
        Sleep(250);
        printf("\r[%s] ", "/");
        Sleep(250);
        printf("\r[%s] ", "-");
        Sleep(250);
        fflush(stdout);
    }

    printf("\n");
    system("cls");
}