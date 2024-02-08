/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:33:15 by mmasarov          #+#    #+#             */
/*   Updated: 2024/02/08 10:47:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int     fd1;
    char    *line;
    int     i;

    i = 1;
    //line = NULL;
    fd1 = open("file_to_read.txt", O_RDONLY);
    line = get_next_line(fd1);
    printf("Line n.%d: %s", i, line);
    i++; 
    while (line)
    {
        free(line);
        line = get_next_line(fd1);
        printf("Line n.%d: %s", i, line);
        i++;
    }
    close(fd1);
    return (0);
}
