/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:43 by achakour          #+#    #+#             */
/*   Updated: 2024/08/03 14:25:26 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define  MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h> 
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PATH_SIZE 5000

# define CMD 1
# define FLAG 2
# define O_FILE 3
# define IN_FILE 4
# define APP_OUT 5
# define DOG 6
# define PIPE 7


// t_env   *env_var;

typedef struct s_a9aw9o3  // storing data while parsing
{
    struct s_a9aw9o3    *next;
    char                *cmd;
    int     quoted;
    int     type;
    int     err;
} t_a9aw9o3;

typedef struct s_arg // storing args as linkd list
{
    char *arg;
    struct s_arg *next;
} t_arg;

typedef struct s_shell  // send to execution
{
    int in;
    int out;
    char *cmd;
    t_arg *args;
    int     err;
    struct s_shell *next;
} t_shell;

typedef struct s_var  // for pipex functions
{
	char	**cmd_1;
	char	**cmd_2;
	char	*cmd_path_1;
	char	*cmd_path_2;
}			t_var;

typedef struct s_env // for storing the env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

typedef struct s_ms // build to execute cmd
{
    int  pid;
    char *cmd;
    int infile;
    char **arg;
    int outfile;
    struct s_ms *next;
} t_ms;

/********************* Parsing **********************/

int         check_syntax(char *str);
int         check_quotes(char *str);
void        process_red(t_a9aw9o3 *cmd);
void        expander(t_a9aw9o3 *tokens);
t_shell     *fill_struct(t_a9aw9o3 **cmd);
int	        ft_charchr(char c, char *find);
t_shell     *zre3_btata_dk_lflah(char *str);
int         ft_strchar(char *s, char *find);
void        sanitize_tokens(t_a9aw9o3 *cmd);
void	    ft_heredoc(char *del, t_ms **ms);
int         get_qoutes(char *str, int index);
void        remove_quotes(t_a9aw9o3 *tokens);
char	    *ft_strjoin_exp(char *s1, char *s2);
t_a9aw9o3	*lstnew_9aw9a3a(char *arg, int quote_type);
void	    add_back_9aw9a3a(t_a9aw9o3 **lst, t_a9aw9o3 *new);

/*********************    Linked_list    *******************/

t_ms	*ft_lstnew(void);
t_ms	*ft_lstlast(t_ms *lst);
void	ft_lstadd_back(t_ms **lst, t_ms *new);
void	ft_lstadd_front(t_ms **lst, t_ms *new);

/**********************     LIBFT    ***********************/

char	*ft_itoa(int n);
int		is_alpha(char c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isdigit( int c );
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memmove( void *dst, const void *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/************************ printf  *************************/

int		ft_putnbr(int c, int len);
int		ft_putchar(char c, int len);
int		ft_putstr(char *s, int len);
int		ft_printf(const char *str, ...);
int		ft_check(char s, va_list args, int len);
int		ft_put_positive(unsigned int c, int len);
int		ft_put_adress(unsigned long decimal, int len);
int		ft_decimal_to_hex(unsigned long decimal, int len);
int		ft_decimal_to_hexa(unsigned int decimal, int len);

/********************* get_next_line  **********************/

char	*get_next_line(int fd);
char	*returnline(char *buffer);
char	*ft_readfile(int fd, char *buffer);

/******************* builtins  **********************/

void    build_pwd(void);
void    build_env(t_env *v);
void    build_exit(char **status);
void    build_echo(char **str, int fd);
void    build_unset(char **str, t_env **v);
void    build_export(char **str, t_env **v);
t_env   *export_split(char *str, t_env **v);
void    build_cd(char **direction, t_env *v);

/*************** env_linked_list  ******************/

t_env   *env_lstnew(void);
t_env   *split_env(char *str);
t_env   *env_lstlast(t_env *lst);
void    get_envp(char **envp, t_env **head);
void    env_lstadd_back(t_env **lst, t_env *new);
void    env_lstadd_front(t_env **lst, t_env *new);

/******************* execution ********************/

int     ft_isalpha(char c);
void	ft_free(char **ptr);
void	swap_nodes(t_env **v);
int     multiple_arg(char **ptr);
void    check_cmd(t_ms **e, t_env *v);
char    *env_searsh(t_env *v, char *find);
int     simple_execute(t_ms *e, char **env);
char	*if_accessible(char *cmd, char *env);
int     execute_builtins(t_ms *e, t_env **v);
int     ft_strcmp(const char *s1, const char *s2);
void	ft_pipe(char **av, char **env, t_var *var);
void    forming_list(t_ms **my_struct, t_shell *shell);
void    execute_cmd(t_ms **e, t_env *v, char **envp, int tmp);

#endif