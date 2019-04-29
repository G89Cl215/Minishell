#include <unistd.h>
int main(int ac, char **av)
{
	while (*av)
	{
		while (**av)
		{
			write(1, *av, 1);
			(*av)++;
		}
		av++;
			write(1, "\n", 1);
	}
}
