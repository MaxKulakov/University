#pragma once

namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);
		Rectangle rect = Form::ClientRectangle;
		Pen^ redPen = gcnew Pen(Color::Red);
		redPen->Width = 4;
		g->DrawLine(redPen, 0, 0, rect.Width, rect.Height);
		Pen^ bluePen = gcnew Pen(Color::Blue);
		bluePen->Width = 10;
		g->DrawLine(bluePen, 50, 70, rect.Width, 80);
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		g->DrawString("Надпись на форме", drawFont, drawBrush, 40, 100);
		Pen^ greenPen = gcnew Pen(Color::Green);
		greenPen->Width = 5;
		int firstLineX = rect.Height / 3;
		int firstLineY = (rect.Width / 3) * 2;
		g->DrawLine(greenPen, 0, firstLineX, firstLineY, 0);
		int secondLineX = (rect.Width / 3) * 2;
		int secondLineY = (rect.Height / 3) * 2;
		g->DrawLine(greenPen, secondLineX, 0, rect.Width, secondLineY);
		int thirdLineY = (rect.Height / 3) * 2;
		int thirdLineX = rect.Width / 3;
		g->DrawLine(greenPen, rect.Width, thirdLineY, thirdLineX, rect.Height);
		int fourthLineX = rect.Width / 3;
		int fourthLineY = rect.Height / 3;
		g->DrawLine(greenPen, fourthLineX, rect.Height, 0, fourthLineY);
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		this->Refresh();
	}
	};
}
