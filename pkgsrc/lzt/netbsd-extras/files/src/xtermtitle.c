#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac,char **av) {
	char 	*p;
	int	i,sz;

	if (ac < 1)
		return 1;

	for (sz=0,i=1;i < ac;i++)
		sz+=strlen(av[i]) + 1;
	if (!(p=calloc(sz,1)))
		return 2;
	for (i=1;i < ac;i++) {
		strcat(p,av[i]);
		strcat(p," ");
	}
	printf("%c]2;%s%c",27,p,7);
	free(p);
	return 0;
}
