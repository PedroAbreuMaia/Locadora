#pragma once
ref class Director
{
private:

	int id;
	System::String^ name;

public:

	Director();
	Director(int id, System::String^ name);
	Director(System::String^ name);
	~Director();

	int getId();
	System::String^ Director::ToString() override;
	System::String^ getName();
	System::String^ sqlTable();
	System::String^ sqlInsert();
	System::String^ sqlSelectAll();
	System::String^ sqlSelect(int option, System::String^ input);
	System::String^ sqlUpdate();
	System::String^ sqlDelete();

	void setName(System::String^ name);
};

