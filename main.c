#include "get_next_line.h"

/*int main()
{
    int     fd1;
    char    *line;
    int     i;

    i = 1;
    //line = NULL;
    fd1 = open("tests/test1.txt", O_RDONLY);
    line = get_next_line(fd1);
    printf("Line n.%d: %s", i, line);
    while (line)
    {
        free(line);
        line = get_next_line(fd1);
        printf("Line n.%d: %s", i, line);
        i++;
    }
    close(fd1);
    return (0);
}*/

int	main(void)
{
	char	*result;
	int		fd;
	int		iterations;

	fd = open("day2.txt", O_RDONLY);
	//printf("FD is %d\n", fd);
	iterations = 100;
	int line_sum = 0;
	char buffer[2];
	int sum = 0;
	char *number_first;
	for (int i = 0; i < iterations; i++)
	{
		result = get_next_line(fd);
		if (get_cubes(result) == 0)
			line_sum = get_number(result);
			printf("%d\n", line_sum);
		//char number_last = get_last(result);
		//buffer[0] = number_first;
		//buffer[1] = number_last;
		//buffer[2] = '\0';
		//line_sum = atoi(number_first);
		//printf("%d\n", sum);
		//sum = sum + line_sum;
		//printf("%d\n", sum);
		free(result);
	}
	printf("=%d", sum);
	close(fd);
	//fd = open("tests/test1.txt", O_RDONLY);
	//printf("FD is %d\n", fd);

	//fd = open("tests/test1.txt", O_RDONLY);

	// result = get_next_line(fd);
	// printf("%s", result);
	// while (result)
	// {
	// 	free(result);
	// 	result = get_next_line(fd);
	// 	printf("%s", result);
	// }
	//iterations = 2;
	//for (int i = 0; i < iterations; i++)
	//{
	//	result = get_next_line(fd);
	//	printf("|%d: %s", i + 1, result);
	//	free(result);
	//}
	//close(fd);

	//int fd1 = open("tests/test1.txt", O_RDONLY);
	//iterations = 5;
	//for (int i = 0; i < iterations; i++)
	//{
	//	result = get_next_line(fd);
	//	printf("|%d: %s", i + 1, result);
	//	free(result);
	//}
	//close(fd);
    //close(fd1);
	return (0);
}