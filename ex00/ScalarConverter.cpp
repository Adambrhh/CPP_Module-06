/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:25:19 by abarahho          #+#    #+#             */
/*   Updated: 2025/08/19 15:55:33 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}
ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &)
{
	return (*this);
}

static void displayAsChar(double d)
{
	char c;
	
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else
	{
		c = static_cast<char>(d);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

static void displayAsInt(double d)
{
	int i;

	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
	{
		i = static_cast<int>(d);
		std::cout << i << std::endl;
	}
}

static void displayAsFloat(double d)
{
	float f = static_cast<float>(d);
	double intPart;

	std::cout << "float: " << f;
	if (std::modf(static_cast<double>(f), &intPart) == 0.0 && !std::isinf(f) && !std::isnan(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void displayAsDouble(double d)
{
	double intPart;

	std::cout << "double: " << d;
	if (std::modf(d, &intPart) == 0.0 && !std::isinf(d) && !std::isnan(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(std::string const input)
{
	type value;
	double d;

	value = find_type(input);
	if (input.empty() || value == INVALID)
	{
		std::cout << "Invalid value" << std::endl;
		return ;
	}
	if (value == CHAR)
		d = static_cast<double>(input[0]);
	else
		d = std::strtod(input.c_str(), NULL);
	if (value == SPECIAL)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else 
	{
		displayAsChar(d);
		displayAsInt(d);
		displayAsFloat(d);
		displayAsDouble(d);
	}
}
