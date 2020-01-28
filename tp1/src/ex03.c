#include "tp1.h"

unsigned int	hachage(char *mot)
{
	unsigned int	ret;
	int				i;

	ret = 0;
	for (i = 0; mot[i]; i++)
		ret += (i + 1) * mot[i];
	return (ret);
}

unsigned int	hach_1(char *mot)
{
	unsigned int	ret;
	int				i;

	ret = *mot;
	for (i = 0; mot[i]; i++)
		ret += mot[i] * *mot;
	return (ret);
}

unsigned int	hach_2(char *mot)
{
	unsigned int	ret;
	int				i;

	ret = 0;
	for (i = 0; mot[i]; i++)
	{
		if (mot[i] % 3 == 2)
			ret += mot[i] * i;
		else if (mot[i] % 3 == 1)
			ret *= mot[i] + i;
		else
			ret += 5;
	}
	return (ret);
}
