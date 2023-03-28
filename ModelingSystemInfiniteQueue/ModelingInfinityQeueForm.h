#pragma once

namespace ModelingSystemInfiniteQueue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ModelingInfinityQeueForm
	/// </summary>
	public ref class ModelingInfinityQeueForm : public System::Windows::Forms::Form
	{
	public:
		ModelingInfinityQeueForm(void)
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
		~ModelingInfinityQeueForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ tb_startInteervalGetTask;
	private: System::Windows::Forms::TextBox^ tb_endInteervalGetTask;
	private: System::Windows::Forms::TextBox^ tb_probabilityGetTaskFirst;
	private: System::Windows::Forms::TextBox^ tb_probabilityGetTaskSecond;

	private: System::Windows::Forms::TextBox^ tb_probabilityGetTaskSecondAfterFirst;
	private: System::Windows::Forms::TextBox^ tb_probabilityGetTaskThirdAfterFirst;
	private: System::Windows::Forms::TextBox^ tb_startTimeExecutionFirst;
	private: System::Windows::Forms::TextBox^ tb_endTimeExecutionFirst;
	private: System::Windows::Forms::TextBox^ tb_startTimeExecutionSecond;
	private: System::Windows::Forms::TextBox^ tb_endTimeExecutionSecond;
	private: System::Windows::Forms::TextBox^ tb_startTimeExecutionThird;
	private: System::Windows::Forms::TextBox^ tb_endTimeExecutionThird;
	private: System::Windows::Forms::Button^ btn_exectuion;
	private: System::Windows::Forms::Label^ lbl_total;

	private: System::Windows::Forms::Label^ lbl_FirstPC;
	private: System::Windows::Forms::Label^ lbl_SecondPC;
	private: System::Windows::Forms::Label^ lbl_ThirdPC;







	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModelingInfinityQeueForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->tb_startInteervalGetTask = (gcnew System::Windows::Forms::TextBox());
			this->tb_endInteervalGetTask = (gcnew System::Windows::Forms::TextBox());
			this->tb_probabilityGetTaskFirst = (gcnew System::Windows::Forms::TextBox());
			this->tb_probabilityGetTaskSecond = (gcnew System::Windows::Forms::TextBox());
			this->tb_probabilityGetTaskSecondAfterFirst = (gcnew System::Windows::Forms::TextBox());
			this->tb_probabilityGetTaskThirdAfterFirst = (gcnew System::Windows::Forms::TextBox());
			this->tb_startTimeExecutionFirst = (gcnew System::Windows::Forms::TextBox());
			this->tb_endTimeExecutionFirst = (gcnew System::Windows::Forms::TextBox());
			this->tb_startTimeExecutionSecond = (gcnew System::Windows::Forms::TextBox());
			this->tb_endTimeExecutionSecond = (gcnew System::Windows::Forms::TextBox());
			this->tb_startTimeExecutionThird = (gcnew System::Windows::Forms::TextBox());
			this->tb_endTimeExecutionThird = (gcnew System::Windows::Forms::TextBox());
			this->btn_exectuion = (gcnew System::Windows::Forms::Button());
			this->lbl_total = (gcnew System::Windows::Forms::Label());
			this->lbl_FirstPC = (gcnew System::Windows::Forms::Label());
			this->lbl_SecondPC = (gcnew System::Windows::Forms::Label());
			this->lbl_ThirdPC = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(154, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(820, 147);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(154, 165);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(729, 42);
			this->label2->TabIndex = 1;
			this->label2->Text = L"   Продолжительность обработки заданий на разных ЭВМ характеризуется интервалами\r"
				L"\nвремени: Т1 = (          ,            ) мин, Т2 = (           ,           ) мин"
				L". Т3 = (           ,           ) мин.\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(154, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(198, 21);
			this->label3->TabIndex = 2;
			this->label3->Text = L"   Количество заданий: ";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->numericUpDown1->Location = System::Drawing::Point(351, 230);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(64, 21);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			// 
			// tb_startInteervalGetTask
			// 
			this->tb_startInteervalGetTask->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_startInteervalGetTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_startInteervalGetTask->Location = System::Drawing::Point(697, 14);
			this->tb_startInteervalGetTask->Name = L"tb_startInteervalGetTask";
			this->tb_startInteervalGetTask->Size = System::Drawing::Size(41, 14);
			this->tb_startInteervalGetTask->TabIndex = 4;
			this->tb_startInteervalGetTask->Text = L"2";
			this->tb_startInteervalGetTask->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_startInteervalGetTask->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_startInteervalGetTask_KeyPress);
			// 
			// tb_endInteervalGetTask
			// 
			this->tb_endInteervalGetTask->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_endInteervalGetTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_endInteervalGetTask->Location = System::Drawing::Point(753, 14);
			this->tb_endInteervalGetTask->Name = L"tb_endInteervalGetTask";
			this->tb_endInteervalGetTask->Size = System::Drawing::Size(41, 14);
			this->tb_endInteervalGetTask->TabIndex = 5;
			this->tb_endInteervalGetTask->Text = L"4";
			this->tb_endInteervalGetTask->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_endInteervalGetTask->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_endInteervalGetTask_KeyPress);
			// 
			// tb_probabilityGetTaskFirst
			// 
			this->tb_probabilityGetTaskFirst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_probabilityGetTaskFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_probabilityGetTaskFirst->Location = System::Drawing::Point(570, 33);
			this->tb_probabilityGetTaskFirst->Name = L"tb_probabilityGetTaskFirst";
			this->tb_probabilityGetTaskFirst->Size = System::Drawing::Size(52, 14);
			this->tb_probabilityGetTaskFirst->TabIndex = 6;
			this->tb_probabilityGetTaskFirst->Text = L"0.4";
			this->tb_probabilityGetTaskFirst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_probabilityGetTaskFirst->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_probabilityGetTaskFirst_KeyPress);
			// 
			// tb_probabilityGetTaskSecond
			// 
			this->tb_probabilityGetTaskSecond->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_probabilityGetTaskSecond->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_probabilityGetTaskSecond->Location = System::Drawing::Point(855, 33);
			this->tb_probabilityGetTaskSecond->Name = L"tb_probabilityGetTaskSecond";
			this->tb_probabilityGetTaskSecond->Size = System::Drawing::Size(52, 14);
			this->tb_probabilityGetTaskSecond->TabIndex = 7;
			this->tb_probabilityGetTaskSecond->Text = L"0.3";
			this->tb_probabilityGetTaskSecond->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_probabilityGetTaskSecond->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_probabilityGetTaskSecond_KeyPress);
			// 
			// tb_probabilityGetTaskSecondAfterFirst
			// 
			this->tb_probabilityGetTaskSecondAfterFirst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_probabilityGetTaskSecondAfterFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_probabilityGetTaskSecondAfterFirst->Location = System::Drawing::Point(463, 97);
			this->tb_probabilityGetTaskSecondAfterFirst->Name = L"tb_probabilityGetTaskSecondAfterFirst";
			this->tb_probabilityGetTaskSecondAfterFirst->Size = System::Drawing::Size(39, 14);
			this->tb_probabilityGetTaskSecondAfterFirst->TabIndex = 9;
			this->tb_probabilityGetTaskSecondAfterFirst->Text = L"0.3";
			this->tb_probabilityGetTaskSecondAfterFirst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_probabilityGetTaskSecondAfterFirst->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_probabilityGetTaskSecondAfterFirst_KeyPress);
			// 
			// tb_probabilityGetTaskThirdAfterFirst
			// 
			this->tb_probabilityGetTaskThirdAfterFirst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_probabilityGetTaskThirdAfterFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_probabilityGetTaskThirdAfterFirst->Location = System::Drawing::Point(191, 118);
			this->tb_probabilityGetTaskThirdAfterFirst->Name = L"tb_probabilityGetTaskThirdAfterFirst";
			this->tb_probabilityGetTaskThirdAfterFirst->Size = System::Drawing::Size(39, 14);
			this->tb_probabilityGetTaskThirdAfterFirst->TabIndex = 10;
			this->tb_probabilityGetTaskThirdAfterFirst->Text = L"0.7";
			this->tb_probabilityGetTaskThirdAfterFirst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_probabilityGetTaskThirdAfterFirst->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_probabilityGetTaskThirdAfterFirst_KeyPress);
			// 
			// tb_startTimeExecutionFirst
			// 
			this->tb_startTimeExecutionFirst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_startTimeExecutionFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_startTimeExecutionFirst->Location = System::Drawing::Point(285, 190);
			this->tb_startTimeExecutionFirst->Name = L"tb_startTimeExecutionFirst";
			this->tb_startTimeExecutionFirst->Size = System::Drawing::Size(41, 14);
			this->tb_startTimeExecutionFirst->TabIndex = 11;
			this->tb_startTimeExecutionFirst->Text = L"3";
			this->tb_startTimeExecutionFirst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_startTimeExecutionFirst->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_startTimeExecutionFirst_KeyPress);
			// 
			// tb_endTimeExecutionFirst
			// 
			this->tb_endTimeExecutionFirst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_endTimeExecutionFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_endTimeExecutionFirst->Location = System::Drawing::Point(350, 190);
			this->tb_endTimeExecutionFirst->Name = L"tb_endTimeExecutionFirst";
			this->tb_endTimeExecutionFirst->Size = System::Drawing::Size(41, 14);
			this->tb_endTimeExecutionFirst->TabIndex = 12;
			this->tb_endTimeExecutionFirst->Text = L"5";
			this->tb_endTimeExecutionFirst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_endTimeExecutionFirst->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_endTimeExecutionFirst_KeyPress);
			// 
			// tb_startTimeExecutionSecond
			// 
			this->tb_startTimeExecutionSecond->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_startTimeExecutionSecond->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_startTimeExecutionSecond->Location = System::Drawing::Point(500, 190);
			this->tb_startTimeExecutionSecond->Name = L"tb_startTimeExecutionSecond";
			this->tb_startTimeExecutionSecond->Size = System::Drawing::Size(41, 14);
			this->tb_startTimeExecutionSecond->TabIndex = 13;
			this->tb_startTimeExecutionSecond->Text = L"2";
			this->tb_startTimeExecutionSecond->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_startTimeExecutionSecond->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_startTimeExecutionSecond_KeyPress);
			// 
			// tb_endTimeExecutionSecond
			// 
			this->tb_endTimeExecutionSecond->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_endTimeExecutionSecond->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_endTimeExecutionSecond->Location = System::Drawing::Point(570, 190);
			this->tb_endTimeExecutionSecond->Name = L"tb_endTimeExecutionSecond";
			this->tb_endTimeExecutionSecond->Size = System::Drawing::Size(41, 14);
			this->tb_endTimeExecutionSecond->TabIndex = 14;
			this->tb_endTimeExecutionSecond->Text = L"4";
			this->tb_endTimeExecutionSecond->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_endTimeExecutionSecond->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_endTimeExecutionSecond_KeyPress);
			// 
			// tb_startTimeExecutionThird
			// 
			this->tb_startTimeExecutionThird->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_startTimeExecutionThird->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_startTimeExecutionThird->Location = System::Drawing::Point(721, 190);
			this->tb_startTimeExecutionThird->Name = L"tb_startTimeExecutionThird";
			this->tb_startTimeExecutionThird->Size = System::Drawing::Size(41, 14);
			this->tb_startTimeExecutionThird->TabIndex = 15;
			this->tb_startTimeExecutionThird->Text = L"3";
			this->tb_startTimeExecutionThird->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_startTimeExecutionThird->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_startTimeExecutionThird_KeyPress);
			// 
			// tb_endTimeExecutionThird
			// 
			this->tb_endTimeExecutionThird->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_endTimeExecutionThird->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->tb_endTimeExecutionThird->Location = System::Drawing::Point(782, 190);
			this->tb_endTimeExecutionThird->Name = L"tb_endTimeExecutionThird";
			this->tb_endTimeExecutionThird->Size = System::Drawing::Size(41, 14);
			this->tb_endTimeExecutionThird->TabIndex = 16;
			this->tb_endTimeExecutionThird->Text = L"7";
			this->tb_endTimeExecutionThird->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_endTimeExecutionThird->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingInfinityQeueForm::Tb_endTimeExecutionThird_KeyPress);
			// 
			// btn_exectuion
			// 
			this->btn_exectuion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_exectuion->Location = System::Drawing::Point(558, 223);
			this->btn_exectuion->Name = L"btn_exectuion";
			this->btn_exectuion->Size = System::Drawing::Size(204, 47);
			this->btn_exectuion->TabIndex = 17;
			this->btn_exectuion->Text = L"Провести вычисления";
			this->btn_exectuion->UseVisualStyleBackColor = true;
			this->btn_exectuion->Click += gcnew System::EventHandler(this, &ModelingInfinityQeueForm::Btn_exectuion_Click);
			// 
			// lbl_total
			// 
			this->lbl_total->AutoSize = true;
			this->lbl_total->Location = System::Drawing::Point(9, 284);
			this->lbl_total->Name = L"lbl_total";
			this->lbl_total->Size = System::Drawing::Size(61, 13);
			this->lbl_total->TabIndex = 18;
			this->lbl_total->Text = L"Total report";
			// 
			// lbl_FirstPC
			// 
			this->lbl_FirstPC->AutoSize = true;
			this->lbl_FirstPC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_FirstPC->Location = System::Drawing::Point(282, 300);
			this->lbl_FirstPC->Name = L"lbl_FirstPC";
			this->lbl_FirstPC->Size = System::Drawing::Size(54, 15);
			this->lbl_FirstPC->TabIndex = 19;
			this->lbl_FirstPC->Text = L"Report 1";
			// 
			// lbl_SecondPC
			// 
			this->lbl_SecondPC->AutoSize = true;
			this->lbl_SecondPC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_SecondPC->Location = System::Drawing::Point(559, 300);
			this->lbl_SecondPC->Name = L"lbl_SecondPC";
			this->lbl_SecondPC->Size = System::Drawing::Size(54, 15);
			this->lbl_SecondPC->TabIndex = 20;
			this->lbl_SecondPC->Text = L"Report 2";
			// 
			// lbl_ThirdPC
			// 
			this->lbl_ThirdPC->AutoSize = true;
			this->lbl_ThirdPC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_ThirdPC->Location = System::Drawing::Point(861, 300);
			this->lbl_ThirdPC->Name = L"lbl_ThirdPC";
			this->lbl_ThirdPC->Size = System::Drawing::Size(54, 15);
			this->lbl_ThirdPC->TabIndex = 21;
			this->lbl_ThirdPC->Text = L"Report 3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(301, 278);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"1 ЭВМ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(595, 278);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 26;
			this->label5->Text = L"2 ЭВМ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(877, 278);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 13);
			this->label6->TabIndex = 27;
			this->label6->Text = L"3 ЭВМ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(43, 262);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(83, 13);
			this->label7->TabIndex = 28;
			this->label7->Text = L"Общие данные";
			// 
			// ModelingInfinityQeueForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(1184, 545);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbl_ThirdPC);
			this->Controls->Add(this->lbl_SecondPC);
			this->Controls->Add(this->lbl_FirstPC);
			this->Controls->Add(this->lbl_total);
			this->Controls->Add(this->btn_exectuion);
			this->Controls->Add(this->tb_endTimeExecutionThird);
			this->Controls->Add(this->tb_startTimeExecutionThird);
			this->Controls->Add(this->tb_endTimeExecutionSecond);
			this->Controls->Add(this->tb_startTimeExecutionSecond);
			this->Controls->Add(this->tb_endTimeExecutionFirst);
			this->Controls->Add(this->tb_startTimeExecutionFirst);
			this->Controls->Add(this->tb_probabilityGetTaskThirdAfterFirst);
			this->Controls->Add(this->tb_probabilityGetTaskSecondAfterFirst);
			this->Controls->Add(this->tb_probabilityGetTaskSecond);
			this->Controls->Add(this->tb_probabilityGetTaskFirst);
			this->Controls->Add(this->tb_endInteervalGetTask);
			this->Controls->Add(this->tb_startInteervalGetTask);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ModelingInfinityQeueForm";
			this->Text = L"ModelingInfinityQeueForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			System::Void setTextForLabelEveryMachine(System::Windows::Forms::Label^ curLabel, int const& totalTimeExectuionTasksCurPC, int const& totalTimeWaitCurPC,int const& totalTimeQueueCurPC, int const& maxCountTaskInQueueCurPC,int const& maxTimeCurrentQueueCurPC, int const& completeTask, int const& countTaskInQueueAfterTask, int const& countQueue);
			System::Void Tb_startInteervalGetTask_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_endInteervalGetTask_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_probabilityGetTaskSecond_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_probabilityGetTaskSecondAfterFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_probabilityGetTaskThirdAfterFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_startTimeExecutionFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_endTimeExecutionFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_startTimeExecutionSecond_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_endTimeExecutionSecond_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_startTimeExecutionThird_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Tb_endTimeExecutionThird_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			System::Boolean checkInput(System::Windows::Forms::KeyPressEventArgs^ e);
			System::Void Btn_exectuion_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void Tb_probabilityGetTaskFirst_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
		 
};
}
