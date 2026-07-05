/*Name-Ashutosh
Date-03/11/2025
project on mp3_tag reader*/
#include <stdio.h>
#include <string.h>
#include "edit.h"

void show_help()
{
    printf("\nUsage:\n");
    printf("  ./a.out -v <file>                           View tags\n");
    printf("  ./a.out -e <file>                           Edit tags \n");
    printf("  ./a.out --help                              Show this help message\n");
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        show_help();
        return 1;
    }

    if(strcmp(argv[1],"--help")==0)
    {
        show_help();
    }
    else if(strcmp(argv[1],"-v")==0)
    {
        if(argc==3)
            view_tags(argv[2]);     //  function to view tags
        else
        {
            printf("Invalid input.\n");
            show_help();
        }
    }
    else if(strcmp(argv[1],"-e")==0)
    {
        if(argc==3)
            edit_tags(argv[2]);     // edit function 
        else
        {
            printf("Invalid input.\n");
            show_help();
        }
    }
    else
    {
        printf("Invalid input.\n");
        show_help();
    }

    return 0;
}
