/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:48:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/31 18:44:51 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string const input)
{
	type value;

	if (input.empty())
	{
		std::cout << "Invalid value" << std::endl;
		return ;
	}
	if ((value = find_type(input)) == INVALID)
	{
		std::cout << "Invalid value" << std::endl;
		return ;
	}
}

// void displayAsChar(TYPE_ORIGINE valeur)
// {
	
// }

// void displayAsInt(TYPE_ORIGINE valeur)
// {

// }

// void displayAsFloat(TYPE_ORIGINE valeur)
// {

// }

// void displayAsDouble(TYPE_ORIGINE valeur)
// {
	
// }
