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
	mat3 initT; // матрица начального преобразования
	//vector<path> figure;
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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	protected:


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
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
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
	private: float left = 30, right = 100, top = 20, bottom = 50; // расстояния до границ окна
			 float minX = left, maxX; // диапазон изменения координат x
			 float minY = top, maxY; // диапазон изменения координат y
			 float Wcx = left, Wcy; // координаты левого нижнего угла прямоугольника
			 float Wx, Wy; // ширина и высота прямоугольника
	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y
		Wcy = maxY; // координаты левого нижнего угла прямоугольника
		Wx = maxX - left; // ширина прямоугольника
		Wy = maxY - top; // ширина и высота прямоугольника
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
		 float deltaX = V_work.x / Wx; // шаг по x в мировых координатах
		
			 bool hasStart;
		
			 vec2 start, end; // концы отрезка в координатах экрана
		 float x, y; // переменные для координат точки в мировой СК
		 start.x = Wcx; // для начальной точки первого отрезка устанавливаем координату x
		 x = Vc_work.x; // координата x начальной точки первого отрезка в мировых координатах
		 hasStart = f_exists(x, deltaX);
		 if (hasStart) {
			 y = f(x); // координата y начальной точки в мировых координатах
			 // вычисляем соответствующее значение в координатах экрана
				 start.y = Wcy - (y - Vc_work.y) / V_work.y * Wy;			
		}
		 while (start.x < maxX) {
			 vec2 end;// точка конца отрезка в координатах экрана
			 bool hasEnd;
			 float deltaY; // высота точки в прямоугольнике (доля общей высоты)
			 float red, green, blue; // компоненты цвета отрезка
			 end.x = start.x + 1.f; // координата x отличается на единицу
			 x += deltaX; // координата x конечной точки отрезка в мировых координатах
			 hasEnd = f_exists(x, deltaX);
			 if (hasEnd) {
				 y = f(x); // координата y начальной точки в мировых координатах
				 // вычисляем соответствующее значение в координатах экрана
				 deltaY = (y - Vc_work.y) / V_work.y;
				 end.y = Wcy - deltaY * Wy;
			 }
			 vec2 tmpEnd = end;
			 bool visible = hasStart && hasEnd && clip(start, end, minX, minY, maxX, maxY);
			 if (visible) { // если отрезок видим
				 // после отсечения, start и end - концы видимой части отрезка
				 if (deltaY > 1.f) deltaY = 1.f; // нормализуем значение высоты точки
				 if (deltaY < 0.f) deltaY = 0.f; // на случай, если отрезок отсекался
				 green = 510.f * deltaY; // предварительное вычисление произведения
				 if (deltaY < 0.5) { // если точка ниже середины области видимости
					 // компонента зеленого уже вычислена
					 blue = 255.f - green; // синий дополняет зеленый
					 red = 0.f; // красный равен нулю				
				 }
				 else { // если точка не ниже середины
					 blue = 0.f; // синий равен нулю
					 red = green - 255.f; // вычисляем красный и зеленый
					 green = 510.f - green; // с использованием вычисленного произведения

				 }
				 pen->Color = Color::FromArgb(red, green, blue); // меняем цвет пера
				 g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей			
			 }
			 // конечная точка неотсеченного отрезка становится начальной точкой следующего
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
		float centerX = Vc_work.x + V_work.x / 2; // координаты центра прямоугольника
		float centerY = Vc_work.y + V_work.y / 2; // в мировой системе координат
		switch (e->KeyCode) {
		case Keys::Escape:
			T = initT; // присвоили T единичную матрицу
			break;
		case Keys::A:
			T = translate(-V_work.x, 0.f) * T;
			break;
		case Keys::Z:
			T = translate(-centerX, -centerY) * T; // перенос начала координат в центр
			T = scale(1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; // возврат позиции начала координат
			break;
		default:
			break;
		}
		worldRectCalc();
		Refresh();
	}
	};
}