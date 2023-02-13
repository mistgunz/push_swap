/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:50:32 by rnait-el          #+#    #+#             */
/*   Updated: 2023/02/13 05:52:19 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	if (!num[i])
		ft_error();
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	args = argv;
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]))
			ft_error();
		if (ft_contains(tmp, args, i))
			ft_error();
		i++;
	}
}
