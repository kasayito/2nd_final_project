#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

//if the user inputs inappropriate values
class CinException : virtual public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Cin_Exception : invalid input";
	}
};

//if the file stream opened a text file failed
class FstreamException : virtual public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Fstream_Exception : failed to open the text file";
	}
};

//if the dynamic memory allocation failed
class BadAllocationException : virtual public std::exception
{
	virtual const char* what() const throw()
	{
		return "Bad_Allocation_Exception : failed to allocate new memory";
	}
};

#endif