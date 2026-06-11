# 🏋️‍♀️ SpringFit - Sistema de E-commerce Para Roupas e Acessórios de Academia

Sistema de gerenciamento para uma loja de roupas e artigos esportivos, desenvolvido inteiramente em linguagem C. O projeto aplica na prática conceitos avançados de Estruturas de Dados e alocação dinâmica de memória para solucionar desafios reais de arquitetura e logística de um e-commerce.

## 🎓 Contexto Acadêmico
Projeto desenvolvido para a disciplina de **Estrutura de Dados** do curso de **Análise e Desenvolvimento de Sistemas (ADS)** do **Centro Universitário UniEuro**.
* **Professor:** Jorge Osvaldo Alves de Lima Torres
* **Desenvolvedoras:** Ana Luiza Fernandes Novaes e Sthefanny Ramos Parrini

## ⚙️ Estruturas de Dados Implementadas
O sistema não utiliza bibliotecas preexistentes. Toda a manipulação de memória (ponteiros, `malloc`, `free`) foi construída do zero para ditar as regras de negócio da loja:
- **Fila (Queue - FIFO):** Expedição e processamento logístico de pedidos.
- **Pilha (Stack - LIFO):** Histórico de ações e botão "Desfazer" no carrinho.
- **Lista Simplesmente Encadeada:** Gerenciamento de sessão do carrinho de compras.
- **Lista Duplamente Encadeada:** Catálogo de navegação bidirecional dos produtos.
- **Lista Circular Duplamente Encadeada:** Carrossel contínuo de promoções da interface.
- **Árvore Binária de Busca (BST):** Busca otimizada $O(\log n)$ de produtos no estoque via ID.

## 🚀 Como Executar o Projeto

Para compilar e rodar o projeto em um ambiente Linux ou no terminal do Windows (via GCC), utilize o comando abaixo na raiz do repositório para unificar e compilar todos os módulos:

```
gcc main.c estoque_bst.c catalogo.c carrinho.c pilha_historico.c fila_pedidos.c promocoes.c -o springfit
Em seguida, execute o sistema gerado:

No Windows:
./springfit.exe

No Linux / macOS:
./springfit
```

🛠️ Boas Práticas Adotadas
Modularização: Separação estrita entre definição de interfaces (.h) e implementação lógica (.c).

Memory Safety: Tratamento de ponteiros nulos e limpeza rigorosa de memória com free() para evitar memory leaks após as operações de faturamento e limpeza de carrinho.

UX de Terminal: Interface interativa blindada contra inputs inválidos do usuário.
