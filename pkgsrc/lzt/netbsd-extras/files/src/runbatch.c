#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

extern	char	*optarg;
extern	int	optind;

int main (int ac,char **av) {
	int	wstatus,i,rc,pid,slptime=10;
	char	area[1024],ch,*pidfile="/var/run/runbatch.pid";
	FILE	*pidfd;

	while ((rc=getopt(ac,av,"p:k")) != -1) {
		switch(rc) {
		case 'k':
			if (!(pidfd=fopen(pidfile,"r"))) {
				perror(pidfile);
				exit(3);
			}
			fgets(area,sizeof(area),pidfd);
			pid=atoi(area);
			fclose(pidfd);
			if (pid) {
				if (kill(pid,SIGINT))
					perror("kill");
			}
			unlink(pidfile);
			exit(0);
		case 'p':
			pidfile=optarg;
			break;
		}
	}

	if (ac > 1) {
		slptime=atoi(av[1]);
	}
	if ( ! slptime) {
		perror ("sleep time");
		return 1;
	}

	if (fork() > 0) 
		return 0;
	if (!(pidfd=fopen(pidfile,"w"))) {
		perror("pidfile");
		return 2;
	}
	fprintf(pidfd,"%d\n",getpid());
	fclose(pidfd);
	for(;;) {
		if (fork() == 0) {
			execlp("/usr/libexec/atrun","atrun",NULL);
			perror("execlp");
			exit(1);
		}
		wait(&wstatus);
		sleep(slptime);
	}
	return 0;
}
