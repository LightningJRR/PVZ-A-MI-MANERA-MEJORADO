#pragma once
#include "Controller.h"

namespace ejerciciosPVZ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpPlayer = gcnew Bitmap("oro.png");
			bmpPared = gcnew Bitmap("lagrima.png");
			bmpPlanta = gcnew Bitmap("plantas.png");
			bmpStar = gcnew Bitmap("star.png");
			bmpFondo = gcnew Bitmap("fondo.png");


			//Controller
			controller = new Controller(bmpPlayer,bmpPared,bmpPlanta,bmpStar);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpPlayer;
		Bitmap^ bmpPared;
		Bitmap^ bmpPlanta;
		Bitmap^ bmpStar;
		Bitmap^ bmpFondo;

		//Controller
		Controller* controller;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(918, 551);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 554);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//colision
		controller->colision();
		//Move
		controller->moveEverything(buffer->Graphics, controller->getplayer());
		//Draw
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, panel1->Width, panel1->Height);
		controller->drawEverything(buffer->Graphics, bmpPlayer, bmpPared,bmpPlanta, bmpStar);
		//Render
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controller->getplayer()->move(buffer->Graphics, 'A', controller->getMyRectangles()); break;
		case Keys::D: case Keys::Right:
			controller->getplayer()->move(buffer->Graphics, 'D', controller->getMyRectangles()); break;
		case Keys::W: case Keys::Up:
			controller->getplayer()->move(buffer->Graphics, 'W', controller->getMyRectangles()); break;
		case Keys::S: case Keys::Down:
			controller->getplayer()->move(buffer->Graphics, 'S', controller->getMyRectangles()); break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
};
}
