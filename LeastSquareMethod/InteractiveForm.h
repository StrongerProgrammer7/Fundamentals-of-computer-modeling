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
			this->table_values->Rows[0]->Cells[0]->Value = 1;
			this->table_values->Rows[0]->Cells[1]->Value = 2;
			this->table_values->Rows[0]->Cells[2]->Value = 3;
			this->table_values->Rows[0]->Cells[3]->Value = 4;
			this->table_values->Rows[0]->Cells[4]->Value = 5;
			this->table_values->Rows[0]->Cells[5]->Value = 6;
			
			this->table_values->Rows[1]->Cells[0]->Value = 1.0;
			this->table_values->Rows[1]->Cells[1]->Value = 1.5;
			this->table_values->Rows[1]->Cells[2]->Value = 3.0;
			this->table_values->Rows[1]->Cells[3]->Value = 4.5;
			this->table_values->Rows[1]->Cells[4]->Value = 7.0;
			this->table_values->Rows[1]->Cells[5]->Value = 8.5;
			
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
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
			this->table_values->Size = System::Drawing::Size(210, 76);
			this->table_values->TabIndex = 1;
			// 
			// btn_action
			// 
			this->btn_action->Location = System::Drawing::Point(12, 94);
			this->btn_action->Name = L"btn_action";
			this->btn_action->Size = System::Drawing::Size(210, 23);
			this->btn_action->TabIndex = 2;
			this->btn_action->Text = L"Вычислить и построить график";
			this->btn_action->UseVisualStyleBackColor = true;
			this->btn_action->Click += gcnew System::EventHandler(this, &InteractiveForm::Btn_action_Click);
			// 
			// btn_random
			// 
			this->btn_random->Location = System::Drawing::Point(228, 12);
			this->btn_random->Name = L"btn_random";
			this->btn_random->Size = System::Drawing::Size(109, 76);
			this->btn_random->TabIndex = 3;
			this->btn_random->Text = L"Заполнить числами";
			this->btn_random->UseVisualStyleBackColor = true;
			this->btn_random->Click += gcnew System::EventHandler(this, &InteractiveForm::Btn_random_Click);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 123);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			series1->LabelToolTip = L"Линенейная функция";
			series1->Legend = L"Legend1";
			series1->MarkerBorderColor = System::Drawing::Color::Red;
			series1->MarkerColor = System::Drawing::Color::Red;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"linear y=ax+b";
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
			series2->Name = L"Power y=b*x^a";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Green;
			series3->Legend = L"Legend1";
			series3->MarkerBorderColor = System::Drawing::Color::Navy;
			series3->MarkerBorderWidth = 2;
			series3->MarkerColor = System::Drawing::Color::Navy;
			series3->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series3->Name = L"Exponential y=b*e^(ax)";
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
			series4->Name = L"Square y=ax^2+bx+c";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(751, 321);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"Метод наименьших квадратов";
			title1->Name = L"Title1";
			title1->Text = L"Метод наименьших квадратов";
			this->chart1->Titles->Add(title1);
			// 
			// label_sumFaultLinear
			// 
			this->label_sumFaultLinear->AutoSize = true;
			this->label_sumFaultLinear->Location = System::Drawing::Point(372, 16);
			this->label_sumFaultLinear->Name = L"label_sumFaultLinear";
			this->label_sumFaultLinear->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultLinear->TabIndex = 5;
			this->label_sumFaultLinear->Text = L"Погрешность:";
			// 
			// label_sumFaultPower
			// 
			this->label_sumFaultPower->AutoSize = true;
			this->label_sumFaultPower->Location = System::Drawing::Point(372, 75);
			this->label_sumFaultPower->Name = L"label_sumFaultPower";
			this->label_sumFaultPower->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultPower->TabIndex = 6;
			this->label_sumFaultPower->Text = L"Погрешность:";
			// 
			// label_sumFaultExponent
			// 
			this->label_sumFaultExponent->AutoSize = true;
			this->label_sumFaultExponent->Location = System::Drawing::Point(372, 35);
			this->label_sumFaultExponent->Name = L"label_sumFaultExponent";
			this->label_sumFaultExponent->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultExponent->TabIndex = 7;
			this->label_sumFaultExponent->Text = L"Погрешность:";
			// 
			// label_sumFaultSquare
			// 
			this->label_sumFaultSquare->AutoSize = true;
			this->label_sumFaultSquare->Location = System::Drawing::Point(372, 55);
			this->label_sumFaultSquare->Name = L"label_sumFaultSquare";
			this->label_sumFaultSquare->Size = System::Drawing::Size(78, 13);
			this->label_sumFaultSquare->TabIndex = 8;
			this->label_sumFaultSquare->Text = L"Погрешность:";
			// 
			// InteractiveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 456);
			this->ControlBox = false;
			this->Controls->Add(this->label_sumFaultSquare);
			this->Controls->Add(this->label_sumFaultExponent);
			this->Controls->Add(this->label_sumFaultPower);
			this->Controls->Add(this->label_sumFaultLinear);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->btn_random);
			this->Controls->Add(this->btn_action);
			this->Controls->Add(this->table_values);
			this->Controls->Add(this->btn_close);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InteractiveForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Метод наименьших квадратов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table_values))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Btn_close_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Btn_action_Click(System::Object^ sender, System::EventArgs^ e);
	protected: 
		void clearInteractiveElement()
		{
			this->chart1->Series[0]->Points->Clear();
			this->chart1->Series[1]->Points->Clear();
			this->chart1->Series[2]->Points->Clear();
			this->chart1->Series[3]->Points->Clear();
			this->label_sumFaultLinear->Text = " ";
			this->label_sumFaultPower->Text = " ";
			this->label_sumFaultExponent->Text = " ";
			this->label_sumFaultSquare->Text = " ";
		}

		double* getCoordinate(int const& ind)
		{
			double* coordinate = new double[2];
			coordinate[0] = Convert::ToDouble(table_values->Rows[0]->Cells[ind]->FormattedValue->ToString());
			coordinate[1] = Convert::ToDouble(table_values->Rows[1]->Cells[ind]->FormattedValue->ToString());
			return coordinate;
		}

	private: System::Void Btn_random_Click(System::Object^ sender, System::EventArgs^ e);
	protected: double GetRandomNumberFloat(double min, double max, int precision);
		
};
}
