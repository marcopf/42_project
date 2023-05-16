/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:13:21 by marco             #+#    #+#             */
/*   Updated: 2023/05/16 22:02:44 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int get_index(int i)
{
    if (i == 7)
        return (0);
    return (i + 1);
}

void    add_contact(PhoneBook *book)
{
    int i;
    static int index;
    std::string input;

    i = -1;
    if (book->full)
        index = get_index(index);
    else
    {   
        while (book->list[++i].get_name() != "" && i < 8)
            ;
        if (i == 8)
        {
            book->full = 1;
            index = 0;
        }
        else
            index = i;
    }
    do
    {
        std::cout << "insert Name\n";
        std::cin >> input;
        book->list[index].set_name(input);
    } while (book->list[index].get_name() == "");
    do
    {
        std::cout << "insert Last Name\n";
        std::cin >> input;
        book->list[index].set_last(input);
    } while (book->list[index].get_last() == "");
    do
    {
        std::cout << "insert Nickname\n";
        std::cin >> input;
        book->list[index].set_nick(input);
    } while (book->list[index].get_nick() == "");
    do
    {
        std::cout << "insert Secret\n";
        std::cin >> input;
        book->list[index].set_secret(input);
    } while (book->list[index].get_secret() == "");
    do
    {
        std::cout << "insert Number\n";
        std::cin >> input;
        book->list[index].set_number(input);
    } while (book->list[index].get_number() == "");
}

std::string size(std::string str)
{
	if (str.length() > 10)
	    return (str.substr(0, 9) + (std::string)".");
	else
	{
		while (str.length() < 10)
			str = " " + str;
	}
	return (str);
}

void    get_info(PhoneBook *book)
{
    std::string input;
    int index = 0;

    std::cout << "enter index [1 - 8]\n";
    std::cin >> input;
    while (input.length() > 1 || input[0] - 48 > 8 || input[0] - 48 < 1)
    {
        std::cout << "enter index [1 - 8]\n";
        std::cin >> input;
    }
    index = input[0] - 48;
    if (book->list[index - 1].get_name() == "")
        std::cout << "index not in list!!\n";
    else
        book->list[index - 1].get_info();
}

void    show_contact(PhoneBook *book)
{
    int i = -1;
    std::string temp;

    std::cout << "| ";
    std::cout << size("Index") << " | ";
    std::cout << size("Name") << " | ";
    std::cout << size("Last Name") << " | ";
    std::cout << size("Nick Name") << " | " << std::endl;
    while (book->list[++i].get_name() != "")
    {
        temp = std::to_string(i + 1);
        std::cout << "| ";
        std::cout << size(temp) << " | ";
        std::cout << size(book->list[i].get_name()) << " | ";
        std::cout << size(book->list[i].get_last()) << " | ";
        std::cout << size(book->list[i].get_nick()) << " | " << std::endl;
    }
    get_info(book);
}

int main()
{
    PhoneBook   book;

    std::string input = "";
    book.full = 0;
    while (input != "EXIT")
    {
        if (input == "ADD")
            add_contact(&book);
        else if (input == "SEARCH")
            show_contact(&book);
        std::cout << ">>";
        std::getline(std::cin, input);
        if (!std::cin)
            return (0);
    }
}