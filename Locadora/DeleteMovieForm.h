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
	/// Summary for DeleteMovieForm
	/// </summary>
	public ref class DeleteMovieForm : public System::Windows::Forms::Form
	{
	public:
		DeleteMovieForm(void)
		{
			InitializeComponent();
			controller = gcnew ControllerClass();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeleteMovieForm()
		{
			delete controller;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbId;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::Label^ lbInfo;

	protected:

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
			this->tbId = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->lbInfo = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id ";
			// 
			// tbId
			// 
			this->tbId->Location = System::Drawing::Point(13, 30);
			this->tbId->Name = L"tbId";
			this->tbId->Size = System::Drawing::Size(359, 20);
			this->tbId->TabIndex = 1;
			this->tbId->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &DeleteMovieForm::tbId_KeyPress);
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 77);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(360, 29);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(3, 3);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(174, 23);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &DeleteMovieForm::btnCancel_Click);
			// 
			// btnConfirm
			// 
			this->btnConfirm->Location = System::Drawing::Point(183, 3);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(174, 23);
			this->btnConfirm->TabIndex = 1;
			this->btnConfirm->Text = L"Remover";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &DeleteMovieForm::btnConfirm_Click);
			// 
			// lbInfo
			// 
			this->lbInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbInfo->AutoSize = true;
			this->lbInfo->Location = System::Drawing::Point(319, 58);
			this->lbInfo->Name = L"lbInfo";
			this->lbInfo->Size = System::Drawing::Size(41, 13);
			this->lbInfo->TabIndex = 3;
			this->lbInfo->Text = L"Pronto.";
			this->lbInfo->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// DeleteMovieForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 111);
			this->Controls->Add(this->lbInfo);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbId);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(400, 150);
			this->MinimumSize = System::Drawing::Size(400, 150);
			this->Name = L"DeleteMovieForm";
			this->Text = L"Locadora: Remove Filme";
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
			int id = Int32::Parse(tbId->Text->ToString());
			controller->opendbConnection("MyDb.db");
			if (controller->verifyMovieId(id))
			{
				System::Windows::Forms::DialogResult confirmResult = MessageBox::Show("Tem certeza que quer remover este filme?", "Confirme para deletar!", MessageBoxButtons::YesNo);
				if (confirmResult == System::Windows::Forms::DialogResult::Yes)
				{
					controller->deleteMovie(id);
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
