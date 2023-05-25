#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define AANIMALS 8

int	main(void)
{
	Animal	*Aanimals[AANIMALS];
	Brain	*brain1;

	for (int i = 0; i < AANIMALS; i++)
	{
		if (i < AANIMALS / 2)
			Aanimals[i] = new Dog();
		else
			Aanimals[i] = new Cat();
		std::cout << Aanimals[i]->getType() << std::endl;
	}

	brain1 = Aanimals[7]->getBrain();
	brain1->ideas[0] = "I'm hungry";
	brain1->ideas[1] = "That's a strange idea I'm having";
	brain1->ideas[2] = "Ball!!!!!";
	brain1->ideas[3] = "Mum";
	std::cout << Aanimals[7]->getBrain()->ideas[0] << std::endl;

	*(Aanimals[5]) = *(Aanimals[7]);
	std::cout << Aanimals[5]->getBrain()->ideas[2] << std::endl;

	for (int i = 0; i < AANIMALS; i++)
		delete Aanimals[i];
}