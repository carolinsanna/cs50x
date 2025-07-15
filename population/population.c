#include <cs50.h>
#include <stdio.h>

int get_start_llama(void);
int get_final_llama(int start_llama);
void llamas_calc(int start_llama, int final_llama);

int main(void){
    int start_population = get_start_llama();
    int final_population = get_final_llama(start_population);
    llamas_calc(start_population, final_population);
}

// Lê o valor inicial da população
int get_start_llama(void){
    int start_llama;

    do {
        start_llama = get_int("Quantas llamas tem agora? ");
    } while (start_llama < 9);

    return start_llama;
}

//Lê o valor de população que se quer atingir
int get_final_llama(int start_llama){
    int final_llama;

    do {
        final_llama = get_int("Quantas llamas quer ter? ");
    } while (final_llama < start_llama);

    return final_llama;
}

// Calcula quantos anos inteiros são necessários para atingir a população desejada
void llamas_calc(int start_llama, int final_llama){
    int n_llamas = start_llama;
    int years = 0;

    while (n_llamas < final_llama){
        n_llamas = n_llamas + (n_llamas/3) - (n_llamas/4);
        years++;
    }

    printf("Years: %i\n", years);
}