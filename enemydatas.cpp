#include "poke.h"

int     enemydata(int name, int number)
{
    //CHARMANDER STATS
    if (name == 1)
    {
        //CURRENT HP
        if (number == 1)
        {
            return(21);
        }
        //TOTAL HP
        else if (number == 2)
        {
            return(21);
        }
        //DEFENSE
        else if (number == 3)
        {
            return(15);
        }
        else if (number == 4)
        {
            return(8);
        }
    }
    //SQUIRTLE STATS
    else if (name == 2)
    {
        //CURRENT HP
        if (number == 1)
        {
            return(30);
        }
        //TOTAL HP
        else if (number == 2)
        {
            return(30);
        }
        //DEFENSE
        else if (number == 3)
        {
            return(17);
        }
        else if (number == 4)
        {
            return(6);
        }
    }
    //GLACEON STATS
    else if (name == 3)
    {
        //CURRENT HP
        if (number == 1)
        {
            return(20);
        }
        //TOTAL HP
        else if (number == 2)
        {
            return(20);
        }
        //DEFENSE
        else if (number == 3)
        {
            return(15);
        }
        else if (number == 4)
        {
            return(10);
        }
    }
    else
        return (0);
}

bool     enemydatabool(int name, int number)
{   
    //CHARMANDER STATS
    if (name == 1)
    {
        //FIRE TYPE
        if (number == 1)
        {
            return(true);
        }
        //WATER TYPE
        else if (number == 2)
        {
            return(false);
        }
        //ICE TYPE
        else if (number == 3)
        {
            return(false);
        }
    }
    //SQUIRTLE STATS
    else if (name == 2)
    {
        //FIRE TYPE
        if (number == 1)
        {
            return(false);
        }
        //WATER TYPE
        else if (number == 2)
        {
            return(true);
        }
        //ICE TYPE
        else if (number == 3)
        {
            return(false);
        }
    }
    //GLACEON STATS
    else if (name == 3)
    {
        //FIRE TYPE
        if (number == 1)
        {
            return(false);
        }
        //WATER TYPE
        else if (number == 2)
        {
            return(false);
        }
        //ICE TYPE
        else if (number == 3)
        {
            return(true);
        }
    }
    else
        return (false);
}

const char     *enemydatastring(int name, int number)
{
    //CHARMANDER STATS
    if (name == 1)
    {
        //POKEMON NAME
        if (number == 1)
            return("Charmander");
    }
    //SQUIRTLE STATS
    else if (name == 2)
    {
        //POKEMON NAME
        if (number == 1)
            return("Squirtle");
    }
    //GLACEON STATS
    else if (name == 3)
    {
        //POKEMON NAME
        if (number == 1)
            return("Glaceon");
    }
    else
        return("ERROR");
}
