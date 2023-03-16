#pragma once

namespace MethodsGenerationNumber {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GenerationForm
	/// </summary>
	public ref class GenerationForm : public System::Windows::Forms::Form
	{
	public:
		GenerationForm(void)
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
		~GenerationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::Button^ btn_squre;
	private: System::Windows::Forms::TextBox^ tb_numb;
	private: System::Windows::Forms::Button^ btn_mult;
	private: System::Windows::Forms::Button^ btn_linearCongruentMethod;


	private: System::Windows::Forms::NumericUpDown^ numeric_countPoint;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tb_numb2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ btn_clear;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GenerationForm::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btn_squre = (gcnew System::Windows::Forms::Button());
			this->tb_numb = (gcnew System::Windows::Forms::TextBox());
			this->btn_mult = (gcnew System::Windows::Forms::Button());
			this->btn_linearCongruentMethod = (gcnew System::Windows::Forms::Button());
			this->numeric_countPoint = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_numb2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btn_clear = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countPoint))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::SkyBlue;
			chartArea2->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea2->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisX->IsMarginVisible = false;
			chartArea2->AxisX->MajorGrid->Enabled = false;
			chartArea2->AxisX->MajorTickMark->Enabled = false;
			chartArea2->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisY->LabelStyle->Format = L"0";
			chartArea2->AxisY->MajorGrid->Interval = 0;
			chartArea2->AxisY->MajorGrid->IntervalOffset = 0;
			chartArea2->AxisY->MaximumAutoSize = 100;
			chartArea2->AxisY->Minimum = 0;
			chartArea2->AxisY->Title = L"Количество";
			chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->BackColor = System::Drawing::Color::Transparent;
			legend2->DockedToChartArea = L"ChartArea1";
			legend2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend2->IsTextAutoFit = false;
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series4->ChartArea = L"ChartArea1";
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series4->IsValueShownAsLabel = true;
			series4->Legend = L"Legend1";
			series4->Name = L"Метод серидинных отрезков";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series4->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			series5->ChartArea = L"ChartArea1";
			series5->Color = System::Drawing::Color::Red;
			series5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series5->IsValueShownAsLabel = true;
			series5->Legend = L"Legend1";
			series5->Name = L"Метод произведений";
			series5->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series5->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			series6->ChartArea = L"ChartArea1";
			series6->Color = System::Drawing::Color::Indigo;
			series6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series6->IsValueShownAsLabel = true;
			series6->Legend = L"Legend1";
			series6->Name = L"Конгруэтный метод";
			series6->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series6->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Size = System::Drawing::Size(734, 345);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// btn_squre
			// 
			this->btn_squre->Location = System::Drawing::Point(12, 363);
			this->btn_squre->Name = L"btn_squre";
			this->btn_squre->Size = System::Drawing::Size(174, 23);
			this->btn_squre->TabIndex = 1;
			this->btn_squre->Text = L"Метод серидинных квадратов";
			this->btn_squre->UseVisualStyleBackColor = true;
			this->btn_squre->Click += gcnew System::EventHandler(this, &GenerationForm::Btn_squre_Click);
			// 
			// tb_numb
			// 
			this->tb_numb->Location = System::Drawing::Point(230, 379);
			this->tb_numb->Name = L"tb_numb";
			this->tb_numb->Size = System::Drawing::Size(57, 20);
			this->tb_numb->TabIndex = 2;
			this->tb_numb->Text = L"7153";
			this->tb_numb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_mult
			// 
			this->btn_mult->Location = System::Drawing::Point(398, 363);
			this->btn_mult->Name = L"btn_mult";
			this->btn_mult->Size = System::Drawing::Size(164, 23);
			this->btn_mult->TabIndex = 3;
			this->btn_mult->Text = L"Метод произведений";
			this->btn_mult->UseVisualStyleBackColor = true;
			this->btn_mult->Click += gcnew System::EventHandler(this, &GenerationForm::Btn_mult_Click);
			// 
			// btn_linearCongruentMethod
			// 
			this->btn_linearCongruentMethod->Location = System::Drawing::Point(580, 363);
			this->btn_linearCongruentMethod->Name = L"btn_linearCongruentMethod";
			this->btn_linearCongruentMethod->Size = System::Drawing::Size(166, 41);
			this->btn_linearCongruentMethod->TabIndex = 4;
			this->btn_linearCongruentMethod->Text = L"Линейный конгруэнтный метод";
			this->btn_linearCongruentMethod->UseVisualStyleBackColor = true;
			this->btn_linearCongruentMethod->Click += gcnew System::EventHandler(this, &GenerationForm::Btn_linearCongruentMethod_Click);
			// 
			// numeric_countPoint
			// 
			this->numeric_countPoint->Location = System::Drawing::Point(62, 406);
			this->numeric_countPoint->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numeric_countPoint->Name = L"numeric_countPoint";
			this->numeric_countPoint->Size = System::Drawing::Size(62, 20);
			this->numeric_countPoint->TabIndex = 6;
			this->numeric_countPoint->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(192, 363);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Начальное значение R0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 389);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Кол-во точек";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(192, 399);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Начальное значение R1";
			// 
			// tb_numb2
			// 
			this->tb_numb2->Location = System::Drawing::Point(230, 415);
			this->tb_numb2->Name = L"tb_numb2";
			this->tb_numb2->Size = System::Drawing::Size(57, 20);
			this->tb_numb2->TabIndex = 9;
			this->tb_numb2->Text = L"3729";
			this->tb_numb2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(293, 420);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Делитель";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(348, 394);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(315, 39);
			this->label5->TabIndex = 12;
			this->label5->Text = resources->GetString(L"label5.Text");
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(319, 375);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(168, 39);
			this->label6->TabIndex = 13;
			this->label6->Text = L"                                                     |\r\n                         "
				L"                            |\r\n<------------------------------------------------"
				L"---";
			// 
			// btn_clear
			// 
			this->btn_clear->Location = System::Drawing::Point(688, 412);
			this->btn_clear->Name = L"btn_clear";
			this->btn_clear->Size = System::Drawing::Size(75, 23);
			this->btn_clear->TabIndex = 14;
			this->btn_clear->Text = L"Очистить";
			this->btn_clear->UseVisualStyleBackColor = true;
			this->btn_clear->Click += gcnew System::EventHandler(this, &GenerationForm::Btn_clear_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(752, 41);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(83, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Мат ожидание:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(752, 12);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(47, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Методы";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(837, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(53, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Методы1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(952, 9);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(53, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Методы2";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1035, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Методы3";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(752, 66);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(67, 13);
			this->label12->TabIndex = 20;
			this->label12->Text = L"Дисперсия:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(752, 97);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(176, 13);
			this->label13->TabIndex = 21;
			this->label13->Text = L"Среднеквадратичное отклонение";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(752, 132);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(149, 13);
			this->label14->TabIndex = 22;
			this->label14->Text = L"Интервал частотного теста:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(797, 163);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 23;
			// 
			// GenerationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(1100, 436);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btn_clear);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_numb2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numeric_countPoint);
			this->Controls->Add(this->btn_linearCongruentMethod);
			this->Controls->Add(this->btn_mult);
			this->Controls->Add(this->tb_numb);
			this->Controls->Add(this->btn_squre);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"GenerationForm";
			this->Text = L"GenerationForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countPoint))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Btn_squre_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void fillChart(int series,int* countPointsInDiapason);
			 System::Void clearChart(int series);
			 System::Void Btn_mult_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Btn_linearCongruentMethod_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Btn_clear_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void fillChart(int series, int count);
			 void fillDiagram(int series, int* countPointsInDiapason);
};
}
