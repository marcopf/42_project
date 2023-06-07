#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	const char *data;
};

class Serializer
{
private:

public:
	uintptr_t	serialize(Data *ptr);
	Data		*deserialize(uintptr_t raw);
	Serializer	&operator=(const Serializer &other);
	Serializer(const Serializer &other);
	Serializer(void);
	~Serializer();
};

#endif
