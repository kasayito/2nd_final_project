#include <iostream>
#include "Exception.h"
#include "Athlete.h"

/**
	sets each attributes (name, weight, hegiht)
	@param new value for each
	@return void
*/
const void Athlete::set_name(const std::string& new_name)
{
	name = new_name;
}
const void Athlete::set_weight(const double& new_weight)
{
	weight = new_weight;
}
const void Athlete::set_height(const double& new_height)
{
	height = new_height;
}
/**
	sets all attributes (name, weight, hegiht)
	@param no
	@return void
*/
const void Athlete::set_attribute()
{
	std::cout << std::endl;

	//name
	std::cin.ignore(1, '\n');
	std::cout << "put the athlete name :";
	std::cin.exceptions(std::ios::failbit);
	getline(std::cin, name);

	//weight
	std::cout << "put the weight :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> weight;

	//height
	std::cout << "put the height :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> height;
}

/**
	gets each attributes (name, weight, hegiht)
	@param no
	@return string, double, double respectively
*/
std::string Athlete::get_name() const
{
	return name;
}
double Athlete::get_weight() const
{
	return weight;
}
double Athlete::get_height() const
{
	return height;
}
/**
	gets all attributes (name, weight, hegiht)
	@param choice for which attribute to get
	@return string
*/
std::string Athlete::get_attribute(const int& ranking_choice) const
{
	switch (ranking_choice)
	{
	case 1: //name
		return get_name();
		break;
	case 2: //weight
		return std::to_string(get_weight());
		break;
	case 3: //height
		return std::to_string(get_height());
		break;
	default:
		CinException ex;
		throw ex;
	}
}