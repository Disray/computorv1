/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:37 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 17:59:16 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <exception>

void	start_calculations( std::vector<std::pair<double, uint32_t>>& poly );
void	first_degree( const std::vector<std::pair<double, uint32_t>>& poly );
void	second_degree( const std::vector<std::pair<double, uint32_t>>& poly );

double	ft_sqrt( double x );
