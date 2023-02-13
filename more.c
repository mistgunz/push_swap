# include "push_swap.h"

int	ft_atol(char *str)
{
	int		neg;
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (str[i] <= ' ')
		i++;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	if (num > INT_MAX && neg > 0)
		ft_error();
	else if ((num * neg) < INT_MIN)
		ft_error();
	return (num * neg);
}