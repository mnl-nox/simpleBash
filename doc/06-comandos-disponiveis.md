# Comandos Disponíveis no Nox Shell

## Visão Geral

O Nox Shell (simpleBash) fornece um conjunto de comandos integrados (builtins) e suporte para executar programas externos do sistema. Esta documentação descreve todos os comandos disponíveis na versão atual.

---

## Comandos Integrados (Builtins)

Os seguintes comandos são implementados nativamente no shell e não requerem programas externos.

### 1. **cd** - Mudar Diretório

**Sintaxe:**

```bash
cd [diretório]
```

**Descrição:**
Muda o diretório de trabalho atual para o diretório especificado. Se nenhum diretório for fornecido, volta para a home do usuário.

**Exemplos:**

```bash
cd /home
cd ..
cd ~
cd src/
```

**Retorno:**

- Sucesso: 0
- Erro: -1 (diretório não encontrado)

---

### 2. **pwd** - Diretório Atual

**Sintaxe:**

```bash
pwd
```

**Descrição:**
Exibe o caminho completo do diretório de trabalho atual.

**Exemplos:**

```bash
pwd
# Saída: /home/nox/bash-c-basic
```

---

### 3. **echo** - Imprimir Texto

**Sintaxe:**

```bash
echo [texto] [argumentos]
```

**Descrição:**
Imprime texto ou argumentos na tela. Separa múltiplos argumentos com espaços.

**Exemplos:**

```bash
echo Hello World
echo "Bem-vindo ao Nox Shell"
echo "O diretório é" $(pwd)
```

---

### 4. **whoami** - Identificar Usuário

**Sintaxe:**

```bash
whoami
```

**Descrição:**
Exibe o nome do usuário atual no shell.

**Exemplos:**

```bash
whoami
# Saída: nox
```

---

### 5. **clear** - Limpar Tela

**Sintaxe:**

```bash
clear
```

**Descrição:**
Limpa o conteúdo da tela do terminal.

**Exemplos:**

```bash
clear
```

---

### 6. **ls** - Listar Arquivos

**Sintaxe:**

```bash
ls [diretório]
```

**Descrição:**
Lista os arquivos e diretórios (implementação básica). Se nenhum diretório for fornecido, lista o diretório atual.

**Exemplos:**

```bash
ls
ls /home
ls src/
```

**Limitações:**

- Versão simplificada (não mostra todas as opções do ls real)
- Não suporta flags como -la, -l, etc.

---

### 7. **date** - Data e Hora

**Sintaxe:**

```bash
date
```

**Descrição:**
Exibe a data e hora atual do sistema.

**Exemplos:**

```bash
date
# Saída: Sat Aug 16 14:30:45 2026
```

---

### 8. **info** - Informações do Shell

**Sintaxe:**

```bash
info
```

**Descrição:**
Exibe informações sobre o Nox Shell, incluindo versão, linguagem, usuário e link do repositório.

**Exemplos:**

```bash
info
# Saída:
# === Nox Shell Info ===
#   Nome: simpleBash (Nox Edition)
#   Versao: 1.0.0
#   Linguagem: C11
#   Usuario: nox
#   Home: /home/nox/bash-c-basic
#   Compilador: gcc
#   Comandos disponiveis: 12
#   Fonte: github.com/mnl-nox/simpleBash
```

---

### 9. **history** - Histórico de Comandos

**Sintaxe:**

```bash
history
```

**Descrição:**
Exibe o histórico básico de comandos executados (versão simplificada).

**Exemplos:**

```bash
history
# Saída:
#   1 cd /home
#   2 pwd
#   3 echo 'hello'
#   4 help
#   5 ls
```

**Limitações:**

- Versão básica com histórico pré-definido
- Não persiste entre sessões

---

### 10. **export** - Definir Variáveis de Ambiente

**Sintaxe:**

```bash
export VAR=valor
```

**Descrição:**
Define uma variável de ambiente que pode ser usada por programas subsequentes.

**Exemplos:**

```bash
export MYVAR=Hello
export PATH=/usr/local/bin:/usr/bin
export USER_NAME=nox
```

**Formato:**

- Deve conter um sinal de igualdade (=)
- Sem espaços ao redor do sinal de igualdade

---

### 11. **help** - Ajuda

**Sintaxe:**

```bash
help
```

**Descrição:**
Exibe a lista de todos os comandos disponíveis com suas descrições breves.

**Exemplos:**

```bash
help
```

---

### 12. **exit** - Sair do Shell

**Sintaxe:**

```bash
exit
```

**Descrição:**
Encerra a sessão do Nox Shell e retorna ao shell pai.

**Exemplos:**

```bash
exit
```

---

## Executáveis Externos

O Nox Shell também permite executar qualquer programa disponível no sistema, desde que esteja no PATH ou seja fornecido um caminho absoluto/relativo.

**Exemplos:**

```bash
ls -la
cat arquivo.txt
grep "texto" arquivo.txt
mkdir nova_pasta
touch arquivo.txt
rm arquivo.txt
python script.py
./meu_programa
```

---

## Prompt e Interface

### Formato do Prompt

O prompt segue o padrão:

```
usuario@host:diretorio$
```

**Exemplo:**

```bash
nox@nox:/home/nox/bash-c-basic$
```

**Componentes:**

- `usuario`: Nome do usuário conectado
- `host`: Nome do host (definido como "nox")
- `diretorio`: Diretório de trabalho atual

---

## Características Especiais

### Cor e Estilo

O shell utiliza códigos ANSI para colorização:

- **Diretórios:** Azul claro
- **Executáveis:** Verde brilhante
- **Arquivos C (.c, .h):** Verde
- **Markdown (.md):** Magenta/Rosa
- **Configuração:** Laranja
- **Usuário:** Verde-amarelo
- **Host:** Laranja
- **Caminho:** Azul

### ASCII Art

Na inicialização, o shell exibe uma árvore de diretórios colorida mostrando a estrutura do projeto.

---

## Erros Comuns

| Erro                           | Causa                                 | Solução                              |
| ------------------------------ | ------------------------------------- | ------------------------------------ |
| "Comando não encontrado"       | Comando digitado errado ou não existe | Verifique a ortografia ou use `help` |
| "Permissão negada"             | Arquivo não tem permissão de execução | Use `chmod +x arquivo` no shell pai  |
| "cd: Diretório não encontrado" | Diretório não existe                  | Verifique o caminho com `pwd` e `ls` |
| "export: format invalido"      | Falta o sinal =                       | Use `export VAR=valor`               |

---

## Limitações Conhecidas

1. **Sem suporte a pipes:** `|` não funciona
2. **Sem redirecionamento:** `>`, `<`, `>>` não funcionam
3. **Sem variáveis:** Expansão de `$VAR` é limitada
4. **Sem glob patterns:** `*`, `?` não expandem
5. **Sem job control:** Não há suporte a `&`, `fg`, `bg`
6. **Histórico básico:** Apenas exemplos pré-definidos

---

## Desenvolvimento Futuro

Funcionalidades planejadas para versões futuras:

- [ ] Suporte a pipes
- [ ] Redirecionamento de I/O
- [ ] Histórico persistente
- [ ] Expansão de variáveis
- [ ] Glob patterns
- [ ] Job control
- [ ] Scripts shell
- [ ] Aliases customizados

---

## Referências

- [Proposta do Projeto](./01-proposta-do-projeto.md)
- [Arquitetura](./02-arquitetura-modulos.md)
- [Requisitos](./03-requisitos-e-criterios-de-aceite.md)
