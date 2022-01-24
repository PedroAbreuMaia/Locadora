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
	/// Summary for AddDirectorForm
	/// </summary>
	public ref class AddDirectorForm : public System::Windows::Forms::Form
	{
	public:
		AddDirectorForm(void)
		{
			InitializeComponent();
			controller = gcnew ControllerClass();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddDirectorForm()
		{
			delete controller;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbName;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbInfo;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnSave;

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
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbInfo = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tbName
			// 
			this->tbName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbName->Location = System::Drawing::Point(12, 26);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(579, 20);
			this->tbName->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Nome";
			// 
			// lbInfo
			// 
			this->lbInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbInfo->AutoSize = true;
			this->lbInfo->Location = System::Drawing::Point(535, 49);
			this->lbInfo->Name = L"lbInfo";
			this->lbInfo->Size = System::Drawing::Size(38, 13);
			this->lbInfo->TabIndex = 18;
			this->lbInfo->Text = L"Pronto";
			this->lbInfo->TextAlign = System::Drawing::ContentAlignment::TopRight;
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 65);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(580, 30);
			this->tableLayoutPanel1->TabIndex = 17;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(3, 3);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(284, 23);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &AddDirectorForm::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(293, 3);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(284, 23);
			this->btnSave->TabIndex = 1;
			this->btnSave->Text = L"Salvar";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &AddDirectorForm::btnSave_Click);
			// 
			// AddDirectorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 106);
			this->Controls->Add(this->lbInfo);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->Name = L"AddDirectorForm";
			this->Text = L"Locadora: Cadastra Diretor";
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
		if (String::IsNullOrEmpty(name))
		{
			lbInfo->Text = "Campos Vazios";
		}
		else
		{
			Director^ dir = gcnew Director(name);
			controller->opendbConnection("MyDb.db");
			bool result = controller->registerNewDirector(dir);
			if (result == true)
			{
				lbInfo->Text = "Sucesso!";
			}
			else
			{
				lbInfo->Text = "Erro.";
			}
			delete dir;
			controller->closedbConnetion();
		}
	}
};
}
