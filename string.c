#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string, or -1 on error
 */
int _strlen(char *str)
{
    if (str == NULL) {
        /* Error: Null pointer */
        return -1;
    }

    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: pointer to next character of haystack or NULL if no match
 */
char *starts_with(const char *haystack, const char *needle)
{
    if (haystack == NULL || needle == NULL) {
        /* Error: Null pointer */
        return NULL;
    }

    while (*needle != '\0') {
        if (*needle != *haystack) {
            return NULL; /* No match */
        }
        needle++;
        haystack++;
    }
    return (char *)haystack; /* Match found */
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer or NULL on error
 */
char *_strcat(char *dest, char *src)
{
    if (dest == NULL || src == NULL) {
        /* Error: Null pointer */
        return NULL;
    }

    char *result = dest;
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; /* Ensure null-termination */
    return result;
}

