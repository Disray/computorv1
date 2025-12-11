/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fraction.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/11 17:36:49 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fraction
{
	private:
		int	numerator, denominator;

	public:
		Fraction( int num, int den = 1 );
		Fraction& operator=( const Fraction& other ) = default;
		Fraction( const Fraction& other ) = default;
		~Fraction() = default;

		void	simplify();	
		void	print() const;

		friend std::ostream&	operator<<( std::ostream& os, const Fraction& f );
};

bool	double_to_fraction( double value, Fraction& out );
int		ft_gcd(int a, int b);