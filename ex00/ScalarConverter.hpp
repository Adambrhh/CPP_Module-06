/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:48:57 by abarahho          #+#    #+#             */
/*   Updated: 2025/08/19 17:02:41 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <cstdlib>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter	&operator=(ScalarConverter const &);
	~ScalarConverter();
public:
	static void	convert(std::string const);
};

type	find_type(std::string const input);

#endif