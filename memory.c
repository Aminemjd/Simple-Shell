#include <stdbool.h>

/**
 * freeAndNullify - Frees a pointer and nullifies the address
 * @ptr: Address of the pointer to free
 *
 * Return: true if freed, otherwise false.
 */
bool freeAndNullify(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return true;
    }
    return false;
}

