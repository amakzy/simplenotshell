#include "shell.h"

char *line = NULL;
char **commands = NULL;
char *shell_name = NULL;
int status = 0;

int main(int argc __attribute__((unused)), char **argv)
{
	int i, type_command = 0;
	char **current_command = NULL;
	size_t n = 0;

	shell_name = argv[0];
	signal(SIGINT, ctrl_c_handler);

	while (1)
	{
		non_interactive();
		print_prompt();

		if (read_input() == -1)
		{
			free_resources();
			exit(status);
		}

		tokenize_commands();

		i = 0;
		while (commands[i] != NULL)
		{
			current_command = tokenize_command(commands[i]);

			if (current_command[0] == NULL)
				break;

			type_command = parse_command_type(current_command[0]);

			switch (type_command)
			{
				case COMMAND_TYPE_1:
					initialize_command_type1(current_command);
					break;
				case COMMAND_TYPE_2:

					break;
				default:

					break;
			}

			free(current_command);
			i++;
		}

		free(commands);
	}

	free_resources();
	return status;
}
