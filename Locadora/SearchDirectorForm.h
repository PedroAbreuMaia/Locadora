#pragma once

#include "Controller.h"
#include "AddMovieForm.h"
#include "AlterMovieForm.h"
#include "DeleteMovieForm.h"
#include "SearchDirectorForm.h"
#include "AddDirectorForm.h"
#include "AlterDirectorForm.h"
#include "DeleteDirectorForm.h"


namespace Locadora {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ControllerNameSpace;

	/// <summary>
	/// Summary for SearchDirectorForm
	/// </summary>
	public ref class SearchDirectorForm : public System::Windows::Forms::Form
	{
	public:
		SearchDirectorForm(void)
		{
			InitializeComponent();
			controller = gcnew ControllerClass();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SearchDirectorForm()
		{
			delete controller;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxDirector;
	protected:
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::TextBox^ tbSearchDirector;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ diretoresToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ adicionarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ alterarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ removerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ filmesToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ buscarFilmesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ adicionarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ alterarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deletarToolStripMenuItem;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBoxDirector = (gcnew System::Windows::Forms::ListBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->tbSearchDirector = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->diretoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adicionarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->alterarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filmesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarFilmesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adicionarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->alterarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deletarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBoxDirector
			// 
			this->listBoxDirector->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBoxDirector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBoxDirector->FormattingEnabled = true;
			this->listBoxDirector->ItemHeight = 20;
			this->listBoxDirector->Location = System::Drawing::Point(15, 115);
			this->listBoxDirector->Name = L"listBoxDirector";
			this->listBoxDirector->Size = System::Drawing::Size(575, 304);
			this->listBoxDirector->TabIndex = 7;
			// 
			// btnSearch
			// 
			this->btnSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch->Location = System::Drawing::Point(490, 79);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(100, 30);
			this->btnSearch->TabIndex = 6;
			this->btnSearch->Text = L"Buscar";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &SearchDirectorForm::btnSearch_Click);
			// 
			// tbSearchDirector
			// 
			this->tbSearchDirector->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbSearchDirector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSearchDirector->Location = System::Drawing::Point(15, 46);
			this->tbSearchDirector->Name = L"tbSearchDirector";
			this->tbSearchDirector->Size = System::Drawing::Size(576, 26);
			this->tbSearchDirector->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Buscar Diretor";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->diretoresToolStripMenuItem,
					this->filmesToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(604, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// diretoresToolStripMenuItem
			// 
			this->diretoresToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->adicionarToolStripMenuItem1,
					this->alterarToolStripMenuItem1, this->removerToolStripMenuItem
			});
			this->diretoresToolStripMenuItem->Name = L"diretoresToolStripMenuItem";
			this->diretoresToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->diretoresToolStripMenuItem->Text = L"Diretores";
			// 
			// adicionarToolStripMenuItem1
			// 
			this->adicionarToolStripMenuItem1->Name = L"adicionarToolStripMenuItem1";
			this->adicionarToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->adicionarToolStripMenuItem1->Text = L"Adicionar";
			this->adicionarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &SearchDirectorForm::adicionarToolStripMenuItem1_Click);
			// 
			// alterarToolStripMenuItem1
			// 
			this->alterarToolStripMenuItem1->Name = L"alterarToolStripMenuItem1";
			this->alterarToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->alterarToolStripMenuItem1->Text = L"Alterar";
			this->alterarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &SearchDirectorForm::alterarToolStripMenuItem1_Click);
			// 
			// removerToolStripMenuItem
			// 
			this->removerToolStripMenuItem->Name = L"removerToolStripMenuItem";
			this->removerToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->removerToolStripMenuItem->Text = L"Remover";
			this->removerToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchDirectorForm::removerToolStripMenuItem_Click);
			// 
			// filmesToolStripMenuItem
			// 
			this->filmesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->buscarFilmesToolStripMenuItem,
					this->adicionarToolStripMenuItem, this->alterarToolStripMenuItem, this->deletarToolStripMenuItem
			});
			this->filmesToolStripMenuItem->Name = L"filmesToolStripMenuItem";
			this->filmesToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->filmesToolStripMenuItem->Text = L"Filmes";
			// 
			// buscarFilmesToolStripMenuItem
			// 
			this->buscarFilmesToolStripMenuItem->Name = L"buscarFilmesToolStripMenuItem";
			this->buscarFilmesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->buscarFilmesToolStripMenuItem->Text = L"Buscar Filmes";
			this->buscarFilmesToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchDirectorForm::buscarFilmesToolStripMenuItem_Click);
			// 
			// adicionarToolStripMenuItem
			// 
			this->adicionarToolStripMenuItem->Name = L"adicionarToolStripMenuItem";
			this->adicionarToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->adicionarToolStripMenuItem->Text = L"Adicionar";
			this->adicionarToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchDirectorForm::adicionarToolStripMenuItem_Click);
			// 
			// alterarToolStripMenuItem
			// 
			this->alterarToolStripMenuItem->Name = L"alterarToolStripMenuItem";
			this->alterarToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->alterarToolStripMenuItem->Text = L"Alterar";
			this->alterarToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchDirectorForm::alterarToolStripMenuItem_Click);
			// 
			// deletarToolStripMenuItem
			// 
			this->deletarToolStripMenuItem->Name = L"deletarToolStripMenuItem";
			this->deletarToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->deletarToolStripMenuItem->Text = L"Remover";
			this->deletarToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchDirectorForm::deletarToolStripMenuItem_Click);
			// 
			// SearchDirectorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 441);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->listBoxDirector);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbSearchDirector);
			this->Controls->Add(this->label1);
			this->Name = L"SearchDirectorForm";
			this->Text = L"Locadora: Diretores";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: ControllerClass^ controller;

	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ name = tbSearchDirector->Text;
		controller->opendbConnection("MyDb.db");

		this->listBoxDirector->Items->Clear();

		if(name->Equals("Todos") || String::IsNullOrEmpty(name))
		{
			List<Director^>^ dirs = controller->searchAllDirector();
			if (dirs != nullptr && dirs->Count > 0)
			{
				for (int i = 0; i < dirs->Count; i++)
				{
					this->listBoxDirector->Items->Add(gcnew String(dirs[i]->ToString()));
				}
			}
			delete dirs;
		}
		else
		{
			Director^ dir = controller->searchDirector(name);
			if (dir != nullptr)
			{
				this->listBoxDirector->Items->Add(gcnew String(dir->ToString()));
			}
			delete dir;
		}

		controller->closedbConnetion();
	}

	private: System::Void buscarFilmesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void adicionarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		AddMovieForm^ addMovieForm = gcnew AddMovieForm();
		addMovieForm->ShowDialog();
		this->Show();
	}
	
	private: System::Void alterarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		AlterMovieForm^ alterMovieForm = gcnew AlterMovieForm();
		alterMovieForm->ShowDialog();
		this->Show();
	}
	
	private: System::Void deletarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		DeleteMovieForm^ deleteMovieForm = gcnew DeleteMovieForm();
		deleteMovieForm->ShowDialog();
		this->Show();
	}

	private: System::Void adicionarToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		AddDirectorForm^ addDirectorForm = gcnew AddDirectorForm();
		addDirectorForm->ShowDialog();
		this->Show();
	}

	private: System::Void alterarToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		AlterDirectorForm^ alterDirectorForm = gcnew AlterDirectorForm();
		alterDirectorForm->ShowDialog();
		this->Show();
	}

	private: System::Void removerToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		DeleteDirectorForm^ deleteDirectorForm = gcnew DeleteDirectorForm();
		deleteDirectorForm->ShowDialog();
		this->Show();
	}
};
}
