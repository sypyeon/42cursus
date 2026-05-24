#include "MutantStack.hpp"

#include <stack>
#include <list>
#include <iostream>

int main()
{
	{
		std::cout << "==== testing MutantStack ====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "current top of the stack: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		std::cout << "==testing iterator==" << std::endl;
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
		std::cout << std::endl;
	}

	{
		std::cout << "==== testing MutantStack ====" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "current top of the stack: " << list.back() << std::endl;
		list.pop_back();
		std::cout << "stack size: " << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::cout << "==testing iterator==" << std::endl;
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
