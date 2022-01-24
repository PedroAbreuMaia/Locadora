#include "Director.h"

Director::Director()
{
    this->id = 0;
    this->name = "";
}

Director::Director(int id, System::String^ name)
{
    this->id = id;
    this->name = name;
}

Director::Director(System::String^ name)
{
    this->name = name;
}

Director::~Director()
{
    delete name;
}

int Director::getId()
{
    return this->id;
}

System::String^ Director::ToString()
{
    System::String^ str = gcnew System::String("id: ");
    str = str + this->id + " nome: " + this->name;
    return str;
}

System::String^ Director::getName()
{
    return this->name;
}

System::String^ Director::sqlTable()
{
    return gcnew System::String("CREATE TABLE Director("
        "id INTEGER PRIMARY KEY, name TEXT NOT NULL);");
}

System::String^ Director::sqlInsert()
{
    return gcnew System::String("INSERT INTO Director VALUES("
        "NULL, '" + this->name + "');");
}

System::String^ Director::sqlSelectAll()
{
    return gcnew System::String("SELECT id, name FROM Director;");
}

System::String^ Director::sqlSelect(int option, System::String^ input)
{
    System::String^ sql = gcnew System::String("");
    switch (option)
    {
    case 1:
        sql = "SELECT id, name FROM Director WHERE id = " + input + ";";
        break;
    case 2:
        sql = "SELECT id, name FROM Director WHERE name = '" + input + "';";
        break;
    case 3:
        sql = "SELECT EXISTS(SELECT 1 FROM Director WHERE id = " + input + ");";
    }
    return sql;
}

System::String^ Director::sqlUpdate()
{
    return gcnew System::String("UPDATE Director SET name = '" + this->name + "' WHERE id = " + this->id + ";");
}

System::String^ Director::sqlDelete()
{
    return gcnew System::String("DELETE FROM Director WHERE id = " + this->id + ";");
}

void Director::setName(System::String^ name)
{
    this->name = name;
}