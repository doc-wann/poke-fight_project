#include "poke.h"

int map(int command)
{
    static char    map[7][14] = {".M...M....M. ", "............ ", "............ ", "............ ", "............ ", "............ ", "............ "};
    static int     posv = 6;
    static int     posh = 6;
    int            ret;
    int            sizeofmap;

    map[4][5] = 'X';
    sizeofmap = 7;
    map[posv][posh] = '.';
    ret = 1;
    if (command == 119)
    {
        if (posv == 0 || map[posv - 1][posh] == 'M')
            ret = 0;
        else
            posv -= 1;
    }
    else if (command == 115)
    {
        if (posv == sizeofmap - 1 || map[posv + 1][posh] == 'M')
            ret = 0;
        else
            posv += 1;
    }
    else if (command == 97)
    {
        if (posh == 0 || map[posv][posh - 1] == 'M')
            ret = 0;
        else
            posh -= 1;
    }
    else if (command == 100)
    {
        if (posh == strlen(map[posv]) - 2 || map[posv][posh + 1] == 'M')
            ret = 0;
        else
            posh += 1;
    }
    else 
        ret = 0;
    ft_cleanline(20);
    printf("\n ret = %i h = %i v = %i \n", ret, posh, posv);
    map[posv][posh] = '0';
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", map[0], map[1], map[2], map[3], map[4], map[5], map[6], map[7]);
    if (posv == 4 && posh == 5)
        return (4);
    return (ret);
}