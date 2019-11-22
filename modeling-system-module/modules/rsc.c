#include <stdio.h>
#include <limits.h>
#include <unistd.h>

FILE *runSystemCommand(const char *system_comand);

int main(int argc, char** argv) {
	FILE *fp;
	char line[LINE_MAX];
	
	printf("Welcome to run system command.\n");
	fp = runSystemCommand("ps -aux");
	
	/* char *fgets(char *s, int size, FILE *stream); */
	while((fgets(line,LINE_MAX,fp)) != NULL){
		printf("%s",line);
	}
	pclose(fp);
	return 0;
}


FILE *runSystemCommand(const char *system_command){
	/* man popen */
	/*
 	FILE *popen(const char *command, const char *type);
        int pclose(FILE *stream);
        */

	FILE *fp = NULL;
	fp=popen(system_command,"r");
	
	
	return fp;
}
