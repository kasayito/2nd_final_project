#include <iostream>
#include "Exception.h"
#include "Fighter.h"

/**
	sets each attributes (reach, record, fight_rule)
	@param new value for each
	@return void
*/
const void Fighter::set_reach(const double& new_reach)
{
	reach = new_reach;
}
const void Fighter::set_record(const int& new_record)
{
	record = new_record;
}
const void Fighter::set_fight_rule(const std::string& new_fight_rule)
{
	fight_rule = new_fight_rule;
}
/**
	sets all attributes (name, weight, height, reach, record, fight_rule)
	@param no
	@return void
*/
const void Fighter::set_attribute()
{
	std::string tmp_name;
	double tmp_weight, tmp_height;

	std::cout << std::endl;

	//name
	std::cin.ignore(1, '\n');
	std::cout << "put the athlete name :";
	std::cin.exceptions(std::ios::failbit);
	getline(std::cin, tmp_name);
	set_name(tmp_name);

	//weight
	std::cout << "put the weight :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> tmp_weight;
	set_weight(tmp_weight);

	//height
	std::cout << "put the height :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> tmp_height;
	set_height(tmp_height);

	//reach
	std::cout << "put the reach :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> reach;

	//record
	std::cout << "put the record :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> record;

	//fight_rule
	std::cin.ignore(1, '\n');
	std::cout << "put fight rule :";
	std::cin.exceptions(std::ios::failbit);
	getline(std::cin, fight_rule);
}

/**
	gets each attributes (reach, record, fight_rule)
	@param no
	@return string, double, double respectively
*/
double Fighter::get_reach() const
{
	return reach;
}
int Fighter::get_record() const
{
	return record;
}
std::string Fighter::get_fight_rule() const
{
	return fight_rule;
}
/**
	gets all attributes (name, weight, height, reach, record, fight_rule)
	@param choice for which attribute to get
	@return string
*/
std::string Fighter::get_attribute(const int& ranking_choice) const
{
	switch (ranking_choice)
	{
	case 1: //name
	case 2: //weight
	case 3: //height
	{
		return ((Athlete)(*this)).get_attribute(ranking_choice);
		break;
	}
	case 4: //reach
	{
		return std::to_string(get_reach());
		break;
	}
	case 5: //record
	{
		return std::to_string(get_record());
		break;
	}
	case 6: //fight_rule
	{
		return get_fight_rule();
		break;
	}
	default:
		CinException ex;
		throw ex;
	}
}