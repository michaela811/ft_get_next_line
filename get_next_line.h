/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:58:26 by mmasarov          #+#    #+#             */
/*   Updated: 2023/10/31 13:29:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash);
int		find_newline(t_list *file);
t_list	*ft_get_last(t_list *file);
void	add_to_file(t_list **file, char *buffer, int was_read);
void	ft_extract_line(t_list *file, char **line);
void	ft_malloc_line(char **line, t_list *file);
void	ft_clean_file(t_list **file);
void	free_file(t_list **file);
int		ft_strlen(const char *str);

#endif
