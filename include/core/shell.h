#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#define MAX_LINE 1024

typedef struct
{
        char *cwd;
        char *user;
} ShellState;

typedef struct
{
        char *argv[MAX_ARGS];
        int argc;
} Command;

void shell_init(ShellState *state);
void shell_cleanup(ShellState *state);
int shell_run_loop(ShellState *state);
int parse_command(char *line, Command *command);
int execute_command(Command *command, ShellState *state);
int is_builtin(const char *name);
int run_builtin(Command *command, ShellState *state);

#endif
