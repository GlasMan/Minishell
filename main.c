#include "minishell.h"

void	sighandler(int sig)
{
	if (sig == SIGINT)
		exit(1);
	else if (sig == SIGQUIT)
		kill(9, getpid());

}

char	*prompt(char **env)
{
	int		i;
	char	*prom;
	char	*colur;

	i = 0;
	prom = malloc(sizeof(char) * 1000);
	colur = ft_strdup("\033[0;35m");
	while (env[i])
	{
		if (ft_strnstr(env[i], "USER", 4))
			break;
		i++;
	}
	prom = ft_strdup(ft_strchr(env[i], '='));
	prom = ft_strjoin(prom, "@minishell \033[0;34m");
	prom = ft_strjoin(prom, getcwd(NULL, 0));
	prom = ft_strjoin(prom, "\n⚡️");
	colur = ft_strjoin(colur, prom);
	return(colur);
}



int	main(int ac, char **av, char **env)
{
	char	*command;
	char	**cmd_lst;
	int		pid;
	signal(SIGINT, sighandler);
	while(1)
	{
		command = readline(prompt(env));
		if (command != NULL)
		{
			cmd_lst = ft_split(command, ' ');
			if (ft_strcmp(cmd_lst[0], "pwd") == 0)
				ft_pwd();
			else if(ft_strcmp(cmd_lst[0], "env") == 0)
				ft_env(env);
			else if (ft_strcmp(cmd_lst[0], "cd") == 0)
			{
				if (ft_cd(cmd_lst[1], env) == -1)
					printf("%s\n", strerror(errno));
			}
			else if (ft_strcmp(cmd_lst[0], "exit") == 0)
					exit(1);
			else if (ft_strcmp(cmd_lst[0], "echo") == 0)
				ft_echo(cmd_lst, 1);
			else if (ft_strcmp(cmd_lst[0], "ls") == 0)
			{
				pid = fork();
				if(pid == 0)
					execve("/bin/ls", cmd_lst, NULL);
				else
					wait(NULL);
			}
			else if (ft_strcmp(cmd_lst[0], "cat") == 0)
			{
				pid = fork();
				if(pid == 0)
					execve("/bin/cat", cmd_lst, NULL);
				else
					wait(NULL);
			}
			else if(pid != 0)
				printf("%s\n", strerror(errno));
		}
		else
			continue;
		add_history(command);
	}
}
