#pragma once

namespace LeastSquareMethod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для InteractiveForm
	/// </summary>
	public ref class InteractiveForm : public System::Windows::Forms::Form
	{
	public:
		InteractiveForm(void)
		{
			InitializeComponent();
			this->table_values->RowCount = 2;
			this->table_values->ColumnCount = 6;
			this->table_values->Rows[0]->HeaderCell->Value = "X";
			this->table_values->Rows[1]->HeaderCell->Value = "Y";
			//Fill default
			this->table_values->Rows[0]->Cells[0]->Value = 2;
			this->table_values->Rows[0]->Cells[1]->Value = 3;
			this->table_values->Rows[0]->Cells[2]->Value = 4;
			this->table_values->Rows[0]->Cells[3]->Value = 5;
			this->table_values->Rows[0]->Cells[4]->Value = 6;
			this->table_values->Rows[0]->Cells[5]->Value = 7;
			
			this->table_values->Rows[1]->Cells[0]->Value = 100;
			this->table_values->Rows[1]->Cells[1]->Value = 190;
			this->table_values->Rows[1]->Cells[2]->Value = 270;
			this->table_values->Rows[1]->Cells[3]->Value = 400;
			this->table_values->Rows[1]->Cells[4]->Value = 500;
			this->table_values->Rows[1]->Cells[5]->Value = 690;

			//Fill table coefficient
			this->dGV_coefficients->RowCount = 4;
			this->dGV_coefficients->Rows[0]->HeaderCell->Value = "Линейная ";
			this->dGV_coefficients->Rows[1]->HeaderCell->Value = "Степенная ";
			this->dGV_coefficients->Rows[2]->HeaderCell->Value = "Экспонен-я";
			this->dGV_coefficients->Rows[3]->HeaderCell->Value = "Квадрат-я";

			
		}
		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~InteractiveForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::DataGridView^ table_values;

	private: System::Windows::Forms::Button^ btn_action;
	private: System::Windows::Forms::Button^ btn_random;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label_sumFaultLinear;
	private: System::Windows::Forms::Label^ label_sumFaultPower;
	private: System::Windows::Forms::Label^ label_sumFaultExponent;
	private: System::Windows::Forms::Label^ label_sumFaultSquare;

	private: System::Windows::Forms::Label^ label_bestFunc;
	private: System::Windows::Forms::DataGridView^ dGV_coefficients;


	private: System::Windows::Forms::Label^ label_X;
	private: System::Windows::Forms::Label^ label_Y;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_a;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_b;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c;



	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InteractiveForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->table_values = (gcnew System::Windows::Forms::DataGridView());
			this->btn_action = (gcnew System::Windows::Forms::Button());
			this->btn_random = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label_sumFaultLinear = (gcnew System::Windows::Forms::Label());
			this->label_sumFaultPower = (gcnew System::Windows::Forms::Label());
			this->label_sumFaultExponent = (gcnew System::Windows::Forms::Label());
			this->label_sumFaultSquare = (gcnew System::Windows::Forms::Label());
			this->label_bestFunc = (gcnew System::Windows::Forms::Label());
			this->dGV_coefficients = (gcnew System::Windows::Forms::DataGridView());
			this->label_X = (gcnew System::Windows::Forms::Label());
			this->label_Y = (gcnew System::Windows::Forms::Label());
			this->col_a = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_b = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dGV_coefficients))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::Color::Red;
			this->btn_close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_close->ForeColor = System::Drawing::Color::White;
			this->btn_close->Location = System::Drawing::Point(718, 12);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(45, 31);
			this->btn_close->TabIndex = 0;
			this->btn_close->Text = L"X";
			this->btn_close->UseVisualStyleBackColor = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &InteractiveForm::Btn_close_Click);
			// 
			// table_values
			// 
			this->table_values->AllowUserToAddRows = false;
			this->table_values->AllowUserToDeleteRows = false;
			this->table_values->AllowUserToResizeColumns = false;
			this->table_values->AllowUserToResizeRows = false;
			this->table_values->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->table_values->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->table_values->BackgroundColor = System::Drawing::SystemColors::ControlDark;
			this->table_values->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->table_values->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table_values->Location = System::Drawing::Point(12, 12);
			this->table_values->Name = L"table_values";
			this->table_values->RowHeadersWidth = 50;
			this->table_values->Size = System::Drawing::Size(227, 76);
			this->table_values->TabIndex = 1;
			// 
			// btn_action
			// 
			this->btn_action->Location = System::Drawing::Point(18, 94);
			this->btn_action->Name = L"btn_action";
			this->btn_action->Size = System::Drawing::Size(210, 23);
			this->btn_action->TabIndex = 2;
			this->btn_action->Text = L"Вычислить и построить график";
			this->btn_action->UseVisualStyleBackColor = true;
			this->btn_action->Click += gcnew System::EventHandler(this, &InteractiveForm::Btn_action_Click);
			// 
			// btn_random
			// 
			this->btn_random->Location = System::Drawing::Point(245, 12);
			this->btn_random->Name = L"btn_random";
			this->btn_random->Size = System::Drawing::Size(109, 76);
			this->btn_random->TabIndex = 3;
			this->btn_random->Text = L"Заполнить числами";
			this->btn_random->UseVisualStyleBackColor = true;
			this->btn_random->Click += gcnew System::EventHandler(this, &InteractiveForm::Btn_random_Click);
			// 
			// chart1
			// 
			this->chart1->AllowDrop = true;
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			chartArea1->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea1->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->LabelStyle->Interval = 0;
			chartArea1->AxisX->MaximumAutoSize = 100;
			chartArea1->AxisX->Title = L"X";
			chartArea1->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->MaximumAutoSize = 100;
			chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea1->AxisY->Title = L"Y";
			chartArea1->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea1->CursorX->LineWidth = 2;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->CursorY->LineColor = System::Drawing::Color::Coral;
			chartArea1->CursorY->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->CursorY->LineWidth = 2;
			chartArea1->CursorY->SelectionColor = System::Drawing::Color::Silver;
			chartArea1->InnerPlotPosition->Auto = false;
			chartArea1->InnerPlotPosition->Height = 85.9457F;
			chartArea1->InnerPlotPosition->Width = 89.71415F;
			chartArea1->InnerPlotPosition->X = 8.80975F;
			chartArea1->InnerPlotPosition->Y = 3.70115F;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			legend1->Title = L"Функции на графике";
			legend1->TitleAlignment = System::Drawing::StringAlignment::Near;
			legend1->TitleBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::ThickLine;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(9, 123);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->EmptyPointStyle->Color = System::Drawing::Color::White;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->LabelToolTip = L"Линенейная функция";
			series1->Legend = L"Legend1";
			series1->MarkerBorderColor = System::Drawing::Color::Red;
			series1->MarkerColor = System::Drawing::Color::Red;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Линенейная";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series2->LabelBackColor = System::Drawing::Color::Transparent;
			series2->LabelBorderColor = System::Drawing::Color::Transparent;
			series2->Legend = L"Legend1";
			series2->MarkerBorderColor = System::Drawing::Color::SkyBlue;
			series2->MarkerBorderWidth = 2;
			series2->MarkerColor = System::Drawing::Color::SkyBlue;
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Star4;
			series2->Name = L"Степенная ";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Green;
			series3->Legend = L"Legend1";
			series3->MarkerBorderColor = System::Drawing::Color::Navy;
			series3->MarkerBorderWidth = 2;
			series3->MarkerColor = System::Drawing::Color::Navy;
			series3->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series3->Name = L"Экспоненциальная";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Color = System::Drawing::Color::Red;
			series4->Legend = L"Legend1";
			series4->MarkerBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series4->MarkerBorderWidth = 2;
			series4->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series4->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
			series4->Name = L"Квадратичная";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series4->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(751, 338);
			this->chart1->TabIndex = 4;
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			title1->Name = L"Title1";
			title1->Text = L"Метод наименьших квадратов";
			this->chart1->Titles->Add(title1);
			this->chart1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &InteractiveForm::Chart1_MouseClick);
			// 
			// label_sumFaultLinear
			// 
			this->label_sumFaultLinear->AutoSize = true;
			this->label_sumFaultLinear->Location = System::Drawing::Point(361, 14);
			this->label_sumFaultLinear->Name = L"label_sumFaultLinear";
			this->label_sumFaultLinear->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultLinear->TabIndex = 5;
			this->label_sumFaultLinear->Text = L"Погрешность:";
			// 
			// label_sumFaultPower
			// 
			this->label_sumFaultPower->AutoSize = true;
			this->label_sumFaultPower->Location = System::Drawing::Point(361, 55);
			this->label_sumFaultPower->Name = L"label_sumFaultPower";
			this->label_sumFaultPower->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultPower->TabIndex = 6;
			this->label_sumFaultPower->Text = L"Погрешность:";
			// 
			// label_sumFaultExponent
			// 
			this->label_sumFaultExponent->AutoSize = true;
			this->label_sumFaultExponent->Location = System::Drawing::Point(361, 33);
			this->label_sumFaultExponent->Name = L"label_sumFaultExponent";
			this->label_sumFaultExponent->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultExponent->TabIndex = 7;
			this->label_sumFaultExponent->Text = L"Погрешность:";
			// 
			// label_sumFaultSquare
			// 
			this->label_sumFaultSquare->AutoSize = true;
			this->label_sumFaultSquare->Location = System::Drawing::Point(361, 73);
			this->label_sumFaultSquare->Name = L"label_sumFaultSquare";
			this->label_sumFaultSquare->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultSquare->TabIndex = 8;
			this->label_sumFaultSquare->Text = L"Погрешность:";
			// 
			// label_bestFunc
			// 
			this->label_bestFunc->AutoSize = true;
			this->label_bestFunc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_bestFunc->Location = System::Drawing::Point(361, 97);
			this->label_bestFunc->Name = L"label_bestFunc";
			this->label_bestFunc->Size = System::Drawing::Size(135, 16);
			this->label_bestFunc->TabIndex = 10;
			this->label_bestFunc->Text = L"Лучшая функция:";
			// 
			// dGV_coefficients
			// 
			this->dGV_coefficients->AllowUserToAddRows = false;
			this->dGV_coefficients->AllowUserToDeleteRows = false;
			this->dGV_coefficients->AllowUserToResizeColumns = false;
			this->dGV_coefficients->AllowUserToResizeRows = false;
			this->dGV_coefficients->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dGV_coefficients->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedHeaders;
			this->dGV_coefficients->BackgroundColor = System::Drawing::SystemColors::ControlDark;
			this->dGV_coefficients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dGV_coefficients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3)
			{
				this->col_a,
					this->col_b, this->c
			});
			this->dGV_coefficients->Location = System::Drawing::Point(586, 253);
			this->dGV_coefficients->MultiSelect = false;
			this->dGV_coefficients->Name = L"dGV_coefficients";
			this->dGV_coefficients->ReadOnly = true;
			this->dGV_coefficients->RowHeadersWidth = 50;
			this->dGV_coefficients->RowTemplate->DefaultCellStyle->Format = L"N2";
			this->dGV_coefficients->RowTemplate->DefaultCellStyle->NullValue = nullptr;
			this->dGV_coefficients->RowTemplate->ReadOnly = true;
			this->dGV_coefficients->Size = System::Drawing::Size(151, 191);
			this->dGV_coefficients->TabIndex = 12;
			// 
			// label_X
			// 
			this->label_X->AutoSize = true;
			this->label_X->Location = System::Drawing::Point(18, 124);
			this->label_X->Name = L"label_X";
			this->label_X->Size = System::Drawing::Size(26, 13);
			this->label_X->TabIndex = 13;
			this->label_X->Text = L"X = ";
			// 
			// label_Y
			// 
			this->label_Y->AutoSize = true;
			this->label_Y->Location = System::Drawing::Point(18, 143);
			this->label_Y->Name = L"label_Y";
			this->label_Y->Size = System::Drawing::Size(26, 13);
			this->label_Y->TabIndex = 14;
			this->label_Y->Text = L"Y = ";
			// 
			// col_a
			// 
			this->col_a->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->col_a->HeaderText = L"a";
			this->col_a->Name = L"col_a";
			this->col_a->ReadOnly = true;
			this->col_a->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col_a->Width = 19;
			// 
			// col_b
			// 
			this->col_b->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->col_b->HeaderText = L"b";
			this->col_b->Name = L"col_b";
			this->col_b->ReadOnly = true;
			this->col_b->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col_b->Width = 19;
			// 
			// c
			// 
			this->c->HeaderText = L"c";
			this->c->Name = L"c";
			this->c->ReadOnly = true;
			this->c->Width = 38;
			// 
			// InteractiveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 473);
			this->ControlBox = false;
			this->Controls->Add(this->label_Y);
			this->Controls->Add(this->label_X);
			this->Controls->Add(this->dGV_coefficients);
			this->Controls->Add(this->label_bestFunc);
			this->Controls->Add(this->label_sumFaultSquare);
			this->Controls->Add(this->label_sumFaultExponent);
			this->Controls->Add(this->label_sumFaultPower);
			this->Controls->Add(this->label_sumFaultLinear);
			this->Controls->Add(this->btn_random);
			this->Controls->Add(this->btn_action);
			this->Controls->Add(this->table_values);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InteractiveForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Метод наименьших квадратов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dGV_coefficients))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Btn_close_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Btn_action_Click(System::Object^ sender, System::EventArgs^ e);
			 void clearInteractiveElement();
			 double* getCoordinate(int const& ind);	
			 System::Void Btn_random_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
};
}
