
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define ANIMALS 8

int	main(void)
{
	Animal	*animals[ANIMALS];
	Brain	*brain1;

	for (int i = 0; i < ANIMALS; i++)
	{
		if (i < ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	brain1 = animals[7]->getBrain();
	brain1->ideas[0] = "I'm hungry";
	brain1->ideas[1] = "That's a strange idea I'm having";
	brain1->ideas[2] = "Ball!!!!!";
	brain1->ideas[3] = "Mum";
	std::cout << animals[7]->getBrain()->ideas[0] << std::endl;

	*(animals[5]) = *(animals[7]);
	std::cout << animals[5]->getBrain()->ideas[2] << std::endl;

	for (int i = 0; i < ANIMALS; i++)
		delete animals[i];
}