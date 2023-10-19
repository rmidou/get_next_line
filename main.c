#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	char	*str;
	
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		printf("---\n");
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);	
}