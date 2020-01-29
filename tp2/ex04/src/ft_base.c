#include "tp2.h"

int 	ft_strlen(char *s)
{
	int		len;

	for (len = 0; s[len]; len++);
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	for (i = 0; i < len; i++)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

void	init_data(Qlc *data)
{
	data->in = NULL;
	data->out = NULL;
	data->in_name = NULL;
	data->out_name = NULL;
	data->qlc = NULL;
	data->error_val = 0;
}


