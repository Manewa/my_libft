#include "libft.h"

void	ft_lstfree(t_list **a)
{
	t_list	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	return ;
}