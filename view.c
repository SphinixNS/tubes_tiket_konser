#include "view.h"


void main_menu() 
{
    printf("Hello World");
    scanf("%*c");
    switch (1)
    {
    case 1:
        register_user();
        break;
    
    default:
        break;
    }
    return 0;
}

void tambah_data(int a, int b) 
{
    printf("Tambah data");
}

void register_user() 
{
    printf("Register");
}