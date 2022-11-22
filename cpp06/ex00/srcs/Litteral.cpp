#include "Litteral.hpp"

Value::Value(void): _type('\0'), _prec(1), _pc("char		:	"), _pi("int		:	"), _pd("double		:	"), _pf("float		:	")
{
}

Value::~Value()
{
}

void		Value::setStr(std::string str){ _str = str; }
std::string	Value::getStr(void){return _str;}

void		Value::setType(char type){ _type = type; }
char		Value::getType(void){return _type;}

void		Value::setChar(char c){ _c = c; }
char		Value::getChar(void){return _c;}

void		Value::setInt(int i){ _i = i; }
int			Value::getInt(void){return _i;}

void		Value::setDouble(double d){ _d = d; }
double		Value::getdouble(void){return _d;}

void		Value::setFloat(float f){ _f = f; }
float		Value::getFloat(void){return _f;}

void		Value::setPrec(int prec){ _prec = prec; }
int			Value::getPrec(void){return _prec;}


bool	IsInf(std::string input)
{
	std::string sign = "";
	if (input.at(0) == '-')
	{
		sign = "-";
		input.erase(0, 1);
	}
	if (!input.compare("inf") || !input.compare("inff"))
	{
		std::cout << "char			:  impossible" << std::endl;
		std::cout << "int			:  impossible" << std::endl;
		std::cout << "double			:  " << sign << "inf" << std::endl;
		std::cout << "float			:  " << sign << "inff" << std::endl;
		return (true);
	}
	return (false);
}

void	Nan(void)
{
	std::cout << "char			:  impossible" << std::endl;
	std::cout << "int			:  impossible" << std::endl;
	std::cout << "double			:  nan" << std::endl;
	std::cout << "float			:  nanf" << std::endl;
}

int			Value::IsChar(void)
{
	if (_str.length() == 1 && !isdigit(_str.at(0)))
		return (1);
	return (0);
}

int			Value::IsInt(void)
{
	int i = 0 ;
	int	size = _str.length();

	if (_str.at(i) == '-' || _str.at(i) == '+')
		++i;
	while (i < size && isdigit(_str.at(i)))
		++i;
	if (i > 0)
		i--;
	if (isdigit(_str.at(i)) && i == size - 1)
		return (1);
	return (0);
}

int			Value::IsDouble(void)
{
	int	i = 0;
	int	j = 1;
	int	size = _str.length();

	if (_str.at(i) == '-' || _str.at(i) == '+')
		++i;
	while (i < size - 1 && isdigit(_str.at(i)))
		++i;
	if (i >= size || _str.at(i) != '.')
		return (0);
	++i;
	while (i < size - 1 && isdigit(_str.at(i)))
	{
		++i;
		++j;
	}
	setPrec(_str.length());
	if (isdigit(_str.at(i)) && i == size - 1)
		return (1);
	return (0);
}

int			Value::IsFloat(void)
{
	int	i = 0;
	int	size = _str.length();

	if (_str.at(i) == '-' || _str.at(i) == '+')
		++i;
	while (i < size - 1 && isdigit(_str.at(i)))
		++i;
	if (i >= size || _str.at(i) != '.')
		return (0);
	++i;
	while (i < size - 1 && isdigit(_str.at(i)))
		++i;
	if (_str.at(i) == 'f' && i == size - 1)
		return (1);
	return (0);
}

void		Value::convert(void)
{
	switch (_type)  //TODO overflows
	{
		case 'c':  _c = _str.at(0);
					_i = static_cast<int>(_c);
					_f = static_cast<float>(_c);
					_d = static_cast<double>(_c);
					break;
		case 'i':   std::istringstream ( _str ) >> _i;
					_c = static_cast<char>(_i);
					_f = static_cast<float>(_i);
					_d = static_cast<double>(_i);
					break;
		case 'd': std::istringstream ( _str ) >> _d;
					_c = static_cast<char>(_d);
					_i = static_cast<int>(_d);
					_f = static_cast<float>(_d);
					break;
		case 'f': std::istringstream ( _str ) >> _f;
					_c = static_cast<char>(_f);
					_i = static_cast<int>(_f);
					_d = static_cast<double>(_f);
					break;
		default: Nan();
					exit(0);
	}
}

void		Value::detectType(void)
{
	char		type = 'c';

	if (IsInf(_str))
		exit(0);
	if (!Value::IsChar())
	{
		if (!Value::IsInt())
		{
			if (!Value::IsDouble())
			{
				if (!Value::IsFloat())
					type = '\0';
				else
					type = 'f';
			}
			else
				type = 'd';
		}
		else
		type	 = 'i';
	}
	setType(type);
	return ;
}

void		Value::display(void)
{
	printC();
	std::cout << std::endl;
	printI();
	std::cout << std::endl;
	printD();
	std::cout << std::endl;
	printF();
	std::cout << std::endl;
}


void 	Value::printC(void) const
{
	std::cout << _pc;
	switch(_type)
	{
		case 'c': 	std::cout << _c;
					break;

		case 'i': 	if (_i >= 32 && _i < 127)
						std::cout << _c;
					else if (_i >= std::numeric_limits<char>::min() && _i <= std::numeric_limits<char>::max() )
						std::cout << "Non diplayable";
					else
						std::cout << "Impossible";
					break;

		case 'd': if (_d >= 32 && _d < 127)
						std::cout << _c;
					else if (_d >= std::numeric_limits<char>::min() && _d <= std::numeric_limits<char>::max() )
						std::cout << "Non diplayable";
					else
						std::cout << "Impossible";
					break;

		case 'f': if (_f >= 32 && _f < 127)
						std::cout << _c;
					else if (_f >= std::numeric_limits<char>::min() && _f <= std::numeric_limits<char>::max() )
						std::cout << "Non diplayable";
					else
						std::cout << "Impossible";
					break;
	}
}

void 	Value::printI(void) const
{
	std::cout << _pi;
	 switch(_type)
	 {
		case 'c': 	std::cout << _i;
					break;
					
		case 'i': 	std::cout << _i;
					break;

		case 'd': 	if (_d >= std::numeric_limits<int>::min() && _d <= std::numeric_limits<int>::max() )
						std::cout << _i;
					else
						std::cout << "Impossible";
					break;

		case 'f': 	if (_f >= std::numeric_limits<int>::min() && _f <= std::numeric_limits<int>::max() )
						std::cout << _i;
					else
						std::cout << "Impossible";
					break;
	 }
}

void 	Value::printD(void) const
{
	std::cout << _pd;
	switch(_type)
	{
		case 'c': 	std::cout << std::setprecision(_prec) << _d << ".0";
					break;
		
		case 'i': 	std::cout << std::setprecision(_prec) << std::fixed << _d;
					break;

		case 'd': 	if (_d >= (- std::numeric_limits<double>::max()) && _d <= std::numeric_limits<double>::max() )
					{   
						std::cout << std::setprecision(_prec) << _d;
						if (roundf(_d) - _d == 0.0f)
							std::cout << ".0";
					} 
					else
						std::cout << "Impossible";
					break;
		
		case 'f':	if (_d >= (- std::numeric_limits<double>::max()) && _d <= std::numeric_limits<double>::max() )
					{   
						std::cout << std::setprecision(_prec) << _f;
						if (roundf(_f) - _f == 0.0f)
							std::cout << ".0";
						std::cout << "f";
					} 
					else
						std::cout << "Impossible";
					break;
	}
}

void 	Value::printF(void) const
{
	std::cout << _pf;
	switch(_type)
	{
		case 'c':	 std::cout << std::setprecision(_prec) << _f << ".0f";
					break;

		case 'i': 	std::cout << std::setprecision(_prec) << std::fixed << _f << "f";
					break;

		case 'd': 	if (_d >= (- std::numeric_limits<float>::max()) && _d <= std::numeric_limits<float>::max() )
					{   
						std::cout << std::setprecision(_prec) << _f;
						if (roundf(_f) - _f == 0.0f)
							std::cout << ".0";
						std::cout << "f";
					} 
					else
						std::cout << "Impossible";
					break;

		case 'f': 	if (_d >= (- std::numeric_limits<float>::max()) && _d <= std::numeric_limits<float>::max() )
					{   
						std::cout << std::setprecision(_prec) << _f;
						if (roundf(_f) - _f == 0.0f)
							std::cout << ".0";
						std::cout << "f";
					} 
					else
						std::cout << "Impossible";
					break;
	 }
}