#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *s;
	char *tmp;

	//s = (char *)malloc(20);
	s = (char *)ft_memalloc(100000000);
	//s = (char *)ft_memalloc(20);
	//tmp = s;
	//for (int i = 0; i < 20; i++, tmp++)
	//	printf("_%c_\n", *tmp);
	if (!s)
		printf("NULL\n");
	free(s);
	return (0);
}
