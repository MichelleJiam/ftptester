/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 20:32:57 by mjiam          #+#    #+#                */
/*   Updated: 2019/12/21 20:52:37 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <stdbool.h>

#ifndef TEST_H
# define TEST_H

typedef struct	s_data
{
	char		type;
	int			left;
	int			zero;
	int			precision;
	int			hash;
	int			group;
	char		sp_plus;
	int			sign;
	int			size;
	int			width;
	char		space;
}				t_data;

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_printf(const char *input, ...);
void	printer(const char c, size_t len, int *printcount);
void	writer(const char *ptr, size_t len, int *printcount);

#endif
