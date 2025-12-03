#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("chcp 65001 > nul");
    tampilMenuAwal();
    return 0;
}
