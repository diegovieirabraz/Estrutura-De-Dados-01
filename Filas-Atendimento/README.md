
# 📋 Sistema de Atendimento com Filas

Este projeto implementa um sistema simples de atendimento utilizando **filas** com as estruturas de **ponteiros e vetores**. O programa simula a geração e o atendimento de senhas com controle de filas.

## 🎯 Objetivo

- Simular um sistema de atendimento com três opções:
  1. **Gerar senha** (adiciona na fila de senhas geradas)
  2. **Realizar atendimento** (remove da fila de senhas geradas e adiciona na fila de senhas atendidas)
  0. **Sair** (só permitido quando todas as senhas forem atendidas)

## ⚙️ Funcionalidades

- A cada execução do menu, é mostrado quantas senhas estão **aguardando atendimento**.
- O programa **só pode ser encerrado** quando todas as senhas foram atendidas.
- Ao encerrar, o programa informa o **total de senhas atendidas**.
- Implementação de filas tanto com **ponteiros (dinâmica)** quanto com **vetores (estática)**.

## 🧱 Estrutura do Projeto

- `main.c` — Lógica principal e interface com o usuário.
- `fila_ponteiro.h` / `fila_ponteiro.c` — Implementação da fila dinâmica (ponteiros).
- `fila_vetor.h` / `fila_vetor.c` — Implementação da fila estática (vetor).

## 🧪 Exemplo de Execução

```
=== Sistema de Atendimento ===
0 - Sair
1 - Gerar senha
2 - Realizar atendimento
Senhas aguardando: 3
Opção: 2
Senha atendida: 4
```

## 📚 Conceitos Envolvidos

- **Fila (Queue)**: Estrutura de dados do tipo FIFO (First In, First Out).
- **Fila com ponteiros**: Usando alocação dinâmica de memória (listas encadeadas).
- **Fila com vetor**: Usando um array fixo circular.

## 🚀 Como Rodar

1. Compile os arquivos:
```bash
gcc main.c fila_ponteiro.c fila_vetor.c -o atendimento
```

2. Execute o programa:
```bash
./atendimento
```

## 📌 Observações

- A implementação pode ser adaptada para utilizar apenas ponteiros ou apenas vetores, conforme o aprendizado desejado.
- É recomendado implementar com ponteiros para entender melhor a manipulação dinâmica de memória.

## 🧑‍💻 Autor

Desenvolvido como exercício de estrutura de dados para praticar manipulação de filas com C.
