#define _POSIX_C_SOURCE 200809L

#include "core/shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *dup_token(const char *token)
{
        size_t len = strlen(token);
        char *copy = malloc(len + 1);
        if (copy == NULL)
        {
                return NULL;
        }
        memcpy(copy, token, len + 1);
        return copy;
}

int parse_command(char *line, Command *command)
{
        char *saveptr = NULL;
        char *token;
        int count = 0;

        if (command == NULL || line == NULL)
        {
                return -1;
        }

        for (int i = 0; i < MAX_ARGS; i++)
        {
                command->argv[i] = NULL;
        }
        command->argc = 0;

        token = strtok_r(line, " \t", &saveptr);
        while (token != NULL)
        {
                if (count >= MAX_ARGS - 1)
                {
                        return -1;
                }

                command->argv[count] = dup_token(token);
                if (command->argv[count] == NULL)
                {
                        return -1;
                }

                count++;
                token = strtok_r(NULL, " \t", &saveptr);
        }

        command->argc = count;
        command->argv[count] = NULL;
        return 0;
}
