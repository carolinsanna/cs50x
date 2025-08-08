#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string get_text(void);
int letters_counter(string text);
int words_counter(string text);
int sentences_counter(string text);
float coleman(int letters, int words, int sentences);

int main(void){
    string text = get_text();
    int letters = letters_counter(text);
    int words = words_counter(text);
    int sentences = sentences_counter(text);
    int coleman_index = floor(coleman(letters, words, sentences));

    if(coleman_index > 16){
        printf("Grade 16+\n");
    } else if(coleman_index < 1){
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", coleman_index);
    }

}

string get_text(void){
    string text = get_string("Text: ");
    return text;
}

int letters_counter(string text){
    int letters = 0;

    for(int i = 0, n = strlen(text); i < n; i++){
        if((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123)){
            letters++;
        }
    }

    return letters;
}

int words_counter(string text){
    int words = 0;

    for(int i = 0, n = strlen(text); i < n; i++){
        if(text[i] == 32 || ((text[i] == 46 || text[i] == 33 || text[i] == 63) && text[i+1] != 32)){
            words++;
        }

    }

    return words;
}

int sentences_counter(string text){
    int sentences = 0;

    for(int i = 0, n = strlen(text); i < n; i++){
        if(text[i] == 33 || text[i] == 46 || text[i] == 63){
            sentences++;
        }
    }

    return sentences;
}

float coleman(int letters, int words, int sentences){
    float index = 0.0598 * ((float)letters/((float)words/100)) - 0.296 * ((float)sentences/((float)words/100)) - 15.8;

    return index;
}