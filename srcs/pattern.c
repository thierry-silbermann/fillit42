/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:58:58 by tsilberm          #+#    #+#             */
/*   Updated: 2016/01/21 15:59:00 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const t_pattern		g_patterns[TETRI_PATTERNS_COUNT] = {
	{ "###...#.........", 57856, 3 },
	{ ".#...#..##......", 17600, 2 },
	{ "#...###.........", 36352, 3 },
	{ "##..#...#.......", 51328, 2 },
	{ "###.#...........", 59392, 3 },
	{ "##...#...#......", 50240, 2 },
	{ "..#.###.........", 11776, 3 },
	{ "#...#...##......", 35008, 2 },
	{ "###..#..........", 58368, 3 },
	{ ".#..##...#......", 19520, 2 },
	{ ".#..###.........", 19968, 3 },
	{ "#...##..#.......", 35968, 2 },
	{ ".##.##..........", 27648, 2 },
	{ "#...##...#......", 35904, 2 },
	{ "##...##.........", 50688, 2 },
	{ ".#..##..#.......", 19584, 2 },
	{ "####............", 61440, 4 },
	{ "#...#...#...#...", 34952, 1 },
	{ "##..##..........", 52224, 2 }
};

int			get_matched_pattern_index(uint16_t value)
{
	int		i;

	i = 0;
	while (i < TETRI_PATTERNS_COUNT)
	{
		if (value == g_patterns[i].value)
			return (i);
		i++;
	}
	return (-1);
}
