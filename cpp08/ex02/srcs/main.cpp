#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	mstack.push(7);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;

	// std::list<int> mstack;
	// mstack.push_back(5);
	// mstack.push_back(17);
	// std::cout << mstack.back() << std::endl;
	// mstack.pop_back();
	// std::cout << mstack.size() << std::endl;
	// mstack.push_back(3);
	// mstack.push_back(5);
	// mstack.push_back(737);
	// //[...]
	// mstack.push_back(0);

	// mstack.push_back(1);
	// mstack.push_back(2);
	// mstack.push_back(3);
	// mstack.push_back(4);
	// mstack.push_back(5);
	// mstack.push_back(6);
	// mstack.push_back(7);

	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::list<int> s(mstack);
	// return 0;
}