/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_analyzer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:17 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 17:59:20 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

void	print_reduced_form( std::vector<std::pair<double, uint32_t>>& poly )
{
	std::cout << "Reduced form: " << poly[0].first << " * X^" << poly[0].second;
	for (size_t i = 1; i < poly.size(); i++)
	{
		if (poly[i].first < 0)
			std::cout << " - ";
		else
			std::cout << " + ";
		std::cout << poly[i].first << " * X^" << poly[i].second;
	}
	std::cout << " = 0" << std::endl;
}

void	start_calculations( std::vector<std::pair<double, uint32_t>>& poly )
{
	uint32_t	max = 0;

	for (size_t i = 0; i < poly.size(); i++)
	{
		for (size_t j = i + 1; j < poly.size(); j++)
		{
			if (poly[i].second == poly[j].second)
			{
				poly[i].first += poly[j].first;
				poly.erase(poly.begin() + j);
				j--;
			}
		}
	}
	for (size_t i = 0; i < poly.size(); i++)
	{
		if (poly[i].first != 0)
			max = std::max(max, poly[i].second);
	}
	print_reduced_form(poly);
	if (max > 1)
		std::cout << "Polynomial degree: " << max << std::endl;
	if (max == 1)
		first_degree(poly);
	else if (max == 2)
		second_degree(poly);
	else if (max == 0)
	{
		if (poly[0].first != 0)
			std::cout << "No solution." << std::endl;
		else
			std::cout << "Any real number is a solution." << std::endl;
	}
	else if (max < 0)
		std::cout << "Wrong polynomial" << std::endl;
	else
		std::cout << "The polynomial is strictly greater than 2, I can't solve" << std::endl;
}