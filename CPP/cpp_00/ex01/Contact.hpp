/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:38:49 by marco             #+#    #+#             */
/*   Updated: 2023/05/15 22:01:48 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
    private:
        std::string name;
        std::string last;
        std::string nick;
        std::string number;
        std::string secret;

    public:
        void    set_name(std::string str);
        void    set_last(std::string str);  
        void    set_nick(std::string str);  
        void    set_number(std::string str);
        void    set_secret(std::string str);

        void    get_info();

        std::string get_name();
        std::string get_last();
        std::string get_nick();
        std::string get_number();
        std::string get_secret();
};

#endif