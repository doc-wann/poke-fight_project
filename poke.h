
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


void        ft_cleanline(int qtt);
int         draw(int player, int enemy, int hp_enemy, int hp_player);
int         enemydata(int name, int number);
bool        enemydatabool(int name, int number);
const char     *enemydatastring(int name, int number);
int         combat(int name, int player);
int         ft_scan(void);
int         map(int command);
void        loading(void);
void        loadingb(void);
int         hit_basic(int   marker, int attack, const char *name);
int         hit_miss(int pon, const char *name, int dice, int needed);
int         hit_crit(int   marker, int attack, const char *name);
void        start_turn(int mark, const char *name, int hp_actual, int hp_max);