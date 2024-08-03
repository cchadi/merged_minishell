/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_shadi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:44:45 by achakour          #+#    #+#             */
/*   Updated: 2024/08/01 20:19:16 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


t_shell *tokens_new(void)
{
    t_shell *new;

    new = malloc(sizeof(t_shell));
    if (!new)
        return (NULL);
    new->next = NULL;
    new->args = NULL;
    new->cmd = NULL;
    new->out = 1;
    new->in = 0;
    return (new);
}

t_arg   *arg_new(char *cmd)
{
    t_arg   *new;

    new = malloc(sizeof(t_arg));
    if (!new)
        return (NULL);
    new->arg = ft_strdup(cmd);
    new->next = NULL;
    return (new);
}

void	lst_rje3_lor(t_arg **lst, t_arg *new)
{
	t_arg   *head;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

t_shell *fill_struct(t_a9aw9o3 **cmd)
{
    t_arg       *arg_strct;
    t_shell     *tokens;
    t_a9aw9o3   *iter;
    t_shell     *head;

    tokens = tokens_new();
    arg_strct = NULL;
    head = tokens;
    iter = *cmd;
    while (iter)
    {
        if (iter->type == 1)
            (tokens)->cmd = ft_strdup(iter->cmd);
        else if (iter->type == 2)
            lst_rje3_lor(&arg_strct, arg_new(ft_strdup(iter->cmd)));
        else if (iter->type == 4 && !ft_strchar(iter->cmd, "<"))
        {
            tokens->in = open(iter->cmd, O_RDWR);
            if (tokens->in == -1)
                perror(iter->cmd);
        }
        else if (iter->type == 3 && !ft_strchar(iter->cmd, ">"))  // add check to infile before openning outfile
        {
            if (tokens->in != -1)
                tokens->out = open(iter->cmd, O_RDWR|O_CREAT|O_TRUNC, 0664);
            if (tokens->out == -1)
                perror(iter->cmd);
        }
        else if (iter->type == 5 && !ft_strchar(iter->cmd, ">>"))
        {
            if (tokens->in != -1)
                tokens->out = open(iter->cmd, O_RDWR|O_CREAT|O_APPEND, 0664);
            if (tokens->out == -1)
                perror(iter->cmd);
        }
        // else if (iter->type == 6 && !ft_strchar(iter->cmd, "<<"))
        //     ft_heredoc()
        if (iter->type == 7 || iter->next == NULL)
        {
            (tokens)->args = arg_strct;
            arg_strct = NULL;
            if (iter->type == 7)
            {
                (tokens)->next = tokens_new();
                tokens = tokens->next;
            }
        }
        iter = iter->next;
    }
    return (head);
}

void    expander(t_a9aw9o3 *tokens) //need a get_env function to get the env value and the linked list of env values
{
    char    *result;//tmp to free the str
    char    *buff;
    int     i;
    int     j;

    result = NULL;
    while (tokens)
    {
        i = 0;
        while (tokens->cmd[i])
        {
            if (tokens->cmd[i] == '$' && get_qoutes(tokens->cmd, i) != 1 && is_alpha(tokens->cmd[i + 1]) && tokens->type != 6)
            {
                j = 0; //the if below checks if $ is in herdog or '' and if $ have chars after it
                while (tokens->cmd[i + j] && is_alpha(tokens->cmd[i + j]))
                    ++j;
                buff = (char *)malloc(sizeof(char) * j + 1);
                j = 0;
                while (is_alpha(tokens->cmd[i + j]))
                {
                    buff[j] = tokens->cmd[i + j];
                    ++j;
                }
                buff[j] = '\0';
                result = getenv(buff);
                if (!result && (tokens->type >= 3 && tokens->type <= 5) && !get_qoutes(tokens->cmd, i))// the cases of ambigius redirection
                {
                    printf("%s ambigious redirectin\n", tokens->cmd + i);
                    tokens->err = 1;
                }
                // free (buff);
                // buff = ft_strjoin(ft_get_str(tokens->cmd + i, &j), result);
                // free (result);
                // tokens->cmd = ft_strjoin(buff, tokens->cmd + i + j);
                i = 0;
            }
            else
                ++i;
        }
        tokens = tokens->next;
    }
}
