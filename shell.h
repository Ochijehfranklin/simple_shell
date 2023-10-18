#ifndef SHELL_H
#define SHELL_H

/* Macro def for EXIT & EOF*/
#define EXIT -3
#define my_EOF -1

#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct lynkd_lst - A new struct type defining a linked list.
 * @dirs: A directory path.
 * @next: points to another struct list_s.
 */
typedef struct lynkd_lst
{
        char *dir;
        struct lynkd_lst *next;
} lynkd_lst;

/**
 * struct bultinz - struct to hold our builtin cmds
 * @nam: builtin cmd
 * @fpt: pointer to our builtin commands
 */
typedef struct builtinz
{
	char *nam;
	int (*fpt)(char **argv, char **fist);
} builtinz;

/**my prototypes*/
char **our_envcopy(void);
int main(int arc, char **argv);
int our_strlength(const char *format);
void mg_sig(int sign __attribute__((unused)));
int child_exec(char **args, char **fist);
char *our_envalue(char *var, int length);
char *_getArgs(char *lin, int *retrn);
void break_line(char **lyn, ssize_t length);
char *cd_err(char **args);
void change_var(char **args, int *retrn);
int (*checkbuiltins(char *cmds))(char **args, char **arg0);
char *env_err(char **args);
char *error_126(char **args);
char *error_127(char **args);
char *exit_err(char **args);
int exit_goshell(char **get_args, char **fist);
int fopen_error(char *path);
int our_strlength(const char *format);
void fri_args(char **args, char **arg0);
void fri_env(void);
void fri_list(lynkd_lst *head);
char **get_env(const char *vra);
int go_cd(char **args, char __attribute__((__unused__)) **fist);
char *hatoi(int m);
int kal_args(char **args, char **arg0, int *retrn);
int length_int(int m);
int look_args(char **args);
int mg_args(int *retrn);
ssize_t newLength(char *lyn);
int no_of_toks(const char *typed);
void op_check(char *lyn, ssize_t *new_length);
int our_commands(char *pat, int *last_retrn);
int our_error(char **args, int err);
void our_exec(char **split_cmd, char **argv, char **env);
ssize_t our_getline(char **linept, size_t *m, FILE *streem);
int child_exec(char **args, char **fist);
void *our_realloc(void *prevptr, unsigned int old_block, unsigned int new_block);
void our_setlineptr(char **linept, size_t *m, char *buffer, size_t c);
char *our_strcat(char *s1, const char *s2);
int our_strcmp(char *str1, char *str2);
char *our_strcpy(char *buffer_dest, const char *src);
char *our_strncat(char *s1, const char *s2, size_t m);
int our_strncmp(const char *str1, const char *str2, size_t m);
char **our_strtok(char *str, char *delem);
int our_tokcount(char *string, char *delem);
int our_toklen(char *string, char *delem);
char *path_locate(char *cmds);
char *path_populate(char *path);
char *pick_pid(void);
int print_goenv(char **args, char __attribute__((__unused__)) **arg0);
lynkd_lst *put_endnode(lynkd_lst **head, char *path);
int ran_args(char **args, char **arg0, int *retrn);
lynkd_lst *ret_path(char *path);
int set_goenv(char **args, char __attribute__((__unused__)) **arg0);
char *syntax_err(char **args);
int unset_goenv(char **args, char __attribute__((__unused__)) **arg0);
/*external and global vars*/
char *nam;
int cmdhist;
extern char **environ;

#endif /*SHELL_H*/
