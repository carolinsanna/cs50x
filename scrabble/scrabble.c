#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int W_INDEX = 2;
int WINNER = 3;

bool verify_chars(string word);
int compute_scores(string word);
void winner(int scores[], int check_winner);


int main(void){

    string words[W_INDEX];
    int score[W_INDEX];

    for(int i = 0; i < W_INDEX; i++){

        do{
            words[i] = get_string("Jogador %i:\n", i+1);

        } while(verify_chars(words[i])==true);

        for(int j = 0; j < W_INDEX; j++){
            score[i] = compute_scores(words[i]);
        }
    }

    winner(score, WINNER);

    return 0;
}

bool verify_chars(string word){

    bool no_word = true;

    for(int i = 0, n = strlen(word); i < n; i++){
        if((word[i] < 65 || word[i] > 90) && (word[i] < 97 || word[i] > 122)){
            no_word = true;
            i = n;
        } else {
            no_word = false;
        }
    }

    return no_word;
}

int compute_scores(string word){

    int score = 0;

    for(int i = 0, n = strlen(word); i < n; i++){
        if(word[i] >= 65 && word[i] <= 90){
            int index = word[i]-65;
            score += POINTS[index];
        } else if(word[i] >= 97 && word[i] <= 122){
            int index = word[i]-97;
            score += POINTS[index];
        }
    }

    return score;
}

void winner(int scores[], int check_winner){

    int winner = check_winner;
    int greater = 0;

    for(int i = 0; i < W_INDEX; i++){
        if(greater < scores[i]){
            greater = scores[i];
            winner = i;
        } else if(greater == scores[i]){
            winner = check_winner;
        }
    }

    if (winner < check_winner){
        printf("O Jogador %i venceu!\n", winner+1);
        printf("%i\n", scores[winner]);
    } else {
        printf("Empate!\n");
    }

}