#ifndef ATHLETE_H
#define ATHLETE_H

#include <string>

class Athlete
{
	//attributes (name, weight, height)
	std::string name;
	double weight, height;

public:
	//default constructor
	Athlete(std::string new_name = "name", double new_weight = 0, double new_height = 0)
		:name(new_name), weight(new_weight), height(new_height) {}

	//default destructor
	~Athlete() {}

	//sets each attribute (name, weight, height)
	const void set_name(const std::string& new_name);
	const void set_weight(const double& new_weight);
	const void set_height(const double& new_height);
	//sets all attributes (name, weight, height)
	virtual const void set_attribute(); //possible to do polymorphism

	//gets each attribute (name, weight, height)
	std::string get_name() const;
	double get_weight() const;
	double get_height() const;
	//gets all attributes (name, weight, height)
	virtual std::string get_attribute(const int& ranking_choice) const; //possible to do polymorphism
};

#endif