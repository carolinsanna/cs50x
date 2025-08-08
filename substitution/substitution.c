#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool key_validation(string key);
string get_message(void);
string substitution(string key, string message);

int main(int argc, string argv[]){

    if(argc != 2){
        printf("Use: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if(key_validation(key) == 0){
        string message = get_message();
        string cipher_message = substitution(key, message);

        printf("ciphertext: %s\n", cipher_message);
    }

    return 0;
}

bool key_validation(string key){
    if(strlen(key) != 26){
        printf("Use: ./substitution key\n");
        return 1;
    } else {
        string key_aux = key;
        for(int index = 1, n = strlen(key); index < n; index++){
            if(isalpha(key[index])){
                if(islower(key[index]) && isupper(key_aux[index-1])){
                    if(key[index] == (key_aux[index-1]+32)){
                        printf("Use: ./substitution key\n");
                        return 1;
                    }
                } else if(isupper(key[index]) && islower(key_aux[index-1])){
                    if(key[index] == (key_aux[index-1]-32)){
                        printf("Use: ./substitution key\n");
                        return 1;
                    }
                } else if(key[index] == key_aux[index-1]){
                    printf("Use: ./substitution key\n");
                    return 1;
                }
            } else {
                printf("Use: ./substitution key\n");
                return 1;
            }
        }
    }
    return 0;
}

string get_message(void){
    string message = get_string("Message: ");

    return message;
}

string substitution(string key, string message){
    string cipher_message = message;

    for(int index = 0, n = strlen(cipher_message); index < n; index++){
        if(isalpha(cipher_message[index])){
            if(isupper(cipher_message[index])){
                int jindex = cipher_message[index]-65;
                if(isupper(key[jindex])){
                    cipher_message[index] = key[jindex];
                } else if(islower(key[jindex])){
                    cipher_message[index] = key[jindex]-32;
                }
            } else if(islower(cipher_message[index])){
                int kindex = cipher_message[index]-97;
                if(isupper(key[kindex])){
                    cipher_message[index] = key[kindex]+32;
                } else if(islower(key[kindex])){
                    cipher_message[index] = key[kindex];
                }
            }
        }
    }

    return cipher_message;
}