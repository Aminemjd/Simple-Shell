#include "shell.h"

/**
 * interactive - checks if the shell is in interactive mode
 * @info: pointer to the info_t structure
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, const char *delim) {
    while (*delim) {
        if (*delim++ == c) {
            return 1;
        }
    }
    return 0;
}

/**
 * _isalpha - checks for an alphabetic character
 * @c: the character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s) {
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++) {
        if (s[i] == '-') {
            sign *= -1;
        }

        if (_isdigit(s[i])) {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        } else if (flag == 1) {
            flag = 2;
        }
    }

    output = (sign == -1) ? -result : result;

    return output;
}

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if true, 0 if false
 */
int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

