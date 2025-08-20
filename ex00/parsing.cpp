/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:42:04 by abarahho          #+#    #+#             */
/*   Updated: 2025/08/19 15:19:53 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>

type find_type(std::string const input)
{
    char* endptr;
    
    if (input == "nan" || input == "nanf" ||
        input == "+inf" || input == "-inf" ||
        input == "+inff" || input == "-inff")
        return (SPECIAL);
    if (input.length() == 1 && !isdigit(input[0]))
        return (CHAR);
    std::strtod(input.c_str(), &endptr);
    if (*endptr == 'f' && *(endptr + 1) == '\0')
        return (FLOAT);
    else if (*endptr == '\0')
    {
        if (input.find('.') != std::string::npos)
            return (DOUBLE);
        else
            return (INT);
    }
    return (INVALID);
}