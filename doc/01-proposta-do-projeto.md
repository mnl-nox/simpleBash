# Proposta do projeto

## 1. Contexto

O projeto `simpleBash` tem como objetivo principal desenvolver uma base funcional de um shell em linguagem C, com foco em estudo, organização e aprendizado de conceitos fundamentais de sistemas operacionais e programação em nível de sistema.

A proposta é criar uma aplicação interativa que receba comandos do usuário, interprete a entrada e execute operações internas ou externas de forma simples e didática.

---

## 2. Problema a ser resolvido

Em ambientes de desenvolvimento e estudo, é importante compreender como um shell funciona na prática. O shell é responsável por interpretar comandos, invocar programas, gerenciar processos e coordenar a interação entre usuário e sistema operacional.

O problema central é construir uma aplicação mínima, porém arquitetada de forma correta, que consiga:

- ler entrada do usuário;
- separar comando e argumentos;
- executar operações internas e externas;
- manter interação contínua com o terminal.

---

## 3. Objetivo geral

Implementar uma versão inicial de um shell em C com estrutura modular, fácil de entender, que permita a execução de comandos básicos e sirva como base para futuras melhorias.

---

## 4. Objetivos específicos

- desenvolver um loop principal de execução;
- interpretar linhas de comando do usuário;
- executar comandos do sistema operacional;
- fornecer comandos internos básicos;
- organizar a solução em módulos;
- produzir documentação técnica inicial do projeto.

---

## 5. Público-alvo

Este projeto é indicado para:

- estudantes de programação em C;
- pessoas interessadas em sistemas operacionais;
- iniciantes que desejam compreender a lógica de shells;
- projetos acadêmicos e de aprendizado.

---

## 6. Proposta de valor

A principal contribuição do projeto é oferecer uma base educacional e funcional de shell, permitindo que o desenvolvedor entenda conceitos fundamentais como:

- processos;
- execução de programas;
- comunicação com o sistema operacional;
- manipulação de entrada e saída;
- organização modular de software.

---

## 7. Premissas técnicas

A implementação inicial considera as seguintes premissas:

- linguagem de programação: C;
- compilação via `Makefile`;
- uso de chamadas do sistema Unix/Linux;
- execução em terminal de linha de comando;
- arquitetura simples e didática.

---

## 8. Escopo inicial

O escopo desta primeira versão inclui:

- prompt interativo;
- leitura de comandos;
- tokenização básica;
- execução de comandos externos;
- implementação de builtins básicos;
- mensagens de erro claras;
- documentação inicial da arquitetura.

---

## 9. Fora de escopo

Os seguintes itens ficam fora do escopo da primeira entrega:

- shell avançado com múltiplos recursos de Bash;
- suporte completo a pipelines e redirecionamentos;
- histórico sofisticado de comandos;
- expansão de variáveis complexa;
- scripts avançados;
- suporte avançado a sinais e jobs.

---

## 10. Entregáveis da proposta inicial

- código-fonte do shell inicial;
- estrutura modular organizada;
- Makefile para compilação;
- documentação em Markdown;
- arquitetura inicial com requisitos e critérios de aceitação.

---

## 11. Conclusão

A proposta do projeto é criar uma base clara e acessível para o desenvolvimento de um shell em C, permitindo a prática de conceitos essenciais de programação de sistemas e preparando o caminho para evoluções futuras e implementações mais robustas.
