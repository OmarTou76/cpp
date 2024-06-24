#pragma once
#include <iostream>
#include <list>
#include <algorithm>

class Span {
	private:
	unsigned int _N;
	std::list<int> _content;
	Span();
	
	public:
	Span(unsigned int size);
	Span(Span const &c);
	Span &operator=(Span const &rhs);
	~Span();

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

};
