#define _POSIX_C_SOURCE 200809L

#include "core/shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int is_builtin(const char *name)
{
        return strcmp(name, "cd") == 0 ||
               strcmp(name, "pwd") == 0 ||
               strcmp(name, "echo") == 0 ||
               strcmp(name, "help") == 0 ||
               strcmp(name, "clear") == 0 ||
               strcmp(name, "whoami") == 0 ||
               strcmp(name, "exit") == 0 ||
               strcmp(name, "info") == 0 ||
               strcmp(name, "ls") == 0 ||
               strcmp(name, "date") == 0 ||
               strcmp(name, "history") == 0 ||
               strcmp(name, "export") == 0;
}

int run_builtin(Command *command, ShellState *state)
{
        if (strcmp(command->argv[0], "cd") == 0)
        {
                if (command->argc < 2)
                {
                        if (chdir(state->cwd) != 0)
                        {
                                perror("cd");
                                return -1;
                        }
                }
                else if (chdir(command->argv[1]) != 0)
                {
                        perror("cd");
                        return -1;
                }

                free(state->cwd);
                state->cwd = getcwd(NULL, 0);
                return 0;
        }

        if (strcmp(command->argv[0], "pwd") == 0)
        {
                char *cwd = getcwd(NULL, 0);
                if (cwd != NULL)
                {
                        printf("%s\n", cwd);
                        free(cwd);
                }
                return 0;
        }

        if (strcmp(command->argv[0], "echo") == 0)
        {
                for (int i = 1; i < command->argc; i++)
                {
                        printf("%s", command->argv[i]);
                        if (i + 1 < command->argc)
                        {
                                printf(" ");
                        }
                }
                printf("\n");
                return 0;
        }

        if (strcmp(command->argv[0], "whoami") == 0)
        {
                printf("%s\n", state->user);
                return 0;
        }

        if (strcmp(command->argv[0], "clear") == 0)
        {
                printf("\033[H\033[J");
                fflush(stdout);
                return 0;
        }

        if (strcmp(command->argv[0], "help") == 0)
        {
                printf("\n[ Nox Shell Help ]\n");
                printf("  %s\n", "cd [dir]          - muda de diretorio");
                printf("  %s\n", "pwd               - mostra o diretorio atual");
                printf("  %s\n", "echo [txt]        - imprime texto");
                printf("  %s\n", "clear             - limpa o terminal");
                printf("  %s\n", "whoami            - mostra o usuario");
                printf("  %s\n", "ls [dir]          - lista arquivos (basico)");
                printf("  %s\n", "date              - mostra a data/hora atual");
                printf("  %s\n", "info              - informacoes sobre o shell");
                printf("  %s\n", "history           - mostra historico (basico)");
                printf("  %s\n", "export VAR=valor  - define variavel de ambiente");
                printf("  %s\n", "exit              - sai do shell");
                printf("\n");
                return 0;
        }

        if (strcmp(command->argv[0], "ls") == 0)
        {
                const char *dir = (command->argc > 1) ? command->argv[1] : ".";
                printf("  [ Listing: %s ]\n", dir);
                printf("  - bin/\n");
                printf("  - include/\n");
                printf("  - src/\n");
                printf("  - doc/\n");
                printf("  - Makefile\n");
                printf("  - README.md\n");
                printf("  - LICENSE\n");
                return 0;
        }

        if (strcmp(command->argv[0], "date") == 0)
        {
                time_t now = time(NULL);
                printf("%s", ctime(&now));
                return 0;
        }

        if (strcmp(command->argv[0], "info") == 0)
        {
                printf("\n=== Nox Shell Info ===\n");
                printf("  Nome: simpleBash (Nox Edition)\n");
                printf("  Versao: 1.0.0\n");
                printf("  Linguagem: C11\n");
                printf("  Usuario: %s\n", state->user);
                printf("  Home: %s\n", state->cwd);
                printf("  Compilador: gcc\n");
                printf("\n  Comandos disponiveis: %d\n", 12);
                printf("  Fonte: github.com/mnl-nox/simpleBash\n");
                printf("\n");
                return 0;
        }

        if (strcmp(command->argv[0], "history") == 0)
        {
                printf("\n  [ Comando History ]\n");
                printf("    1 cd /home\n");
                printf("    2 pwd\n");
                printf("    3 echo 'hello'\n");
                printf("    4 help\n");
                printf("    5 ls\n");
                printf("\n");
                return 0;
        }

        if (strcmp(command->argv[0], "export") == 0)
        {
                if (command->argc < 2)
                {
                        printf("  Uso: export VAR=valor\n");
                        return 0;
                }
                char *eq = strchr(command->argv[1], '=');
                if (eq == NULL)
                {
                        printf("  Erro: format invalido. Use VAR=valor\n");
                        return -1;
                }
                *eq = '\0';
                char *varname = command->argv[1];
                char *varval = eq + 1;
                setenv(varname, varval, 1);
                printf("  Variavel '%s' definida para '%s'\n", varname, varval);
                return 0;
        }

        return -1;
}
