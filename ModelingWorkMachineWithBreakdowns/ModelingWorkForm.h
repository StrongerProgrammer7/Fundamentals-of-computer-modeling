#pragma once

namespace ModelingWorkMachineWithBreakdowns {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ModelingWorkForm
	/// </summary>
	public ref class ModelingWorkForm : public System::Windows::Forms::Form
	{
	public:
		ModelingWorkForm(void)
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
		~ModelingWorkForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_execution;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tb_TimeExecutionInterval1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tb_TimeExecutionInterval2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tb_TimeExecutionM_X;
	private: System::Windows::Forms::TextBox^ tb_TimeExecutionStandartDeviation;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tb_breakdownM_X;
	private: System::Windows::Forms::TextBox^ tb_breakdownStandartDeviation;
	private: System::Windows::Forms::TextBox^ tb_troubleshootingFrom;
	private: System::Windows::Forms::TextBox^ tb_troubleshootingTo;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ lbl_countTask;
	private: System::Windows::Forms::Label^ lbl_CountBreakdown;
	private: System::Windows::Forms::Label^ lbl_TimeWork;
	private: System::Windows::Forms::Label^ lbl_DetailInQueue;
	private: System::Windows::Forms::Label^ lbl_TotalTimeRepair;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModelingWorkForm::typeid));
			this->btn_execution = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_TimeExecutionInterval1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_TimeExecutionInterval2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tb_TimeExecutionM_X = (gcnew System::Windows::Forms::TextBox());
			this->tb_TimeExecutionStandartDeviation = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tb_breakdownM_X = (gcnew System::Windows::Forms::TextBox());
			this->tb_breakdownStandartDeviation = (gcnew System::Windows::Forms::TextBox());
			this->tb_troubleshootingFrom = (gcnew System::Windows::Forms::TextBox());
			this->tb_troubleshootingTo = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_countTask = (gcnew System::Windows::Forms::Label());
			this->lbl_CountBreakdown = (gcnew System::Windows::Forms::Label());
			this->lbl_TimeWork = (gcnew System::Windows::Forms::Label());
			this->lbl_DetailInQueue = (gcnew System::Windows::Forms::Label());
			this->lbl_TotalTimeRepair = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_execution
			// 
			this->btn_execution->Location = System::Drawing::Point(148, 271);
			this->btn_execution->Name = L"btn_execution";
			this->btn_execution->Size = System::Drawing::Size(272, 23);
			this->btn_execution->TabIndex = 0;
			this->btn_execution->Text = L"Расчитать";
			this->btn_execution->UseVisualStyleBackColor = true;
			this->btn_execution->Click += gcnew System::EventHandler(this, &ModelingWorkForm::Btn_execution_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(561, 80);
			this->label1->TabIndex = 1;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// tb_TimeExecutionInterval1
			// 
			this->tb_TimeExecutionInterval1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_TimeExecutionInterval1->Location = System::Drawing::Point(348, 75);
			this->tb_TimeExecutionInterval1->Name = L"tb_TimeExecutionInterval1";
			this->tb_TimeExecutionInterval1->Size = System::Drawing::Size(28, 13);
			this->tb_TimeExecutionInterval1->TabIndex = 2;
			this->tb_TimeExecutionInterval1->Text = L"0.2";
			this->tb_TimeExecutionInterval1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_TimeExecutionInterval1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_TimeExecutionInterval1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(420, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"ч. Время выполнения задания";
			// 
			// tb_TimeExecutionInterval2
			// 
			this->tb_TimeExecutionInterval2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_TimeExecutionInterval2->Location = System::Drawing::Point(392, 75);
			this->tb_TimeExecutionInterval2->Name = L"tb_TimeExecutionInterval2";
			this->tb_TimeExecutionInterval2->Size = System::Drawing::Size(28, 13);
			this->tb_TimeExecutionInterval2->TabIndex = 4;
			this->tb_TimeExecutionInterval2->Text = L"0.5";
			this->tb_TimeExecutionInterval2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_TimeExecutionInterval2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_TimeExecutionInterval2_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(377, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"-";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(596, 32);
			this->label4->TabIndex = 6;
			this->label4->Text = L"нормально распредлено с математическим ожиданием                    ч и среднеква"
				L"дратичным\r\nотклонением              ч.";
			// 
			// tb_TimeExecutionM_X
			// 
			this->tb_TimeExecutionM_X->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_TimeExecutionM_X->Location = System::Drawing::Point(380, 92);
			this->tb_TimeExecutionM_X->Name = L"tb_TimeExecutionM_X";
			this->tb_TimeExecutionM_X->Size = System::Drawing::Size(56, 13);
			this->tb_TimeExecutionM_X->TabIndex = 7;
			this->tb_TimeExecutionM_X->Text = L"0.5";
			this->tb_TimeExecutionM_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_TimeExecutionM_X->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_TimeExecutionM_X_KeyPress);
			// 
			// tb_TimeExecutionStandartDeviation
			// 
			this->tb_TimeExecutionStandartDeviation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_TimeExecutionStandartDeviation->Location = System::Drawing::Point(107, 108);
			this->tb_TimeExecutionStandartDeviation->Name = L"tb_TimeExecutionStandartDeviation";
			this->tb_TimeExecutionStandartDeviation->Size = System::Drawing::Size(35, 13);
			this->tb_TimeExecutionStandartDeviation->TabIndex = 8;
			this->tb_TimeExecutionStandartDeviation->Text = L"0.1";
			this->tb_TimeExecutionStandartDeviation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_TimeExecutionStandartDeviation->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_TimeExecutionStandartDeviation_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 124);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(590, 144);
			this->label5->TabIndex = 9;
			this->label5->Text = resources->GetString(L"label5.Text");
			// 
			// tb_breakdownM_X
			// 
			this->tb_breakdownM_X->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_breakdownM_X->Location = System::Drawing::Point(157, 158);
			this->tb_breakdownM_X->Name = L"tb_breakdownM_X";
			this->tb_breakdownM_X->Size = System::Drawing::Size(35, 13);
			this->tb_breakdownM_X->TabIndex = 10;
			this->tb_breakdownM_X->Text = L"20";
			this->tb_breakdownM_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_breakdownM_X->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_breakdownM_X_KeyPress);
			// 
			// tb_breakdownStandartDeviation
			// 
			this->tb_breakdownStandartDeviation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_breakdownStandartDeviation->Location = System::Drawing::Point(458, 158);
			this->tb_breakdownStandartDeviation->Name = L"tb_breakdownStandartDeviation";
			this->tb_breakdownStandartDeviation->Size = System::Drawing::Size(35, 13);
			this->tb_breakdownStandartDeviation->TabIndex = 11;
			this->tb_breakdownStandartDeviation->Text = L"2";
			this->tb_breakdownStandartDeviation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_breakdownStandartDeviation->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_breakdownStandartDeviation_KeyPress);
			// 
			// tb_troubleshootingFrom
			// 
			this->tb_troubleshootingFrom->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_troubleshootingFrom->Location = System::Drawing::Point(67, 221);
			this->tb_troubleshootingFrom->Name = L"tb_troubleshootingFrom";
			this->tb_troubleshootingFrom->Size = System::Drawing::Size(35, 13);
			this->tb_troubleshootingFrom->TabIndex = 12;
			this->tb_troubleshootingFrom->Text = L"0.1";
			this->tb_troubleshootingFrom->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_troubleshootingFrom->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_troubleshootingFrom_KeyPress);
			// 
			// tb_troubleshootingTo
			// 
			this->tb_troubleshootingTo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_troubleshootingTo->Location = System::Drawing::Point(122, 221);
			this->tb_troubleshootingTo->Name = L"tb_troubleshootingTo";
			this->tb_troubleshootingTo->Size = System::Drawing::Size(35, 13);
			this->tb_troubleshootingTo->TabIndex = 13;
			this->tb_troubleshootingTo->Text = L"0.5";
			this->tb_troubleshootingTo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_troubleshootingTo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ModelingWorkForm::Tb_troubleshootingTo_KeyPress);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numericUpDown1->Location = System::Drawing::Point(384, 236);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(52, 16);
			this->numericUpDown1->TabIndex = 14;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			// 
			// lbl_countTask
			// 
			this->lbl_countTask->AutoSize = true;
			this->lbl_countTask->Location = System::Drawing::Point(12, 299);
			this->lbl_countTask->Name = L"lbl_countTask";
			this->lbl_countTask->Size = System::Drawing::Size(69, 13);
			this->lbl_countTask->TabIndex = 15;
			this->lbl_countTask->Text = L"label_answer";
			// 
			// lbl_CountBreakdown
			// 
			this->lbl_CountBreakdown->AutoSize = true;
			this->lbl_CountBreakdown->Location = System::Drawing::Point(12, 318);
			this->lbl_CountBreakdown->Name = L"lbl_CountBreakdown";
			this->lbl_CountBreakdown->Size = System::Drawing::Size(69, 13);
			this->lbl_CountBreakdown->TabIndex = 16;
			this->lbl_CountBreakdown->Text = L"label_answer";
			// 
			// lbl_TimeWork
			// 
			this->lbl_TimeWork->AutoSize = true;
			this->lbl_TimeWork->Location = System::Drawing::Point(12, 337);
			this->lbl_TimeWork->Name = L"lbl_TimeWork";
			this->lbl_TimeWork->Size = System::Drawing::Size(69, 13);
			this->lbl_TimeWork->TabIndex = 17;
			this->lbl_TimeWork->Text = L"label_answer";
			// 
			// lbl_DetailInQueue
			// 
			this->lbl_DetailInQueue->AutoSize = true;
			this->lbl_DetailInQueue->Location = System::Drawing::Point(12, 354);
			this->lbl_DetailInQueue->Name = L"lbl_DetailInQueue";
			this->lbl_DetailInQueue->Size = System::Drawing::Size(69, 13);
			this->lbl_DetailInQueue->TabIndex = 18;
			this->lbl_DetailInQueue->Text = L"label_answer";
			// 
			// lbl_TotalTimeRepair
			// 
			this->lbl_TotalTimeRepair->AutoSize = true;
			this->lbl_TotalTimeRepair->Location = System::Drawing::Point(12, 371);
			this->lbl_TotalTimeRepair->Name = L"lbl_TotalTimeRepair";
			this->lbl_TotalTimeRepair->Size = System::Drawing::Size(69, 13);
			this->lbl_TotalTimeRepair->TabIndex = 19;
			this->lbl_TotalTimeRepair->Text = L"label_answer";
			// 
			// ModelingWorkForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 409);
			this->Controls->Add(this->lbl_TotalTimeRepair);
			this->Controls->Add(this->lbl_DetailInQueue);
			this->Controls->Add(this->lbl_TimeWork);
			this->Controls->Add(this->lbl_CountBreakdown);
			this->Controls->Add(this->lbl_countTask);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->tb_troubleshootingTo);
			this->Controls->Add(this->tb_troubleshootingFrom);
			this->Controls->Add(this->tb_breakdownStandartDeviation);
			this->Controls->Add(this->tb_breakdownM_X);
			this->Controls->Add(this->tb_TimeExecutionStandartDeviation);
			this->Controls->Add(this->tb_TimeExecutionM_X);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_TimeExecutionInterval2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb_TimeExecutionInterval1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_execution);
			this->Controls->Add(this->label5);
			this->Name = L"ModelingWorkForm";
			this->Text = L"ModelingWorkForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:  System::Void Btn_execution_Click(System::Object^ sender, System::EventArgs^ e);
			  System::Boolean checkInput(System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_TimeExecutionInterval1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_TimeExecutionInterval2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_TimeExecutionM_X_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_TimeExecutionStandartDeviation_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_breakdownM_X_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_breakdownStandartDeviation_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_troubleshootingFrom_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			  System::Void Tb_troubleshootingTo_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
			 
};
}
