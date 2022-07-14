#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

int		ft_cd(char *cmd, char **env);
void	ft_pwd(void);
void	ft_env(char **env);
#endif
