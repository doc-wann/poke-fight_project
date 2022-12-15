#include "poke.h"                                                                                                    
int draw(int player, int enemy, int hp_enemy, int hp_player)
{                                                                                                
    printf("         %s VS %s            \n                              &&&        \n                             &&&&&&      \n        &&&&                   &&&&&     \n      &&&&&                     &&&&&&   \n      &&&&                   PV: %i/%i   \n      &&&&&&                             \n    PV: %i/%i                            \n", enemydatastring(player, 1), enemydatastring(enemy, 1), hp_enemy, enemydata(enemy, 1), hp_player, enemydata(player, 1));
    return (0);
}