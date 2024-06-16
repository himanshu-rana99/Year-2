
/*"I pledge my honor that I have abided by the Stevens Honor System" - Himanshu Rana - hrana2*/

#include<stdio.h>
#include<signal.h> 
#include<unistd.h>


/*define your signal handler here*/
void sig_handler(int signo){
	printf("SIGINT received\n");
}


//act.sa_flags = SA_SIGINFO || SA_RESETHAND
int main(int argc, char* argv[]) {
	/*register your signal handler here*/
	signal(SIGINT, sig_handler); 

	while(1){
		sleep(1); 
		printf("Hello\n"); 
	}


	return 0; 
}