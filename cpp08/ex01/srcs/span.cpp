#include "span.hpp"

span::span(void)
{
	_sizemax = 5;
}

span::span(int size)
{
	_sizemax = size;
	// _v.resize(size);
}

span::span(const span & parent)
{
	_v = parent._v;
	// _sizemax = parent._sizemax;
}

span::~span(void)
{
}

unsigned int	span::getSize(void)
{
	return (_v.size());
}

const char *span::NoMoreSpaceException::what(void) const throw(){
	return ("No more space available \n");
}

const char *span::NotEnoughValuesException::what(void) const throw(){
	return ("\nError: Less than 2 values in span \n");
}

void	span::addNumber(int n)
{
	if (_v.size() == _sizemax)
		throw span::NoMoreSpaceException();
	_v.push_back(n);
}

int	span::longestSpan(void)
{
	if (_v.size() < 2)
		throw span::NotEnoughValuesException();
	return (*(std::max_element(_v.begin(), _v.end())) - *(std::min_element(_v.begin(), _v.end())));
}

int	span::shortestSpan(void)
{
	if (_v.size() < 2)
		throw span::NotEnoughValuesException();
	int shortest = *(std::max_element(_v.begin(), _v.end())) - *(std::min_element(_v.begin(), _v.end()));
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
	{
		for (std::vector<int>::iterator it2 = it; it2 != _v.end(); it2++)
		{
			if (it != it2 && abs(*it2 - *it) < shortest)
				shortest = abs(*it2 - *it);
		}
	}
	return (shortest);
}

void	span::printSpan(void)
{
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << std::endl;
}

void	span::fill(void)
{
	srand(time(NULL));
	_v.clear();
	for (unsigned long i = 0; i < _sizemax; i++)
		_v.push_back(rand() % 999999);
}
