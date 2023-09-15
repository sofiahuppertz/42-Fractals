/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:25:11 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/15 18:25:19 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	generate_random(double min, double max)
{
	double	random;
	time_t	t;

	srand((unsigned)time(&t));
	random = (double)rand() / RAND_MAX;
	return (min + random * (max - min));
}
