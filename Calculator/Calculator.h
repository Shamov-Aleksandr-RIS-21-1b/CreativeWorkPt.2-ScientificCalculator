#pragma once
#include "Parser.h"
namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Calculator
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		Calculator(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->ActiveControl = Expression;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonAbs;
	private: System::Windows::Forms::Button^ buttonBackspace;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonE;
	private: System::Windows::Forms::Button^ buttonPi;
	private: System::Windows::Forms::Button^ buttonLn;
	private: System::Windows::Forms::Button^ buttonSqrt;
	private: System::Windows::Forms::Button^ buttonPower;
	private: System::Windows::Forms::Button^ buttonCtg;
	private: System::Windows::Forms::Button^ buttonTg;
	private: System::Windows::Forms::Button^ buttonCos;
	private: System::Windows::Forms::Button^ buttonSin;
	private: System::Windows::Forms::Button^ buttonEquals1;
	private: System::Windows::Forms::Button^ buttonPlus;
	private: System::Windows::Forms::Button^ buttonDivision;
	private: System::Windows::Forms::Button^ buttonMultiply;
	private: System::Windows::Forms::Button^ buttonMinus;
	private: System::Windows::Forms::Button^ buttonPoint;
	private: System::Windows::Forms::Button^ buttonEquals2;
	private: System::Windows::Forms::Button^ button0;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ Answer;
	private: System::Windows::Forms::TextBox^ Expression;
	private: System::Windows::Forms::Button^ buttonLeftBracket;
	private: System::Windows::Forms::Button^ buttonRightBracket;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Calculator::typeid));
			this->buttonAbs = (gcnew System::Windows::Forms::Button());
			this->buttonBackspace = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonE = (gcnew System::Windows::Forms::Button());
			this->buttonPi = (gcnew System::Windows::Forms::Button());
			this->buttonLn = (gcnew System::Windows::Forms::Button());
			this->buttonSqrt = (gcnew System::Windows::Forms::Button());
			this->buttonPower = (gcnew System::Windows::Forms::Button());
			this->buttonCtg = (gcnew System::Windows::Forms::Button());
			this->buttonTg = (gcnew System::Windows::Forms::Button());
			this->buttonCos = (gcnew System::Windows::Forms::Button());
			this->buttonSin = (gcnew System::Windows::Forms::Button());
			this->buttonEquals1 = (gcnew System::Windows::Forms::Button());
			this->buttonPlus = (gcnew System::Windows::Forms::Button());
			this->buttonDivision = (gcnew System::Windows::Forms::Button());
			this->buttonMultiply = (gcnew System::Windows::Forms::Button());
			this->buttonMinus = (gcnew System::Windows::Forms::Button());
			this->buttonPoint = (gcnew System::Windows::Forms::Button());
			this->buttonEquals2 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Answer = (gcnew System::Windows::Forms::TextBox());
			this->Expression = (gcnew System::Windows::Forms::TextBox());
			this->buttonLeftBracket = (gcnew System::Windows::Forms::Button());
			this->buttonRightBracket = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonAbs
			// 
			this->buttonAbs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonAbs->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonAbs->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAbs->ForeColor = System::Drawing::Color::White;
			this->buttonAbs->Location = System::Drawing::Point(136, 140);
			this->buttonAbs->Name = L"buttonAbs";
			this->buttonAbs->Size = System::Drawing::Size(118, 60);
			this->buttonAbs->TabIndex = 11;
			this->buttonAbs->TabStop = false;
			this->buttonAbs->Text = L"|x|";
			this->buttonAbs->UseVisualStyleBackColor = false;
			this->buttonAbs->Click += gcnew System::EventHandler(this, &Calculator::buttonAbs_Click);
			// 
			// buttonBackspace
			// 
			this->buttonBackspace->BackColor = System::Drawing::Color::IndianRed;
			this->buttonBackspace->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonBackspace->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonBackspace->ForeColor = System::Drawing::Color::White;
			this->buttonBackspace->Location = System::Drawing::Point(632, 74);
			this->buttonBackspace->Name = L"buttonBackspace";
			this->buttonBackspace->Size = System::Drawing::Size(118, 60);
			this->buttonBackspace->TabIndex = 9;
			this->buttonBackspace->TabStop = false;
			this->buttonBackspace->Text = L"⌫";
			this->buttonBackspace->UseVisualStyleBackColor = false;
			this->buttonBackspace->Click += gcnew System::EventHandler(this, &Calculator::buttonBackspace_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::Color::IndianRed;
			this->buttonClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonClear->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClear->ForeColor = System::Drawing::Color::White;
			this->buttonClear->Location = System::Drawing::Point(508, 74);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(118, 60);
			this->buttonClear->TabIndex = 8;
			this->buttonClear->TabStop = false;
			this->buttonClear->Text = L"C";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Calculator::buttonClear_Click);
			// 
			// buttonE
			// 
			this->buttonE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonE->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonE->ForeColor = System::Drawing::Color::White;
			this->buttonE->Location = System::Drawing::Point(136, 74);
			this->buttonE->Name = L"buttonE";
			this->buttonE->Size = System::Drawing::Size(118, 60);
			this->buttonE->TabIndex = 5;
			this->buttonE->TabStop = false;
			this->buttonE->Text = L"e";
			this->buttonE->UseVisualStyleBackColor = false;
			this->buttonE->Click += gcnew System::EventHandler(this, &Calculator::buttonE_Click);
			// 
			// buttonPi
			// 
			this->buttonPi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonPi->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonPi->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPi->ForeColor = System::Drawing::Color::White;
			this->buttonPi->Location = System::Drawing::Point(12, 74);
			this->buttonPi->Name = L"buttonPi";
			this->buttonPi->Size = System::Drawing::Size(118, 60);
			this->buttonPi->TabIndex = 4;
			this->buttonPi->TabStop = false;
			this->buttonPi->Text = L"π";
			this->buttonPi->UseVisualStyleBackColor = false;
			this->buttonPi->Click += gcnew System::EventHandler(this, &Calculator::buttonPi_Click);
			// 
			// buttonLn
			// 
			this->buttonLn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonLn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLn->ForeColor = System::Drawing::Color::White;
			this->buttonLn->Location = System::Drawing::Point(12, 140);
			this->buttonLn->Name = L"buttonLn";
			this->buttonLn->Size = System::Drawing::Size(118, 60);
			this->buttonLn->TabIndex = 10;
			this->buttonLn->TabStop = false;
			this->buttonLn->Text = L"ln(x)";
			this->buttonLn->UseVisualStyleBackColor = false;
			this->buttonLn->Click += gcnew System::EventHandler(this, &Calculator::buttonLn_Click);
			// 
			// buttonSqrt
			// 
			this->buttonSqrt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonSqrt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSqrt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSqrt->ForeColor = System::Drawing::Color::White;
			this->buttonSqrt->Location = System::Drawing::Point(136, 207);
			this->buttonSqrt->Name = L"buttonSqrt";
			this->buttonSqrt->Size = System::Drawing::Size(118, 60);
			this->buttonSqrt->TabIndex = 17;
			this->buttonSqrt->TabStop = false;
			this->buttonSqrt->Text = L"√x";
			this->buttonSqrt->UseVisualStyleBackColor = false;
			this->buttonSqrt->Click += gcnew System::EventHandler(this, &Calculator::buttonSqrt_Click);
			// 
			// buttonPower
			// 
			this->buttonPower->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonPower->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPower->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPower->ForeColor = System::Drawing::Color::White;
			this->buttonPower->Location = System::Drawing::Point(12, 206);
			this->buttonPower->Name = L"buttonPower";
			this->buttonPower->Size = System::Drawing::Size(118, 60);
			this->buttonPower->TabIndex = 16;
			this->buttonPower->TabStop = false;
			this->buttonPower->Text = L"^";
			this->buttonPower->UseVisualStyleBackColor = false;
			this->buttonPower->Click += gcnew System::EventHandler(this, &Calculator::buttonPower_Click);
			// 
			// buttonCtg
			// 
			this->buttonCtg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonCtg->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonCtg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCtg->ForeColor = System::Drawing::Color::White;
			this->buttonCtg->Location = System::Drawing::Point(136, 338);
			this->buttonCtg->Name = L"buttonCtg";
			this->buttonCtg->Size = System::Drawing::Size(118, 60);
			this->buttonCtg->TabIndex = 29;
			this->buttonCtg->TabStop = false;
			this->buttonCtg->Text = L"ctg(x)";
			this->buttonCtg->UseVisualStyleBackColor = false;
			this->buttonCtg->Click += gcnew System::EventHandler(this, &Calculator::buttonCtg_Click);
			// 
			// buttonTg
			// 
			this->buttonTg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonTg->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonTg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonTg->ForeColor = System::Drawing::Color::White;
			this->buttonTg->Location = System::Drawing::Point(12, 338);
			this->buttonTg->Name = L"buttonTg";
			this->buttonTg->Size = System::Drawing::Size(118, 60);
			this->buttonTg->TabIndex = 28;
			this->buttonTg->TabStop = false;
			this->buttonTg->Text = L"tg(x)";
			this->buttonTg->UseVisualStyleBackColor = false;
			this->buttonTg->Click += gcnew System::EventHandler(this, &Calculator::buttonTg_Click);
			// 
			// buttonCos
			// 
			this->buttonCos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonCos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonCos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCos->ForeColor = System::Drawing::Color::White;
			this->buttonCos->Location = System::Drawing::Point(136, 271);
			this->buttonCos->Name = L"buttonCos";
			this->buttonCos->Size = System::Drawing::Size(118, 60);
			this->buttonCos->TabIndex = 23;
			this->buttonCos->TabStop = false;
			this->buttonCos->Text = L"cos(x)";
			this->buttonCos->UseVisualStyleBackColor = false;
			this->buttonCos->Click += gcnew System::EventHandler(this, &Calculator::buttonCos_Click);
			// 
			// buttonSin
			// 
			this->buttonSin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonSin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSin->ForeColor = System::Drawing::Color::White;
			this->buttonSin->Location = System::Drawing::Point(12, 272);
			this->buttonSin->Name = L"buttonSin";
			this->buttonSin->Size = System::Drawing::Size(118, 60);
			this->buttonSin->TabIndex = 22;
			this->buttonSin->TabStop = false;
			this->buttonSin->Text = L"sin(x)";
			this->buttonSin->UseVisualStyleBackColor = false;
			this->buttonSin->Click += gcnew System::EventHandler(this, &Calculator::buttonSin_Click);
			// 
			// buttonEquals1
			// 
			this->buttonEquals1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonEquals1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonEquals1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEquals1->ForeColor = System::Drawing::Color::White;
			this->buttonEquals1->Location = System::Drawing::Point(508, 338);
			this->buttonEquals1->Name = L"buttonEquals1";
			this->buttonEquals1->Size = System::Drawing::Size(118, 60);
			this->buttonEquals1->TabIndex = 32;
			this->buttonEquals1->TabStop = false;
			this->buttonEquals1->Text = L"=";
			this->buttonEquals1->UseVisualStyleBackColor = false;
			this->buttonEquals1->Click += gcnew System::EventHandler(this, &Calculator::buttonEquals1_Click);
			// 
			// buttonPlus
			// 
			this->buttonPlus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonPlus->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPlus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPlus->ForeColor = System::Drawing::Color::White;
			this->buttonPlus->Location = System::Drawing::Point(632, 140);
			this->buttonPlus->Name = L"buttonPlus";
			this->buttonPlus->Size = System::Drawing::Size(118, 60);
			this->buttonPlus->TabIndex = 15;
			this->buttonPlus->TabStop = false;
			this->buttonPlus->Text = L"+";
			this->buttonPlus->UseVisualStyleBackColor = false;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &Calculator::buttonPlus_Click);
			// 
			// buttonDivision
			// 
			this->buttonDivision->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonDivision->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDivision->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDivision->ForeColor = System::Drawing::Color::White;
			this->buttonDivision->Location = System::Drawing::Point(632, 338);
			this->buttonDivision->Name = L"buttonDivision";
			this->buttonDivision->Size = System::Drawing::Size(118, 60);
			this->buttonDivision->TabIndex = 33;
			this->buttonDivision->TabStop = false;
			this->buttonDivision->Text = L"/";
			this->buttonDivision->UseVisualStyleBackColor = false;
			this->buttonDivision->Click += gcnew System::EventHandler(this, &Calculator::buttonDivision_Click);
			// 
			// buttonMultiply
			// 
			this->buttonMultiply->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonMultiply->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonMultiply->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMultiply->ForeColor = System::Drawing::Color::White;
			this->buttonMultiply->Location = System::Drawing::Point(632, 271);
			this->buttonMultiply->Name = L"buttonMultiply";
			this->buttonMultiply->Size = System::Drawing::Size(118, 60);
			this->buttonMultiply->TabIndex = 27;
			this->buttonMultiply->TabStop = false;
			this->buttonMultiply->Text = L"*";
			this->buttonMultiply->UseVisualStyleBackColor = false;
			this->buttonMultiply->Click += gcnew System::EventHandler(this, &Calculator::buttonMultiply_Click);
			// 
			// buttonMinus
			// 
			this->buttonMinus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonMinus->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonMinus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMinus->ForeColor = System::Drawing::Color::White;
			this->buttonMinus->Location = System::Drawing::Point(632, 206);
			this->buttonMinus->Name = L"buttonMinus";
			this->buttonMinus->Size = System::Drawing::Size(118, 60);
			this->buttonMinus->TabIndex = 21;
			this->buttonMinus->TabStop = false;
			this->buttonMinus->Text = L"-";
			this->buttonMinus->UseVisualStyleBackColor = false;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &Calculator::buttonMinus_Click);
			// 
			// buttonPoint
			// 
			this->buttonPoint->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonPoint->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPoint->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPoint->ForeColor = System::Drawing::Color::White;
			this->buttonPoint->Location = System::Drawing::Point(260, 338);
			this->buttonPoint->Name = L"buttonPoint";
			this->buttonPoint->Size = System::Drawing::Size(118, 60);
			this->buttonPoint->TabIndex = 30;
			this->buttonPoint->TabStop = false;
			this->buttonPoint->Text = L".";
			this->buttonPoint->UseVisualStyleBackColor = false;
			this->buttonPoint->Click += gcnew System::EventHandler(this, &Calculator::buttonPoint_Click);
			// 
			// buttonEquals2
			// 
			this->buttonEquals2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonEquals2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonEquals2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonEquals2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEquals2->ForeColor = System::Drawing::Color::White;
			this->buttonEquals2->Location = System::Drawing::Point(508, 12);
			this->buttonEquals2->Name = L"buttonEquals2";
			this->buttonEquals2->Size = System::Drawing::Size(83, 43);
			this->buttonEquals2->TabIndex = 2;
			this->buttonEquals2->TabStop = false;
			this->buttonEquals2->Text = L"=";
			this->buttonEquals2->UseVisualStyleBackColor = false;
			this->buttonEquals2->Click += gcnew System::EventHandler(this, &Calculator::buttonEquals2_Click);
			// 
			// button0
			// 
			this->button0->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button0->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button0->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button0->ForeColor = System::Drawing::Color::White;
			this->button0->Location = System::Drawing::Point(384, 338);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(118, 60);
			this->button0->TabIndex = 31;
			this->button0->TabStop = false;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = false;
			this->button0->Click += gcnew System::EventHandler(this, &Calculator::button0_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Location = System::Drawing::Point(508, 140);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(118, 60);
			this->button9->TabIndex = 14;
			this->button9->TabStop = false;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Calculator::button9_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Location = System::Drawing::Point(384, 140);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(118, 60);
			this->button8->TabIndex = 13;
			this->button8->TabStop = false;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Calculator::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Location = System::Drawing::Point(260, 140);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(118, 60);
			this->button7->TabIndex = 12;
			this->button7->TabStop = false;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Calculator::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(508, 206);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(118, 60);
			this->button6->TabIndex = 20;
			this->button6->TabStop = false;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Calculator::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(384, 206);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(118, 60);
			this->button5->TabIndex = 19;
			this->button5->TabStop = false;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Calculator::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(260, 206);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(118, 60);
			this->button4->TabIndex = 18;
			this->button4->TabStop = false;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Calculator::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(508, 272);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 60);
			this->button3->TabIndex = 26;
			this->button3->TabStop = false;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Calculator::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(384, 272);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 60);
			this->button2->TabIndex = 25;
			this->button2->TabStop = false;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Calculator::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(260, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 60);
			this->button1->TabIndex = 24;
			this->button1->TabStop = false;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Calculator::button1_Click);
			// 
			// Answer
			// 
			this->Answer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Answer->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Answer->Cursor = System::Windows::Forms::Cursors::Default;
			this->Answer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Answer->Location = System::Drawing::Point(597, 12);
			this->Answer->Name = L"Answer";
			this->Answer->ReadOnly = true;
			this->Answer->Size = System::Drawing::Size(153, 43);
			this->Answer->TabIndex = 3;
			this->Answer->TabStop = false;
			this->Answer->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Expression
			// 
			this->Expression->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Expression->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Expression->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Expression->Location = System::Drawing::Point(12, 12);
			this->Expression->Name = L"Expression";
			this->Expression->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Expression->Size = System::Drawing::Size(490, 43);
			this->Expression->TabIndex = 1;
			this->Expression->TabStop = false;
			this->Expression->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonLeftBracket
			// 
			this->buttonLeftBracket->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonLeftBracket->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLeftBracket->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLeftBracket->ForeColor = System::Drawing::Color::White;
			this->buttonLeftBracket->Location = System::Drawing::Point(260, 74);
			this->buttonLeftBracket->Name = L"buttonLeftBracket";
			this->buttonLeftBracket->Size = System::Drawing::Size(118, 60);
			this->buttonLeftBracket->TabIndex = 6;
			this->buttonLeftBracket->TabStop = false;
			this->buttonLeftBracket->Text = L"(";
			this->buttonLeftBracket->UseVisualStyleBackColor = false;
			this->buttonLeftBracket->Click += gcnew System::EventHandler(this, &Calculator::buttonLeftBracket_Click);
			// 
			// buttonRightBracket
			// 
			this->buttonRightBracket->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonRightBracket->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonRightBracket->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRightBracket->ForeColor = System::Drawing::Color::White;
			this->buttonRightBracket->Location = System::Drawing::Point(384, 74);
			this->buttonRightBracket->Name = L"buttonRightBracket";
			this->buttonRightBracket->Size = System::Drawing::Size(118, 60);
			this->buttonRightBracket->TabIndex = 7;
			this->buttonRightBracket->TabStop = false;
			this->buttonRightBracket->Text = L")";
			this->buttonRightBracket->UseVisualStyleBackColor = false;
			this->buttonRightBracket->Click += gcnew System::EventHandler(this, &Calculator::buttonRightBracket_Click);
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Silver;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(761, 408);
			this->Controls->Add(this->buttonRightBracket);
			this->Controls->Add(this->buttonLeftBracket);
			this->Controls->Add(this->buttonAbs);
			this->Controls->Add(this->buttonBackspace);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonE);
			this->Controls->Add(this->buttonPi);
			this->Controls->Add(this->buttonLn);
			this->Controls->Add(this->buttonSqrt);
			this->Controls->Add(this->buttonPower);
			this->Controls->Add(this->buttonCtg);
			this->Controls->Add(this->buttonTg);
			this->Controls->Add(this->buttonCos);
			this->Controls->Add(this->buttonSin);
			this->Controls->Add(this->buttonEquals1);
			this->Controls->Add(this->buttonPlus);
			this->Controls->Add(this->buttonDivision);
			this->Controls->Add(this->buttonMultiply);
			this->Controls->Add(this->buttonMinus);
			this->Controls->Add(this->buttonPoint);
			this->Controls->Add(this->buttonEquals2);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Answer);
			this->Controls->Add(this->Expression);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximumSize = System::Drawing::Size(779, 455);
			this->MinimumSize = System::Drawing::Size(779, 455);
			this->Name = L"Calculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Scientific Calculator";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Calculator::Calculator_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button0_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"0";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"1";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"2";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"3";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"4";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"5";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"6";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"7";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"8";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"9";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonPoint_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L".";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonPlus_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"+";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonMinus_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"-";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonMultiply_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"*";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonDivision_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"/";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonPower_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"^";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonSqrt_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"sqrt";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonSin_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"sin";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonCos_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"cos";
		Answer->Text = "";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonTg_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"tg";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonCtg_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"ctg";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonLn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"ln";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonAbs_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"abs";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonLeftBracket_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"(";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonRightBracket_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L")";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->Text = L"";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonBackspace_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (Expression->Text->Length >= 3)
		{
			if (Expression->Text->Substring(Expression->Text->Length - 3) == "sin" || Expression->Text->Substring(Expression->Text->Length - 3) == "cos" || Expression->Text->Substring(Expression->Text->Length - 3) == "ctg" || Expression->Text->Substring(Expression->Text->Length - 3) == "abs")
				Expression->Text = Expression->Text->Substring(0, Expression->Text->Length - 3);
			else if (Expression->Text->Substring(Expression->Text->Length - 2) == "tg" || Expression->Text->Substring(Expression->Text->Length - 2) == "ln" || Expression->Text->Substring(Expression->Text->Length - 2) == "pi")
				Expression->Text = Expression->Text->Substring(0, Expression->Text->Length - 2);
			else
				Expression->Text = Expression->Text->Substring(0, Expression->Text->Length - 1);
		}
		else if (Expression->Text->Length >= 2)
		{
			if (Expression->Text->Substring(Expression->Text->Length - 2) == "tg" || Expression->Text->Substring(Expression->Text->Length - 2) == "ln" || Expression->Text->Substring(Expression->Text->Length - 2) == "pi")
				Expression->Text = Expression->Text->Substring(0, Expression->Text->Length - 2);
			else
				Expression->Text = Expression->Text->Substring(0, Expression->Text->Length - 1);
		}
		else if (Expression->Text->Length > 0)
			Expression->Text = Expression->Text->Substring(0, Expression->Text->Length - 1);

		Answer->Text = L"";

		this->ActiveControl = Expression;
	}
	private: System::Void buttonPi_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"pi";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonE_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Expression->SelectedText = L"e";
		Answer->Text = L"";
		this->ActiveControl = Expression;
	}
	private: System::Void buttonEquals1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		using namespace Runtime::InteropServices;

		String^ managedString = Expression->Text;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(managedString)).ToPointer();
		std::string expression = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		try
		{
			Answer->Text = gcnew String(std::to_string(count(expression)).c_str());
		}
		catch (UnexpectedSymbolError& E)
		{
			Answer->Text = L"ОШИБКА";
			MessageBox::Show(gcnew String(E.get_message().c_str()), "", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		this->ActiveControl = Expression;
	}
	private: System::Void buttonEquals2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		using namespace Runtime::InteropServices;

		String^ managedString = Expression->Text;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(managedString)).ToPointer();
		std::string expression = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		try
		{
			Answer->Text = gcnew String(std::to_string(count(expression)).c_str());
		}
		catch (UnexpectedSymbolError& E)
		{
			Answer->Text = L"ОШИБКА";
			MessageBox::Show(gcnew String(E.get_message().c_str()), "", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		this->ActiveControl = Expression;
	}
	private: System::Void Calculator_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode)
		{
		case Keys::Enter:
			buttonEquals1->PerformClick();
			break;
		case Keys::Escape:
			buttonClear->PerformClick();
			break;
		}
	}
};
}
