# 🦙 Módulo 2 - Exercícios 🦙 

Neste diretório estão os exercícios resolvidos do secundo módulo. 

> [!TIP]
> Para resolução desses exercícios, o github copilot autocomplete foi desabilitado no vscode50. Tente também resolve-los apenas com os conceitos aprendidos nas aulas, usando IA somente para validação dos códigos e pesquisa. 

## :technologist: Scrabble

Recebe duas palavras do usuário, do jogador 1 e do jogador 2, calcula os pontos de acordo com o score dado para cada letra, e imprime de qual jogador foi a maior pontuação.

```
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
```

### Entre no diretório do exercício:
```
cd scrabble
```

### Compile e execute:
```
make scrabble
./scrabble
```
### Input:
```
Jogador 1: COMPUTER 
Jogador 2: science 
```
### Output:
```
Jogador 1 venceu!
```

## :technologist: Legibilidade

Calcula e imprime o nível exigido para leitura de um texto, baseado no índice Coleman-Liau 

```
indice = 0.0588 * L - 0.296 * S - 15.8
```

### Entre no diretório do exercício:
```
cd readability
```

### Compile e execute:
```
make readability
./readability
```
### Input:
```
Texto: Congratulations! Today is your day. You're off to Great Places! You're off and away!
```
### Output:
```
Grade: 3
```

## :technologist: Caesar

Criptografa mensagens usando a cifra de César. <br>
O programa deve receber a chave numérica como parâmetro na linha de comando.

### Entre no diretório do exercício:
```
cd caesar
```

### Compile e execute:
```
make caesar
./caesar [key]
```
### Input:
```
$ ./caesar 13
plaintext:  hello, world
```
### Output:
```
ciphertext: uryyb, jbeyq
```

## :technologist: Substituição

Recebe uma chave de cifra como parâmetro na linha de comando no seguinte formato :<br>
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
``` 
26 letras sem repetições e sem distinção entre maiúsculas e minúsculas <br>
Valida se a sequência de digitos inseridos pelo usuário corresponde aos requisitos. <br>
Recebe um texto puro do usuário, e então imprime o texto com as letras substituidas conforme a chave dada.

### Entre no diretório do exercício:
```
cd substitution
```

### Compile e execute:
```
make substitution
./substitution [cipher]
```
### Input:
```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
texto simples: hello, world
```
### Output:
```
texto cifrado: jrssb, ybwsp
```