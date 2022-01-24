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
	/// Sumário para mainForm
	/// </summary>
	public ref class SearchMovieForm : public System::Windows::Forms::Form
	{
	public:
		SearchMovieForm()
		{
			InitializeComponent();
			controller = gcnew ControllerClass();
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~SearchMovieForm()
		{
			delete controller;
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ tbSearchMovie;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::ListBox^ listBoxMovies;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ filmesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ adicionarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ alterarToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ diretoresToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deletarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ adicionarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ alterarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ removerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ buscarDiretorToolStripMenuItem;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbSearchMovie = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->listBoxMovies = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->filmesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adicionarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->alterarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deletarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diretoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adicionarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->alterarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarDiretorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Buscar Filme";
			// 
			// tbSearchMovie
			// 
			this->tbSearchMovie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbSearchMovie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSearchMovie->Location = System::Drawing::Point(15, 46);
			this->tbSearchMovie->Name = L"tbSearchMovie";
			this->tbSearchMovie->Size = System::Drawing::Size(576, 26);
			this->tbSearchMovie->TabIndex = 1;
			// 
			// btnSearch
			// 
			this->btnSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch->Location = System::Drawing::Point(490, 79);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(100, 30);
			this->btnSearch->TabIndex = 2;
			this->btnSearch->Text = L"Buscar";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &SearchMovieForm::btnSearch_Click);
			// 
			// listBoxMovies
			// 
			this->listBoxMovies->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBoxMovies->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBoxMovies->FormattingEnabled = true;
			this->listBoxMovies->ItemHeight = 20;
			this->listBoxMovies->Location = System::Drawing::Point(15, 115);
			this->listBoxMovies->Name = L"listBoxMovies";
			this->listBoxMovies->Size = System::Drawing::Size(575, 304);
			this->listBoxMovies->TabIndex = 3;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->filmesToolStripMenuItem,
					this->diretoresToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(604, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// filmesToolStripMenuItem
			// 
			this->filmesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->adicionarToolStripMenuItem,
					this->alterarToolStripMenuItem, this->deletarToolStripMenuItem
			});
			this->filmesToolStripMenuItem->Name = L"filmesToolStripMenuItem";
			this->filmesToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->filmesToolStripMenuItem->Text = L"Filmes";
			// 
			// adicionarToolStripMenuItem
			// 
			this->adicionarToolStripMenuItem->Name = L"adicionarToolStripMenuItem";
			this->adicionarToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->adicionarToolStripMenuItem->Text = L"Adicionar";
			this->adicionarToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchMovieForm::adicionarToolStripMenuItem_Click);
			// 
			// alterarToolStripMenuItem
			// 
			this->alterarToolStripMenuItem->Name = L"alterarToolStripMenuItem";
			this->alterarToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->alterarToolStripMenuItem->Text = L"Alterar";
			this->alterarToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchMovieForm::alterarToolStripMenuItem_Click);
			// 
			// deletarToolStripMenuItem
			// 
			this->deletarToolStripMenuItem->Name = L"deletarToolStripMenuItem";
			this->deletarToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->deletarToolStripMenuItem->Text = L"Remover";
			this->deletarToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchMovieForm::deletarToolStripMenuItem_Click);
			// 
			// diretoresToolStripMenuItem
			// 
			this->diretoresToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->adicionarToolStripMenuItem1,
					this->alterarToolStripMenuItem1, this->removerToolStripMenuItem, this->buscarDiretorToolStripMenuItem
			});
			this->diretoresToolStripMenuItem->Name = L"diretoresToolStripMenuItem";
			this->diretoresToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->diretoresToolStripMenuItem->Text = L"Diretores";
			// 
			// adicionarToolStripMenuItem1
			// 
			this->adicionarToolStripMenuItem1->Name = L"adicionarToolStripMenuItem1";
			this->adicionarToolStripMenuItem1->Size = System::Drawing::Size(148, 22);
			this->adicionarToolStripMenuItem1->Text = L"Adicionar";
			this->adicionarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &SearchMovieForm::adicionarToolStripMenuItem1_Click);
			// 
			// alterarToolStripMenuItem1
			// 
			this->alterarToolStripMenuItem1->Name = L"alterarToolStripMenuItem1";
			this->alterarToolStripMenuItem1->Size = System::Drawing::Size(148, 22);
			this->alterarToolStripMenuItem1->Text = L"Alterar";
			this->alterarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &SearchMovieForm::alterarToolStripMenuItem1_Click);
			// 
			// removerToolStripMenuItem
			// 
			this->removerToolStripMenuItem->Name = L"removerToolStripMenuItem";
			this->removerToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->removerToolStripMenuItem->Text = L"Remover";
			this->removerToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchMovieForm::removerToolStripMenuItem_Click);
			// 
			// buscarDiretorToolStripMenuItem
			// 
			this->buscarDiretorToolStripMenuItem->Name = L"buscarDiretorToolStripMenuItem";
			this->buscarDiretorToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->buscarDiretorToolStripMenuItem->Text = L"Buscar Diretor";
			this->buscarDiretorToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchMovieForm::buscarDiretorToolStripMenuItem_Click);
			// 
			// SearchMovieForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 441);
			this->Controls->Add(this->listBoxMovies);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbSearchMovie);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(620, 480);
			this->Name = L"SearchMovieForm";
			this->Text = L"Locadora: Filmes";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SearchMovieForm::SearchMovieForm_FormClosed);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: ControllerClass^ controller;

	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = tbSearchMovie->Text;
		controller->opendbConnection("MyDb.db");

		this->listBoxMovies->Items->Clear();
		
		if(name->Equals("Todos") || String::IsNullOrEmpty(name)) 
		{
			List<Movie^>^ mvs = controller->searchAllMovie();
			if (mvs != nullptr && mvs->Count > 0)
			{
				for (int i = 0; i < mvs->Count; i++)
				{
					this->listBoxMovies->Items->Add(gcnew String(mvs[i]->ToString()));
				}
			}
			delete mvs;
		} 
		else
		{
			Movie^ mv = controller->searchMovie(name);
			if(mv != nullptr)
			{
				this->listBoxMovies->Items->Add(gcnew String(mv->ToString()));
			}
			delete mv;
		}
		controller->closedbConnetion();
	}
	private: System::Void SearchMovieForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) 
	{
		Application::Exit();
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

	private: System::Void buscarDiretorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		SearchDirectorForm^ searchDirectorForm = gcnew SearchDirectorForm();
		searchDirectorForm->ShowDialog();
		this->Show();
	}

};
}