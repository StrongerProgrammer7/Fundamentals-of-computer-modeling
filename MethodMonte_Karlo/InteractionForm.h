#pragma once

namespace MethodMonteKarlo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для InteractionForm
	/// </summary>
	public ref class InteractionForm : public System::Windows::Forms::Form
	{
	public:
		InteractionForm(void)
		{
			InitializeComponent();
			this->table_values->RowCount = 5;
			this->table_values->Rows[0]->HeaderCell->Value = "X";
			this->table_values->Rows[1]->HeaderCell->Value = "F(x)";
			this->table_values->Rows[2]->HeaderCell->Value = "rnd(X)";
			this->table_values->Rows[3]->HeaderCell->Value = "rnd(Y)";
			this->table_values->Rows[4]->HeaderCell->Value = "F(rnd(Y))";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~InteractionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ numeric_numVar;
	protected:

	protected:
	private: System::Windows::Forms::DataGridView^ table_values;
	private: System::Windows::Forms::NumericUpDown^ numeric_countRNDPointN;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ btn_squareTringle;



	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tb_a;
	private: System::Windows::Forms::TextBox^ tb_b;
	private: System::Windows::Forms::Label^ label_X;
	private: System::Windows::Forms::Label^ label_Y;
	private: System::Windows::Forms::CheckBox^ cb_randUniform;




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
			System::Windows::Forms::DataVisualization::Charting::StripLine^ stripLine1 = (gcnew System::Windows::Forms::DataVisualization::Charting::StripLine());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InteractionForm::typeid));
			this->numeric_numVar = (gcnew System::Windows::Forms::NumericUpDown());
			this->table_values = (gcnew System::Windows::Forms::DataGridView());
			this->numeric_countRNDPointN = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btn_squareTringle = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tb_a = (gcnew System::Windows::Forms::TextBox());
			this->tb_b = (gcnew System::Windows::Forms::TextBox());
			this->label_X = (gcnew System::Windows::Forms::Label());
			this->label_Y = (gcnew System::Windows::Forms::Label());
			this->cb_randUniform = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_numVar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countRNDPointN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// numeric_numVar
			// 
			this->numeric_numVar->Location = System::Drawing::Point(29, 120);
			this->numeric_numVar->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numeric_numVar->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_numVar->Name = L"numeric_numVar";
			this->numeric_numVar->Size = System::Drawing::Size(42, 22);
			this->numeric_numVar->TabIndex = 0;
			this->numeric_numVar->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// table_values
			// 
			this->table_values->AllowUserToAddRows = false;
			this->table_values->AllowUserToDeleteRows = false;
			this->table_values->AllowUserToResizeColumns = false;
			this->table_values->AllowUserToResizeRows = false;
			this->table_values->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->table_values->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->table_values->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->table_values->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->table_values->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table_values->Location = System::Drawing::Point(12, 12);
			this->table_values->Name = L"table_values";
			this->table_values->RowHeadersWidth = 100;
			this->table_values->Size = System::Drawing::Size(313, 86);
			this->table_values->TabIndex = 1;
			// 
			// numeric_countRNDPointN
			// 
			this->numeric_countRNDPointN->Location = System::Drawing::Point(233, 120);
			this->numeric_countRNDPointN->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numeric_countRNDPointN->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_countRNDPointN->Name = L"numeric_countRNDPointN";
			this->numeric_countRNDPointN->Size = System::Drawing::Size(53, 22);
			this->numeric_countRNDPointN->TabIndex = 2;
			this->numeric_countRNDPointN->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(202, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Кол случ точек N:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"# вариантa:";
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::AntiqueWhite;
			chartArea1->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea1->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->MajorGrid->Interval = 0;
			chartArea1->AxisX->StripLines->Add(stripLine1);
			chartArea1->AxisX->Title = L"X";
			chartArea1->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->MajorGrid->Interval = 0;
			chartArea1->AxisY->MinorTickMark->Enabled = true;
			chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea1->AxisY->Title = L"Y";
			chartArea1->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->CursorX->AutoScroll = false;
			chartArea1->CursorX->Interval = 0.5;
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea1->CursorX->LineWidth = 2;
			chartArea1->CursorX->SelectionColor = System::Drawing::Color::LightGreen;
			chartArea1->CursorY->Interval = 0.5;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->CursorY->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDotDot;
			chartArea1->CursorY->LineWidth = 2;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->HeaderSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DashLine;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend1->MaximumAutoSize = 25;
			legend1->Name = L"Legend1";
			legend1->Title = L"Функция";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::GradientLine;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 148);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::DodgerBlue;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->Legend = L"Legend1";
			series1->MarkerColor = System::Drawing::Color::Red;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series1->Name = L"Фигура";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::DodgerBlue;
			series2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series2->Legend = L"Legend1";
			series2->MarkerColor = System::Drawing::Color::Red;
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series2->Name = L"~";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series3->Legend = L"Legend1";
			series3->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->MarkerSize = 7;
			series3->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series3->Name = L"Точки внутри";
			series3->YValuesPerPoint = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series4->Color = System::Drawing::Color::Red;
			series4->Legend = L"Legend1";
			series4->MarkerColor = System::Drawing::Color::Violet;
			series4->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series4->Name = L"Точки снаружи";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(695, 364);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			title1->Alignment = System::Drawing::ContentAlignment::TopLeft;
			title1->BackImageAlignment = System::Windows::Forms::DataVisualization::Charting::ChartImageAlignmentStyle::Top;
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			title1->ForeColor = System::Drawing::Color::ForestGreen;
			title1->Name = L"Title1";
			title1->Text = L"Метод Монте-Карло";
			title1->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
			this->chart1->Titles->Add(title1);
			this->chart1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &InteractionForm::Chart1_MouseClick);
			// 
			// btn_squareTringle
			// 
			this->btn_squareTringle->Location = System::Drawing::Point(331, 10);
			this->btn_squareTringle->Name = L"btn_squareTringle";
			this->btn_squareTringle->Size = System::Drawing::Size(186, 53);
			this->btn_squareTringle->TabIndex = 6;
			this->btn_squareTringle->Text = L"Заполнить таблицу и построить график";
			this->btn_squareTringle->UseVisualStyleBackColor = true;
			this->btn_squareTringle->Click += gcnew System::EventHandler(this, &InteractionForm::Btn_squareTringle);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(105, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"a:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(161, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"b:";
			// 
			// tb_a
			// 
			this->tb_a->Cursor = System::Windows::Forms::Cursors::No;
			this->tb_a->Location = System::Drawing::Point(97, 120);
			this->tb_a->Name = L"tb_a";
			this->tb_a->Size = System::Drawing::Size(32, 22);
			this->tb_a->TabIndex = 12;
			this->tb_a->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_b
			// 
			this->tb_b->Cursor = System::Windows::Forms::Cursors::No;
			this->tb_b->Location = System::Drawing::Point(151, 120);
			this->tb_b->Name = L"tb_b";
			this->tb_b->Size = System::Drawing::Size(32, 22);
			this->tb_b->TabIndex = 13;
			this->tb_b->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_X
			// 
			this->label_X->AutoSize = true;
			this->label_X->Location = System::Drawing::Point(555, 287);
			this->label_X->Name = L"label_X";
			this->label_X->Size = System::Drawing::Size(16, 16);
			this->label_X->TabIndex = 14;
			this->label_X->Text = L"X";
			// 
			// label_Y
			// 
			this->label_Y->AutoSize = true;
			this->label_Y->Location = System::Drawing::Point(555, 315);
			this->label_Y->Name = L"label_Y";
			this->label_Y->Size = System::Drawing::Size(17, 16);
			this->label_Y->TabIndex = 15;
			this->label_Y->Text = L"Y";
			// 
			// cb_randUniform
			// 
			this->cb_randUniform->AutoSize = true;
			this->cb_randUniform->Location = System::Drawing::Point(331, 69);
			this->cb_randUniform->Name = L"cb_randUniform";
			this->cb_randUniform->Size = System::Drawing::Size(223, 20);
			this->cb_randUniform->TabIndex = 16;
			this->cb_randUniform->Text = L"Равномерное распределение";
			this->cb_randUniform->UseVisualStyleBackColor = true;
			// 
			// InteractionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1106, 524);
			this->Controls->Add(this->cb_randUniform);
			this->Controls->Add(this->label_Y);
			this->Controls->Add(this->label_X);
			this->Controls->Add(this->tb_b);
			this->Controls->Add(this->tb_a);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_squareTringle);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numeric_countRNDPointN);
			this->Controls->Add(this->table_values);
			this->Controls->Add(this->numeric_numVar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"InteractionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Метод Монте-Карло";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_numVar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countRNDPointN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Btn_squareTringle(System::Object^ sender, System::EventArgs^ e);
			 bool isEmptyValuesTable(int const& cell, int const& row);
			 void clearInteractiveElement();
			 System::Void Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	 
};
}
