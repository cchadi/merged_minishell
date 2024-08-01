/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:47 by achakour          #+#    #+#             */
/*   Updated: 2024/07/30 14:09:45 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_charchr(char c, char *find)
{
	int	i;

	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		++i;
	}
	return(0);
}

int	ft_strchar(char *s, char *find)
{
	int			i;
	int			j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (find[j])
		{
			if (s[i] == find[j])
				return (1);
			++j;
		}
		++i;
	}
	return(0);
}


