/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: new_head on success, NULL on failure
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    if (!head)
        return (NULL);

    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }

    new_node->next = *head;
    *head = new_node;
    return (new_node);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: new_node on success, NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    if (!head)
        return (NULL);

    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }

    if (*head)
    {
        list_t *last = *head;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
    else
    {
        *head = new_node;
    }

    return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    if (!head || !*head)
        return (0);

    list_t *current = *head;
    list_t *prev = NULL;
    unsigned int i = 0;

    while (current)
    {
        if (i == index)
        {
            if (prev)
                prev->next = current->next;
            else
                *head = current->next;

            free(current->str);
            free(current);
            return (1);
        }

        i++;
        prev = current;
        current = current->next;
    }

    return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
    if (!head_ptr || !*head_ptr)
        return;

    list_t *current = *head_ptr;
    list_t *next_node;

    while (current)
    {
        next_node = current->next;
        free(current->str);
        free(current);
        current = next_node;
    }

    *head_ptr = NULL;
}

