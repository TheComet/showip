#include <stdio.h>
#include "showip/showip.h"

void show_help(const char* prog_name)
{
    printf("Usage: %s <hostname> [port]\n", prog_name);
}

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        show_help(argv[0]);
        return 0;
    }

    showip(argv[1], 0); // ports not implemented yet

    return 0;
}
