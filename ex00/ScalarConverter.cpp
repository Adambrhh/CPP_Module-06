/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ScalarConverter.cpp                                :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/05/30 18:48:59 by abarahho          #+#    #+#             */
/* Updated: 2025/08/19 12:04:31 by abarahho         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}
ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &) { return (*this); }

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
	float f;

	f = static_cast<float>(d);
	std::cout << "float: " << std::fixed << std::setprecision(1);
	std::cout << f << "f" << std::endl;
}

static void displayAsDouble(double d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1);
	std::cout << d << std::endl;
}

void	ScalarConverter::convert(std::string const input)
{
	type value;
	double d;

	if (input.empty())
	{
		std::cout << "Invalid value" << std::endl;
		return ;
	}

	value = find_type(input);
	if (value == INVALID)
	{
		std::cout << "Invalid value" << std::endl;
		return ;
	}
	
	if (value == CHAR)
		d = static_cast<double>(input[0]);
	else
		d = std::strtod(input.c_str(), NULL);

    switch (value)
    {
        case (CHAR):
            displayAsChar(d);
            displayAsInt(d);
            displayAsFloat(d);
            displayAsDouble(d);
            break;
        case (INT):
            displayAsChar(d);
            displayAsInt(d);
            displayAsFloat(d);
            displayAsDouble(d);
            break;
        case (FLOAT):
            displayAsChar(d);
            displayAsInt(d);
            displayAsFloat(d);
            displayAsDouble(d);
            break;
        case (DOUBLE):
            displayAsChar(d);
            displayAsInt(d);
            displayAsFloat(d);
            displayAsDouble(d);
            break;
        case (SPECIAL):
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            // Utilisation de d qui contient déjà la valeur (nan, inf)
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            break;
		case (INVALID):
			std::cout << "Invalid value" << std::endl;
			break;
    }
}