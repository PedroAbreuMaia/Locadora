#pragma once

#include "Movie.h"
#include "Director.h"
#include "User.h"

namespace ControllerNameSpace
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Data::SQLite;

	public ref class ControllerClass
	{
	private:

		void fillLists()
		{
			User^ user = gcnew User(1, gcnew String("Admin"), gcnew String("Admin"));

			Movie^ movie1 = gcnew Movie(1, gcnew String("Trazan"), 1999, 5, 0, 1);
			Movie^ movie2 = gcnew Movie(2, gcnew String("Spider-Man"), 2002, 3, 0, 2);
			Movie^ movie3 = gcnew Movie(3, gcnew String("The Lord Of The Rings: The Return of the King"), 2003, 4, 0, 3);
			Movie^ movie4 = gcnew Movie(4, gcnew String("Spider-Man 2"), 2004, 6, 0, 2);
			Movie^ movie5 = gcnew Movie(5, gcnew String("King Kong"), 2005, 2, 0, 3);

			Director^ director1 = gcnew Director(1, gcnew String("Chris Buck"));
			Director^ director2 = gcnew Director(2, gcnew String("Sam Raimi"));
			Director^ director3 = gcnew Director(3, gcnew String("Peter Jackson"));

			this->opendbConnection("MyDb.db");

			this->dbexecuteNonQuery(user->sqlTable());
			this->dbexecuteNonQuery(user->sqlInsert());

			this->dbexecuteNonQuery(director1->sqlTable());
			this->dbexecuteNonQuery(director1->sqlInsert());
			this->dbexecuteNonQuery(director2->sqlInsert());
			this->dbexecuteNonQuery(director3->sqlInsert());

			this->dbexecuteNonQuery(movie1->sqlTable());
			this->dbexecuteNonQuery(movie1->sqlInsert());
			this->dbexecuteNonQuery(movie2->sqlInsert());
			this->dbexecuteNonQuery(movie3->sqlInsert());
			this->dbexecuteNonQuery(movie4->sqlInsert());
			this->dbexecuteNonQuery(movie5->sqlInsert());

			this->closedbConnetion();
		}

	public:
		SQLiteConnection^ db;

		ControllerClass()
		{

		}

		~ControllerClass()
		{
			delete (IDisposable^)db;
		}

		void opendbConnection(String^ dbName)
		{
			try
			{
				db = gcnew SQLiteConnection();
				Console::WriteLine("Opening Database Connection To " + dbName + " ...");
				db->ConnectionString = "Data Source=" + dbName;
				db->Open();
				Console::WriteLine("Database Connection To " + dbName + " Opened.");
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
			}
		}

		void closedbConnetion()
		{
			try
			{
				Console::WriteLine("Closing Database Connection...");
				db->Close();
				Console::WriteLine("Database Connection Closed.");
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
			}
		}

		int dbexecuteNonQuery(String^ sqlCode)
		{
			try
			{
				Console::WriteLine("Execute command...");
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				int ret = cmd->ExecuteNonQuery();
				Console::WriteLine("Command executed.");
				return ret;
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
			}
		}

		void dbexecuteNonQueryAsync(String^ sqlCode)
		{
			try
			{
				Console::WriteLine("Execute command...");
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				cmd->ExecuteNonQueryAsync();
				Console::WriteLine("Command executed.");
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
			}
		}

		User^ dbselectUser(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				reader->Read();
				int id = Int32::Parse(reader->GetValue(0)->ToString());
				String^ name = reader->GetValue(1)->ToString();
				String^ pass = reader->GetValue(2)->ToString();
				return gcnew User(id, name, pass);
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return nullptr;
			}
		}

		int dbselectDirectorExist(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				reader->Read();
				int ret = Int32::Parse(reader->GetValue(0)->ToString());
				return ret;
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return 0;
			}
		}

		Director^ dbselectDirector(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				reader->Read();
				int id = Int32::Parse(reader->GetValue(0)->ToString());
				String^ name = reader->GetValue(1)->ToString();
				return gcnew Director(id, name);
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return nullptr;
			}
		}

		List<Director^>^ dbselectDirectors(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				List<Director^>^ directors = gcnew List<Director^>();
				while (reader->Read())
				{
					int id = Int32::Parse(reader->GetValue(0)->ToString());
					String^ name = reader->GetValue(1)->ToString();
					directors->Add(gcnew Director(id, name));
				}
				return directors;
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return nullptr;
			}
		}

		int dbselectMovieExist(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				reader->Read();
				int ret = Int32::Parse(reader->GetValue(0)->ToString());
				return ret;
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return 0;
			}
		}

		Movie^ dbselectMovie(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				reader->Read();
				int id = Int32::Parse(reader->GetValue(0)->ToString());
				String^ name = reader->GetValue(1)->ToString();
				int year = Int32::Parse(reader->GetValue(2)->ToString());
				int copies = Int32::Parse(reader->GetValue(3)->ToString());
				int rented = Int32::Parse(reader->GetValue(4)->ToString());
				int directorId = Int32::Parse(reader->GetValue(5)->ToString());
				return gcnew Movie(id, name, year, copies, rented, directorId);
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return nullptr;
			}
		}

		List<Movie^>^ dbselectMovies(String^ sqlCode)
		{
			try
			{
				SQLiteCommand^ cmd = db->CreateCommand();
				cmd->CommandText = sqlCode;
				SQLiteDataReader^ reader = cmd->ExecuteReader();
				List<Movie^>^ movies = gcnew List<Movie^>();
				while (reader->Read())
				{
					int id = Int32::Parse(reader->GetValue(0)->ToString());
					String^ name = reader->GetValue(1)->ToString();
					int year = Int32::Parse(reader->GetValue(2)->ToString());
					int copies = Int32::Parse(reader->GetValue(3)->ToString());
					int rented = Int32::Parse(reader->GetValue(4)->ToString());
					int directorId = Int32::Parse(reader->GetValue(5)->ToString());
					movies->Add(gcnew Movie(id, name, year, copies, rented, directorId));
				}
				return movies;
			}
			catch (Exception^ e)
			{
				Console::WriteLine("Erro: " + e->Message);
				return nullptr;
			}
		}

		bool verifyUser(String^ name, String^ password)
		{
			User^ usr = gcnew User();
			User^ user = this->dbselectUser(usr->sqlSelect(2, name));
			delete usr;
			if(user->checkPassword(password))
			{
				delete user;
				return true;
			}
			delete user;
			return false;
		}

		Movie^ searchMovie(String^ name)
		{
			Movie^ mv = gcnew Movie();
			Movie^ mvr = this->dbselectMovie(mv->sqlSelect(2, name));
			delete mv;
			return mvr;
		}

		List<Movie^>^ searchAllMovie()
		{
			Movie^ mv = gcnew Movie();
			List<Movie^>^ mvs = this->dbselectMovies(mv->sqlSelectAll());
			delete mv;
			return mvs;
		}

		Director^ searchDirector(String^ name)
		{
			Director^ di = gcnew Director();
			Director^ dir = this->dbselectDirector(di->sqlSelect(2, name));
			delete di;
			return dir;
		}

		List<Director^>^ searchAllDirector()
		{
			Director^ di = gcnew Director();
			List<Director^>^ dirs = this->dbselectDirectors(di->sqlSelectAll());
			delete di;
			return dirs;
		}

		bool verifyDirectorID(int directorID)
		{
			Director^ dir = gcnew Director();
			int ret = dbselectDirectorExist(dir->sqlSelect(3, directorID.ToString()));
			if (ret == 1)
			{
				delete dir;
				return true;
			}
			delete dir;
			return false;
		}

		bool registerNewMovie(Movie^ mv)
		{
			int ret = dbexecuteNonQuery(mv->sqlInsert());
			if (ret == 1)
			{
				return true;
			}
			return false;
		}

		bool verifyMovieId(int movieId)
		{
			Movie^ mv = gcnew Movie();
			int ret = dbselectMovieExist(mv->sqlSelect(4, movieId.ToString()));
			if (ret == 1)
			{
				delete mv;
				return true;
			}
			delete mv;
			return false;
		}

		void deleteMovie(int movieId)
		{
			Movie^ mv = gcnew Movie(movieId, gcnew String(" "), 0, 0, 0, 0);
			dbexecuteNonQueryAsync(mv->sqlDelete());
			delete mv;
		}

		bool alterMovie(Movie^ mv)
		{
			int ret = dbexecuteNonQuery(mv->sqlUpdate());
			if (ret == 1)
			{
				return true;
			}
			return false;
		}

		bool registerNewDirector(Director^ dir)
		{
			int ret = dbexecuteNonQuery(dir->sqlInsert());
			if (ret == 1)
			{
				return true;
			}
			return false;
		}

		void deleteDirector(int directorId)
		{
			Director^ dir = gcnew Director(directorId, " ");
			Movie^ mv = gcnew Movie();
			dbexecuteNonQueryAsync(mv->sqlChangeDirector(directorId));
			dbexecuteNonQueryAsync(dir->sqlDelete());
			delete mv;
			delete dir;
		}

		bool alterDirector(Director^ dir)
		{
			int ret = dbexecuteNonQuery(dir->sqlUpdate());
			if (ret == 1)
			{
				return true;
			}
			return false;
		}
	};

}
