/* 
Matala 2 in Operating systems
 by ilan Souffir and Nerya Rez
*/
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "stdio.h"
#include "errno.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <signal.h>
#include <stdbool.h>

void handle_sigint(int sig) {
    // do nothing
}

int main(){

	int i;
	char *argv[10];
	char command[1024];
	char *token;

	char* output_file;
	bool redi1 = false;
	bool redi2 = false;

	int fd;


    signal(SIGINT, handle_sigint);


	while (1) {
	    printf("hello: \n");
	    fgets(command, 1024, stdin);
	    command[strlen(command) - 1] = '\0'; // replace \n with \0

	    /* parse command line */
	    i = 0;
	    token = strtok (command," ");
	    while (token != NULL)
	    {
        
		    if(strcmp(token, ">") == 0)
		    {
		    redi1 = true;
		    output_file = strtok (NULL, " ");
		    printf("the output file is: %s\n", output_file);
		    break;
		   } 
			else if(strcmp(token, ">>") == 0)
			{
			redi2 = true;
			output_file = strtok (NULL, " ");
			printf("the output file is: %s\n", output_file);
		    break;
			} 
		argv[i] = token;
		printf (" argv[%d] == %s\n",i, argv[i]);
		token = strtok (NULL, " ");
		i++;
	    }

		// printf("i == %d\n", i);



		// else if (redi2)
		// {
		// 	fd = fopen(argv[i-1], "ab");
		// 	if(dup2(fileno(fd), STDOUT_FILENO) == -1){
		// 		perror("cannot redirect");
		// 		return 1;
		// 	}
		// 	fclose(fd);
			
		// }
		
		
	    argv[i] = NULL;

	    /* Is command empty */ 
	    if (argv[0] == NULL)
		continue;

        if (strcmp(argv[0], "exit") == 0) {
            exit(EXIT_SUCCESS);
        }

        

	    /* for commands not part of the shell command language */ 
	    if (fork() == 0) { 
			if (redi1 || redi2)
			{
			if (redi1) fd = open(output_file, O_WRONLY|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP, S_IROTH);
			else if(redi2) fd = open(output_file, O_WRONLY| O_APPEND|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP| S_IROTH);

			// if(fd == NULL){
			// 	perror("can't open the file\n");
			// 	return 1;

			// }

			if(dup2(fd, STDOUT_FILENO) == -1){
				perror("cannot redirect\n");
				return 1;
			}
			if(dup2(fd, STDERR_FILENO) == -1){
				perror("cannot redirect\n");
				return 1;
			}
			
			
			// fflush(stdout);
			}
		if(redi1||redi2) close(fd);
		execvp(argv[0], argv);
		
		 
	    } 
        wait(NULL);
		
		// fclose(fd);

	}


    return 0;
}
