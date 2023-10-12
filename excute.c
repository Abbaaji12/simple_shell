#include "shell.h"

/**
 * handle_builtin - Handle Builtin Cmmd
 * @cmd: Parsed Cmd
 * @er:statue of last Excute
 * Return: on success it return 0 and -1 when it failed
 */

int handle_builtin(char **cmd, int er) /*builtin declaration*/
	{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Excute Simple Shell Cmd (Fork,Wait,Excute)
 *
 * @cmd:Parsed Cmd
 * @input: User Input
 * @c:Shell Excution Time Case of Cmd Not Found
 * @argv:Prog Name
 * Return: 1 Case Cmd Null -1 Wrong Cmd 0 Cmd Excuted
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
