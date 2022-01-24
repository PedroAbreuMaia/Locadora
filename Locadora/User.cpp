#include "User.h"

User::User()
{
    this->id = 0;
    this->name = "";
    this->password = "";
}

User::User(int id, System::String^ name, System::String^ password)
{
    this->id = id;
    this->name = name;
    this->password = password;
}

User::User(System::String^ name, System::String^ password)
{
    this->name = name;
    this->password = password;
}

System::String^ User::sqlTable()
{
    return gcnew System::String("CREATE TABLE User("
        "id INTEGER PRIMARY KEY, name TEXT NOT NULL, PASSWORD TEXT NOT NULL);");
}

System::String^ User::sqlInsert()
{
    return gcnew System::String("INSERT INTO User VALUES(NULL, '" + this->name + "', '" + this->password + "');");
}

System::String^ User::sqlSelectAll()
{
    return gcnew System::String("SELECT id, name, password FROM User;");
}

System::String^ User::sqlSelect(int option, System::String^ input)
{
    System::String^ sql = gcnew System::String("");
    switch (option)
    {
    case 1:
        sql = "SELECT id, name, password FROM User WHERE id = " + input + ";";
        break;
    case 2:
        sql = "SELECT id, name, password FROM User WHERE name = '" + input + "';";
        break;
    }
    return sql;
}

System::String^ User::sqlUpdate()
{
    return gcnew System::String("UPDATE User SET name = '" + this->name +
        "', password = '" + this->password + "' WHERE id = " + this->id + ";");
}

System::String^ User::sqlDelete()
{
    return gcnew System::String("DELETE FROM User WHERE id = " + this->id + ";");
}

int User::getID()
{
    return this->id;
}

System::String^ User::getName()
{
    return this->name;
}

bool User::checkPassword(System::String^ pswrd)
{
    if (this->password->Equals(pswrd))
    {
        return true;
    }
    return false;
}

void User::setName(System::String^ name)
{
    this->name = name;
}

void User::setPassword(System::String^ password)
{
    this->password = password;
}