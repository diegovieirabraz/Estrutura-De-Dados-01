# 🎭 Sistema de Reserva de Poltronas de Teatro

Este é um sistema simples em C++ para gerenciamento de reservas de poltronas em um teatro. O programa permite ao usuário reservar assentos, visualizar o mapa de ocupação e calcular o faturamento total com base nas reservas realizadas.

---

## 📌 Funcionalidades

- **Reservar Poltrona**: O usuário pode escolher uma fileira e uma poltrona específica para reservar.
- **Mapa de Ocupação**: Exibe visualmente os assentos ocupados (`#`) e os disponíveis (`.`).
- **Faturamento**: Calcula e exibe o total arrecadado com base nas reservas feitas, considerando o preço por fileira.

---

## 🏷️ Preços por Fileira

O teatro possui 15 fileiras com os seguintes preços por poltrona:

- **Fileiras 1 a 5**: R$ 50,00
- **Fileiras 6 a 10**: R$ 30,00
- **Fileiras 11 a 15**: R$ 15,00

---

## ▶️ Como Executar

1. Certifique-se de ter um compilador C++ instalado (como `g++`).
2. Compile o código:

```bash
g++ -o teatro teatro.cpp

