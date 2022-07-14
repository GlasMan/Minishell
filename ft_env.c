#include "minishell.h"

void    ft_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        printf("\033[0;36m%s\n", env[i]);
        i++;
    }
}
