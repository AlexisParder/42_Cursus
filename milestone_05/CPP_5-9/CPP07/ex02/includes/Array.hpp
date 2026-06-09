/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:24:52 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/09 09:32:21 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		unsigned int size(void) const;
		T &operator[](unsigned int n);
};

template <typename T>
Array<T>::Array(void)
{
	_array = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size = n;
}


template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_size = other._size;
		delete[] _array;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= Array<T>::size())
		throw std::out_of_range("Index out of bounds");
	return _array[n];
}