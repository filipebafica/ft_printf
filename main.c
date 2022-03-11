#include "ft_printf.h"
#include <fcntl.h>

int	main(void)
{
	char	*var;

	int fd = open("./ppm_file.ppm", O_RDWR | O_CREAT | O_APPEND, 0777);

	var = "Hello World";
	ft_printf("Print this: %s\n", var);
	ft_dprintf(fd, "Print this: %s\n", var);
	return (0);
}