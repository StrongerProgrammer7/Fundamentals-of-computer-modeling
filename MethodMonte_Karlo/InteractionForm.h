#pragma once
#include "InteractiveForm2.h"
#include <vector>
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

			this->table_values_integral->RowCount = 5;
			this->table_values_integral->Rows[0]->HeaderCell->Value = "X";
			this->table_values_integral->Rows[1]->HeaderCell->Value = "F(x)";
			this->table_values_integral->Rows[2]->HeaderCell->Value = "rnd(X)";
			this->table_values_integral->Rows[3]->HeaderCell->Value = "rnd(Y)";
			this->table_values_integral->Rows[4]->HeaderCell->Value = "F(rnd(Y))";
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
	private: System::Windows::Forms::Label^ label_squareTringle;
	private: System::Windows::Forms::Button^ btn_squareIntegral;

	private: System::Windows::Forms::DataGridView^ table_values_integral;
	private: System::Windows::Forms::Label^ label_Y2;
	private: System::Windows::Forms::Label^ label_X2;
	private: System::Windows::Forms::TextBox^ tb_b_int;
	private: System::Windows::Forms::TextBox^ tb_a_int;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label_integral;
	private: System::Windows::Forms::Label^ label_checkSquare;
	private: System::Windows::Forms::Label^ label_checkIntegral;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ToolStripMenuItem_openForm2;




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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->label_squareTringle = (gcnew System::Windows::Forms::Label());
			this->btn_squareIntegral = (gcnew System::Windows::Forms::Button());
			this->table_values_integral = (gcnew System::Windows::Forms::DataGridView());
			this->label_Y2 = (gcnew System::Windows::Forms::Label());
			this->label_X2 = (gcnew System::Windows::Forms::Label());
			this->tb_b_int = (gcnew System::Windows::Forms::TextBox());
			this->tb_a_int = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_integral = (gcnew System::Windows::Forms::Label());
			this->label_checkSquare = (gcnew System::Windows::Forms::Label());
			this->label_checkIntegral = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ToolStripMenuItem_openForm2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_numVar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countRNDPointN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values_integral))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// numeric_numVar
			// 
			this->numeric_numVar->Location = System::Drawing::Point(995, 498);
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
			this->table_values->Location = System::Drawing::Point(790, 30);
			this->table_values->Name = L"table_values";
			this->table_values->RowHeadersWidth = 100;
			this->table_values->Size = System::Drawing::Size(313, 122);
			this->table_values->TabIndex = 1;
			// 
			// numeric_countRNDPointN
			// 
			this->numeric_countRNDPointN->Location = System::Drawing::Point(818, 498);
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
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(787, 475);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Кол случ точек N:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(970, 477);
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
			chartArea1->CursorX->Interval = 0.2;
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea1->CursorX->LineWidth = 2;
			chartArea1->CursorX->SelectionColor = System::Drawing::Color::LightGreen;
			chartArea1->CursorY->Interval = 0.2;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->CursorY->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDotDot;
			chartArea1->CursorY->LineWidth = 2;
			chartArea1->Name = L"ChartArea1";
			chartArea1->Position->Auto = false;
			chartArea1->Position->Height = 48.38229F;
			chartArea1->Position->Width = 74.13878F;
			chartArea1->Position->X = 3;
			chartArea1->Position->Y = 5.235418F;
			chartArea2->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea2->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisX->IsMarksNextToAxis = false;
			chartArea2->AxisX->MajorGrid->Interval = 0;
			chartArea2->AxisX->MajorTickMark->Interval = 0;
			chartArea2->AxisX->MinorTickMark->Enabled = true;
			chartArea2->AxisX->MinorTickMark->TickMarkStyle = System::Windows::Forms::DataVisualization::Charting::TickMarkStyle::AcrossAxis;
			chartArea2->AxisX->Title = L"Х";
			chartArea2->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea2->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Lines;
			chartArea2->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisY->MajorGrid->Interval = 0;
			chartArea2->AxisY->MajorTickMark->Interval = 0;
			chartArea2->AxisY->MinorTickMark->Enabled = true;
			chartArea2->AxisY->MinorTickMark->TickMarkStyle = System::Windows::Forms::DataVisualization::Charting::TickMarkStyle::AcrossAxis;
			chartArea2->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea2->AxisY->Title = L"У";
			chartArea2->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea2->CursorX->AutoScroll = false;
			chartArea2->CursorX->Interval = 0.4;
			chartArea2->CursorX->IsUserEnabled = true;
			chartArea2->CursorX->IsUserSelectionEnabled = true;
			chartArea2->CursorY->Interval = 0.4;
			chartArea2->CursorY->IsUserEnabled = true;
			chartArea2->CursorY->IsUserSelectionEnabled = true;
			chartArea2->Name = L"ChartArea2";
			chartArea2->Position->Auto = false;
			chartArea2->Position->Height = 50.38229F;
			chartArea2->Position->Width = 74.70908F;
			chartArea2->Position->X = 3;
			chartArea2->Position->Y = 49.61771F;
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->ChartAreas->Add(chartArea2);
			legend1->HeaderSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DashLine;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend1->MaximumAutoSize = 25;
			legend1->Name = L"Legend1";
			legend1->Title = L"Легенда площадь";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::GradientLine;
			legend2->DockedToChartArea = L"ChartArea2";
			legend2->HeaderSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DashLine;
			legend2->IsDockedInsideChartArea = false;
			legend2->ItemColumnSpacing = 10;
			legend2->MaximumAutoSize = 100;
			legend2->Name = L"Legend2";
			legend2->TableStyle = System::Windows::Forms::DataVisualization::Charting::LegendTableStyle::Tall;
			legend2->Title = L"Легенда интеграл";
			legend2->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend2->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DashLine;
			this->chart1->Legends->Add(legend1);
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(12, 34);
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
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea2";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series5->Color = System::Drawing::Color::Transparent;
			series5->Legend = L"Legend2";
			series5->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series5->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series5->Name = L"Фигура-2";
			series5->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			series5->YValuesPerPoint = 2;
			series6->ChartArea = L"ChartArea2";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series6->Legend = L"Legend2";
			series6->MarkerColor = System::Drawing::Color::Green;
			series6->MarkerSize = 6;
			series6->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series6->Name = L"Точки внутри -2";
			series7->ChartArea = L"ChartArea2";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series7->Legend = L"Legend2";
			series7->MarkerColor = System::Drawing::Color::Purple;
			series7->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Triangle;
			series7->Name = L"Точки снаружи -2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Series->Add(series7);
			this->chart1->Size = System::Drawing::Size(772, 506);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
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
			this->btn_squareTringle->Location = System::Drawing::Point(851, 154);
			this->btn_squareTringle->Name = L"btn_squareTringle";
			this->btn_squareTringle->Size = System::Drawing::Size(186, 53);
			this->btn_squareTringle->TabIndex = 6;
			this->btn_squareTringle->Text = L"Вычислить площадь фигуры\r\n";
			this->btn_squareTringle->UseVisualStyleBackColor = true;
			this->btn_squareTringle->Click += gcnew System::EventHandler(this, &InteractionForm::Btn_squareTringle);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(811, 207);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"a:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(869, 207);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"b:";
			// 
			// tb_a
			// 
			this->tb_a->Cursor = System::Windows::Forms::Cursors::No;
			this->tb_a->Location = System::Drawing::Point(805, 227);
			this->tb_a->Name = L"tb_a";
			this->tb_a->Size = System::Drawing::Size(32, 22);
			this->tb_a->TabIndex = 12;
			this->tb_a->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_b
			// 
			this->tb_b->Cursor = System::Windows::Forms::Cursors::No;
			this->tb_b->Location = System::Drawing::Point(861, 227);
			this->tb_b->Name = L"tb_b";
			this->tb_b->Size = System::Drawing::Size(32, 22);
			this->tb_b->TabIndex = 13;
			this->tb_b->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_X
			// 
			this->label_X->AutoSize = true;
			this->label_X->BackColor = System::Drawing::Color::Transparent;
			this->label_X->Location = System::Drawing::Point(634, 177);
			this->label_X->Name = L"label_X";
			this->label_X->Size = System::Drawing::Size(16, 16);
			this->label_X->TabIndex = 14;
			this->label_X->Text = L"X";
			// 
			// label_Y
			// 
			this->label_Y->AutoSize = true;
			this->label_Y->BackColor = System::Drawing::Color::Transparent;
			this->label_Y->Location = System::Drawing::Point(634, 205);
			this->label_Y->Name = L"label_Y";
			this->label_Y->Size = System::Drawing::Size(17, 16);
			this->label_Y->TabIndex = 15;
			this->label_Y->Text = L"Y";
			// 
			// cb_randUniform
			// 
			this->cb_randUniform->AutoSize = true;
			this->cb_randUniform->Location = System::Drawing::Point(837, 523);
			this->cb_randUniform->Name = L"cb_randUniform";
			this->cb_randUniform->Size = System::Drawing::Size(223, 20);
			this->cb_randUniform->TabIndex = 16;
			this->cb_randUniform->Text = L"Равномерное распределение";
			this->cb_randUniform->UseVisualStyleBackColor = true;
			// 
			// label_squareTringle
			// 
			this->label_squareTringle->AutoSize = true;
			this->label_squareTringle->Location = System::Drawing::Point(899, 216);
			this->label_squareTringle->Name = L"label_squareTringle";
			this->label_squareTringle->Size = System::Drawing::Size(52, 16);
			this->label_squareTringle->TabIndex = 17;
			this->label_squareTringle->Text = L"Square";
			// 
			// btn_squareIntegral
			// 
			this->btn_squareIntegral->Location = System::Drawing::Point(860, 395);
			this->btn_squareIntegral->Name = L"btn_squareIntegral";
			this->btn_squareIntegral->Size = System::Drawing::Size(186, 23);
			this->btn_squareIntegral->TabIndex = 18;
			this->btn_squareIntegral->Text = L"Вычислить интеграл";
			this->btn_squareIntegral->UseVisualStyleBackColor = true;
			this->btn_squareIntegral->Click += gcnew System::EventHandler(this, &InteractionForm::Btn_squareIntegral_Click);
			// 
			// table_values_integral
			// 
			this->table_values_integral->AllowUserToAddRows = false;
			this->table_values_integral->AllowUserToDeleteRows = false;
			this->table_values_integral->AllowUserToResizeColumns = false;
			this->table_values_integral->AllowUserToResizeRows = false;
			this->table_values_integral->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->table_values_integral->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->table_values_integral->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->table_values_integral->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->table_values_integral->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table_values_integral->Location = System::Drawing::Point(790, 263);
			this->table_values_integral->Name = L"table_values_integral";
			this->table_values_integral->RowHeadersWidth = 100;
			this->table_values_integral->Size = System::Drawing::Size(313, 127);
			this->table_values_integral->TabIndex = 19;
			// 
			// label_Y2
			// 
			this->label_Y2->AutoSize = true;
			this->label_Y2->BackColor = System::Drawing::Color::Transparent;
			this->label_Y2->Location = System::Drawing::Point(633, 416);
			this->label_Y2->Name = L"label_Y2";
			this->label_Y2->Size = System::Drawing::Size(17, 16);
			this->label_Y2->TabIndex = 21;
			this->label_Y2->Text = L"Y";
			// 
			// label_X2
			// 
			this->label_X2->AutoSize = true;
			this->label_X2->BackColor = System::Drawing::Color::Transparent;
			this->label_X2->Location = System::Drawing::Point(633, 392);
			this->label_X2->Name = L"label_X2";
			this->label_X2->Size = System::Drawing::Size(16, 16);
			this->label_X2->TabIndex = 20;
			this->label_X2->Text = L"X";
			// 
			// tb_b_int
			// 
			this->tb_b_int->Cursor = System::Windows::Forms::Cursors::No;
			this->tb_b_int->Location = System::Drawing::Point(860, 437);
			this->tb_b_int->Name = L"tb_b_int";
			this->tb_b_int->Size = System::Drawing::Size(32, 22);
			this->tb_b_int->TabIndex = 25;
			this->tb_b_int->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tb_a_int
			// 
			this->tb_a_int->Cursor = System::Windows::Forms::Cursors::No;
			this->tb_a_int->Location = System::Drawing::Point(804, 437);
			this->tb_a_int->Name = L"tb_a_int";
			this->tb_a_int->Size = System::Drawing::Size(32, 22);
			this->tb_a_int->TabIndex = 24;
			this->tb_a_int->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(868, 417);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 16);
			this->label5->TabIndex = 23;
			this->label5->Text = L"b:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(810, 417);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 16);
			this->label6->TabIndex = 22;
			this->label6->Text = L"a:";
			// 
			// label_integral
			// 
			this->label_integral->AutoSize = true;
			this->label_integral->Location = System::Drawing::Point(899, 427);
			this->label_integral->Name = L"label_integral";
			this->label_integral->Size = System::Drawing::Size(52, 16);
			this->label_integral->TabIndex = 26;
			this->label_integral->Text = L"Integral";
			// 
			// label_checkSquare
			// 
			this->label_checkSquare->AutoSize = true;
			this->label_checkSquare->Location = System::Drawing::Point(899, 241);
			this->label_checkSquare->Name = L"label_checkSquare";
			this->label_checkSquare->Size = System::Drawing::Size(46, 16);
			this->label_checkSquare->TabIndex = 27;
			this->label_checkSquare->Text = L"Check";
			// 
			// label_checkIntegral
			// 
			this->label_checkIntegral->AutoSize = true;
			this->label_checkIntegral->Location = System::Drawing::Point(899, 458);
			this->label_checkIntegral->Name = L"label_checkIntegral";
			this->label_checkIntegral->Size = System::Drawing::Size(46, 16);
			this->label_checkIntegral->TabIndex = 28;
			this->label_checkIntegral->Text = L"Check";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ToolStripMenuItem_openForm2 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1106, 24);
			this->menuStrip1->TabIndex = 29;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ToolStripMenuItem_openForm2
			// 
			this->ToolStripMenuItem_openForm2->Name = L"ToolStripMenuItem_openForm2";
			this->ToolStripMenuItem_openForm2->Size = System::Drawing::Size(345, 20);
			this->ToolStripMenuItem_openForm2->Text = L"Форма вычисления площади круга и полярных координат";
			this->ToolStripMenuItem_openForm2->Click += gcnew System::EventHandler(this, &InteractionForm::ToolStripMenuItem_openForm2_Click);
			// 
			// InteractionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1106, 550);
			this->Controls->Add(this->label_checkIntegral);
			this->Controls->Add(this->label_checkSquare);
			this->Controls->Add(this->label_integral);
			this->Controls->Add(this->tb_b_int);
			this->Controls->Add(this->tb_a_int);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label_Y2);
			this->Controls->Add(this->label_X2);
			this->Controls->Add(this->table_values_integral);
			this->Controls->Add(this->btn_squareIntegral);
			this->Controls->Add(this->label_squareTringle);
			this->Controls->Add(this->cb_randUniform);
			this->Controls->Add(this->label_Y);
			this->Controls->Add(this->label_X);
			this->Controls->Add(this->tb_b);
			this->Controls->Add(this->tb_a);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_squareTringle);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numeric_countRNDPointN);
			this->Controls->Add(this->table_values);
			this->Controls->Add(this->numeric_numVar);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->chart1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"InteractionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Метод Монте-Карло";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_numVar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countRNDPointN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values_integral))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Btn_squareTringle(System::Object^ sender, System::EventArgs^ e);
			 bool isEmptyValuesTable(int const& cell, int const& row);
			 void clearInteractiveElementChartArea1();
			 void clearInteractiveElementChartArea2();
			 System::Void Chart1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
			 System::Void Btn_squareIntegral_Click(System::Object^ sender, System::EventArgs^ e);
			 void fillTable_values(const int& N, std::vector<double> rnd_x, std::vector<double> rnd_y, DataGridView^ table);
			 System::Void ToolStripMenuItem_openForm2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
