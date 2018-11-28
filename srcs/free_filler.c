#include "filler.h"

void	free_filler(t_filler *filler)
{
	int	i;

	i = 0;
	ft_clean_arr(&filler->map.field);
	ft_clean_arr(&filler->piece.field);
}