#pragma once
ref class User
{
private:

	int id;
	System::String^ name;
	System::String^ password;

public:

	User();

	User(int id, System::String^ name, System::String^ password);

	User(System::String^ name, System::String^ password);

	System::String^ sqlTable();
	System::String^ sqlInsert();
	System::String^ sqlSelectAll();
	System::String^ sqlSelect(int option, System::String^ input);
	System::String^ sqlUpdate();
	System::String^ sqlDelete();

	int getID();
	System::String^ getName();
	bool checkPassword(System::String^ pswrd);

	void setName(System::String^ name);
	void setPassword(System::String^ password);
};
