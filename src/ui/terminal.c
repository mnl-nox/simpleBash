#include "ui/terminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ANSI_RESET "\033[0m"
#define ANSI_DIR "\033[38;5;117m"
#define ANSI_EXEC "\033[38;5;46m"
#define ANSI_C_CODE "\033[38;5;82m"
#define ANSI_MARKDOWN "\033[38;5;207m"
#define ANSI_TEXT "\033[38;5;226m"
#define ANSI_CONFIG "\033[38;5;214m"
#define ANSI_HOST "\033[38;5;208m"
#define ANSI_USER "\033[38;5;118m"
#define ANSI_PATH "\033[38;5;123m"

static void print_directory_tree(void)
{
        printf("  %s~/nox-shell%s\n", ANSI_DIR, ANSI_RESET);
        printf("  %s├── %sbin/%s\n", ANSI_DIR, ANSI_DIR, ANSI_RESET);
        printf("  %s│   ├── %sbash%s\n", ANSI_DIR, ANSI_EXEC, ANSI_RESET);
        printf("  %s│   ├── %sls%s\n", ANSI_DIR, ANSI_EXEC, ANSI_RESET);
        printf("  %s│   └── %snox%s\n", ANSI_DIR, ANSI_EXEC, ANSI_RESET);
        printf("  %s├── %setc/%s\n", ANSI_DIR, ANSI_DIR, ANSI_RESET);
        printf("  %s│   └── %sconfig%s\n", ANSI_DIR, ANSI_CONFIG, ANSI_RESET);
        printf("  %s├── %sdoc/%s\n", ANSI_DIR, ANSI_DIR, ANSI_RESET);
        printf("  %s│   ├── %s01-proposta-do-projeto.md%s\n", ANSI_DIR, ANSI_MARKDOWN, ANSI_RESET);
        printf("  %s│   ├── %s02-arquitetura-modulos.md%s\n", ANSI_DIR, ANSI_MARKDOWN, ANSI_RESET);
        printf("  %s│   ├── %s03-requisitos.md%s\n", ANSI_DIR, ANSI_MARKDOWN, ANSI_RESET);
        printf("  %s│   └── %s04-casos-de-uso.md%s\n", ANSI_DIR, ANSI_MARKDOWN, ANSI_RESET);
        printf("  %s├── %sinclude/%s\n", ANSI_DIR, ANSI_DIR, ANSI_RESET);
        printf("  %s│   ├── %score.h%s\n", ANSI_DIR, ANSI_C_CODE, ANSI_RESET);
        printf("  %s│   └── %sui.h%s\n", ANSI_DIR, ANSI_C_CODE, ANSI_RESET);
        printf("  %s├── %ssrc/%s\n", ANSI_DIR, ANSI_DIR, ANSI_RESET);
        printf("  %s│   ├── %score.c%s\n", ANSI_DIR, ANSI_C_CODE, ANSI_RESET);
        printf("  %s│   ├── %sui.c%s\n", ANSI_DIR, ANSI_C_CODE, ANSI_RESET);
        printf("  %s│   └── %smain.c%s\n", ANSI_DIR, ANSI_C_CODE, ANSI_RESET);
        printf("  %s├── %sREADME.md%s\n", ANSI_DIR, ANSI_MARKDOWN, ANSI_RESET);
        printf("  %s├── %sMakefile%s\n", ANSI_DIR, ANSI_CONFIG, ANSI_RESET);
        printf("  %s└── %sLICENSE%s\n", ANSI_DIR, ANSI_TEXT, ANSI_RESET);
        printf("\n");
}

void print_banner(void)
{
        print_directory_tree();
}

void print_prompt(const ShellState *state)
{
        char *cwd = getcwd(NULL, 0);
        printf("%s%s%s@%s%s%s:%s%s%s$ ",
               ANSI_USER, state->user, ANSI_RESET,
               ANSI_HOST, "nox", ANSI_RESET,
               ANSI_PATH, (cwd != NULL ? cwd : state->cwd), ANSI_RESET);
        free(cwd);
}

void print_error(const char *message)
{
        fprintf(stderr, "[ERROR] %s\n", message);
}

void clear_screen(void)
{
        printf("\033[H\033[J");
        fflush(stdout);
}
