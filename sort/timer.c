//Por Carolina Dias
//@carolinsanna

#define _POSIX_C_SOURCE 200809L
#include <time.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
		//Cria um ponteiro para o endereço de memória onde vamos abrir o arquivo
    FILE *output_csv;

		//Abre o arquivo no endereço de memória
    output_csv = fopen("output.csv", "w");

		//Verifica se o arquivo está ocupando memória
    if(output_csv == NULL) {
			printf("Erro ao abrir o arquivo! Tente novamente.\n");
			return 1;
    }
		
		//Define o cabeçalho do arquivo csv para identificar as informações nas linhas subsequentes
		//Programa -- Arquivo -- Tempo de execução
		fprintf(output_csv, "Program,File,Runtime\n");

		//Inicializa dois vetores com comandos que serão passado como parâmetros para automzatizar a execução dos 3 programas com 9 entradas cada um    
		string programs[] = {"sort1", "sort2", "sort3"};
    string args[] = {"random5000.txt", "random10000.txt", "random50000.txt", "reversed5000.txt", "reversed10000.txt", "reversed50000.txt", "sorted5000.txt", "sorted10000.txt", "sorted50000.txt", };

		//Inicializa o buffer de comando
    char comand[30];

		//Percorre os arrays para gerar os comandos dinamicamente
    for(int i = 0; i < 3; i++){
        string program = programs[i];

        for(int j = 0; j < 9; j++){
            string file = args[j];

						//'Monta' o comando numa variável do tipo string
            sprintf(comand, "./%s %s", program, file);

						//Inicializa as variáveis e a struct do timer
            struct timespec start, end;
            double timer;

						//Inicia a contagem da execução
            clock_gettime(CLOCK_MONOTONIC, &start);

						//Executa o comando da iteração atual, através de uma chamada de sistema
						//Ex.: ./sort1 random50000.txt
            system(comand);

						//Encerra a contagem da execução
            clock_gettime(CLOCK_MONOTONIC, &end);

						//Calcula o tempo -- dividindo em nanossegundos para gerar uma maior precisão -- levando em conta decimais e não apenas inteiros
            timer = (end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/1e9;

						//Escreve em uma linha do arquivo o resultado no mesmo formato do cabeçalho
						//Programa, arquivo, tempo de execução
            fprintf(output_csv, "%s %s %.9fseg\n", program, file, timer);

        }
    }

		//Fecha o arquivo
    fclose(output_csv);

    printf("Arquivo 'output.csv' gerado com sucesso!\n");

    return 0;
}