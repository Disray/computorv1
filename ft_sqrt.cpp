/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:38 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 17:53:54 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

double	ft_abs( double x )
{
	return x > 0 ? x : -x;
}

double	ft_sqrt( double x )
{
	double			guess = x / 2;
	const double	tolerance = 1e-6;

	while (true)
	{
		double	other_side = x / guess;
		double	new_guess = (guess + other_side) / 2;

		double	diff = ft_abs(guess - new_guess);

		if (diff < tolerance)
			return (new_guess);
		guess = new_guess;
	}
}