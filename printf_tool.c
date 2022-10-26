#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_put_adress(unsigned long n, const char *base, int *len)
{
	if (n >= 16)
		ft_put_adress(n / 16, base, len);
	ft_putchar(base[n % 16], len);
}
