#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data *ret = reinterpret_cast<Data*>(raw);
	return (ret);
}


Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer::Serializer(/* args */)
{
}

Serializer::~Serializer()
{
}
