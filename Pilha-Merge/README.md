# 📊 Sistema de Empilhamento de Números Pares e Ímpares

Este é um programa desenvolvido em **C++** que realiza a separação e organização de números inteiros em pilhas, utilizando tanto **vetores** quanto **listas encadeadas**. O programa permite que o usuário digite uma sequência de 30 números inteiros, garantindo a ordem crescente na entrada, e depois exibe esses números em ordem decrescente.

---

## 📌 Funcionalidades

✅ **Entrada de Números**:  
O usuário deve digitar **30 números inteiros**, sendo que cada número inserido precisa ser **maior que o anterior**, assegurando uma sequência estritamente crescente.

✅ **Separação em Pilhas**:  
Cada número digitado será empilhado de acordo com sua natureza:
- **Números pares** → Pilha de pares
- **Números ímpares** → Pilha de ímpares

✅ **Estruturas Utilizadas**:
- **Pilha com Vetor**: Implementação baseada em um array estático.
- **Pilha com Lista Encadeada**: Implementação dinâmica utilizando nós encadeados.

✅ **Desempilhamento e Exibição**:  
Após a entrada de todos os números, o programa realiza o desempilhamento das duas pilhas, exibindo os números em **ordem decrescente**.

---

## 🛠️ Estruturas Implementadas

- **Pilha de Vetor**:  
  - Capacidade máxima: **30 elementos**.
  - Controle via variável de quantidade (topo).

- **Pilha de Lista Encadeada**:  
  - Estrutura dinâmica, sem limite fixo.
  - Cada nó armazena um número e um ponteiro para o próximo elemento.

---

## ▶️ Como Executar

1. Certifique-se de ter um **compilador C++** instalado (como `g++`).

2. Compile o código:
