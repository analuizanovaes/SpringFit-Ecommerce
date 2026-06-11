# 🏋️‍♀️ SpringFit - E-commerce de Artigos Esportivos

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/gcc-%231A2C37.svg?style=for-the-badge&logo=gnu&logoColor=white)
![Status](https://img.shields.io/badge/Status-Concluído-success?style=for-the-badge)

Sistema de gerenciamento para uma loja de roupas e artigos esportivos, desenvolvido inteiramente em linguagem C. O projeto aplica na prática conceitos avançados de Estruturas de Dados e alocação dinâmica de memória para solucionar desafios reais de arquitetura e logística de um e-commerce sob alta demanda.

## 🎓 Contexto Acadêmico
Projeto prático desenvolvido como requisito de avaliação para a disciplina de **Estrutura de Dados** do curso de **Análise e Desenvolvimento de Sistemas (ADS)** do **Centro Universitário UniEuro**.

* **Professor:** Jorge Osvaldo Alves de Lima Torres
* **Desenvolvedoras:** Ana Luiza Fernandes Novaes e Sthefanny Ramos Parrini

## ⚙️ Estruturas de Dados Implementadas
O sistema não utiliza bibliotecas preexistentes. Toda a manipulação de memória (ponteiros, `malloc`, `free`) foi construída do zero para ditar as regras de negócio da loja:

- **Fila (Queue - FIFO):** Expedição e processamento logístico de pedidos faturados.
- **Pilha (Stack - LIFO):** Gerenciamento do histórico de ações e botão "Desfazer" no carrinho.
- **Lista Simplesmente Encadeada:** Gerenciamento de sessão e armazenamento do carrinho de compras.
- **Lista Duplamente Encadeada:** Catálogo principal com navegação bidirecional de produtos.
- **Lista Circular Duplamente Encadeada:** Carrossel contínuo de promoções da interface gráfica.
- **Árvore Binária de Busca (BST):** Busca otimizada em *O(log n)* de produtos no estoque através do ID.

## 🚀 Como Executar o Projeto

### Pré-requisitos
Certifique-se de ter um compilador C instalado na sua máquina, como o **GCC** (GNU Compiler Collection).

### Compilação e Execução
No terminal de sua preferência, navegue até a raiz do repositório e execute o comando abaixo para unificar e compilar todos os módulos do sistema:

```bash
gcc main.c estoque_bst.c catalogo.c carrinho.c pilha_historico.c fila_pedidos.c promocoes.c -o springfit

```

Em seguida, execute o binário gerado:

* **No Windows:**

```bash
./springfit.exe

```

* **No Linux / macOS:**

```bash
./springfit

```

## 🛠️ Boas Práticas Adotadas

* **Modularização:** Separação estrita entre a definição de interfaces (`.h`) e a implementação da lógica de negócio (`.c`), facilitando a manutenção do código.
* **Memory Safety:** Tratamento de ponteiros nulos e limpeza rigorosa de memória com o uso de `free()` para evitar *memory leaks* após as operações de faturamento, deleções na BST e esvaziamento de carrinhos.
* **UX de Terminal:** Interface interativa e resiliente, blindada contra travamentos e *inputs* inválidos do usuário durante a navegação.

```
