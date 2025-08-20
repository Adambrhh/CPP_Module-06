/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:10:07 by abarahho          #+#    #+#             */
/*   Updated: 2025/08/19 17:24:07 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data original_data;
    original_data.string_value = "Test Data";
    original_data.int_value = 42;

    Data* original_ptr = &original_data;

    std::cout << "Original pointer address: " << original_ptr << std::endl;
    std::cout << "Original data values: " << original_ptr->string_value << ", " << original_ptr->int_value << std::endl;

    uintptr_t serialized_data = Serializer::serialize(original_ptr);
    std::cout << "Serialized address (as uintptr_t): " << serialized_data << std::endl;

    Data* deserialized_ptr = Serializer::deserialize(serialized_data);
    std::cout << "Deserialized pointer address: " << deserialized_ptr << std::endl;

    if (original_ptr == deserialized_ptr) {
        std::cout << "Pointers are equal. The conversion was successful." << std::endl;
        std::cout << "Values after deserialization: " << deserialized_ptr->string_value << ", " << deserialized_ptr->int_value << std::endl;
    } else {
        std::cout << "Pointers are NOT equal. Something went wrong." << std::endl;
    }

    return 0;
}