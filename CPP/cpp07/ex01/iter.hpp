#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array, const int length, F func(T&))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template <typename T, typename F>
void iter(const T *array, const int length, F func(const T&))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif