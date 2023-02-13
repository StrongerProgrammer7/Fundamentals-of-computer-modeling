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
			this->table_values->RowCount = 3;
			this->table_values->Rows[0]->HeaderCell->Value = "X";
			this->table_values->Rows[1]->HeaderCell->Value = "Y";
			this->table_values->Rows[2]->HeaderCell->Value = "F(x)";
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
	private: System::Windows::Forms::Button^ btn_rndPoint;
	private: System::Windows::Forms::Button^ btn_createGraph;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ numeric_a;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ numeric_b;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InteractionForm::typeid));
			this->numeric_numVar = (gcnew System::Windows::Forms::NumericUpDown());
			this->table_values = (gcnew System::Windows::Forms::DataGridView());
			this->numeric_countRNDPointN = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btn_rndPoint = (gcnew System::Windows::Forms::Button());
			this->btn_createGraph = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numeric_a = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numeric_b = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_numVar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countRNDPointN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_b))->BeginInit();
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
			this->table_values->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->table_values->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->table_values->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->table_values->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->table_values->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table_values->Location = System::Drawing::Point(12, 12);
			this->table_values->Name = L"table_values";
			this->table_values->RowHeadersWidth = 54;
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
			chartArea1->AxisX->StripLines->Add(stripLine1);
			chartArea1->AxisX->Title = L"X";
			chartArea1->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea1->AxisY->Title = L"Y";
			chartArea1->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
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
			legend1->DockedToChartArea = L"ChartArea1";
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend1->HeaderSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DashLine;
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
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->Legend = L"Legend1";
			series1->MarkerColor = System::Drawing::Color::Red;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series1->Name = L"x y";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series2->Name = L"f(x)";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(695, 364);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			// 
			// btn_rndPoint
			// 
			this->btn_rndPoint->Location = System::Drawing::Point(331, 10);
			this->btn_rndPoint->Name = L"btn_rndPoint";
			this->btn_rndPoint->Size = System::Drawing::Size(186, 23);
			this->btn_rndPoint->TabIndex = 6;
			this->btn_rndPoint->Text = L"Заполнить таблицу";
			this->btn_rndPoint->UseVisualStyleBackColor = true;
			this->btn_rndPoint->Click += gcnew System::EventHandler(this, &InteractionForm::Btn_rndPoint_Click);
			// 
			// btn_createGraph
			// 
			this->btn_createGraph->Location = System::Drawing::Point(331, 40);
			this->btn_createGraph->Name = L"btn_createGraph";
			this->btn_createGraph->Size = System::Drawing::Size(186, 23);
			this->btn_createGraph->TabIndex = 7;
			this->btn_createGraph->Text = L"Построить график";
			this->btn_createGraph->UseVisualStyleBackColor = true;
			this->btn_createGraph->Click += gcnew System::EventHandler(this, &InteractionForm::Btn_createGraph_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(110, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"a:";
			// 
			// numeric_a
			// 
			this->numeric_a->Location = System::Drawing::Point(100, 120);
			this->numeric_a->Name = L"numeric_a";
			this->numeric_a->Size = System::Drawing::Size(42, 22);
			this->numeric_a->TabIndex = 8;
			this->numeric_a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(166, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"b:";
			// 
			// numeric_b
			// 
			this->numeric_b->Location = System::Drawing::Point(157, 120);
			this->numeric_b->Name = L"numeric_b";
			this->numeric_b->Size = System::Drawing::Size(42, 22);
			this->numeric_b->TabIndex = 10;
			this->numeric_b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// InteractionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1106, 524);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numeric_b);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numeric_a);
			this->Controls->Add(this->btn_createGraph);
			this->Controls->Add(this->btn_rndPoint);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_b))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Btn_rndPoint_Click(System::Object^ sender, System::EventArgs^ e);
			 bool isEmptyValuesTable(int const& cell, int const& row);
			 void clearInteractiveElement();
	private: System::Void Btn_createGraph_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		 int N;
		 int numVar;
};
}
