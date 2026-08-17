#include "core/shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int execute_command(Command *command, ShellState *state)
{
        pid_t pid;
        int status;

        if (command == NULL || command->argv[0] == NULL)
        {
                return -1;
        }

        if (is_builtin(command->argv[0]))
        {
                return run_builtin(command, state);
        }

        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                return -1;
        }

        if (pid == 0)
        {
                execvp(command->argv[0], command->argv);
                perror("execvp");
                exit(127);
        }

        waitpid(pid, &status, 0);
        return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}
