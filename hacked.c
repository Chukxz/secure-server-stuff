#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int isValidPassword(char *input)
{
	char actual_password[1024];
	int fd = open("./password", O_RDONLY);
	if (fd < 0)
	{
		perror("read");
		printf("Report this to an admin\n");
		return 0;
	}

	ssize_t n_read = read(fd, actual_password, 1024);
	if (actual_password[n_read-1] == 0xa)
	{
		actual_password[n_read-1] = 0x0;
	}
	close(fd);

	return (strcmp(actual_password, input) == 0);
}

void debug() 
{
    printf("!! ENTERING DEBUG MODE !!\n");
    system("/bin/bash");
}

int checkPassword()
{
    char password[64];

    printf("password: ");
    gets(password);

    return isValidPassword(password);
}

int main(int argc, char **argv)
{
    printf("WELCOME TO THE SECURE SERVER\n");

    if (checkPassword())
    {
        debug();
    } else {
        printf("Wrong password, sorry;\n");
    }
}
