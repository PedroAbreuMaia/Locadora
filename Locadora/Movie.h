#pragma once
ref class Movie
{
private:

	int id;
	System::String^ name;
	int year;
	int copies;
	int rented;
	int directorId;

	void setId(int id);
	void setCopies(int copies);
	void setRented(int rented);

public:

	Movie();
	Movie(int id, System::String^ name, int year, int copies, int rented, int director);
	Movie(System::String^ name, int year, int copies, int director);
	Movie(System::String^ name, int year, int copies);
	~Movie();

	int getId();
	System::String^ getName();
	int getYear();
	int getCopies();
	int getRented();
	int getDirector();
	System::String^ Movie::ToString() override;
	System::String^ sqlTable();
	System::String^ sqlInsert();
	System::String^ sqlSelectAll();
	System::String^ sqlSelect(int option, System::String^ input);
	System::String^ sqlUpdate();
	System::String^ sqlDelete();
	System::String^ sqlChangeDirector(int id);

	void setName(System::String^ name);
	void setYear(int year);
	void setDirector(int director);

	bool rentCopy();
	bool changeCopies(int newCopies);
};

