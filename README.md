# 🦙 CS50x Harvard Codes 🦙

# 🦙 Módulo 3 - Exercícios 🦙 

Neste diretório estão os exercícios resolvidos do 3 módulo. 

> [!TIP]
> Para resolução desses exercícios, o github copilot autocomplete foi desabilitado no vscode50. Tente também resolve-los apenas com os conceitos aprendidos nas aulas, usando IA somente para validação dos códigos e pesquisa. 

## :technologist: Ordenação

Analisar três programas de classificação para determinar quais algoritmos eles usam: <br>
<strong>selection sort</strong>, <strong>bubble sort</strong> ou <strong>merge sort</strong>. <br>

* O <strong>selection sort</strong> itera através das partes não classificadas de uma lista, selecionando o menor elemento a cada vez e movendo-o para seu local correto.

* O <strong>bubble sort</strong> compara pares de valores adjacentes, um de cada vez, e os troca se estiverem na ordem incorreta. Isso continua até que a lista seja classificada.

* O <strong>merge sort</strong> divide recursivamente a lista em duas repetidamente e, em seguida, mescla as listas menores de volta em uma maior na ordem correta.

### Solução 

### Baixe o arquivo .zip

Este arquivo contem: <br>
 - três programas escritos em C já compilados; <br>
 - vários arquivos de texto (.txt) para entrada de valores (como argumento na linha de comando); <br>
 - e um arquivo de texto <strong>answers.txt</strong> para inserir as respostas. 

```
wget https://cdn.cs50.net/2023/fall/psets/3/sort.zip
```

### Descompacte o .zip

```
unzip sort.zip
```

### Remova o .zip do diretório atual

```
rm sort.zip
```

### Entre no diretório do exercício:
```
cd sort
```

### Teste cada um dos programas com as entradas fornecidas

```
./[nome_do_programa] [arquivo_texto.txt]
```
> [!NOTE]
> Para esta etapa fiz um programa em C chamado timer que executa o comando acima automaticamente no terminal, testando todos os programas 'sort' com todos os arquivos de entrada .txt e, ao final, gera um relatório em 'output.csv' com cada um dos testes e seu respectivo tempo de execução.

### Compile e execute o timer: 
```
make timer
./timer
```

### Output:
```
...
49996
49997
49998
49999
50000
Arquivo 'output.csv' gerado com sucesso!
```

## Análise

Ao executar três programas de ordenação (sort1, sort2, sort3) sobre nove arquivos (listas aleatórias, ordenadas e invertidas, com 5k/10k/50k elementos) e medir o tempo de execução, concluí: <br> 

- <b> sort1 é Bubble Sort </b> (com parada antecipada): apresentou forte queda de tempo quando a entrada já estava ordenada (ex.: 50k caiu de ~6,76 s no aleatório para ~0,73 s no ordenado), o que é típico do Bubble com detecção de ausência de trocas; além disso, o crescimento em entradas aleatórias foi próximo de quadrático (5k→50k ≈ 122×).

- <b> sort2 é Merge Sort </b>: foi o mais rápido em 50k (~0,74–0,85 s) e praticamente insensível à ordem inicial (random/sorted/reversed parecidos). O crescimento ficou muito abaixo de n² (5k→50k ≈ 26×), condizente com a ordem O(n log n).

- <b> sort3 é Selection Sort: </b> manteve tempos semelhantes entre ordenado/aleatório/invertido e foi substancialmente mais lento que o sort2 em 50k (~2,77–3,09 s), comportamento esperado de um algoritmo O(n²) sem ganho no melhor caso.