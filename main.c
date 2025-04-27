#include "main.h"

char* commands[] = {"pwd", "help"};
int num_of_coms = sizeof(commands) / sizeof(commands[0]);

char* get_curr_dir() {
	static char cwd[PATH_MAX];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
			return cwd;
	} else {
			perror("getcwd() error");
			return "";
	}
}

bool is_valid_command(char* command) {
	bool valid_c = false;
	for (int i = 0; i < num_of_coms; i++) {
			if (strcmp(command, commands[i]) == 0) {
					valid_c = true;
					break;
			}
	}
	return valid_c;
}

int main() {
	system("figlet -f big WELCOME TO THE TERMGASM");

	while (1) {
			char command[50];
			char* curr_dir = get_curr_dir();
			printf("\n%s>  ", curr_dir);
			fgets(command, sizeof(command), stdin);
			command[strcspn(command, "\n")] = 0;

			bool valid = is_valid_command(command);
			if (valid == true) {
					printf("\nDEBUG: Command valid\n");
			} else {
					printf("\nDEBUG: Command not valid\n");
			}
	}

	return 0;
}

