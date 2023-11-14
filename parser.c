#include "shell.h"

#define MAX_BUFFER_SIZE 1024

int is_cmd(char *path);

char *get_substring(char *pathstr, int start, int stop);

char *find_path(info_t *info, char *pathstr, char *cmd);

int is_cmd(char *path)
{
    struct stat st;

    if (!path || stat(path, &st))
        return 0;

    if (st.st_mode & S_IFREG)
    {
        return 1;
    }
    return 0;
}

char *get_substring(char *pathstr, int start, int stop)
{
    char *buf = malloc(stop - start + 1);
    if (!buf)
        return NULL;

    int k = 0;
    for (int i = start; i < stop; i++)
    {
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    }
    buf[k] = '\0';
    return buf;
}

char *find_path(info_t *info, char *pathstr, char *cmd)
{
    if (!pathstr)
        return NULL;

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(cmd))
            return _strdup(cmd);
    }

    int i = 0, curr_pos = 0;
    char *path;

    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = get_substring(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (is_cmd(path))
                return path;
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }

    return NULL;
}

