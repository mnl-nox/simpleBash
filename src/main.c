#include "core/shell.h"
#include "ui/terminal.h"

#include <stdio.h>

int main(void)
{
        ShellState state;

        print_banner();
        shell_init(&state);

        printf("Bem-vindo ao simpleBash. Digite 'help' para ver os comandos.\n\n");

        int exit_code = shell_run_loop(&state);

        shell_cleanup(&state);
        return exit_code;
}
