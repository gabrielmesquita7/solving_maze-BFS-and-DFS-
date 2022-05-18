<h1 align="center">Solving Maze (DFS / BFS)</h1>


<p align="center">Grupo: Gabriel Mesquita || Augusto Bebiano</p>
<h1 align="center"> 
    <a href="https://github.com/gabrielmesquita7/solving_maze-BFS-and-DFS-/graphs/contributors">
    <img src="https://contrib.rocks/image?repo=gabrielmesquita7/solving_maze-BFS-and-DFS-" />
    </a>
</h1>
<p align="center">
  <a href="#problema">Problema</a> -
  <a href="#desenvolvimento">Desenvolvimento</a> -
  <a href="#entrada">Entrada</a> -
  <a href="#interacoes">Interacoes</a> -
  <a href="#saida">Saida</a> -
  <a href="#executar">Executar</a>
</p>
 

# Problema
### Regras
1. O jogo deve ser elaborado utilizando um arquivo de configuração. Nele deve conter: (a) tamanho da matriz; (b) posições das paredes e; (c) tipo de busca.
1. O jogo termina assim que for atingido o alvo.

1. É preciso imprimir o caminho em tela sob uma representação de matriz. Então, imprima conforme o exercício de matriz já realizado.

### Perguntas
* Para diferentes tamanhos de matriz e posicionamento de paredes, há predominância de um dos dois algoritmos em termos de casas caminhadas e tempo de execução?
* Um dos dois algoritmos consegue encontrar o melhor caminho, ou seja, o com menor número de passos?

# Desenvolvimento
### O problema foi desenvolvido da seguinte maneira:

* É definido pelo usuario o tamanho da **fila** atribuindo o valor para **N** na função **define**
* É definido pelo usuario o tamanho da **pilha**  atribuindo o valor para **N** na função **define**

* ![image](https://user-images.githubusercontent.com/55333375/167706372-01a0bb6c-44d1-497e-8685-cdc1d21979c6.png)

* Também é definido um máximo de 1024 caracteres em uma linha

* ![image](https://user-images.githubusercontent.com/55333375/167706445-478ff54e-dc10-482c-a0a5-ccbca8d0e7f6.png)

* É feito a abertura do arquivo por meio do **fopen()** e depois tokenizado pela função **TokenizerM()**, dentro dessa função a primeira coisa sendo feita é a tokenização do tamanho da matriz, da posição dos obstaculos e do tipo de busca, e por fim iniciado a matriz de acordo com os parametros e retornando a mesma.

* Depois é executado a função **TipoCaminho()**
* Dentro da função é feito a passagem de um if/else com o tipo de busca especificado no arquivo de texto  para determinar o método a ser executado, por fim é executado o método escolhido.
* Por fim é impresso a matriz com o caminho percorrido

# Entrada
### A entrada do usuário é feito no arquivo _gameconfig.txt_ e segue a seguinte estrutura:
Linha   | variavel
--------- | ------
1 | ( l x c ) -> Tamanho da matriz
2 | ( l x c ) , ( l x c ) , ... -> Posições dos obstaculos
3 | Tipo de busca

# Interacoes
### A contagem do numero de interações foi calculado de forma que considera cada checagem uma interação, ou seja, mesmo se houver obstaculo no caminho é contabilizado.

# Saida
### É esperado que a saida tenha o print da matriz após tokenizada, depois a matriz com o caminho percorrido de acordo com o tipo escolhido e por fim o numero de interações que aquele tipo gastou




# Executar
* Como executar:

```
  make clean
  make
  make run
```
