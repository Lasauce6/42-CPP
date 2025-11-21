/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:00:21 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/21 14:07:18 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <exception>

template<typename T>
class Array {
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &other);
	Array	&operator=(const Array &other);

	T	&operator[](unsigned int n);

	class OutOfBoundsException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	class AllocationFailedException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	unsigned int	size(void);

	~Array();
private:
	T				*_elems;
	unsigned int	_size;
};

template<typename T>
Array<T>::Array(void) : _elems(new T[0]), _size(0) {
	if (!_elems)
		throw AllocationFailedException();
}

template<typename T>
Array<T>::Array(unsigned int n) : _elems(new T[n]), _size(n) {
	if (!_elems)
		throw AllocationFailedException();
}

template<typename T>
Array<T>::Array(const Array &other) {
	if (&other != this) {
		if (other._elems) {
			_elems = new T[other._size];
			if (!_elems)
				throw AllocationFailedException();
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
				_elems[i] = other._elems[i];
		} else
			_elems = NULL;
	}
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &other) {
	if (&other != this) {
		if (_elems)
			delete[] _elems;
		if (other._elems) {
			_elems = new T[other._size];
			if (!_elems)
				throw AllocationFailedException();
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
				_elems[i] = other._elems[i];
		} else
			_elems = NULL;
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int n) {
	if (n >= _size)
		throw OutOfBoundsException();
	return _elems[n];
}

template<typename T>
const char	*Array<T>::OutOfBoundsException::what(void) const throw() {
	return ("index out of bouds");
}

template<typename T>
const char	*Array<T>::AllocationFailedException::what(void) const throw() {
	return ("allocation failed");
}

template<typename T>
unsigned int	Array<T>::size(void) {
	return (_size);
}

template<typename T>
Array<T>::~Array(void) {
	delete[] _elems;
}
