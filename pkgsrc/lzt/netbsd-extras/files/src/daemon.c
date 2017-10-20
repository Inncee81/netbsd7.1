#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int ac,char **av){
	av[ac]=NULL;

	av[0]=av[1];
	daemon(1,1);
	execvp (av[0],av+1);
}
