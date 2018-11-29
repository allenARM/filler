#include "filler.h"

int         check_placement(t_filler filler, int i, int j)
{
    int     i_piece;
    int     j_piece;
    int     count;

    i_piece = 0;
    j_piece = 0;
    count = 0;
    while (filler.piece.field[i_piece])
    {
        j_piece = 0;
        while (filler.piece.field[i_piece][j_piece])
        {
            if (filler.piece.field[i_piece][j_piece] == '*')
            {
                if (filler.map.field[i_piece + i][j_piece + j])
                {
                    if (filler.map.field[i_piece + i][j_piece + j] == filler.player.symbol || filler.map.field[i_piece + i][j_piece + j] == filler.player.symbol + 32)
                        ++count;
                    if (filler.map.field[i_piece + i][j_piece + j] == filler.enemy.symbol || filler.map.field[i_piece + i][j_piece + j] == filler.enemy.symbol + 32)
                        return (0);
                }
                else
                    return (0);
            }
            ++j_piece;
        }
        ++i_piece;
    }
    if (count == 1)
        return (1);
    return (0);
}

t_point     *simple_placing(t_filler filler)
{
    t_point     *answer;
    int         i;
    int         j;

    i = 0;
    j = 0;
    answer = malloc(sizeof(t_point *));
    answer = NULL;
    while (filler.map.field[i])
    {
        j = 0;
        while (filler.map.field[i][j])
        {
            if (check_placement(filler, i, j) == 1)
            {
                answer->y = i;
                answer->x = j;
                return (answer);
            }
            ++j;
        }
        ++i;
    }
    answer->y = 0;
    answer->x = 0;
    return(answer);
}

int         solver(t_filler filler)
{
    t_point     *answer;

    answer = malloc(sizeof(t_point *));
    answer = NULL;
    
    t_filler temp;
    temp = filler;

    // int i;
    // i = 0;
    // while (filler.map.field[i])
    //     ft_printf("%s\n", filler.map.field[i++]);
    // i = 0;
    // while (filler.piece.field[i])
    //     ft_printf("%s\n", filler.piece.field[i++]);

    // answer = simple_placing(filler);
    // ft_printf("%d %d\n", answer->y, answer->x);
    write(1, "8 2\n", 4);
    return (0);
}