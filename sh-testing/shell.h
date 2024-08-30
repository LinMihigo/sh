#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#define TOKEN_ARRAY_SIZE 20
#define DELIM " \t\n"

void display_prompt(void);
char *get_input(char *lineptr, size_t len);
char **string_tok(char *str, char *delim);
int exec_builtin(char *args[], char **envp);
void exec_external(char *pathname, char *args[], char *envp[]);
char *get_env_path(char **envp, int size);
int _path_size(char **envp);
char *_concatenate(char *dir, char *pathname);
int is_executable(char *full_path);
char *find_ext_file(char *pathname, char **envp, int cmd_count);
char *get_home_path(char **envp, int size);
int home_path_size(char **envp);
char *get_pwd_path(char **envp, int size);
int pwd_path_size(char **envp);
char *get_oldpwd_path(char **envp, int size);
int oldpwd_path_size(char **envp);
int cd_args(char **args, char **envp);
void exit_function(char *args[]);
int set_oldpwd(void);
int set_pwd(void);
int cd_exec(char *args[], char **envp);
void _free(void **ptr);

/* str_utils.c */
size_t _strlen(const char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int n);
char *_concat(char *var, char *val);
int _strcon(char *str, char c);

/* str_utils.c */
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);
char *_strcat(char *dest, const char *src);

/* exec_utils */
char *get_env_path(char **envp, int size);
int _path_size(char **envp);
char *_concatenate(char *dir, char *pathname);
int is_executable(char *full_path);

/* env_utils.c */
int env_size(void);
int get_env_size(char **env);
char **copy_environ(void);
char *get_env_var_value(char **env, char *var);
int get_env_var_value_len(char **env, char *var);


/* env_functions */
extern char **environ;
void get_env(void);
int set_env(char *var, char *val, int overwrite);
int unset_env(char *var);

char *shell_path_exec(char *pathname);
char *find_command(char *comm, char **envp);
#endif
