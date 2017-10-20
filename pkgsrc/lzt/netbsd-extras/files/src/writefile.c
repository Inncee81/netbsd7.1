#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define	BUFFSIZE	4096

int main(int ac,char **av) {
	struct stat	st;
	int		rc,k;
	long		incr=0,pos=0,blocks=0;
	FILE		*ifile=NULL,*ofile=NULL;
	char		buffer[BUFFSIZE];

	if (ac != 3) {
		fprintf(stderr,"USE %s ifile ofile\n",av[0]); 
		printf("#USE %s ifile ofile\n",av[0]); 
		exit(1);
	}
	if (!(ifile=fopen(av[1],"r"))) {
		printf("#INVALID %s\n",av[1]); 
		perror(av[1]);
		exit(1);
	}
	if (!(ofile=fopen(av[2],"w"))) {
		printf("#INVALID %s\n",av[2]); 
		perror(av[2]);
		exit(2);
	}
	fstat(fileno(ifile),&st);
	blocks=(st.st_size / BUFFSIZE);
	incr=(blocks/100) + 1;
	for (k=0,pos=0;fread(buffer,sizeof(buffer),1,ifile);pos++) {
		if (!(pos % incr)) {
			printf("%d\n#%d%%\n",k,k++);
			fflush(stdout);
		}
		usleep(10000);
		fwrite(buffer,sizeof(buffer),1,ofile);
	}
	printf("100%%\n#FLUSH BUFFERS\n");
	fclose(ifile);
	fclose(ofile);
	printf("#DONE\n");
	return 0;
}
