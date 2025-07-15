#include <cs50.h>
#include <stdio.h>

int get_height(void);
void constructor(int height);

int main(void)
{
    int height = get_height();
    constructor(height);
}

//Recebe do usuário o valor da altura das pirâmides e valida se está entre 1 e 8 inclusos
int get_height(void)
{
    int height;

    do
    {
        height = get_int("Digite a altura da pirâmide (o valor deve estar entre 1 e 8): ");
    } while (height < 1 || height > 8);

    return height;
}

//Constrói as pirâmides de #
void constructor(int height)
{
    for(int row = 0; row < height; row++)
    {
        for(int espace = 0; espace < height - row - 1; espace++)
        {
            printf(" ");
        }
        for(int leftHashes = 0; leftHashes <= row; leftHashes++)
        {
            printf("#");
        }
        printf("  ");
        for(int rightHashes = 0; rightHashes <= row; rightHashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
