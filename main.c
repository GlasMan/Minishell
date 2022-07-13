#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char *command;
    while(1)
    {
        command = readline("\033[0;34mscoskun@minishell:");
        if (ft_strncmp(command, "pwd", 2) == 0)
            ft_pwd();
        else if(ft_strncmp(command, "env", 3) == 0)
            ft_env(env);
        else
            printf("%s\n", strerror(errno));
        add_history(command);
    }
}