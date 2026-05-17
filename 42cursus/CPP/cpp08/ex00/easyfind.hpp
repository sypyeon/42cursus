#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <stdexcept>  // For std::runtime_error

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    // Search for the integer value in the container
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    // If the value isn't found, std::find returns the end iterator
    if (it == container.end()) {
        throw std::runtime_error("Value not found in the container.");
    }
    
    return it;
}

#endif
