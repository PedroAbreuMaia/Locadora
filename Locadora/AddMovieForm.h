#pragma once

#include "Controller.h"

namespace Locadora {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ControllerNameSpace;

	/// <summary>
	/// Summary for AddMovieForm
	/// </summary>
	public ref class AddMovieForm : public System::Windows::Forms::Form
	{
	public:
		AddMovieForm(void)
		{
			InitializeComponent();
			controller = gcnew ControllerClass();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddMovieForm()
		{
			delete controller;
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbYear;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbCopies;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbDirector;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Label^ lbInfo;
	private: System::Windows::Forms::Label^ label5;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbYear = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbCopies = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbDirector = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lbInfo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Nome";
			// 
			// tbName
			// 
			this->tbName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbName->Location = System::Drawing::Point(12, 26);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(579, 20);
			this->tbName->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Ano";
			// 
			// tbYear
			// 
			this->tbYear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbYear->Location = System::Drawing::Point(12, 70);
			this->tbYear->Name = L"tbYear";
			this->tbYear->Size = System::Drawing::Size(579, 20);
			this->tbYear->TabIndex = 9;
			this->tbYear->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddMovieForm::tbYear_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"C?pias";
			// 
			// tbCopies
			// 
			this->tbCopies->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbCopies->Location = System::Drawing::Point(12, 114);
			this->tbCopies->Name = L"tbCopies";
			this->tbCopies->Size = System::Drawing::Size(579, 20);
			this->tbCopies->TabIndex = 11;
			this->tbCopies->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddMovieForm::tbCopies_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Diretor";
			// 
			// tbDirector
			// 
			this->tbDirector->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbDirector->Location = System::Drawing::Point(12, 158);
			this->tbDirector->Name = L"tbDirector";
			this->tbDirector->Size = System::Drawing::Size(579, 20);
			this->tbDirector->TabIndex = 13;
			this->tbDirector->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddMovieForm::tbDirector_KeyPress);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnCancel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnSave, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 197);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(580, 30);
			this->tableLayoutPanel1->TabIndex = 15;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(3, 3);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(284, 23);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &AddMovieForm::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(293, 3);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(284, 23);
			this->btnSave->TabIndex = 1;
			this->btnSave->Text = L"Salvar";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &AddMovieForm::btnSave_Click);
			// 
			// lbInfo
			// 
			this->lbInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbInfo->AutoSize = true;
			this->lbInfo->Location = System::Drawing::Point(535, 181);
			this->lbInfo->Name = L"lbInfo";
			this->lbInfo->Size = System::Drawing::Size(38, 13);
			this->lbInfo->TabIndex = 16;
			this->lbInfo->Text = L"Pronto";
			this->lbInfo->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Ano";
			// 
			// AddMovieForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 236);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lbInfo);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbDirector);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbCopies);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbYear);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(620, 275);
			this->MinimumSize = System::Drawing::Size(620, 275);
			this->Name = L"AddMovieForm";
			this->Text = L"Locadora: Cadastra Filme";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: ControllerClass^ controller;

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ name = tbName->Text;
		String^ s_year = tbYear->Text;
		String^ s_copies = tbCopies->Text;
		String^ s_dir = tbDirector->Text;

		if (String::IsNullOrEmpty(name) || String::IsNullOrEmpty(s_year) || String::IsNullOrEmpty(s_copies) || String::IsNullOrEmpty(s_dir) )
		{
			lbInfo->Text = "Campos Vazios";
		}
		else
		{
			int year = Int32::Parse(s_year);
			int copies = Int32::Parse(s_copies);
			int directorId = Int32::Parse(s_dir);
			controller->opendbConnection("MyDb.db");
			if (controller->verifyDirectorID(directorId))
			{
				Movie^ mv = gcnew Movie(name, year, copies, directorId);
				bool result = controller->registerNewMovie(mv);
				if (result == true)
				{
					lbInfo->Text = "Sucesso!";
				}
				else
				{
					lbInfo->Text = "Erro.";
				}
				delete mv;
			}
			else
			{
				lbInfo->Text = "DirectorID Inv?lida.";
				tbDirector->Text = "";
			}
			controller->closedbConnetion();
		}
	}

	private: System::Void buscarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void tbYear_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '-') && (e->KeyChar != '.'))
		{
			e->Handled = true;
		}
	}

	private: System::Void tbCopies_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '-') && (e->KeyChar != '.'))
		{
			e->Handled = true;
		}
	}

	private: System::Void tbDirector_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '-') && (e->KeyChar != '.'))
		{
			e->Handled = true;
		}
	}
};
}
