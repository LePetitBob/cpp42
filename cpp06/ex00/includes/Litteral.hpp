#ifndef LITTERAL_HPP
# define LITTERAL_HPP
# include <string>
# include <climits>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <tgmath.h>

class Value
{
	private:
		std::string	_str;
		char		_type;
		char		_c;
		int			_i;
		double		_d;
		float		_f;
		
		int			_prec;
		std::string	_pc;
		std::string	_pi;
		std::string	_pd;
		std::string	_pf;

	public:
		Value(void);
		~Value();

		void		setStr(std::string _str);
		std::string	getStr(void);

		void		setType(char type);
		char		getType(void);

		void		setChar(char c);
		char		getChar(void);

		void		setInt(int i);
		int			getInt(void);

		void		setDouble(double d);
		double		getdouble(void);

		void		setFloat(float f);
		float		getFloat(void);

		void		detectType(void);
		int			IsChar(void);
		int			IsInt(void);
		int			IsDouble(void);
		int			IsFloat(void);

		void		setPrec(int prec);
		int			getPrec(void);

		void		convert(void);

		void		display(void);
		void 		printC(void) const;
		void 		printI(void) const;
		void 		printF(void) const;
		void 		printD(void) const;
};


//!----------------------------------------


// bool	IsInf(std::string input);
// void	Nan(void);

#endif