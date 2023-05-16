/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:35:11 by marco             #+#    #+#             */
/*   Updated: 2023/05/15 21:35:26 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void    capitalize(char *str)
{
    int i = -1;

    while (str[++i])
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    while (argv[++i])
    {
        capitalize(argv[i]);
        std::cout << argv[i];
    }
    std::cout << std::endl;
    return (0);
}