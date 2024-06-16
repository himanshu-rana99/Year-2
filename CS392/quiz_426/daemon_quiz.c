//"I pledge my honor that I have abided by the Stevens Honor System" - Himanshu Rana - hrana2

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <fcntl.h>
#include <time.h>

int main() { 
	pid_t pid, sid; 

	pid = fork(); 
	if(pid < 0) { 
		exit(EXIT_FAILURE);
	}

	if(pid > 0) {
		exit(EXIT_SUCCESS); 
	}

	umask(0); 

	sid = setsid(); 
	if(sid < 0) {
		//log failure 
		exit(EXIT_FAILURE);
	}

	//change the current working directory
	if((chdir("/tmp")) < 0) {
		exit(EXIT_FAILURE);
	}

	//close out the standard file descriptors
	close(STDIN_FILENO); 
	close(STDOUT_FILENO); 
	close(STDERR_FILENO); 

	FILE *fp = fopen("cs392_daemon.log", "a"); 
	if(fp == NULL) {
		perror("file cannot be opened");
		exit(EXIT_FAILURE);
	}

	//daemon-specific initialization goes here 
	time_t t; 
	struct tm *tm; 
	while(1) {
		//some task here 
		sleep(2); 
		t = time(NULL); 
		tm = localtime(&t); 
		fprintf(fp, "%s", asctime(tm));
		//fflush(daemon_quiz);
		fflush(fp);
	

	}
	//properly close the file 
	fclose(fp);

	return 0; 


}