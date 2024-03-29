#pragma once
#include <iostream>
#include <vector>
namespace MethodsGenerationNumber {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� GenerationForm
	/// </summary>
	public ref class GenerationForm : public System::Windows::Forms::Form
	{
	public:
		GenerationForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			this->dg_equability->Rows->Add();
			this->dg_equability->Rows[0]->HeaderCell->Value = "��� 1";
			this->dg_equability->Rows->Add();
			this->dg_equability->Rows[1]->HeaderCell->Value = "��� 2";
			this->dg_equability->Rows->Add();
			this->dg_equability->Rows[2]->HeaderCell->Value = "��� 3";

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::Label^ lbl_intervalTest1;









	private: System::Windows::Forms::DataGridView^ dg_data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ current;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ reultMult;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ recieved;
	private: System::Windows::Forms::DataGridView^ dg_equability;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ met1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ met2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ met3;
	private: System::Windows::Forms::Label^ lbl_intervalTest2;
	private: System::Windows::Forms::Label^ lbl_intervalTest3;








	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->lbl_intervalTest1 = (gcnew System::Windows::Forms::Label());
			this->dg_data = (gcnew System::Windows::Forms::DataGridView());
			this->current = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->reultMult = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->recieved = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dg_equability = (gcnew System::Windows::Forms::DataGridView());
			this->met1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->met2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->met3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lbl_intervalTest2 = (gcnew System::Windows::Forms::Label());
			this->lbl_intervalTest3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_countPoint))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_data))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_equability))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::SkyBlue;
			chartArea1->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->IsMarginVisible = false;
			chartArea1->AxisX->LabelStyle->Format = L"{0:0.0}";
			chartArea1->AxisX->MajorGrid->Enabled = false;
			chartArea1->AxisX->MajorTickMark->Enabled = false;
			chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->LabelStyle->Format = L"0";
			chartArea1->AxisY->MajorGrid->Interval = 0;
			chartArea1->AxisY->MajorGrid->IntervalOffset = 0;
			chartArea1->AxisY->MaximumAutoSize = 100;
			chartArea1->AxisY->Minimum = 0;
			chartArea1->AxisY->Title = L"����������";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::Color::Transparent;
			legend1->DockedToChartArea = L"ChartArea1";
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			this->chart1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series1->EmptyPointStyle->CustomProperties = L"DrawingStyle=Cylinder";
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"Legend1";
			series1->Name = L"����� ���������� ��������";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::Red;
			series2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series2->IsValueShownAsLabel = true;
			series2->Legend = L"Legend1";
			series2->Name = L"����� ������������";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			series3->ChartArea = L"ChartArea1";
			series3->Color = System::Drawing::Color::Indigo;
			series3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series3->IsValueShownAsLabel = true;
			series3->Legend = L"Legend1";
			series3->Name = L"����������� �����";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
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
			this->btn_squre->Text = L"����� ���������� ���������";
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
			this->btn_mult->Text = L"����� ������������";
			this->btn_mult->UseVisualStyleBackColor = true;
			this->btn_mult->Click += gcnew System::EventHandler(this, &GenerationForm::Btn_mult_Click);
			// 
			// btn_linearCongruentMethod
			// 
			this->btn_linearCongruentMethod->Location = System::Drawing::Point(580, 363);
			this->btn_linearCongruentMethod->Name = L"btn_linearCongruentMethod";
			this->btn_linearCongruentMethod->Size = System::Drawing::Size(166, 41);
			this->btn_linearCongruentMethod->TabIndex = 4;
			this->btn_linearCongruentMethod->Text = L"�������� ������������ �����";
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
			this->label1->Text = L"��������� �������� R0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 389);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"���-�� �����";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(192, 399);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"��������� �������� R1";
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
			this->label4->Text = L"��������";
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
			this->btn_clear->Text = L"��������";
			this->btn_clear->UseVisualStyleBackColor = true;
			this->btn_clear->Click += gcnew System::EventHandler(this, &GenerationForm::Btn_clear_Click);
			// 
			// lbl_intervalTest1
			// 
			this->lbl_intervalTest1->AutoSize = true;
			this->lbl_intervalTest1->Location = System::Drawing::Point(752, 334);
			this->lbl_intervalTest1->Name = L"lbl_intervalTest1";
			this->lbl_intervalTest1->Size = System::Drawing::Size(158, 13);
			this->lbl_intervalTest1->TabIndex = 22;
			this->lbl_intervalTest1->Text = L"�������� ���������� ����� 1:";
			// 
			// dg_data
			// 
			this->dg_data->AllowUserToAddRows = false;
			this->dg_data->AllowUserToDeleteRows = false;
			this->dg_data->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dg_data->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->dg_data->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dg_data->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dg_data->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->current, this->reultMult,
					this->recieved
			});
			this->dg_data->Location = System::Drawing::Point(752, 12);
			this->dg_data->Name = L"dg_data";
			this->dg_data->ReadOnly = true;
			this->dg_data->Size = System::Drawing::Size(281, 150);
			this->dg_data->TabIndex = 23;
			// 
			// current
			// 
			this->current->HeaderText = L"�������";
			this->current->Name = L"current";
			this->current->ReadOnly = true;
			this->current->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// reultMult
			// 
			this->reultMult->HeaderText = L"��������� ���������";
			this->reultMult->Name = L"reultMult";
			this->reultMult->ReadOnly = true;
			this->reultMult->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// recieved
			// 
			this->recieved->HeaderText = L"����������";
			this->recieved->Name = L"recieved";
			this->recieved->ReadOnly = true;
			this->recieved->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dg_equability
			// 
			this->dg_equability->AllowUserToAddRows = false;
			this->dg_equability->AllowUserToDeleteRows = false;
			this->dg_equability->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dg_equability->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->dg_equability->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dg_equability->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dg_equability->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->met1, this->met2,
					this->met3
			});
			this->dg_equability->Location = System::Drawing::Point(752, 168);
			this->dg_equability->Name = L"dg_equability";
			this->dg_equability->ReadOnly = true;
			this->dg_equability->Size = System::Drawing::Size(281, 150);
			this->dg_equability->TabIndex = 24;
			// 
			// met1
			// 
			this->met1->HeaderText = L"��� ��������";
			this->met1->Name = L"met1";
			this->met1->ReadOnly = true;
			this->met1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// met2
			// 
			this->met2->HeaderText = L"���������";
			this->met2->Name = L"met2";
			this->met2->ReadOnly = true;
			this->met2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// met3
			// 
			this->met3->HeaderText = L"������������������ ����������";
			this->met3->Name = L"met3";
			this->met3->ReadOnly = true;
			this->met3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// lbl_intervalTest2
			// 
			this->lbl_intervalTest2->AutoSize = true;
			this->lbl_intervalTest2->Location = System::Drawing::Point(752, 363);
			this->lbl_intervalTest2->Name = L"lbl_intervalTest2";
			this->lbl_intervalTest2->Size = System::Drawing::Size(158, 13);
			this->lbl_intervalTest2->TabIndex = 25;
			this->lbl_intervalTest2->Text = L"�������� ���������� ����� 2:";
			// 
			// lbl_intervalTest3
			// 
			this->lbl_intervalTest3->AutoSize = true;
			this->lbl_intervalTest3->Location = System::Drawing::Point(752, 391);
			this->lbl_intervalTest3->Name = L"lbl_intervalTest3";
			this->lbl_intervalTest3->Size = System::Drawing::Size(161, 13);
			this->lbl_intervalTest3->TabIndex = 26;
			this->lbl_intervalTest3->Text = L"�������� ���������� ����� 3: ";
			// 
			// GenerationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(1045, 436);
			this->Controls->Add(this->lbl_intervalTest3);
			this->Controls->Add(this->lbl_intervalTest2);
			this->Controls->Add(this->dg_equability);
			this->Controls->Add(this->dg_data);
			this->Controls->Add(this->lbl_intervalTest1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_data))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_equability))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Btn_squre_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void fillChart(int series,int* countPointsInDiapason);
			 System::Void fillChart(int series, int count);
			 System::Void clearChart(int series);
			 System::Void clearDataGrid_data();
			 System::Void fillDataGrid(__int64 curNumb, __int64 squareCurNumb, __int64 receivedNumb);
			 System::Void fillDataGridEquability(int const& method, double expectedValue, double dispersion, double standardDeviation);
			 System::Void fillIntervalTest(int method,double expectedValue, double dispersion, double standart);
			 void fillDiagram(int series, int* countPointsInDiapason);
			 //methods
			 std::vector<double> methodOfMeanSquares(int countPoints, __int64 R0);
			 std::vector<double> methodOfMult(int const& countPoints, __int64 R0, __int64& R1);
			 std::vector<double> methodLinearCongruent(int const& countPoints, __int64 multiplier, __int64 divisor);
			 System::Void Btn_mult_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Btn_linearCongruentMethod_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Btn_clear_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
