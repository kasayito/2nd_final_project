/**
	Final Project : Athletes Database of Combat Sports
	@file final_project.cpp
	@author Kasay Ito
	@version 1.0 2021/05/09
*/

#include <iostream>
#include <fstream>
#include "Exception.h"
#include "Athlete.h"
#include "Fighter.h"
#include "Database.h"

//functions for menu
const void selection_menu(Database<>& database_athlete, Database<Fighter>& database_fighter);
const void save_text(const Database<>& database_athlete, const Database<Fighter>& database_fighter);
const void insert_athlete(Database<>& database_athlete, Database<Fighter>& database_fighter);
const void search_athlete(const Database<>& database_athlete, const Database<Fighter>& database_fighter);
const void delete_athlete(Database<>& database_athlete, Database<Fighter>& database_fighter);
const void ranking(Database<>& database_athlete, Database<Fighter>& database_fighter);
//ostream operator overloading
std::ostream& operator<<(std::ostream& os, const Athlete& data_os);
std::ostream& operator<<(std::ostream& os, const Fighter& data_os);

int main()
{
	//declarations the data structure
	Database<> database_athlete;
	Database<Fighter> database_fighter;

	//integer for escaping from the loop
	int loop = 1;

	do
	{
		try
		{
			//main menu
			selection_menu(database_athlete, database_fighter);
		}
		catch (const std::exception& ex) //if the user inputs inappropriate values
		{
			std::cin.clear();
			std::cerr << std::endl << ex.what() << std::endl << std::endl;
			std::cin.clear();
		}
		catch (const std::bad_alloc& ba) //if the dynamic memory allocation failed
		{
			std::cerr << std::endl << ba.what() << std::endl << std::endl;
		}
		catch (const int& zero) //if save_text function trows 0
		{
			//ends this program
			if (zero == 0)
				loop = 0;
		}
	} while (loop == 1);

	return 0;
}

/**
	selects the options
	@param databases of athlete and fighter
	@return void
*/
const void selection_menu(Database<>& database_athlete, Database<Fighter>& database_fighter)
{
	char menu_input = '0';

	std::cout << std::endl <<
		"1. save the text file and end program" << std::endl <<
		"2. put an athlete data" << std::endl <<
		"3. delete an athlete data" << std::endl <<
		"4. search the data" << std::endl <<
		"5. show ranking" << std::endl;
	std::cout << "select from menu : ";
	std::cin.clear();
	std::cin >> menu_input;

	switch (menu_input)
	{
	case '1': //1. saves the text file and ends program
		save_text(database_athlete, database_fighter);
		break;

	case '2': //2. puts an athlete data
		insert_athlete(database_athlete, database_fighter);
		break;

	case '3': //3. deletes an athlete data
		delete_athlete(database_athlete, database_fighter);
		break;

	case '4': //4. searches the data
		search_athlete(database_athlete, database_fighter);
		break;

	case '5': //5. shows ranking
		ranking(database_athlete, database_fighter);
		break;

	default:
		CinException ex;
		throw ex;
	}
}

/**
	saves and writes the data to the text file
	@param databases of athlete and fighter
	@return void
*/
const void save_text(const Database<>& database_athlete, const Database<Fighter>& database_fighter)
{
	//creates a text file
	std::ofstream file_database("database.txt");
	if (!file_database)
	{
		FstreamException ex;
		throw ex;
	}

	//writes all athlete data
	file_database << std::endl << "Athlete Database [athlete name] [weight] [height]" << std::endl;
	for (int i = 0; i < database_athlete.get_element_number(); i++)
		file_database << (database_athlete.get_pointer_data(i)) << std::endl;
	//writes all fighter data
	file_database << std::endl << "Fighter Database [athlete name] [weight] [height] [reach] [record] [fight rule]" << std::endl;
	for (int i = 0; i < database_fighter.get_element_number(); i++)
		file_database << (database_fighter.get_pointer_data(i)) << std::endl;

	file_database.close();

	//ends this program
	throw 0;
}

/**
	inserts a new data
	@param databases of athlete and fighter
	@return void
*/
const void insert_athlete(Database<>& database_athlete, Database<Fighter>& database_fighter)
{
	char insert_input = '0';

	std::cout << std::endl <<
		"1. Athlete" << std::endl <<
		"2. Fighter" << std::endl;
	std::cout << "select from insert menu : ";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> insert_input;

	switch (insert_input)
	{
	case '1': //1. Athlete
	{
		Athlete athlete_data;
		athlete_data.set_attribute();
		database_athlete.insert_data(athlete_data);
		break;
	}
	case '2': //2. Fighter
	{
		Fighter fighter_data;
		fighter_data.set_attribute();
		database_fighter.insert_data(fighter_data);
		break;
	}
	default:
		CinException ex;
		throw ex;
	}
}

/**
	searchs the name in data
	@param databases of athlete and fighter
	@return void
*/
const void search_athlete(const Database<>& database_athlete, const Database<Fighter>& database_fighter)
{
	std::string search_name;

	std::cout << "put the athlete name :";
	std::cin.exceptions(std::ios::failbit);
	std::cin >> search_name;

	if (database_fighter.search_data(search_name))
		std::cout << "found the data" << std::endl;
	else
		std::cout << "no such data" << std::endl;
}

/**
	deletes a data
	@param databases of athlete and fighter
	@return void
*/
const void delete_athlete(Database<>& database_athlete, Database<Fighter>& database_fighter)
{
	std::string delete_name;

	std::cout << std::endl;

	std::cin.ignore(1, '\n');
	std::cout << "put the athlete name :";
	std::cin.exceptions(std::ios::failbit);
	getline(std::cin, delete_name);

	database_athlete.delete_data(delete_name);
	database_fighter.delete_data(delete_name);
}

/**
	selects and shows the ranking
	@param databases of athlete and fighter
	@return void
*/
const void ranking(Database<>& database_athlete, Database<Fighter>& database_fighter)
{
	char ranking_input = '0';

	std::cout << std::endl <<
		"1. athlete name" << std::endl <<
		"2. weight" << std::endl <<
		"3. height" << std::endl <<
		"4. reach" << std::endl <<
		"5. record" << std::endl <<
		"6. fight rule" << std::endl;
	std::cout << "select from ranking menu : ";
	std::cin >> ranking_input;

	if (!(isdigit(ranking_input)))
	{
		CinException ex;
		throw ex;
	}

	if (ranking_input >= '1' && ranking_input <= '3')
		database_athlete.sort_data(ranking_input - '0');
	if (ranking_input >= '1' && ranking_input <= '6')
		database_fighter.sort_data(ranking_input - '0');

	//displays all athlete data
	std::cout << std::endl << "Athlete Database [athlete name] [weight] [height]" << std::endl;
	for (int i = 0; i < database_athlete.get_element_number(); i++)
		std::cout << (database_athlete.get_pointer_data(i)) << std::endl;
	//displays all fighter data
	std::cout << std::endl << "Fighter Database [athlete name] [weight] [height] [reach] [record] [fight rule]" << std::endl;
	for (int i = 0; i < database_fighter.get_element_number(); i++)
		std::cout << (database_fighter.get_pointer_data(i)) << std::endl;
}

//ostream operator overloading for athlete
std::ostream& operator<<(std::ostream& os, const Athlete& data_os)
{
	os << data_os.get_name() << " " <<
		data_os.get_weight() << " " <<
		data_os.get_height();

	return os;
}

//ostream operator overloading for fighter
std::ostream& operator<<(std::ostream& os, const Fighter& data_os)
{
	os << data_os.get_name() << " " <<
		data_os.get_weight() << " " <<
		data_os.get_height() << " " <<
		data_os.get_reach() << " " <<
		data_os.get_record() << " " <<
		data_os.get_fight_rule();

	return os;
}