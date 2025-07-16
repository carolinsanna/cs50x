# 🦙 Módulo 1 - Exercícios 🦙 

Neste diretório estão os exercícios resolvidos do primeiro módulo. 

> [!TIP]
> Para resolução desses exercícios, o github copilot autocomplete foi desabilitado no vscode50. Tente também resolve-los apenas com os conceitos aprendidos nas aulas, usando IA somente para validação dos códigos e pesquisa. 

## :technologist: Mario

Imprime uma pirâmide de '#' alinhada à direita com uma altura inserida pelo usuário. <br>
O input é lido até que o usuário insira um valor entre 1 e 8.

### Entre no diretório do exercício:
```
cd mario
```

### Compile e execute:
```
make mario
./mario
```
### Input:
```
Digite a altura da pirâmide (o valor deve estar entre 1 e 8):
Digite a altura da pirâmide (o valor deve estar entre 1 e 8): -2
Digite a altura da pirâmide (o valor deve estar entre 1 e 8): 9 
Digite a altura da pirâmide (o valor deve estar entre 1 e 8): 8
```
### Output:
```
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```

## :technologist: Mario (desafio)

Imprime duas pirâmides de '#', uma alinhada à esquerda e outra alinhada à direita, separadas por dois espaços.
A altura é recebida do usuário até que ele insira um valor entre 1 e 8.

### Entre no diretório do exercício:
```
cd mario-challenge
```

### Compile e execute:
```
make mario
./mario
```
### Input:
```
Digite a altura da pirâmide (o valor deve estar entre 1 e 8):
Digite a altura da pirâmide (o valor deve estar entre 1 e 8): -2
Digite a altura da pirâmide (o valor deve estar entre 1 e 8): 9 
Digite a altura da pirâmide (o valor deve estar entre 1 e 8): 8
```
### Output:
```
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

## :technologist: Cash

Calcula qual é o menor número possível de moedas dadas em troco. O valor do troco é recebido do usuário até que ele insira um valor positivo. A moedas disponíveis para troco são de: 25, 10, 5 e 1.

### Entre no diretório do exercício:
```
cd cash
```

### Compile e execute:
```
make cash
./cash
```
### Input:
```
Entre com o valor do troco: -0.41
Entre com o valor do troco: foo
Entre com o valor do troco: 0.41
```
### Output:
```
4
```

> [!NOTE]
> Na saída desse código foram colocados os nomes das moedas para testar se a contagem estava passando pelos condicionais corretos. 

## :technologist: Credit (desafio)

Lê a entrada do usuário até que ele insira somente números (sem hífen, texto, etc). <br> 
Valida se a sequência de digitos inseridos pelo usuário corresponde a um cartão de crédito válido utilizando o algoritmo de Luhn, imprimindo a bandeira em seguida.

### Entre no diretório do exercício:
```
cd credit
```

### Compile e execute:
```
make credit
./credit
```
### Input:
```
Entre com o número do cartão de crédito: 4003-6000-0000-0014
Entre com o número do cartão de crédito: foo
Entre com o número do cartão de crédito: 4003600000000014
```
### Output:
```
VISA
```
### Cenário em que a entrada é válida, mas não corresponde aos requisitos do algoritmo de Luhn
### Input:
```
Entre com o número do cartão de crédito: 6176292929
```
### Output:
```
INVALID
```
