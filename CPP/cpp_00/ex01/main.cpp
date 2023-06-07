/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:13:21 by marco             #+#    #+#             */
/*   Updated: 2023/05/17 11:07:37 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook   book;

    std::string input = "";
    book.full = 0;
    while (input != "EXIT")
    {
        if (input == "ADD")
            book.add_contact();
        else if (input == "SEARCH")
            book.show_contact();
        std::cout << ">>";
        std::getline(std::cin, input);
        if (!std::cin)
            return (0);
    }
}