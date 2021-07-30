#ifndef DATABASE_H
#define DATABASE_H

#include <stdexcept>
#include "Athlete.h"
#include "Fighter.h"

//template class (Athlete is default)
template<class T = Athlete>
class Database
{
	//attributes (element_number, pointer_data)
	int element_number;
	T* pointer_data;

public:
	//default constructor
	Database() { element_number = 0; pointer_data = NULL; }
	//default destructor
	~Database() { delete[] pointer_data; } //dynamic memory management

	//gets each attribute (element_number, data)
	int get_element_number() const { return element_number; }
	T get_pointer_data(const int& position) const { return pointer_data[position]; }

	/**
		inserts a new data
		@param new data
		@return void
	*/
	const void insert_data(const T& data)
	{
		T* tmp_pointer_data = new T[element_number + 1];

		for (int i = 0; i < element_number; i++)
			tmp_pointer_data[i] = pointer_data[i];
		tmp_pointer_data[element_number] = data;

		delete[] pointer_data;

		pointer_data = tmp_pointer_data;
		element_number += 1;
	}

	/**
		searches the name in data
		@param new data
		@return true (found), false (not found)
	*/
	bool search_data(const std::string& search_name) const
	{
		for (int i = 0; i < element_number; i++)
			if (pointer_data[i].get_name() == search_name)
				return true;

		return false;
	}

	/**
		deletes a data
		@param the name
		@return void
	*/
	const void delete_data(const std::string& delete_name)
	{
		if (search_data(delete_name))
		{
			T* tmp_pointer_data = new T[element_number - 1];

			for (int i = 0, j = 0; i < element_number; i++)
				if (pointer_data[i].get_name() != delete_name)
				{
					tmp_pointer_data[j] = pointer_data[i];
					j++;
				}

			delete[] pointer_data;

			pointer_data = tmp_pointer_data;
			element_number -= 1;
		}
	}

	/**
		determines which value is larger than the other for sort
		@param string, string
		@return true (the first value is larger), false (the first value is not larger)
	*/
	bool determine_larger(const std::string& i, const std::string& j) const
	{
		try
		{
			//conversion from string to double
			//if the conversion failed => throw the exception (invalid_argument)
			return stod(i) > stod(j) ? true : false;
		}
		catch (const std::invalid_argument& ia)
		{
			//when the values are not numbers (the values are string)
			return i > j ? true : false;
		}
	}

	/**
		sort a data in descending order
		@param the user input of ranking_choice
		@return void
	*/
	const void sort_data(const int& ranking_choice)
	{
		T tmp_swap;

		for (int i = 0; i < element_number; i++)
			for (int j = 0; j < element_number; j++)
				if (determine_larger(pointer_data[i].get_attribute(ranking_choice), pointer_data[j].get_attribute(ranking_choice)))
				{
					tmp_swap = pointer_data[i];
					pointer_data[i] = pointer_data[j];
					pointer_data[j] = tmp_swap;
				}
	}
};

#endif