#pragma once
#include <exception>
#include <iostream>
#include <ostream>

class Bureaucrat {
	private:
	const std::string _name;
	int _grade;

	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void canUpdateGrade(int newGrade) const;

	void incrementGrade();
	void decrementGrade();


	class GradeTooHighException: public std::exception {
		public:
		virtual const char *what() const throw();
	};
	

	class GradeTooLowException: public std::exception {
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

