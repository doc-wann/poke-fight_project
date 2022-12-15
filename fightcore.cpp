#include "poke.h"

class BaseMonster
{
    public:
        int hp;
        const char    *name;
        int hp_max;
        int defense;
        int basic_attack;
        bool isfire;
        bool iswater;
        bool isice;
};

int rollDie(int min, int max)
{
    int roll;

    roll = 1 + (rand() % max);
    return (roll);
}

int ft_scan(void)
{
    int ret;
    scanf("%i", &ret);
    fflush(stdin);
    return (ret);
}

bool elementcounter(bool aisfire,bool aisice,bool aiswater,bool disfire,bool diswater,bool disice)
{
    if (aisfire == true && disice == true)
        return (true);
    else if (aisice == true && diswater == true)
        return (true);
    else if (aiswater == true && disfire == true)
        return (true);
    else
        return (false);
}

int combat(int name, int player)
{
    bool    combat;
    bool    turn;
    int     action;
    int     damage_player;
    int     dice_roll;
    int     dice_roll2;
    int     exp;

    BaseMonster dummy;
    dummy.hp = enemydata(name, 1);
    dummy.name = enemydatastring(name, 1);
    dummy.hp_max = enemydata(name, 1);
    dummy.defense = enemydata(name, 3);
    dummy.basic_attack = enemydata(name, 4);
    dummy.isfire = enemydatabool(name, 1);
    dummy.iswater = enemydatabool(name, 2);
    dummy.isice = enemydatabool(name, 3);

    BaseMonster pokemon;
    pokemon.hp = enemydata(player, 1);
    pokemon.name = enemydatastring(player, 1);
    pokemon.hp_max = enemydata(player, 1);
    pokemon.defense = enemydata(player, 3);
    pokemon.basic_attack = enemydata(player, 4);
    pokemon.isfire = enemydatabool(player, 1);
    pokemon.iswater = enemydatabool(player, 2);
    pokemon.isice = enemydatabool(player, 3);

    combat = true;
    turn = true;
    damage_player = 0;

    while (combat == true)
    {
        // PLAYER TURN
        while (turn == true)
        {
            pokemon.hp -= damage_player;
            damage_player = 0;
            draw(player, name, dummy.hp, pokemon.hp);

            start_turn(1, dummy.name, dummy.hp, dummy.hp_max);
            action = ft_scan();
            ft_cleanline(100);
            //ATAQUE, DEFESA e SUPER-ATAQUE
            if (action == 1 || action == 2 || action == 3 || action == 4)
            {
                //ATAQUE
                if (action == 1)
                {
                    srand(time(NULL));
                    dice_roll = rand() % 20 + pokemon.basic_attack + 1;
                    if (dice_roll >= dummy.defense)
                    {
                        damage_player = hit_basic(1, pokemon.basic_attack, pokemon.name);
                    }
                    else
                        hit_miss(1, pokemon.name, dice_roll, dummy.defense);
                }
                //DEFESA
                else if (action == 2)
                {
                    printf(" > Seu %s se defende do proximo ataque, aumentando sua defesa em 5!", pokemon.name);
                    pokemon.defense += 5;
                }
                //ATAQUE ESPECIAL
                else if (action == 3)
                {
                    srand(time(NULL));
                    dice_roll = rand() % 20 + pokemon.basic_attack + 1;
                    if (dice_roll >= dummy.defense)
                    {
                        if (elementcounter(pokemon.isfire, pokemon.isice, pokemon.iswater, dummy.isfire, dummy.iswater, dummy.isice) == true)
                        {
                            damage_player = hit_crit(1, pokemon.basic_attack, pokemon.name);
                        }
                        else
                        {
                            damage_player = hit_basic(1, pokemon.basic_attack, pokemon.name);
                        }
                    }
                    else
                        hit_miss(1, pokemon.name, dice_roll, dummy.defense);
                }
                else if (action == 4)
                {
                    printf("ESTATISTICAS DO POKEMON: \n > Nome: %s\n > Vida: %i/%i \n > Defesa: %i \n > Ataque: %i \n ", pokemon.name, pokemon.hp, pokemon.hp_max, pokemon.defense, pokemon.basic_attack);
                    if (pokemon.isfire == true)
                        printf("> Tipo: Fogo\n");
                    else if (pokemon.iswater == true)
                        printf("> Tipo: Agua\n");
                    else if (pokemon.isice == true)
                        printf("> Tipo: Gelo\n");
                    printf("Voltando para o menu em 6 segundos...");
                    printf("\n\n");
                    sleep(6);
                    ft_cleanline(100);
                }
                if (action != 4)
                {
                    sleep(4);
                    dummy.defense = enemydata(name, 3);
                    turn = false;
                }
                else
                    turn = true;
            }
            else
                turn = true;
            ft_cleanline(100);
        }
        // TURNO DO INIMIGO
        while (turn == false)
        {
            dummy.hp -= damage_player;
            damage_player = 0;

            draw(player, name, dummy.hp, pokemon.hp);

            if (dummy.hp <= 0)
            {
                combat = false;
                break ;
            }
            start_turn(2, dummy.name, dummy.hp, dummy.hp_max);
            sleep(2);
            dice_roll = rand() % 5 + 1;
            if (dice_roll == 0)
            {
                printf(" > Falha critica! O oponente perdeu o turno!");
            }
            else if (dice_roll == 1)
            {
                printf(" > Seu inimigo, um %s, se defende do proximo ataque, aumentando sua defesa em 5!", dummy.name);
                dummy.defense += 5;
            }
            else if (dice_roll == 2 || dice_roll == 3)
            {
                srand(time(NULL));
                dice_roll2 = rand() % 20 + dummy.basic_attack + 1;
                if (dice_roll2 >= pokemon.defense)
                {
                    if (elementcounter(dummy.isfire, dummy.isice, dummy.iswater, pokemon.isfire, pokemon.iswater, pokemon.isice) == true)
                    {
                        damage_player = hit_crit(2, pokemon.basic_attack, pokemon.name);
                    }
                    else
                    {
                        damage_player = hit_basic(2, dummy.basic_attack, dummy.name);
                    }
                }
                else
                    hit_miss(2, dummy.name, dice_roll2, pokemon.defense);
            }
            else if (dice_roll >= 4)
            {
                srand(time(NULL));
                dice_roll2 = rand() % 20 + dummy.basic_attack + 1;
                if (dice_roll2 >= pokemon.defense)
                {
                    damage_player = hit_basic(2, dummy.basic_attack, dummy.name);
                }
                else
                    hit_miss(2, dummy.name, dice_roll2, pokemon.defense);
            }
            sleep(4);
            ft_cleanline(100);
            pokemon.defense = enemydata(player, 3);
            turn = true;
        }
    }
    exp = rand()%pokemon.hp + 1;
    printf(" > Voce derrotou o pokemon inimigo! Seu pokemon ganhou %i pontos de experiencia!", exp); 
    sleep(4);
    return (exp);
}