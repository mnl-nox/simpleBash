<h1 align="center">simpleBash</h1>

<p align="center">
  Projeto basico de um shell em C.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black" alt="C" />
  <img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub" />
  <img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white" alt="Git" />
  <img src="https://img.shields.io/badge/Assembly-525252?style=for-the-badge&logo=gnuassembler&logoColor=white" alt="Assembly" />
  <img src="https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" alt="VS Code" />
  <img src="https://img.shields.io/badge/Markdown-000000?style=for-the-badge&logo=markdown&logoColor=white" alt="Markdown" />
  <img src="https://img.shields.io/badge/draw.io-F08705?style=for-the-badge&logo=diagramsdotnet&logoColor=white" alt="draw.io" />
</p>

## Sobre

Este projeto tem como objetivo criar um shell basico, com comandos simples e foco em estudo.

## Objetivos

- Praticar programacao em C aplicada a sistemas.
- Entender o funcionamento basico de um interpretador de comandos.
- Trabalhar conceitos como processos, execucao e controle de comandos.
- Desenvolver uma base simples para futuras melhorias no shell.

## Documentação do projeto

A documentação inicial do projeto está organizada em [doc/README.md](doc/README.md) e inclui:

- proposta do projeto;
- arquitetura inicial;
- requisitos e critérios de aceite;
- casos de uso e UML;
- roadmap de desenvolvimento;
- referência completa de comandos.

Documentação principal:

- [Visão geral](doc/01-proposta-do-projeto.md)
- [Arquitetura inicial](doc/02-arquitetura-modulos.md)
- [Requisitos e critérios de aceite](doc/03-requisitos-e-criterios-de-aceite.md)
- [Casos de uso e UML](doc/04-casos-de-uso-e-uml.md)
- [Roadmap e marcos](doc/05-roadmap-e-milestones.md)
- [Comandos disponíveis](doc/06-comandos-disponiveis.md)

## Compilar

```bash
make
```

## Executar

```bash
./simpleBash
```

## Comandos Disponíveis

O Nox Shell inclui 12 comandos integrados:

| Comando | Descrição | Exemplo |
|---------|-----------|---------|
| `cd` | Mudar diretório | `cd /home` |
| `pwd` | Diretório atual | `pwd` |
| `echo` | Imprimir texto | `echo "Olá"` |
| `whoami` | Nome do usuário | `whoami` |
| `clear` | Limpar tela | `clear` |
| `ls` | Listar arquivos | `ls src/` |
| `date` | Data e hora | `date` |
| `info` | Info do shell | `info` |
| `history` | Histórico | `history` |
| `export` | Variáveis | `export VAR=valor` |
| `help` | Ajuda | `help` |
| `exit` | Sair | `exit` |

Para uma documentação completa de cada comando, consulte [Comandos Disponíveis](doc/06-comandos-disponiveis.md).

## Exemplo de Uso

```bash
$ ./simpleBash
  ~/nox-shell
  ├── bin/
  │   ├── bash
  │   ├── ls
  │   └── nox
  ├── etc/
  │   └── config
  ├── doc/
  ├── include/
  ├── src/
  ├── README.md
  ├── Makefile
  └── LICENSE

Bem-vindo ao simpleBash. Digite 'help' para ver os comandos.

nox@nox:/home/nox/bash-c-basic$ help

[ Nox Shell Help ]
  cd [dir]          - muda de diretorio
  pwd               - mostra o diretorio atual
  echo [txt]        - imprime texto
  clear             - limpa o terminal
  whoami            - mostra o usuario
  ls [dir]          - lista arquivos (basico)
  date              - mostra a data/hora atual
  info              - informacoes sobre o shell
  history           - mostra historico (basico)
  export VAR=valor  - define variavel de ambiente
  exit              - sai do shell

nox@nox:/home/nox/bash-c-basic$ info

=== Nox Shell Info ===
  Nome: simpleBash (Nox Edition)
  Versao: 1.0.0
  Linguagem: C11
  Usuario: nox
  Home: /home/nox/bash-c-basic
  Compilador: gcc

  Comandos disponiveis: 12
  Fonte: github.com/mnl-nox/simpleBash

nox@nox:/home/nox/bash-c-basic$ pwd
/home/nox/bash-c-basic

nox@nox:/home/nox/bash-c-basic$ whoami
nox

nox@nox:/home/nox/bash-c-basic$ date
Sun Aug 16 22:11:00 2026

nox@nox:/home/nox/bash-c-basic$ ls

  [ Listing: . ]
  - bin/
  - include/
  - src/
  - doc/
  - Makefile
  - README.md
  - LICENSE

nox@nox:/home/nox/bash-c-basic$ export MYVAR=Nox
  Variavel 'MYVAR' definida para 'Nox'

nox@nox:/home/nox/bash-c-basic$ echo "Shell funcionando!"
Shell funcionando!

nox@nox:/home/nox/bash-c-basic$ exit
```

## Estrutura do Projeto

```
simpleBash/
├── src/              # Código fonte
│   ├── main.c
│   ├── core/
│   │   ├── shell.c
│   │   ├── parser.c
│   │   ├── executor.c
│   │   └── builtins.c
│   └── ui/
│       └── terminal.c
├── include/          # Headers
│   ├── core/
│   │   └── shell.h
│   └── ui/
│       └── terminal.h
├── doc/              # Documentação
│   ├── 01-proposta-do-projeto.md
│   ├── 02-arquitetura-modulos.md
│   ├── 03-requisitos-e-criterios-de-aceite.md
│   ├── 04-casos-de-uso-e-uml.md
│   ├── 05-roadmap-e-milestones.md
│   ├── 06-comandos-disponiveis.md
│   └── README.md
├── Makefile          # Build
├── LICENSE           # Licença
└── README.md         # Este arquivo
```

## Versão Atual

**Versão:** 1.0.0  
**Status:** Funcional com 12 comandos integrados  
**Linguagem:** C (C11)  
**Compilador:** GCC  
**Plataforma:** Linux/Unix
