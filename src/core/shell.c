#define _POSIX_C_SOURCE 200809L

#include "core/shell.h"
#include "ui/terminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void shell_init(ShellState *state)
{
        state->user = getenv("USER");
        if (state->user == NULL)
        {
                state->user = "root";
        }

        state->cwd = getcwd(NULL, 0);
        if (state->cwd == NULL)
        {
                state->cwd = strdup("/");
        }
}

void shell_cleanup(ShellState *state)
{
        free(state->cwd);
}

int shell_run_loop(ShellState *state)
{
        char line[MAX_LINE];
        Command command;

        while (1)
        {
                print_prompt(state);

                if (fgets(line, sizeof(line), stdin) == NULL)
                {
                        printf("\n");
                        return 0;
                }

                line[strcspn(line, "\r\n")] = '\0';

                if (line[0] == '\0')
                {
                        continue;
                }

                if (parse_command(line, &command) != 0)
                {
                        print_error("erro ao analisar comando");
                        continue;
                }

                if (command.argc == 0)
                {
                        continue;
                }

                if (strcmp(command.argv[0], "exit") == 0)
                {
                        for (int i = 0; i < command.argc; i++)
                        {
                                free(command.argv[i]);
                        }
                        return 0;
                }

                if (execute_command(&command, state) != 0)
                {
                        print_error("comando falhou");
                }

                for (int i = 0; i < command.argc; i++)
                {
                        free(command.argv[i]);
                }
        }
}
