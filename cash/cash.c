#include <cs50.h>
#include <stdio.h>

float get_positive_number(void);
void verify_exchange(float exchange);

int main(void)
{
    float exchange = get_positive_number();
    verify_exchange(exchange);
}

// Espera do usuário um valor flutuante positivo
float get_positive_number(void)
{
    float exchange;

    do
    {
        exchange = get_float("Entre com o valor do troco: ");
    } while (exchange < 0);

    return exchange;
}

// Separa o troco com o menor numero de moedas possível
void verify_exchange(float exchange)
{
    int coins = 0;
    int money = exchange * 100;

    while (money>0)
    {
        if(money>=25)
        {
            money -= 25;
            coins ++;
            printf("quarter\n");
        }
        else if(money>=10)
        {
            money -= 10;
            coins++;
            printf("dimmie\n");
        }
        else if(money>=5)
        {
            money -= 5;
            coins++;
            printf("nickel\n");
        }
        else
        {
            money -= 1;
            coins++;
            printf("penny\n");
        }
    }

    printf("%i\n", coins);

}