#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // for std::find
#include <exception> // for std::exception

class NotFoundException : public std::exception
{
    virtual const char* what() const throw(){
		return "couldn't find value in container";
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif
