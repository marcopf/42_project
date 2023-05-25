#include "Brain.hpp"

Brain::Brain(void)
{
	std::string				str =  "large feeling oceanic powerful feeling toys cable kitty feeling gray feeling mate feeling understood mark disastrous open joke sedate unnatural busy female early adamant smile high home stain physical twig girls hanging stomach synonymous frog curious detail list exchange clumsy play enter ill-fated cave moaning bumpy great island route cold petite stone judicious reaction thoughtful things employ geese harsh tawdry statement callous wriggle injure swanky yarn calculate basin aboard army knock mint copy earsplitting need spotted slimy watch attach kill statuesque ticket encourage nine fear battle thinkable burn fasten disgusted afraid explode exotic poor succinct crib white dreary cracker laborer";
    std::stringstream		ss(str); 
	int						i = -1;

    while (getline(ss, str, ' ')) 
        this->ideas[++i] = str;
	std::cout << "brain setted\n";
}

Brain::Brain(std::string str)
{
    std::stringstream		ss(str); 
	int						i = -1;

    while (getline(ss, str, ' ')) 
        this->ideas[++i] = str;
	std::cout << "brain setted\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "brain copied\n";
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "brain copy assign\n";
	int i = -1;

	while (++i < 100)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "brain decostructed\n";
}
