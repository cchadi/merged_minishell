#include "minishell.h"

//this file is for main only (for "zre3_btata..c" function i already  
// added a seperate file for it)

int main(int ac, char **ar, char **envp)
{
    t_env *env;
    t_shell *shell;
    t_ms *ms;
    char *input;

    env = NULL; 
    get_envp(envp, &env);
    input = readline("minishell $:");
    zre3_btata_dk_lflah(input); // take address of shell as parameter to fill on it
    ms = NULL;
    forming_list(&ms, shell);
    
    // read_history(input);
    return (0);
}