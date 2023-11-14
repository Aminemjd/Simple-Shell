#include "shell.h"

/**
 * main - Entry point for the shell program
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int ac, char **av)
{
    info_t info[] = { INFO_INIT };
    int fd = STDERR_FILENO; // Use constant for clarity

    // Example of inline assembly (modify file descriptor)
    asm("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (fd)
        : "r" (fd));

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            perror(av[0]); // Print specific error message
            return EXIT_FAILURE;
        }
        info->readfd = fd;
    }

    populate_env_list(info);
    read_history(info);
    hsh(info, av); // Consider adding a comment about what hsh does

    return EXIT_SUCCESS;
}

