#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _myenv(info_t *info) {
    if (info->env == NULL) {
        _eputs("Environment list is empty.\n");
        return 1;
    }

    print_list_str(info->env);
    return 0;
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments.
 * @name: env var name
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *_getenv(info_t *info, const char *name) {
    list_t *node = info->env;
    char *value;

    while (node) {
        value = starts_with(node->str, name);
        if (value && *value) {
            return value;
        }
        node = node->next;
    }

    return NULL;
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _mysetenv(info_t *info) {
    if (info->argc != 3) {
        _eputs("Usage: setenv VARIABLE VALUE\n");
        return 1;
    }

    if (_setenv(info, info->argv[1], info->argv[2])) {
        _eputs("Failed to set environment variable.\n");
        return 1;
    }

    return 0;
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _myunsetenv(info_t *info) {
    int i;

    if (info->argc == 1) {
        _eputs("Usage: unsetenv VARIABLE [VARIABLE ...]\n");
        return 1;
    }

    for (i = 1; i < info->argc; i++) {
        if (_unsetenv(info, info->argv[i])) {
            _eputs("Failed to unset environment variable.\n");
            return 1;
        }
    }

    return 0;
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info) {
    list_t *node = NULL;
    size_t i;

    if (environ == NULL) {
        _eputs("Environ array is NULL.\n");
        return 1;
    }

    for (i = 0; environ[i]; i++) {
        if (add_node_end(&node, environ[i], 0) == NULL) {
            _eputs("Failed to populate environment list.\n");
            return 1;
        }
    }

    info->env = node;
    return 0;
}

