#pragma once
#include <iostream>
#include <list>
#include <algorithm>

class Span
{
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
	void addRange(std::list<int>::const_iterator, std::list<int>::const_iterator);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void status() const;

	class SpanNotBigEnough : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class SpanAlreadyFull : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class RangeToLarge : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
