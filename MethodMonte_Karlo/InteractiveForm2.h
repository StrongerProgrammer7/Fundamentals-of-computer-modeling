#pragma once

namespace MethodMonteKarlo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для InteractiveForm2
	/// </summary>
	public ref class InteractiveForm2 : public System::Windows::Forms::Form
	{
	public:
		InteractiveForm2(void)
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
		~InteractiveForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_numVar;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown_CountPoint;
	protected:


	private: System::Windows::Forms::CheckBox^ chb_randUniform;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label_squareSquare;
	private: System::Windows::Forms::Label^ label_squareCicle;
	private: System::Windows::Forms::Label^ label_pi;
	private: System::Windows::Forms::Button^ btn_polar;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label_squareFigure;





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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InteractiveForm2::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->numericUpDown_numVar = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_CountPoint = (gcnew System::Windows::Forms::NumericUpDown());
			this->chb_randUniform = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label_squareSquare = (gcnew System::Windows::Forms::Label());
			this->label_squareCicle = (gcnew System::Windows::Forms::Label());
			this->label_pi = (gcnew System::Windows::Forms::Label());
			this->btn_polar = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_squareFigure = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_numVar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CountPoint))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea1->AxisX->InterlacedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->MajorGrid->Enabled = false;
			chartArea1->AxisX->MinorTickMark->Enabled = true;
			chartArea1->AxisX->MinorTickMark->TickMarkStyle = System::Windows::Forms::DataVisualization::Charting::TickMarkStyle::AcrossAxis;
			chartArea1->AxisX->Title = L"X";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->MajorGrid->Enabled = false;
			chartArea1->AxisY->MinorTickMark->Enabled = true;
			chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea1->AxisY->Title = L"Y";
			chartArea1->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->CursorX->Interval = 0.2;
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->CursorY->Interval = 0.2;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->CursorY->LineColor = System::Drawing::Color::Cyan;
			chartArea1->Name = L"ChartArea1";
			chartArea2->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea2->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisX->MinorTickMark->Enabled = true;
			chartArea2->AxisX->Title = L"Х";
			chartArea2->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea2->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea2->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisY->MinorTickMark->Enabled = true;
			chartArea2->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea2->AxisY->Title = L"У";
			chartArea2->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea2->CursorX->Interval = 0.2;
			chartArea2->CursorX->IsUserEnabled = true;
			chartArea2->CursorX->IsUserSelectionEnabled = true;
			chartArea2->CursorY->Interval = 0.2;
			chartArea2->CursorY->IsUserEnabled = true;
			chartArea2->CursorY->IsUserSelectionEnabled = true;
			chartArea2->Name = L"ChartArea2";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->ChartAreas->Add(chartArea2);
			legend1->HeaderSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::Line;
			legend1->Name = L"Legend1";
			legend1->Title = L"Cicle";
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DoubleLine;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 11);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Квадрат";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Purple;
			series2->Legend = L"Legend1";
			series2->Name = L"Круг";
			series2->YValuesPerPoint = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series3->Legend = L"Legend1";
			series3->MarkerColor = System::Drawing::Color::Brown;
			series3->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series3->Name = L"Точки снаружи";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series4->Color = System::Drawing::Color::Green;
			series4->Legend = L"Legend1";
			series4->MarkerSize = 7;
			series4->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series4->Name = L"Точки внутри";
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea2";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Color = System::Drawing::Color::Navy;
			series5->Legend = L"Legend1";
			series5->Name = L"Полярные";
			series6->ChartArea = L"ChartArea2";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series6->Legend = L"Legend1";
			series6->MarkerColor = System::Drawing::Color::Green;
			series6->MarkerSize = 7;
			series6->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series6->Name = L"Точки внутри-2";
			series7->ChartArea = L"ChartArea2";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series7->Legend = L"Legend1";
			series7->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series7->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series7->Name = L"Точки снаружи-2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Series->Add(series7);
			this->chart1->Size = System::Drawing::Size(865, 437);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// numericUpDown_numVar
			// 
			this->numericUpDown_numVar->Location = System::Drawing::Point(980, 404);
			this->numericUpDown_numVar->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown_numVar->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_numVar->Name = L"numericUpDown_numVar";
			this->numericUpDown_numVar->Size = System::Drawing::Size(41, 20);
			this->numericUpDown_numVar->TabIndex = 1;
			this->numericUpDown_numVar->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numericUpDown_CountPoint
			// 
			this->numericUpDown_CountPoint->Location = System::Drawing::Point(1055, 404);
			this->numericUpDown_CountPoint->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numericUpDown_CountPoint->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_CountPoint->Name = L"numericUpDown_CountPoint";
			this->numericUpDown_CountPoint->Size = System::Drawing::Size(98, 20);
			this->numericUpDown_CountPoint->TabIndex = 2;
			this->numericUpDown_CountPoint->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// chb_randUniform
			// 
			this->chb_randUniform->AutoSize = true;
			this->chb_randUniform->Location = System::Drawing::Point(980, 436);
			this->chb_randUniform->Name = L"chb_randUniform";
			this->chb_randUniform->Size = System::Drawing::Size(176, 17);
			this->chb_randUniform->TabIndex = 3;
			this->chb_randUniform->Text = L"Равномерное распределение";
			this->chb_randUniform->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(977, 384);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Вариант:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1091, 384);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"N";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(920, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 56);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Вычислить площадь круга";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &InteractiveForm2::Button1_Click);
			// 
			// label_squareSquare
			// 
			this->label_squareSquare->AutoSize = true;
			this->label_squareSquare->Location = System::Drawing::Point(884, 13);
			this->label_squareSquare->Name = L"label_squareSquare";
			this->label_squareSquare->Size = System::Drawing::Size(104, 13);
			this->label_squareSquare->TabIndex = 7;
			this->label_squareSquare->Text = L"Площадь квадрата";
			// 
			// label_squareCicle
			// 
			this->label_squareCicle->AutoSize = true;
			this->label_squareCicle->Location = System::Drawing::Point(883, 35);
			this->label_squareCicle->Name = L"label_squareCicle";
			this->label_squareCicle->Size = System::Drawing::Size(85, 13);
			this->label_squareCicle->TabIndex = 8;
			this->label_squareCicle->Text = L"Площадь круга";
			this->label_squareCicle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_pi
			// 
			this->label_pi->AutoSize = true;
			this->label_pi->Location = System::Drawing::Point(884, 59);
			this->label_pi->Name = L"label_pi";
			this->label_pi->Size = System::Drawing::Size(23, 13);
			this->label_pi->TabIndex = 9;
			this->label_pi->Text = L"ПИ";
			this->label_pi->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// btn_polar
			// 
			this->btn_polar->Location = System::Drawing::Point(930, 236);
			this->btn_polar->Name = L"btn_polar";
			this->btn_polar->Size = System::Drawing::Size(196, 49);
			this->btn_polar->TabIndex = 10;
			this->btn_polar->Text = L"Вычислить полярные координаты";
			this->btn_polar->UseVisualStyleBackColor = true;
			this->btn_polar->Click += gcnew System::EventHandler(this, &InteractiveForm2::Btn_polar_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(894, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"ПИ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_squareFigure
			// 
			this->label_squareFigure->AutoSize = true;
			this->label_squareFigure->Location = System::Drawing::Point(894, 164);
			this->label_squareFigure->Name = L"label_squareFigure";
			this->label_squareFigure->Size = System::Drawing::Size(104, 13);
			this->label_squareFigure->TabIndex = 11;
			this->label_squareFigure->Text = L"Площадь квадрата";
			// 
			// InteractiveForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1165, 460);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label_squareFigure);
			this->Controls->Add(this->btn_polar);
			this->Controls->Add(this->label_pi);
			this->Controls->Add(this->label_squareCicle);
			this->Controls->Add(this->label_squareSquare);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chb_randUniform);
			this->Controls->Add(this->numericUpDown_CountPoint);
			this->Controls->Add(this->numericUpDown_numVar);
			this->Controls->Add(this->chart1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InteractiveForm2";
			this->Text = L"Площадь круга и полярные координаты";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_numVar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CountPoint))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e);
			 void clearInteractiveElementChartArea1();
private: System::Void Btn_polar_Click(System::Object^ sender, System::EventArgs^ e);
};
}
