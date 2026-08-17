# Arquitetura inicial

## Visão geral da arquitetura

A arquitetura inicial do `simpleBash` será organizada em camadas com responsabilidades bem definidas. A intenção é manter uma estrutura simples, fácil de compreender e expandir, sem perder a lógica essencial de um shell funcional.

A arquitetura central é baseada em um loop principal de interação que lê, interpreta e executa comandos do usuário.

---

## Componentes principais

### 1. Shell principal

O shell principal é o componente coordenador do sistema. Ele executa o loop principal do programa, controla a interação com o usuário e delega responsabilidades para os módulos específicos.

Responsabilidades:

- exibir o prompt;
- receber comandos do usuário;
- manter a execução repetitiva até o encerramento;
- decidir qual fluxo de execução será usado.

---

### 2. Módulo de entrada

Responsável por capturar a linha digitada pelo usuário.

Funções principais:

- leitura da linha com `getline` ou `fgets`;
- remoção da quebra de linha;
- validação de entradas vazias;
- armazenamento temporário do comando.

---

### 3. Módulo de parsing

O módulo de parsing transforma o texto bruto em dados estruturados que o shell consegue entender.

Estrutura conceitual esperada:

```c
typedef struct {
    char **argv;
    int argc;
    char *input_file;
    char *output_file;
    int append_mode;
    int background;
} Command;
```

Responsabilidades:

- separar comandos e argumentos;
- identificar operadores básicos;
- preparar estrutura de execução;
- facilitar a etapa de decisão do executor.

---

### 4. Módulo de execução

Esse módulo decide como cada comando será tratado.

#### 4.1 Comandos internos

Comandos armazenados diretamente no shell, como:

- `cd`
- `exit`
- `pwd`
- `help`

Esses comandos normalmente alteram o estado do shell e não exigem criação de processo filho.

#### 4.2 Comandos externos

Quando o comando não é interno, o shell executa um processo externo usando `fork()` e `execvp()`.

Fluxo de execução:

```text
shell -> fork() -> processo filho -> execvp() -> retorno
      -> processo pai -> waitpid() -> prompt
```

---

### 5. Módulo de builtins

Centraliza a lógica de comandos internos do shell.

Exemplos de funções:

- `builtin_cd()`
- `builtin_exit()`
- `builtin_help()`
- `builtin_pwd()`

Esse módulo aumenta a organização e reduz a mistura de responsabilidades no núcleo do programa.

---

### 6. Módulo de gerenciamento de processos

Responsável por controlar o ciclo de vida de subprocessos.

Funções esperadas:

- criar processos filho;
- monitorar status de execução;
- tratar retorno do processo;
- realizar gerenciamento básico de sinais.

---

### 7. Módulo de ambiente e estado

Esse módulo armazena dados do contexto do shell, como:

- diretório atual;
- variáveis de ambiente;
- status do último comando;
- nome do shell.

Exemplo:

```c
typedef struct {
    char *current_dir;
    char **envp;
    int last_status;
} ShellState;
```

---

### 8. Módulo de apresentação e mensagens

Responsável pela comunicação com o usuário na interface textual.

Funções principais:

- exibir prompt;
- informar erros;
- formatar mensagens e retornos;
- manter a experiência interativa robusta.

---

## Organização sugerida dos arquivos

```text
project/
├── include/
│   ├── shell.h
│   ├── parser.h
│   ├── executor.h
│   └── builtins.h
├── src/
│   ├── main.c
│   ├── shell.c
│   ├── parser.c
│   ├── executor.c
│   ├── builtins.c
│   └── utils.c
├── Makefile
├── README.md
└── doc/
    ├── README.md
    ├── 01-proposta-do-projeto.md
    ├── 02-arquitetura-modulos.md
    ├── 03-requisitos-e-criterios-de-aceite.md
    ├── 04-casos-de-uso-e-uml.md
    └── 05-roadmap-e-milestones.md
```

---

## Princípios da arquitetura

- simplicidade;
- modularização;
- baixo acoplamento;
- separação entre entrada, parsing e execução;
- facilidade de extensão.

Essa abordagem torna o projeto mais didático e mais adequado para aprendizado progressivo em C e sistemas operacionais.

---

## Conclusão

A arquitetura inicial do `simpleBash` deve priorizar clareza, estabilidade e evolução incremental. Ao manter o projeto dividido por responsabilidades, a implementação se torna mais legível, mais fácil de testar e mais escalável para versões futuras.
