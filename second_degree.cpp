/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_degree.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:36:40 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 17:59:23 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

void	second_degree( const std::vector<std::pair<double, uint32_t>>& poly )
{
	double	a = 0.0, b = 0.0, c = 0.0, det = 0.0;

	for (const auto& i : poly)
	{
		if (i.second == 0)
			c = i.first;
		else if (i.second == 1)
			b = i.first;
		else
			a = i.first;
	}
	det = b * b - 4.0 * a * c;
	if (det == 0)
	{
		double	res = -1.0 * b / (2 * a);

		std::cout << "The solution is:\n" << res << std::endl;
	}
	else if (det > 0)
	{
		double root1 = 0.0, root2 = 0.0;

		root1 = (-b - ft_sqrt(det)) / (2 * a);
		root2 = (-b + ft_sqrt(det)) / (2 * a);
		std::cout << "Discriminant is strictly positive, the two solutions are:\n" << root1 << std::endl << root2 << std::endl;
	}
	else if (det < 0)
	{
		double	real_root = 0.0, imag_root1 = 0.0, imag_root2 = 0.0;

		real_root = -b / (2 * a);
		imag_root1 = ft_sqrt(-det) / (2 * a);
		imag_root2 = -ft_sqrt(-det) / (2 * a);
		std::cout	<< "Discriminant is strictly negative, the two complex solutions are:\n"
					<< real_root << (a > 0 ? " + " : " - ") << imag_root1 << "i" << std::endl
					<< real_root << (a < 0 ? " + " : " ") << imag_root2 << "i" << std::endl;
	}
}