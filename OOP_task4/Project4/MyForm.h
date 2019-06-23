#pragma once
#include"Classes.h"
#include<Windows.h>


namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;





	private: System::Windows::Forms::Button^  work;
	private: System::Windows::Forms::Label^  lblN;
	private: System::Windows::Forms::Label^  lblM;
	private: System::Windows::Forms::Label^  lblGEN;



	private: System::Windows::Forms::TextBox^  InputN;
	private: System::Windows::Forms::TextBox^  InputM;
	private: System::Windows::Forms::TextBox^  InputGEN;
	private: System::Windows::Forms::Label^  lblEmpty;












	private: System::Windows::Forms::TextBox^  OutputEmpty;
	private: System::Windows::Forms::Label^  lblAVG;



	private: System::Windows::Forms::TextBox^  OutputAVG;

	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::ErrorProvider^  errorProvider2;
	private: System::Windows::Forms::ErrorProvider^  errorProvider3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  from;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  to;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  begin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  end;
	private: System::ComponentModel::IContainer^  components;
	protected:



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->from = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->to = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->begin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->end = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->work = (gcnew System::Windows::Forms::Button());
			this->lblN = (gcnew System::Windows::Forms::Label());
			this->lblM = (gcnew System::Windows::Forms::Label());
			this->lblGEN = (gcnew System::Windows::Forms::Label());
			this->InputN = (gcnew System::Windows::Forms::TextBox());
			this->InputM = (gcnew System::Windows::Forms::TextBox());
			this->InputGEN = (gcnew System::Windows::Forms::TextBox());
			this->lblEmpty = (gcnew System::Windows::Forms::Label());
			this->OutputEmpty = (gcnew System::Windows::Forms::TextBox());
			this->lblAVG = (gcnew System::Windows::Forms::Label());
			this->OutputAVG = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider3 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider3))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->from, this->to,
					this->begin, this->end
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(443, 445);
			this->dataGridView1->TabIndex = 0;
			// 
			// from
			// 
			this->from->HeaderText = L"Откуда";
			this->from->Name = L"from";
			this->from->ReadOnly = true;
			// 
			// to
			// 
			this->to->HeaderText = L"Куда";
			this->to->Name = L"to";
			this->to->ReadOnly = true;
			// 
			// begin
			// 
			this->begin->HeaderText = L"Время начала";
			this->begin->Name = L"begin";
			this->begin->ReadOnly = true;
			// 
			// end
			// 
			this->end->HeaderText = L"Время окончания";
			this->end->Name = L"end";
			this->end->ReadOnly = true;
			// 
			// work
			// 
			this->work->Location = System::Drawing::Point(731, 70);
			this->work->Name = L"work";
			this->work->Size = System::Drawing::Size(102, 47);
			this->work->TabIndex = 1;
			this->work->Text = L"Моделирование";
			this->work->UseVisualStyleBackColor = true;
			this->work->Click += gcnew System::EventHandler(this, &MyForm::work_Click);
			// 
			// lblN
			// 
			this->lblN->AutoSize = true;
			this->lblN->Location = System::Drawing::Point(677, 175);
			this->lblN->Name = L"lblN";
			this->lblN->Size = System::Drawing::Size(15, 13);
			this->lblN->TabIndex = 2;
			this->lblN->Text = L"N";
			// 
			// lblM
			// 
			this->lblM->AutoSize = true;
			this->lblM->Location = System::Drawing::Point(678, 240);
			this->lblM->Name = L"lblM";
			this->lblM->Size = System::Drawing::Size(16, 13);
			this->lblM->TabIndex = 3;
			this->lblM->Text = L"M";
			// 
			// lblGEN
			// 
			this->lblGEN->Location = System::Drawing::Point(627, 303);
			this->lblGEN->Name = L"lblGEN";
			this->lblGEN->Size = System::Drawing::Size(100, 30);
			this->lblGEN->TabIndex = 4;
			this->lblGEN->Text = L"Интервал между \r\n       заявками";
			// 
			// InputN
			// 
			this->InputN->Location = System::Drawing::Point(731, 168);
			this->InputN->Name = L"InputN";
			this->InputN->Size = System::Drawing::Size(100, 20);
			this->InputN->TabIndex = 8;
			// 
			// InputM
			// 
			this->InputM->Location = System::Drawing::Point(731, 237);
			this->InputM->Name = L"InputM";
			this->InputM->Size = System::Drawing::Size(100, 20);
			this->InputM->TabIndex = 9;
			// 
			// InputGEN
			// 
			this->InputGEN->Location = System::Drawing::Point(733, 300);
			this->InputGEN->Name = L"InputGEN";
			this->InputGEN->Size = System::Drawing::Size(100, 20);
			this->InputGEN->TabIndex = 10;
			// 
			// lblEmpty
			// 
			this->lblEmpty->AutoSize = true;
			this->lblEmpty->Location = System::Drawing::Point(649, 352);
			this->lblEmpty->Name = L"lblEmpty";
			this->lblEmpty->Size = System::Drawing::Size(58, 26);
			this->lblEmpty->TabIndex = 11;
			this->lblEmpty->Text = L"\"Пустые\" \r\nпереезды";
			// 
			// OutputEmpty
			// 
			this->OutputEmpty->Location = System::Drawing::Point(733, 358);
			this->OutputEmpty->Name = L"OutputEmpty";
			this->OutputEmpty->ReadOnly = true;
			this->OutputEmpty->Size = System::Drawing::Size(100, 20);
			this->OutputEmpty->TabIndex = 12;
			// 
			// lblAVG
			// 
			this->lblAVG->AutoSize = true;
			this->lblAVG->Location = System::Drawing::Point(627, 406);
			this->lblAVG->Name = L"lblAVG";
			this->lblAVG->Size = System::Drawing::Size(85, 13);
			this->lblAVG->TabIndex = 13;
			this->lblAVG->Text = L"Среднее время";
			// 
			// OutputAVG
			// 
			this->OutputAVG->Location = System::Drawing::Point(733, 403);
			this->OutputAVG->Name = L"OutputAVG";
			this->OutputAVG->ReadOnly = true;
			this->OutputAVG->Size = System::Drawing::Size(100, 20);
			this->OutputAVG->TabIndex = 14;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// errorProvider3
			// 
			this->errorProvider3->ContainerControl = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 620);
			this->Controls->Add(this->OutputAVG);
			this->Controls->Add(this->lblAVG);
			this->Controls->Add(this->OutputEmpty);
			this->Controls->Add(this->lblEmpty);
			this->Controls->Add(this->InputGEN);
			this->Controls->Add(this->InputM);
			this->Controls->Add(this->InputN);
			this->Controls->Add(this->lblGEN);
			this->Controls->Add(this->lblM);
			this->Controls->Add(this->lblN);
			this->Controls->Add(this->work);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Моделирование работы курьерской службы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void work_Click(System::Object^  sender, System::EventArgs^  e) {
		errorProvider1->SetError(this->InputN, String::Empty);
		errorProvider2->SetError(this->InputM, String::Empty);
		errorProvider3->SetError(this->InputGEN, String::Empty);
		int m, n, gen;
		bool resultN = Int32::TryParse(this->InputN->Text, n);
		bool resultM = Int32::TryParse(this->InputM->Text, m);
		bool resultGen = Int32::TryParse(this->InputGEN->Text, gen);
		if (!resultN && !resultM && !resultGen)
		{
			errorProvider1->SetError(this->InputN, "Неверные данные");
			errorProvider2->SetError(this->InputM, "Неверные данные");
			errorProvider3->SetError(this->InputGEN, "Неверные данные");
		}
		else if (!resultN && !resultM)
		{
			errorProvider1->SetError(this->InputN, "Неверные данные");
			errorProvider2->SetError(this->InputM, "Неверные данные");
		}
		else if (!resultN && !resultGen)
		{
			errorProvider1->SetError(this->InputN, "Неверные данные");
			errorProvider3->SetError(this->InputGEN, "Неверные данные");
		}
		else if (!resultM && !resultGen)
		{
			errorProvider2->SetError(this->InputM, "Неверные данные");
			errorProvider3->SetError(this->InputGEN, "Неверные данные");
		}
		else if (!resultN)
		{
			errorProvider1->SetError(this->InputN, "Неверные данные");
		}
		else if (!resultM)
		{
			errorProvider2->SetError(this->InputM, "Неверные данные");
		}
		else if (!resultGen)
		{
			errorProvider3->SetError(this->InputGEN, "Неверные данные");
		}
		else
		{
			Controller controller;
			controller.Work(m, n, gen);
			int k = controller.getDim();
			for (int i = 0; i < k; i++)
			{
				this->dataGridView1->RowCount++;
				Request tmp = controller.getRequest(i);
				String^ from = System::Convert::ToString(tmp.getFrom());
				String^ to = System::Convert::ToString(tmp.getTo());
				int hb = tmp.getHB();
				int mb = tmp.getMB();
				int he = tmp.getHE();
				int me = tmp.getME();
				String^ strB = "";
				if (mb < 10)
				{
					strB = "0" + System::Convert::ToString(mb);
				}
				else
				{
					strB = System::Convert::ToString(mb);
				}
				String^ begin = System::Convert::ToString(hb) + ":" + strB;
				String^ strE = "";
				if (me < 10)
				{
					strE = "0" + System::Convert::ToString(me);
				}
				else
				{
					strE = System::Convert::ToString(me);
				}
				String^ end = System::Convert::ToString(he) + ":" + strE;
				this->dataGridView1->Rows[i]->Cells[0]->Value = System::Convert::ToString(from);
				this->dataGridView1->Rows[i]->Cells[1]->Value = System::Convert::ToString(to);
				this->dataGridView1->Rows[i]->Cells[2]->Value = System::Convert::ToString(begin);
				this->dataGridView1->Rows[i]->Cells[3]->Value = System::Convert::ToString(end);
			}
			double emptyTransfer = controller.getemptyTransfer();
			String^ emp = System::Convert::ToString(emptyTransfer) + " мин";
			this->OutputEmpty->Text = System::Convert::ToString(emp);
			double avgTransfer = controller.getavgTime();
			String^ a = System::Convert::ToString(avgTransfer) + " мин";
			this->OutputAVG->Text = System::Convert::ToString(a);
		}
	}

};
}
