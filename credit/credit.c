#include <cs50.h>
#include <stdio.h>

long get_credit_card_number(void);
int checkdigits(long card_number);
void checksum(long card_number, int digits);

int main(void){

    long card_number = get_credit_card_number();
    int digits = checkdigits(card_number);

    if(digits > 12){
        checksum(card_number, digits);
    } else {
        printf("INVALID\n");
    }

}

// Espera do usuário uma sequencia de digitos longa, sem hífens
long get_credit_card_number(void){

    long card_number;

    do{
        card_number = get_long("Entre com o número do cartão de crédito: ");
    } while (card_number <= 0);


    return card_number;
}

// Conta quantos digitos possui a entrada do usuário
int checkdigits(long card_number){

    int digits = 0;
    long card = card_number;

    while(card > 0) {
        card/=10;
        digits++;
    }

    return digits;
}

// Valida se a sequencia de digitos é um cartão de crédito válido,
// se sim, imprime qual deles é: AMEX, MASTERCARD ou VISA,
// senão, imprime INVALID
void checksum(long card_number, int digits){

    long card = card_number;
    int module_ten = 0;
    int mult = 0;
    int sum_mult = 0;
    int sum = 0;
    int initial = 0;
    int temp_card = 0;

    for(int count = 1; count <= digits; count++){
        module_ten = card%10;
        if(count  == digits-1){
            temp_card=card/10;
            temp_card%=10;
            if(digits == 15){
                if(module_ten == 7 || module_ten == 4){
                    if(temp_card == 3) {
                        initial=1;
                    }
                }
            } else if (digits == 13 || digits == 16){
                if(temp_card == 4){
                    initial=2;
                } else if(digits == 16){
                    if(module_ten == 1 || module_ten == 2 || module_ten == 3 || module_ten == 4 || module_ten == 5){
                        if(temp_card == 5){
                            initial=3;
                        }
                    }
                }
            }
        }

        if(count%2 == 0){
            mult = module_ten*2;
            if(mult > 9){
                sum_mult = 0;
                while(mult > 0){
                    sum_mult+=mult%10;
                    mult/=10;
                }
                sum+=sum_mult;
            } else {
                sum+=mult;
            }
        } else {
            sum+=module_ten;
        }
        card/=10;
    }

    if(sum%10 == 0){
        switch (initial) {
            case 1:
            printf("AMEX\n");
            break;
            case 2:
            printf("VISA\n");
            break;
            case 3:
            printf("MASTERCARD\n");
            break;
            default:
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}