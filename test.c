#include <stdio.h>
#include "libft/libft.h"
#include <time.h>

// simple generator random values
// TODO add this to libft

int main(void)
{
	time_t lt;
	int x;
	lt = time(NULL);
	ft_show_binary(lt);
	printf("%ld\n", lt);
	x = lt % 1000;
	double y = (double)x / 1000; 
	ft_show_binary(x);
	printf("%d\n", x);
	printf("%f\n", y);
	return 0;
}