/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:09:34 by abarahho          #+#    #+#             */
/*   Updated: 2025/08/19 16:48:42 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
    int         int_value;
    std::string string_value;
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &);
	Serializer	&operator=(Serializer const &);
	~Serializer();
public:
    static  uintptr_t serialize(Data* ptr);
    static  Data* deserialize(uintptr_t raw);
};

#endif