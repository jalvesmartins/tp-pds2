# README

## Visão Geral

O objetivo deste projeto é desenvolver um sistema que simula a execução de diferentes jogos de tabuleiro, utilizando o paradigma de orientação a objetos. Os jogos implementados são: Reversi (Othello), Lig4 (Conecta 4) e Jogo da Velha (TickTackToe). O sistema permite o cadastro de jogadores, mantendo suas estatísticas de vitórias e derrotas, e possibilita a execução de partidas entre jogadores, com verificação da validade das jogadas e condições de vitória.

O sistema foi desenvolvido de forma modular e orientada a objetos, utilizando classes abstratas e herança para a implementação dos jogos. Além disso, o programa conta com um módulo de cadastro de jogadores que permite a persistência das informações em arquivos.

## Jogos Implementados

### 1. **Reversi (Othello)**

Reversi é um jogo de tabuleiro de dois jogadores, onde cada jogador deve tentar virar as peças do adversário através de jogadas estratégicas. O objetivo é conseguir o maior número de peças próprias no tabuleiro ao final do jogo. O tabuleiro de Reversi tem dimensões de 8x8 e o jogo começa com 4 peças posicionadas no centro.

### 2. **Lig4 (Conecta 4)**

Lig4 é um jogo de dois jogadores, onde o objetivo é alinhar 4 peças consecutivas em linha, seja na vertical, horizontal ou diagonal. O tabuleiro é composto por 6 linhas e 7 colunas, e cada jogador insere uma peça de cada vez, que cai na coluna desejada. O jogador que primeiro alinhar 4 peças vence a partida.

### 3. **Jogo da Velha (TickTackToe)**

O Jogo da Velha é um jogo clássico onde dois jogadores se alternam na marcação de células em um tabuleiro 3x3. O objetivo é ser o primeiro a alinhar três peças em linha, seja na vertical, horizontal ou diagonal.

## Conceitos Utilizados

O sistema foi desenvolvido utilizando os seguintes conceitos de programação orientada a objetos:

- **Classes Abstratas**: A classe `Game` é a base para todos os jogos, implementando métodos comuns como a verificação de vitória e a execução do jogo.
- **Herança**: Cada jogo (Reversi, Lig4, Jogo da Velha) herda da classe `Game`, especializando os métodos conforme as regras de cada jogo.
- **Composição**: O tabuleiro de cada jogo é representado pela classe `Board`, que é composta nas classes específicas de cada jogo.
- **Persistência de Dados**: O sistema mantém os dados dos jogadores em arquivos, permitindo que os cadastros e as estatísticas sejam salvos entre as execuções do sistema.

## Como Jogar

### Passo 1: Cadastro de Jogadores
Ao iniciar o programa, o usuário pode cadastrar novos jogadores informando um nome e um apelido único. Os dados dos jogadores são armazenados em um arquivo para persistência.

### Passo 2: Escolha do Jogo
Após o cadastro, o usuário pode escolher qual jogo deseja jogar: Reversi, Lig4 ou Jogo da Velha. O sistema então solicita os apelidos dos jogadores que irão participar da partida.

### Passo 3: Execução da Partida
O sistema exibe o tabuleiro e solicita ao jogador que faça uma jogada. O programa valida se a jogada é permitida e atualiza o tabuleiro. A partida continua até que um dos jogadores vença ou o jogo termine empatado. Após o término da partida, as estatísticas dos jogadores são atualizadas.

## CRC's

### CRC Classe Player

- **Responsabilidades**:
  - Guardar os dados do jogador (nome, apelido e estatísticas).
  - Armazenar as estatísticas de vitórias e derrotas de cada jogo.

- **Colaborações**:
  - A classe `Player` é utilizada pelo módulo de cadastro para criar jogadores e atualizar suas estatísticas.

### CRC Classe Registration

- **Responsabilidades**:
  - Criar o arquivo de jogadores e manipulá-lo (adicionar, remover e atualizar jogadores).
  
- **Colaborações**:
  - A classe `Registration` é utilizada pela classe `SystemOperation` para interagir com o usuário e gerenciar os dados dos jogadores.

### CRC Classe SystemOperation

- **Responsabilidades**:
  - Interagir com o usuário, imprimindo mensagens e validando entradas.
  
- **Colaborações**:
  - A classe `SystemOperation` facilita a execução do programa e organiza a interação entre os módulos.

### CRC Classe VirtualBoard

- **Responsabilidades**:
  - Representar o tabuleiro dos jogos.
  - Inicializar o tabuleiro.
  - Fazer as jogadas.
  - Exibir o tabuleiro.

- **Colaborações**:
  - A classe `VirtualBoard` serve como base para todos os jogos específicos (Reversi, Lig4, Jogo da Velha).

### CRC Classe Game

- **Responsabilidades**:
  - Ser a classe base para os jogos.
  - Implementar métodos virtuais para verificar jogadas e condições de vitória.
  - Executar a partida.

- **Colaborações**:
  - A classe `Game` é a classe pai das classes `Reversi`, `Lig4` e `TickTackToe`.

### CRC Classe TickTackToe

- **Responsabilidades**:
  - Implementar o jogo da velha.
  - Inicializar o tabuleiro 3x3.
  - Verificar jogadas e condições de vitória específicas.
  - Executar a partida e determinar o vencedor.

- **Colaborações**:
  - Possui composição com a classe `Board`.
  - Herda da classe `Game`.

### CRC Classe Reversi

- **Responsabilidades**:
  - Implementar o jogo Reversi.
  - Inicializar o tabuleiro 8x8 com peças no centro.
  - Verificar jogadas e condições de vitória específicas do Reversi.
  - Executar a partida e determinar o vencedor.

- **Colaborações**:
  - Possui composição com a classe `Board`.
  - Herda da classe `Game`.

### CRC Classe Lig4

- **Responsabilidades**:
  - Implementar o jogo Lig4.
  - Inicializar o tabuleiro 6x7.
  - Verificar jogadas e condições de vitória específicas do Lig4.
  - Executar a partida e determinar o vencedor.

- **Colaborações**:
  - Possui composição com a classe `Board`.
  - Herda da classe `Game`.

## Principais Dificuldades

### 1. Dificuldade na manipulação do arquivo (reescrever as estatísticas no arquivo CSV)

Uma das principais dificuldades encontradas foi a manipulação do arquivo CSV para armazenar e atualizar as estatísticas dos jogadores. Como o sistema precisa persistir as informações de vitórias e derrotas entre as execuções do programa, foi necessário desenvolver uma maneira eficiente de reescrever as estatísticas no arquivo sem corromper os dados já existentes. Isso envolveu cuidados na leitura e escrita no arquivo, garantindo que as modificações não apagassem informações anteriores e que a estrutura do CSV fosse mantida corretamente.

### 2. Dificuldade para criação de testes mais complexos que envolvem acessos privados

Outra dificuldade foi a criação de testes mais complexos, especialmente aqueles que envolvem a interação com métodos e atributos privados das classes. Como o sistema foi desenvolvido com encapsulamento, muitas das lógicas estavam ocultas em métodos privados, o que dificultava a escrita de testes unitários para essas partes do código.

