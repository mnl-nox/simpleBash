#ifndef TERMINAL_H
#define TERMINAL_H

#include "core/shell.h"

void print_banner(void);
void print_prompt(const ShellState *state);
void print_error(const char *message);
void clear_screen(void);

#endif
