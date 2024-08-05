#include "../minishell.h"

int ft_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9))
        return (1);
    else
        return (-1);
}