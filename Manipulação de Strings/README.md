
# 🧠 Exercícios de Strings em C++


Este projeto contém a implementação de 4 exercícios focados em **manipulação de strings**, entrada de dados e manipulação de tela no console com C++.

---

## 📘 Exercício 1 - Mensagem em Cascata

- O programa solicita ao usuário uma **mensagem digitada**.
- A mensagem é exibida **centralizada na linha 5** do console.
- Em seguida, **cada letra da mensagem "cai" até a linha 20**, simulando o efeito de uma **cascata**.
- Ao final da animação, a mensagem completa aparece na linha 20.

🔧 Utiliza:
- `gotoxy()` com `windows.h` para controle do cursor
- `Sleep()` para simular animação

---

## 📘 Exercício 2 - Verificador de Palíndromos

- O usuário digita uma mensagem.
- O programa verifica se a mensagem é um **palíndromo** (ou seja, se pode ser lida da mesma forma de trás pra frente).
- **Espaços são desconsiderados** na verificação.

📝 Exemplos válidos:
- `OVO`
- `ARARA`
- `SOCORRAM ME SUBI NO ONIBUS EM MARROCOS`

---

## 📘 Exercício 3 - Nome em Formato de Agenda

- A partir de um **arquivo TXT com nomes completos**, o programa converte os nomes para o formato de **agenda telefônica**:

  **Entrada:**  
  `José Antonio Santos Silva`  
  **Saída:**  
  `Silva, José Antonio Santos`

---

## 📘 Exercício 4 - Nome em Formato de Citação Bibliográfica

- A partir de um **arquivo TXT com nomes completos**, o programa formata os nomes no estilo de **citação bibliográfica acadêmica**:

  **Entrada:**  
  `José Antonio Santos Silva`  
  **Saída:**  
  `SILVA, José A. S.`

🔠 Último sobrenome em caixa alta + iniciais dos demais nomes.

---


