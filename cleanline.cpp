#include <stdio.h>
#include <unistd.h>

void    ft_cleanline(int qtt)
{
    while (qtt != 0)
    {
        printf("\x1b[1F"); // Move to beginning of previous line
        printf("\x1b[2K"); // Clear entire line
        qtt--;
    }
}