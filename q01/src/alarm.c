#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t flag = 1;

void signal_handler(int signal_number)
{
	flag = 0;
}

int main ()
{
	pid_t alarm_child;
	signal(SIGALRM, alarm_wait);
	alarm_child = fork();
	if (alarm_child != 0) {
		printf("antes do pause\n");
		pause();
		printf("depois do pause\n");
	}
	else {
		alarm(1);
		while(flag) {
			sleep(1);
		}
	}

	printf("Alarme disparado!\n");
	return 0;
}
