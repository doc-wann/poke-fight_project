#include "poke.h"

void start_turn(int mark, const char *name, int hp_actual, int hp_max)
{
    if (mark == 1)
    {
        printf("\n > Turno do Jogador!                                                                      \n > Seu inimigo e um %s, com %i/%i pontos de vida.                                                     \n", name, hp_actual, hp_max);
        printf("\n   1- Ataque Basico || 2- Defender || 3- Ataque elemental || 4- Estatisticas\n\n   Escolha: ");
    }
    else
    {
        printf("\n > Turno do %s inimigo!                                                             \n", name);
    }
}

int hit_basic(int   marker, int attack, const char *name)
{
    int damage;

    if (marker == 1)
    {
        damage =  rand() % attack + 1;
        printf(" > Seu %s ataca, causando %i pontos de dano!", name, damage);
    }
    else
    {
        damage =  rand() % attack + 1;
        printf(" > O %s inimigo ataca, causando %i pontos de dano!\n", name, damage);
    }
    return (damage);
}

int hit_crit(int   marker, int attack, const char *name)
{
    int damage;

    if (marker == 1)
    {
        damage =  rand() % attack + 1;
        printf(" > Seu %s ataca, causando %i pontos de dano!\n Isso foi super efetivo!", name, (damage * 3));
    }
    else
    {
        damage =  rand() % attack + 1;
        printf(" > O %s inimigo ataca, causando %i pontos de dano!\n Isso foi super efetivo!", name, (damage * 3));
    }
    return ((damage * 3));
}

int hit_miss(int pon, const char *name, int dice, int needed)
{
    if (pon == 1)
        printf(" > Seu %s erra o ataque! Voce tirou %i, e precisava de %i...", name, dice, needed);
    else
        printf(" > O %s inimigo tenta atacar, mas erra! Ele tirou %i, e precisava de %i...", name, dice, needed);
    return (0);
}