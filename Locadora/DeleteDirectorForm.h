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
	/// Summary for DeleteDirectorForm
	/// </summary>
	public ref class DeleteDirectorForm : public System::Windows::Forms::Form
	{
	public:
		DeleteDirectorForm(void)
		{
			InitializeComponent();
			controller = gcnew ControllerClass();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeleteDirectorForm()
		{
			delete controller;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbInfo;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::TextBox^ tbId;
	private: System::Windows::Forms::Label^ label1;

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
			this->lbInfo = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->tbId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbInfo
			// 
			this->lbInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbInfo->AutoSize = true;
			this->lbInfo->Location = System::Drawing::Point(319, 54);
			this->lbInfo->Name = L"lbInfo";
			this->lbInfo->Size = System::Drawing::Size(41, 13);
			this->lbInfo->TabIndex = 7;
			this->lbInfo->Text = L"Pronto.";
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
			this->tableLayoutPanel1->Controls->Add(this->btnConfirm, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(11, 73);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(360, 29);
			this->tableLayoutPanel1->TabIndex = 6;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(3, 3);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(174, 23);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &DeleteDirectorForm::btnCancel_Click);
			// 
			// btnConfirm
			// 
			this->btnConfirm->Location = System::Drawing::Point(183, 3);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(174, 23);
			this->btnConfirm->TabIndex = 1;
			this->btnConfirm->Text = L"Remover";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &DeleteDirectorForm::btnConfirm_Click);
			// 
			// tbId
			// 
			this->tbId->Location = System::Drawing::Point(12, 26);
			this->tbId->Name = L"tbId";
			this->tbId->Size = System::Drawing::Size(359, 20);
			this->tbId->TabIndex = 5;
			this->tbId->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &DeleteDirectorForm::tbId_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Id ";
			// 
			// DeleteDirectorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 111);
			this->Controls->Add(this->lbInfo);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbId);
			this->Controls->Add(this->label1);
			this->Name = L"DeleteDirectorForm";
			this->Text = L"Locadora: Remove Diretor";
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

	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ s_id = tbId->Text;
		if (String::IsNullOrEmpty(s_id))
		{
			lbInfo->Text = "Campos Vazios";
		}
		else
		{
			int id = Int32::Parse(s_id);
			controller->opendbConnection("MyDb.db");
			if (controller->verifyDirectorID(id))
			{
				System::Windows::Forms::DialogResult confirmResult = MessageBox::Show("Tem certeza que quer remover este diretor?", "Confirme para deletar!", MessageBoxButtons::YesNo);
				if (confirmResult == System::Windows::Forms::DialogResult::Yes)
				{
					controller->deleteDirector(id);
					controller->closedbConnetion();
					this->Close();
				}
				else
				{
					controller->closedbConnetion();
					this->Close();
				}
			}
			lbInfo->Text = "Id inválida!";
			controller->closedbConnetion();
		}
	}
	private: System::Void tbId_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '-') && (e->KeyChar != '.'))
		{
			e->Handled = true;
		}
	}
};
}
