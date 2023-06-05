#include "Serializer.hpp"

int	main(void)
{
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	raw;
	Serializer	t;

	ptr->data = "test string data";
	raw = t.serialize(ptr);
	new_ptr = t.deserialize(raw);
	std::cout << "new_ptr->data = " << new_ptr->data << std::endl;
}