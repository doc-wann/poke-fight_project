#include "poke.h"

int main(void)
{
    int ismap;
    int input1;
    int input2;

    srand(time(NULL));
    printf("Seed: %i, %i, %i, %i, %i\n", rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1);
    sleep(2);
    // loading();
    // ft_cleanline(100);
    while (ismap != 4)
        ismap = map(getch());
    ft_cleanline(100);
    // loadingb();
    printf("Escolha seu Pokemon!\n > 1 - Charmander\n > 2 - Squirtle\n > 3 - Glaceon\n\n Escolha :");
    input1 = ft_scan();
    ft_cleanline(100);
    printf("Escolha o Pokemon inimigo!\n > 1 - Charmander\n > 2 - Squirtle\n > 3 - Glaceon\n\n Escolha :");
    input2 = ft_scan();
    ft_cleanline(100);
    combat(input2, input1);
    return (0);
}