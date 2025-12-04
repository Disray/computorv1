/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_degree.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:36:40 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 18:17:29 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

void	print_complex( double re, double im )
{
	const double	eps = 1e-6;

	auto near = [&](double x, double target)
	{
		return (std::abs(x - target) < eps);
	};

	if (std::abs(im) < eps)
	{
		std::cout << re << std::endl;
		return ;
	}
	if (std::abs(re) < eps)
	{
		if (near(im, 1))
			std::cout << "i";
		else if (near(im, -1))
			std::cout << "-i";
		else
			std::cout << im << "i";
		std::cout << std::endl;
		return ;
	}
	std::cout << re << " ";
	if (near(im, 1))
		std::cout << "+ i";
	else if (near(im, -1))
		std::cout << " - i";
	else if (im > 0)
		std::cout << "+ " << im << "i";
	else
		std::cout << "- " << -im << "i";
	std::cout << std::endl;
}

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
		double	real_root = 0.0, imag_root = 0.0;

		if (b != 0.0)
			real_root = -b / (2 * a);
		imag_root = ft_sqrt(-det) / (2 * a);
		std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
		print_complex(real_root, imag_root);
		print_complex(real_root, -imag_root);
	}
}