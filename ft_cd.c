#include "minishell.h"
#include <string.h>

void	ft_ch_env(char **env, char *buff)
{
	int 	i;
	char	*path;
	char	*p;
	i = 0;
	path = ft_strdup("PWD=");
	p = malloc(10000);
	while (env[i])
	{
		if(strstr(env[i], "PWD"))
		{
			p = getcwd(p, 10000);
			env[i] = ft_strjoin(path, p);
			break;
		}
		i++;
	}
	free(path);
	i = 0;
	while (env[i])
	{
		if (strstr(env[i], "OLDPWD"))
		{
			//getcwd(buff, 1000);
			path = ft_strdup("OLDPWD=");
			env[i] = ft_strjoin(path, buff);
			break;
		}
		i++;
	}
	free(buff);
	free(p);
}

void	ft_pwd(void)
{
	printf("\033[34m%s\n",getcwd(NULL,0));
}

int	ft_cd(char *cmd, char **env)
{
	char	*buff;
	int		res;

	buff = malloc(1000);
	buff = getcwd(buff, 10000);
	res = chdir(cmd);
	ft_ch_env(env, buff);
	return (res);
}
