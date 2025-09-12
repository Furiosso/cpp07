#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T* array, size_t len, void (*function)(T&))
{
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

#endif