#include "../minishell.h"

int count_arg(char **ptr)
{
	int l;

	l = 0;
	while (ptr[l])
		l++;
	if (l > 1)
		return (1);
	return (-1);
}

void build_cd(char **direction, t_env *v)
{
        if (direction)
        {
                if (count_arg(direction) == 1)
                        ft_printf("cd: too many arguments\n");
                else if (ft_strncmp(direction[0], "-", sizeof(direction[0])) == 0)
                {
                        ft_printf("%s\n", env_searsh(v, "OLDPWD"));
                        if (chdir(env_searsh(v, "OLDPWD")) == -1)
                                perror(direction[0]);
                }
                else if (chdir(direction[0]) == -1)
                        perror(direction[0]);
        }
        else
        {
                if (chdir(env_searsh(v, "HOME")) == -1)
                        perror(direction[0]);
        }
	return ;
}
