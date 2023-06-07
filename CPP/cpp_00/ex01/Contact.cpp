/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:50:45 by marco             #+#    #+#             */
/*   Updated: 2023/05/15 22:00:16 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


std::string Contact::get_name()
{
        return (name);
}

std::string Contact::get_last()
{
        return (last);
}

std::string Contact::get_nick()
{
        return (nick);
}

std::string Contact::get_number()
{
        return (number);
}

std::string Contact::get_secret()
{
        return (secret);
}

void    Contact::set_name(std::string str)
{
    name = str;
}

void    Contact::set_last(std::string str)
{
    last = str;
}

void    Contact::set_nick(std::string str)
{
    nick = str;
}

void    Contact::set_number(std::string str)
{
    number = str;
}

void    Contact::set_secret(std::string str)
{
    secret = str;
}

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void    Contact::get_info()
{
    std::cout << "Name      " << name << std::endl;
    std::cout << "Last Name " << last << std::endl;
    std::cout << "Nickname  " << nick << std::endl;
    std::cout << "Number    " << number << std::endl;
    std::cout << "Secret    " << secret << std::endl;
}
