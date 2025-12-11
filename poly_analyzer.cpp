/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_analyzer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:17 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/11 15:26:05 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

static void	print_reduced_form( PolyMap& poly )
{
	std::cout << "Reduced form: ";
	for (auto& t : poly)
	{
		if (t.second > 0.0 && t.first != 0)
			std::cout << " + ";
		std::cout << t.second << " * X^" << t.first; 
	}
	std::cout << " = 0" << std::endl;
}

void	start_calculations( PolyMap& poly )
{
	auto	max = poly.rbegin()->first;

	print_reduced_form(poly);
	if (max > 1)
		std::cout << "Polynomial degree: " << max << std::endl;
	if (max == 1)
		first_degree(poly);
	else if (max == 2)
		second_degree(poly);
	else if (max == 0)
	{
		if (poly[0] != 0)
			std::cout << "No solution." << std::endl;
		else
			std::cout << "Any real number is a solution." << std::endl;
	}
	else if (max < 0)
		std::cout << "Wrong polynomial" << std::endl;
	else
		std::cout << "The polynomial is strictly greater than 2, I can't solve" << std::endl;
}