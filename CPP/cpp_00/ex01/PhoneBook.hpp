/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:09:46 by marco             #+#    #+#             */
/*   Updated: 2023/05/17 11:55:10 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
public:
    Contact list[8];
    int     contacts;
    int     full;

    void    show_contact(void);
    void    add_contact(void);
    PhoneBook();
    ~PhoneBook();
private:
    void    get_info(void);
    int     get_index(int i);
    std::string size(std::string str);
};

#endif
