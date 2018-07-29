#pragma once

namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	float UVx = 13.5f;
	float UVy = 13.5f;
	float Vx;
	float Vy;
	vec2 Vc;
	vec2 V;
	vec2 Vc_work, V_work;
	mat3 T;
	mat3 initT; // ������� ���������� ��������������
	//vector<path> figure;
	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	protected:


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"��������� ����� (*.txt)|*.txt|��� ����� (*.*)|*.*";
			this->openFileDialog->Title = L"������� ����";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(155, 120);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: float left = 30, right = 100, top = 20, bottom = 50; // ���������� �� ������ ����
			 float minX = left, maxX; // �������� ��������� ��������� x
			 float minY = top, maxY; // �������� ��������� ��������� y
			 float Wcx = left, Wcy; // ���������� ������ ������� ���� ��������������
			 float Wx, Wy; // ������ � ������ ��������������
	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // �������� ��������� ��������� x
		maxY = ClientRectangle.Height - bottom; // �������� ��������� ��������� y
		Wcy = maxY; // ���������� ������ ������� ���� ��������������
		Wx = maxX - left; // ������ ��������������
		Wy = maxY - top; // ������ � ������ ��������������
	}
	private: System::Void worldRectCalc() {
		Vc_work = normalize(T * vec3(Vc, 1.f));
		V_work = mat2(T) * V;
	}
	private: float f(float x) {
		return  tan(x);
	}	private: bool f_exists(float x, float delta) {
		return fabs(2.f * acos(cos(x)) - Math::PI) > V_work.x / Wx;
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		 g->Clear(Color::Aquamarine);	
			 Pen^ rectPen = gcnew Pen(Color::Black, 2);
		 g->DrawRectangle(rectPen, left, top, Wx, Wy);
		
			 Pen^ pen = gcnew Pen(Color::Blue, 1);
		 float deltaX = V_work.x / Wx; // ��� �� x � ������� �����������
		
			 bool hasStart;
		
			 vec2 start, end; // ����� ������� � ����������� ������
		 float x, y; // ���������� ��� ��������� ����� � ������� ��
		 start.x = Wcx; // ��� ��������� ����� ������� ������� ������������� ���������� x
		 x = Vc_work.x; // ���������� x ��������� ����� ������� ������� � ������� �����������
		 hasStart = f_exists(x, deltaX);
		 if (hasStart) {
			 y = f(x); // ���������� y ��������� ����� � ������� �����������
			 // ��������� ��������������� �������� � ����������� ������
				 start.y = Wcy - (y - Vc_work.y) / V_work.y * Wy;			
		}
		 while (start.x < maxX) {
			 vec2 end;// ����� ����� ������� � ����������� ������
			 bool hasEnd;
			 float deltaY; // ������ ����� � �������������� (���� ����� ������)
			 float red, green, blue; // ���������� ����� �������
			 end.x = start.x + 1.f; // ���������� x ���������� �� �������
			 x += deltaX; // ���������� x �������� ����� ������� � ������� �����������
			 hasEnd = f_exists(x, deltaX);
			 if (hasEnd) {
				 y = f(x); // ���������� y ��������� ����� � ������� �����������
				 // ��������� ��������������� �������� � ����������� ������
				 deltaY = (y - Vc_work.y) / V_work.y;
				 end.y = Wcy - deltaY * Wy;
			 }
			 vec2 tmpEnd = end;
			 bool visible = hasStart && hasEnd && clip(start, end, minX, minY, maxX, maxY);
			 if (visible) { // ���� ������� �����
				 // ����� ���������, start � end - ����� ������� ����� �������
				 if (deltaY > 1.f) deltaY = 1.f; // ����������� �������� ������ �����
				 if (deltaY < 0.f) deltaY = 0.f; // �� ������, ���� ������� ���������
				 green = 510.f * deltaY; // ��������������� ���������� ������������
				 if (deltaY < 0.5) { // ���� ����� ���� �������� ������� ���������
					 // ���������� �������� ��� ���������
					 blue = 255.f - green; // ����� ��������� �������
					 red = 0.f; // ������� ����� ����				
				 }
				 else { // ���� ����� �� ���� ��������
					 blue = 0.f; // ����� ����� ����
					 red = green - 255.f; // ��������� ������� � �������
					 green = 510.f - green; // � �������������� ������������ ������������

				 }
				 pen->Color = Color::FromArgb(red, green, blue); // ������ ���� ����
				 g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� ������			
			 }
			 // �������� ����� ������������� ������� ���������� ��������� ������ ����������
			 start = tmpEnd;
			 hasStart = hasEnd;		 }
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		this->rectCalc();
		this->Refresh();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Vc = vec2(-2.f, -2.f);
		V = vec2(4.f, 4.f);
		T = mat3(1.f);
		rectCalc();
		worldRectCalc();
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		float centerX = Vc_work.x + V_work.x / 2; // ���������� ������ ��������������
		float centerY = Vc_work.y + V_work.y / 2; // � ������� ������� ���������
		switch (e->KeyCode) {
		case Keys::Escape:
			T = initT; // ��������� T ��������� �������
			break;
		case Keys::A:
			T = translate(-V_work.x, 0.f) * T;
			break;
		case Keys::Z:
			T = translate(-centerX, -centerY) * T; // ������� ������ ��������� � �����
			T = scale(1.1) * T; // ��������������� ������������ ������ ���������
			T = translate(centerX, centerY) * T; // ������� ������� ������ ���������
			break;
		default:
			break;
		}
		worldRectCalc();
		Refresh();
	}
	};
}