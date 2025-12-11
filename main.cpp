/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:04:41 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/11 15:20:58 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

static std::string	normalize( const std::string& str )
{
	std::string	res;
	res.reserve(str.size());

	for (char c : str)
	{
		if (std::isspace(static_cast<unsigned char>(c)))
			continue;
		if (c == 'X')
			c = 'x';
		if (c == '*')
			continue;
		res.push_back(c);
	}
	return (res);
}

static void			parse_term( const std::string& term, int side_sign, PolyMap& poly )
{
	if (term.empty())
		throw std::runtime_error("empty term");

	int		sign = 1;
	size_t	i    = 0;

	if (term[i] == '+' || term[i] == '-')
	{
		if (term[i] == '-')
			sign = -1;
		i++;
	}
	if (i >= term.size())
		throw std::runtime_error("invalid term: sign only");

	auto	pos_x = term.find('x', i);
	if (pos_x == std::string::npos)
	{
		double	magnitude = std::stod(term.substr(i));
		double	coef	  = sign * side_sign * magnitude;
		poly[0] += coef;
		return;
	}
	std::string	coef_str = term.substr(i, pos_x - i);
	double		magnitude;

	if (coef_str.empty())
		magnitude = 1.0;
	else
		magnitude = std::stod(coef_str);
	int	power = 1;
	if (pos_x + 1 < term.size())
	{
		if (term[pos_x + 1] != '^')
			throw std::runtime_error("invalid term: expected '^' after x");
		std::string	exp_str = term.substr(pos_x + 2);
		if (exp_str.empty())
			throw std::runtime_error("invalid term: missing exponent after '^'");
		power = std::stoi(exp_str);
	}
	double	coef  = sign * side_sign * magnitude;
	poly[power] += coef;
}

static void	parse_side( const std::string& side, int side_sign, PolyMap& poly )
{
	std::string s = side;
	if (!s.empty() && s[0] != '+' && s[0] != '-')
		s.insert(s.begin(), '+');
	
	size_t	i = 0;
	while (i < s.size())
	{
		size_t	j = i + 1;
		while (j < s.size() && s[j] != '+' && s[j] != '-')
			j++;
		std::string	term_str = s.substr(i, j - i);
		parse_term(term_str, side_sign, poly);
		i = j;
	}
}

static PolyMap	parse_formula( const std::string& formula )
{
	std::string	s = normalize(formula);
	auto		pos_eq = s.find('=');

	if (pos_eq == std::string::npos)
		throw std::runtime_error("missing '='");		

	std::string	lhs = s.substr(0, pos_eq);
	std::string	rhs = s.substr(pos_eq + 1);

	PolyMap	poly;

	parse_side(lhs, +1, poly);
	parse_side(rhs, -1, poly);
	return (poly);
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
	try
	{
		auto	poly = parse_formula(input);
		start_calculations(poly);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}