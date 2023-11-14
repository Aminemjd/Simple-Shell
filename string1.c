#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
    if (dest == src || src == NULL)
        return dest;

    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL on failure
 */
char *_strdup(const char *str)
{
    if (str == NULL)
        return NULL;

    size_t length = _strlen(str);
    char *ret = malloc((length + 1) * sizeof(char));

    if (ret == NULL)
        return NULL;

    _strcpy(ret, str);
    return ret;
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(const char *str)
{
    if (str == NULL)
        return;

    while (*str != '\0')
    {
        _putchar(*str);
        str++;
    }
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    static int index;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
    {
        write(1, buffer, index);
        index = 0;
    }
    if (c != BUF_FLUSH)
        buffer[index++] = c;

    return 1;
}

