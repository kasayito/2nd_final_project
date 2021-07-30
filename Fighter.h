#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include "Athlete.h"

class Fighter :public Athlete
{
	//attributes (reach, record, fight_rule)
	double reach;
	int record;
	std::string fight_rule;

public:
	//default constructor
	Fighter(std::string new_name = "name", double new_weight = 0, double new_height = 0, double new_reach = 0, int new_record = 0, std::string new_fight_rule = "fight rule")
		:Athlete(new_name, new_weight, new_height), reach(new_reach), record(new_record), fight_rule(new_fight_rule) {}

	//default destructor
	~Fighter() {}

	//sets each attribute (reach, record, fight_rule)
	const void set_reach(const double& new_reach);
	const void set_record(const int& new_record);
	const void set_fight_rule(const std::string& new_fight_rule);
	//sets all attributes (name, weight, height, reach, record, fight_rule)
	virtual const void set_attribute();

	//gets each attribute (reach, record, fight_rule)
	double get_reach() const;
	int get_record() const;
	std::string get_fight_rule() const;
	//gets all attributes (name, weight, height, reach, record, fight_rule)
	virtual std::string get_attribute(const int& ranking_choice) const;
};

#endif