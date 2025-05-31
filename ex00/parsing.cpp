/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:42:04 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/31 18:45:05 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>

bool	isChar(std::string const input, size_t len)
{
	if (len == 1 && std::isdigit(input[0]))
		return (true);
	return (false);
}

bool	isInt(std::string const input, size_t len)
{
	size_t	i;

	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < len)
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}
// {
// 	size_t		i;
// 	bool		sign;
	
// 	i = 0;
// 	sign = false;
// 	if (input[0] == '+' || input[0] == '-')
// 	{
// 		sign = true;
// 		i++;
// 	}
// 	while (i < 12)
// 	{
// 		if (!isdigit(input[i]))
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

bool	isFloat(std::string const input, size_t len)
{
	size_t	i;
	size_t	dot;
	
	if (input[len] != 'f')
		return (false);
	i = 0;
	dot = input.find(".");
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < len - 1)
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
		if (i == dot)
			i++;
	}
	return (true);
}

bool	isDouble(std::string const input, size_t len)
{
	size_t	i;
	size_t	dot;

	i = 0;
	dot = input.find(".");
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < len)
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
		if (i == dot)
			i++;
	}
	return (true);
}


bool	isSpecial(std::string const input)
{
	if (input == "inf" || input == "inf" || input == "-inf" ||
		input == "-inf" || input == "-inff" || input == "+inf" ||
		input == "+inff" ||input == "nan" || input == "nanf")
		return (true);
	return (false);
}

type	find_type(std::string const input)
{
	size_t	len;

	len = input.length();
	if (input.find('.'))
	{
		if (input.find('f'))
		{
			if (isFloat(input, len))
				return (FLOAT);
		}
		else if (isDouble(input, len))
			return (DOUBLE);
	}
	else if (isChar(input, len))
		return (CHAR);
	else if (isInt(input, len))
		return (INT);
	else if (isSpecial(input))
		return (SPECIAL);
	std::cout << input << isFloat(input, len) << isDouble(input, len) << isChar(input, len) << isInt(input, len) << isSpecial(input) << std::endl;
	return (INVALID);
}