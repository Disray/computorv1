/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:37 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/11 15:17:57 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <cctype>


using PolyMap = std::map<int, double>;


void	start_calculations( PolyMap& poly );
void	first_degree( PolyMap& poly );
void	second_degree( PolyMap& poly );

double	ft_sqrt( double x );
double	ft_abs( double x );
