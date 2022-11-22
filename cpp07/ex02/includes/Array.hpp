#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iomanip>
# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private :
		T	*_array;
		int	_size;

	public :
		Array(){
			_array = NULL;
			_size = 0;
		};

		Array(unsigned int n){
			_array = new T[n];
			_size = n;
		};

		Array(Array const & parent){
			_size = parent._size;
			_array = new T[_size];
			for (int i = 0; i < _size; i++)
				_array[i] = parent._array[i];
		};

		~Array(void){
			if (_array)
				delete[] _array;
		};

		class WrongIndex : public std::exception {
			const char	*what(void) const throw(){
				return ("Wrong index !\n");
			};
		};

		class NoArray : public std::exception {
			const char	*what(void) const throw(){
				return ("Array doesn't exist !\n");
			};
		};

		int	size(void){
			return (_size);
		};

		void	print(void){
			for ( int i = 0; i < _size; i++)
				std::cout << _array[i] << std::endl;
		};
		
		T &operator[](int i){
			if(!_array){
				throw NoArray();
			}
			if (i >= _size){
				throw WrongIndex();
			}
			return _array[i];
		};
		
		Array<T> &operator=(Array<T> const & rhs){
			if (!rhs._array && !_array)
				return (*this);
			if (!rhs._array && _array)
			{
				delete[] _array;
				_array = NULL;
				return (*this);
			}
			if (!_array && rhs._array)
			{
				_size = rhs._size;
				_array = new T[_size];
			}
			int	size = (_size > rhs._size ? rhs._size : _size);
			for (int i = 0; i < size; i++)
				_array[i] = rhs._array[i];
			return (*this);
		};
};

#endif