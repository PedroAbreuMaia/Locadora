#include "Movie.h"

void Movie::setId(int id)
{
	throw gcnew System::NotImplementedException();
}

void Movie::setCopies(int copies)
{
	this->copies = copies;
}

void Movie::setRented(int rented)
{
	this->rented = rented;
}

Movie::Movie()
{
	this->id = 0;
	this->name = "";
	this->year = 0;
	this->copies = 0;
	this->rented = 0;
	this->directorId = 0;
}

Movie::Movie(int id, System::String^ name, int year, int copies, int rented, int director)
{
	this->id = id;
	this->name = name;
	this->year = year;
	this->copies = copies;
	this->rented = rented;
	this->directorId = director;
}

Movie::Movie(System::String^ name, int year, int copies, int director)
{
	this->id = 0;
	this->name = name;
	this->year = year;
	this->copies = copies;
	this->rented = 0;
	this->directorId = director;
}

Movie::Movie(System::String^ name, int year, int copies)
{
	this->id = 0;
	this->name = name;
	this->year = year;
	this->copies = copies;
	this->rented = 0;
	this->directorId = 0;
}

Movie::~Movie()
{
	delete name;
}

int Movie::getId()
{
	return this->id;
}

System::String^ Movie::getName()
{
	return this->name;
}

int Movie::getYear()
{
	return this->year;
}

int Movie::getCopies()
{
	return this->copies;
}

int Movie::getRented()
{
	return this->rented;
}

int Movie::getDirector()
{
	return this->directorId;
}

System::String^ Movie::sqlTable()
{
	return gcnew System::String("CREATE TABLE Movie("
		"id INTEGER PRIMARY KEY, name TEXT NOT NULL, year INTEGER, "
		"copies INTEGER, rented INTEGER, directorId INTEGER);");
}

System::String^ Movie::sqlInsert()
{
	return gcnew System::String("INSERT INTO Movie VALUES(NULL, '" + this->name + "', "
		+ this->year + ", " + this->copies + ", " + this->rented + ", "
		+ this->directorId + ");");
}

System::String^ Movie::sqlSelectAll()
{
	return gcnew System::String("SELECT id, name, year, copies, rented, directorId FROM Movie;");
}

System::String^ Movie::sqlSelect(int option, System::String^ input)
{
	System::String^ sql = gcnew System::String("");
	switch (option)
	{
	case 1:
		sql = "SELECT id, name, year, copies, rented, directorId FROM Movie WHERE id = " + input + ";";
		break;
	case 2:
		sql = "SELECT id, name, year, copies, rented, directorId FROM Movie WHERE name = '" + input + "';";
		break;
	case 3:
		sql = "SELECT id, name, year, copies, rented, directorId FROM Movie WHERE directorId = " + input + ";";
		break;
	case 4:
		sql = "SELECT EXISTS(SELECT 1 FROM Movie WHERE id = " + input + ");";
	}
	return sql;
}

System::String^ Movie::sqlUpdate()
{
	return gcnew System::String("UPDATE Movie SET name = '"
		+ this->name + "', year = " + this->year + ", copies = "
		+ this->copies + ", directorId = " + this->directorId + " WHERE id = " + this->id + ";");
}

System::String^ Movie::sqlDelete()
{
	return gcnew System::String("DELETE FROM Movie WHERE id = " + this->id + ";");
}

System::String^ Movie::sqlChangeDirector(int id)
{
	return gcnew System::String("UPDATE Movie SET directorId = " + 0 + " WHERE directorId = " + this->id + ";");
}

void Movie::setName(System::String^ name)
{
	this->name = name;
}

void Movie::setYear(int year)
{
	this->year = year;
}

void Movie::setDirector(int director)
{
	this->directorId = director;
}

bool Movie::rentCopy()
{
	if (copies == rented)
	{
		return false;
	}
	this->setRented(this->rented + 1);
	return true;
}

bool Movie::changeCopies(int newCopies)
{
	if (newCopies > this->copies || newCopies >= this->rented)
	{
		this->setCopies(newCopies);
		return true;
	}
	return false;
}

System::String^ Movie::ToString()
{
	System::String^ str = gcnew System::String("id: ");
	str = str + this->id + " nome: " + this->name + " ano: " + this->year + " cópias: " + this->copies + " alugadas: " + this->rented + " idDiretor: " + this->directorId;
	return str;
}