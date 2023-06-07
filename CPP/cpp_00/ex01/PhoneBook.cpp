#include "PhoneBook.hpp"

int PhoneBook::get_index(int i)
{
    if (i == 7)
        return (0);
    return (i + 1);
}

std::string PhoneBook::size(std::string str)
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

void    PhoneBook::get_info()
{
    std::string input;
    int index = 0;

    std::cout << "enter index [1 - 8]" << std::endl;
    std::cin >> input;
    if (!std::cin)
        exit(0);
    while (input.length() > 1 || input[0] - 48 > 8 || input[0] - 48 < 1)
    {
        std::cout << "enter index [1 - 8]\n";
        std::cin >> input;
        if (!std::cin)
            exit(0);
    }
    index = input[0] - 48;
    if (list[index - 1].get_name() == "")
        std::cout << "index not in list!!\n";
    else
        list[index - 1].get_info();
}

void    PhoneBook::show_contact()
{
    int i = -1;

    std::cout << "| ";
    std::cout << size("Index") << " | ";
    std::cout << size("Name") << " | ";
    std::cout << size("Last Name") << " | ";
    std::cout << size("Nick Name") << " | " << std::endl;
    while (i < 7 && list[++i].get_name() != "")
    {
        std::cout << "| ";
        std::cout << std::setfill(' ') << std::setw(9) << i + 1 << "  | ";
        std::cout << size(list[i].get_name()) << " | ";
        std::cout << size(list[i].get_last()) << " | ";
        std::cout << size(list[i].get_nick()) << " | " << std::endl;
    }
    get_info();
}

void    PhoneBook::add_contact()
{
    int i;
    static int index;
    std::string input;

    i = -1;
    if (full)
        index = get_index(index);
    else
    {   
        while (i < 7 && list[++i].get_name() != "")
            ;
        if (i == 7 && list[i].get_name() != "")
        {
            full = 1;
            index = 0;
        }
        else
            index = i;
    }
    do
    {
        std::cout << "insert Name\n";
        std::cin >> input;
        if (!std::cin)
            exit(0);
        list[index].set_name(input);
    } while (list[index].get_name() == "");
    do
    {
        std::cout << "insert Last Name\n";
        std::cin >> input;
        if (!std::cin)
            exit(0);
        list[index].set_last(input);
    } while (list[index].get_last() == "");
    do
    {
        std::cout << "insert Nickname\n";
        std::cin >> input;
        if (!std::cin)
            exit(0);
        list[index].set_nick(input);
    } while (list[index].get_nick() == "");
    do
    {
        std::cout << "insert Secret\n";
        std::cin >> input;
        if (!std::cin)
            exit(0);
        list[index].set_secret(input);
    } while (list[index].get_secret() == "");
    do
    {
        std::cout << "insert Number\n";
        std::cin >> input;
        if (!std::cin)
            exit(0);
        list[index].set_number(input);
    } while (list[index].get_number() == "");
}

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}