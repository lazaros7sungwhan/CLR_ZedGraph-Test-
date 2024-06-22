#pragma once
#include <iostream>
#include <math.h>
#include <cliext/list>
double var1 = 0, var2 = 0, var3 = 0, rangeMin = 0, rangeMax=0, var5=0;

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Diagnostics;
	using namespace ZedGraph;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(227, 20);
			this->comboBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(772, 183);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(8, 8);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(140, 34);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 24);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Connection";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"D2Coding", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox1->ForeColor = System::Drawing::Color::Lime;
			this->textBox1->Location = System::Drawing::Point(10, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(94, 25);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 71);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(822, 456);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(263, 12);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 51);
			this->button3->TabIndex = 6;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(895, 596);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Form1";
			this->Text = L"SerialPort1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma region Variables
		Thread^ task1=nullptr;
		SerialPort^ serial1 = nullptr;
		String^ message;

		ZedGraphControl^ zg1;
		; //컨트롤 선언
		LineItem^ myBar;
		
		PointPairList^ pointpairing; 
		PointPairList^ pointpairing2;

		int datacount = 0;
		array<double>^ test_array = gcnew array<double>(10); //declaration - no problem
		
		List<double>^ list = gcnew List<double>();

#pragma endregion
#pragma region Delegates
		delegate void tributeForLabel1(); //String^ Data
		void del_Label1_Func() // String^ Data
		{
			
			textBox1->Text = var5.ToString();//Data
		}

		delegate void tributeForPic1();
		void del_pic1_Func()
		{
			zg1->Dock = DockStyle::Fill; // 도크 채우셈

			//
			if (datacount > 1000)
			{
				pointpairing2->RemoveAt(0);
				pointpairing->RemoveAt(0);
				rangeMin = pointpairing[0]->X;
				rangeMax = pointpairing[999]->X;
				zg1->GraphPane->XAxis->Scale->Min = rangeMin;
				zg1->GraphPane->XAxis->Scale->Max = rangeMax;
			}
			else 
			{
				if (datacount > 2)
				{
					var5 = pointpairing[datacount - 1]->X;
					rangeMin = pointpairing[0]->X;
					//rangeMax = pointpairing[datacount - 1]->X;
					zg1->GraphPane->XAxis->Scale->Min = rangeMin;
					zg1->GraphPane->XAxis->Scale->Max = 15.243;
				}
				datacount++;
			}  
			pointpairing->Add(var1, var2);
			pointpairing2->Add(var1, var3);
			
			zg1->AxisChange();
			zg1->Invalidate();

			zg1->Show();

			pictureBox1->Controls->Add(zg1);
		}
#pragma endregion

#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->Items->AddRange(SerialPort::GetPortNames());
	}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try 
		{
			if (serial1 == nullptr)
			{
				serial1 = gcnew SerialPort();
			}
			else
			{
				serial1->Close();
			}
			//if (comboBox1->Text == "")
			serial1->PortName = comboBox1->Text;
			
			serial1->BaudRate = 115200;
			serial1->Parity = Parity::None;
			serial1->DataBits = 8;
			serial1->StopBits = StopBits::One;
			serial1->Handshake = Handshake::None;

			//serial1->Open();
			zg1 = gcnew ZedGraph::ZedGraphControl();
			task1 = gcnew Thread(gcnew ThreadStart(this, &Form1::threadFunction1));
			task1->Start();
		}
		catch (char* str)//std::exception& err
		{
			MessageBox::Show("아 뭐냐");
		}
	}
#pragma region Funcitons
			void threadFunction1()
			{   
				zg1->GraphPane = gcnew  GraphPane(); //그래프 판 새로 설정
				myBar = gcnew LineItem("Bar1");
				zg1->GraphPane->CurveList->Add(myBar);
				myBar->Line->Fill = gcnew Fill(Color::AliceBlue, Color::White, Color::AliceBlue);
				pointpairing = gcnew PointPairList(); //stage2
				pointpairing2 = gcnew PointPairList();
				myBar = zg1->GraphPane->AddCurve("Sin", pointpairing, Color::Red, SymbolType::None);
				myBar = zg1->GraphPane->AddCurve("Cos", pointpairing2, Color::Blue, SymbolType::None);

				Stopwatch^ sw1=gcnew Stopwatch();
				sw1->Start();

				while (true)
				{
					var1 = double(sw1->ElapsedMilliseconds) / 1000;
					var2 = sin(var1);
					var3 = cos(var1);

					String^ time_string = var1.ToString();
					String^ sin_string = var2.ToString();
			
					if (textBox1->InvokeRequired)
					{
						tributeForLabel1^ newdel1 = gcnew tributeForLabel1(this, &Form1::del_Label1_Func);
						Control::Invoke(newdel1);
					}
					else
					{
						del_Label1_Func();
					}

					if (pictureBox1->InvokeRequired)
					{
						tributeForPic1^ newdel2 = gcnew tributeForPic1(this, &Form1::del_pic1_Func);
						Control::Invoke(newdel2);
					}
					else
					{
						del_pic1_Func();
					}
					Thread::Sleep(1);
				}

				//button3_Click(this, nullptr);


					/*while (true)
					{
						message = serial1->ReadLine();
						if (textBox1->InvokeRequired)
						{
							tributeForLabel1^ newdel = gcnew tributeForLabel1(this, &Form1::del_Label1_Func);
							Control::Invoke(newdel, message);
						}
						else
						{
							del_Label1_Func(message);
						}
					}*/
			}
			private: System::Void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) 
			{
				if (task1 != nullptr)
				{
					task1->Abort();
				}
			}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		}

};
}

class my_out_of_range : public std::exception { // exception객체 상속
public:
	const char* what(void) const throw() { // exception객체의 what함수 재정의
		return ("index is out of range");
	}
};