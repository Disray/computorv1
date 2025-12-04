/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:37 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/04 16:52:08 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

void	start_calculations( std::vector<std::pair<double, uint32_t>>& poly );
void	first_degree( const std::vector<std::pair<double, uint32_t>>& poly );
void	second_degree( const std::vector<std::pair<double, uint32_t>>& poly );
