#pragma once
#include "Date.h"

namespace lab7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ output_txt;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->output_txt = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// output_txt
			// 
			this->output_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->output_txt->Location = System::Drawing::Point(72, 111);
			this->output_txt->Name = L"output_txt";
			this->output_txt->Size = System::Drawing::Size(635, 33);
			this->output_txt->TabIndex = 0;
			this->output_txt->Text = L"\r\n";
			this->output_txt->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(77, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(199, 34);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(484, 59);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(199, 34);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(224, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(341, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Please enter dates to compare";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(317, 174);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 39);
			this->button2->TabIndex = 5;
			this->button2->Text = L"check day";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(740, 248);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->output_txt);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"calendar";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ date1 = textBox1->Text;
		String^ date2 = textBox2->Text;
		array<String^>^ d1 = date1->Split('.');
		array<String^>^ d2 = date2->Split('.');
		try {

			int day1 = Convert::ToInt32(d1[0]);
			int month1 = Convert::ToInt32(d1[1]);
			int year1 = Convert::ToInt32(d1[2]);

			int day2 = Convert::ToInt32(d2[0]);
			int month2 = Convert::ToInt32(d2[1]);
			int year2 = Convert::ToInt32(d2[2]);

			if ((day2 < 1 || day2 > 31 || month2 < 1 || month2 > 12) || (day1 < 1 || day1 > 31 || month1 < 1 || month1 > 12))
			{
				MessageBox::Show(this, "Invalid date input.", "Error");
				output_txt->Text = "Wrong input.";
			}

			Date date_1(day1, month1, year1);
			Date date_2(day2, month2, year2);

			int day_week1 = date_1.getDayOfWeek();
			int day_week2 = date_2.getDayOfWeek();

			if (day_week1 == day_week2) {
				String^ output_day;
				switch (day_week1) {
				case 0: output_day = "Sanday"; break;
				case 1: output_day = "Monday"; break;
				case 2: output_day = "Tuesday"; break;
				case 3: output_day = "Wednesday"; break;
				case 4: output_day = "Thursday"; break;
				case 5: output_day = "Friday"; break;
				case 6: output_day = "Saturday"; break;
				}
				output_txt->Text = "Dates have the same day of the week: " + output_day;
			}
			else {
				output_txt->Text = "Dates have different days of the week.";
			}
		}
		catch (FormatException^) {
			MessageBox::Show(this, "Invalid date format. Please enter dates in the format 'dd.mm.yyyy'.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
};
}
