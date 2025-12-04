/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:04:41 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 18:07:18 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

std::vector<std::pair<double, uint32_t>>	parse_formula( const std::string& formula )
{
	std::vector<std::pair<double, uint32_t>>	polynomial;
	std::istringstream							iss(formula);
	std::string									token;
	double										sign = 1;
	int											side = 1;

	while (iss >> token)
	{
		if (token == "+" || token == "-")
		{
			sign = (token == "+") ? 1.0 : -1.0;
			continue;
		}
		if (token == "=")
		{
			side = -1;
			sign = 1.0;
			continue;
		}
		if (token == "*")
			continue;
		double 		coef = 0.0;
		uint32_t	power = 0;

		coef = std::stod(token) * sign * side;
		std::string	star, xpow;
		if (!(iss >> star >> xpow)  || star != "*" || xpow.size() < 3 || xpow[0] != 'X' || xpow[1] != '^')
			throw std::runtime_error("Invalid term format, expected 'a * X^p'");
		power = static_cast<uint32_t>(std::stoul(xpow.substr(2)));
		polynomial.push_back({coef, power});
	}
	return (polynomial);
}

int	main( int argc, char **argv )
{
	std::string	input;
	if (argc == 1)
		std::getline(std::cin, input);
	else if (argc == 2)
		input = argv[1];
	else
		throw std::runtime_error("Error: wrong number of argument");
	auto	poly = parse_formula(input);
	start_calculations(poly);
	return (0);
}