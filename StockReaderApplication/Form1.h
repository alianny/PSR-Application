#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "sqlite3.h"
#include "SQLCallBack.h"

namespace StockReaderApplication {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	std::string databaseName = "localPSR.db";
	
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
	private: System::Windows::Forms::Label^  NAStockSymbolLabel;
	protected: 

	private: System::Windows::Forms::TextBox^  StockSymbol;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Button^  Go;
	private: System::Windows::Forms::Label^  NUStartDate;
	private: System::Windows::Forms::RichTextBox^  InformationBox;
	private: System::Windows::Forms::Label^  NUEndDate;
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->NAStockSymbolLabel = (gcnew System::Windows::Forms::Label());
			this->StockSymbol = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->Go = (gcnew System::Windows::Forms::Button());
			this->NUStartDate = (gcnew System::Windows::Forms::Label());
			this->NUEndDate = (gcnew System::Windows::Forms::Label());
			this->InformationBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// NAStockSymbolLabel
			// 
			this->NAStockSymbolLabel->AutoSize = true;
			this->NAStockSymbolLabel->Location = System::Drawing::Point(13, 13);
			this->NAStockSymbolLabel->Name = L"NAStockSymbolLabel";
			this->NAStockSymbolLabel->Size = System::Drawing::Size(72, 13);
			this->NAStockSymbolLabel->TabIndex = 0;
			this->NAStockSymbolLabel->Text = L"Stock Symbol";
			// 
			// StockSymbol
			// 
			this->StockSymbol->Location = System::Drawing::Point(13, 30);
			this->StockSymbol->Name = L"StockSymbol";
			this->StockSymbol->Size = System::Drawing::Size(100, 20);
			this->StockSymbol->TabIndex = 1;
			this->StockSymbol->TextChanged += gcnew System::EventHandler(this, &Form1::StockSymbol_TextChanged);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(13, 88);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(13, 136);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 3;
			// 
			// Go
			// 
			this->Go->Location = System::Drawing::Point(137, 218);
			this->Go->Name = L"Go";
			this->Go->Size = System::Drawing::Size(75, 23);
			this->Go->TabIndex = 4;
			this->Go->Text = L"Go";
			this->Go->UseVisualStyleBackColor = true;
			this->Go->Click += gcnew System::EventHandler(this, &Form1::Go_Click);
			// 
			// NUStartDate
			// 
			this->NUStartDate->AutoSize = true;
			this->NUStartDate->Location = System::Drawing::Point(16, 69);
			this->NUStartDate->Name = L"NUStartDate";
			this->NUStartDate->Size = System::Drawing::Size(55, 13);
			this->NUStartDate->TabIndex = 5;
			this->NUStartDate->Text = L"Start Date";
			// 
			// NUEndDate
			// 
			this->NUEndDate->AutoSize = true;
			this->NUEndDate->Location = System::Drawing::Point(13, 117);
			this->NUEndDate->Name = L"NUEndDate";
			this->NUEndDate->Size = System::Drawing::Size(52, 13);
			this->NUEndDate->TabIndex = 6;
			this->NUEndDate->Text = L"End Date";
			// 
			// InformationBox
			// 
			this->InformationBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->InformationBox->Location = System::Drawing::Point(228, 13);
			this->InformationBox->Name = L"InformationBox";
			this->InformationBox->ReadOnly = true;
			this->InformationBox->Size = System::Drawing::Size(354, 264);
			this->InformationBox->TabIndex = 7;
			this->InformationBox->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 289);
			this->Controls->Add(this->InformationBox);
			this->Controls->Add(this->NUEndDate);
			this->Controls->Add(this->NUStartDate);
			this->Controls->Add(this->Go);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->StockSymbol);
			this->Controls->Add(this->NAStockSymbolLabel);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		
	private: System::Void StockSymbol_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }
	private: System::Void Go_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 InformationBox->Text = "Sanity Check...";
				 // Commented out for testing purposes
				 if(!readyToStart())
				 {
				   InformationBox->Text += "\nSomething when wrong...";
				   return;
				 }

				std::string startDate = msclr::interop::marshal_as<std::string>(dateTimePicker1->Value.ToString("MM/dd/yyyy"));
				std::string endDate = msclr::interop::marshal_as<std::string>(dateTimePicker1->Value.ToString("MM/dd/yyyy"));
				
				std::string test = msclr::interop::marshal_as<std::string>(dateTimePicker1->Text);

			 }

	private: bool readyToStart()
			 {
				 /*

				 Make sure we call python in here if needed

				 */
				char *error = "";

				const char* data = "Callback function called";
				//Make sure stock field isnt empty
				InformationBox->Text += "\nChecking for stock symbol...";
				if(!StockSymbol->Text->Length )
				{
				  InformationBox->Text += "\nStock symbol sanity check Failed...";
				  return false;
				}
				//Date sanity check
				InformationBox->Text += "\nChecking dates...";
				if(dateTimePicker1->Value.Date >= dateTimePicker2->Value.Date)
				{
					InformationBox->Text += "\nDate sanity check failed...";
				    return false;
				}

				//Opening Local Database
				InformationBox->Text += "\nOpening Local Database...";
				sqlite3 * db;
				CallBackClass callBackMethod;

				int rc = sqlite3_open(databaseName.c_str(), &db);
				if(rc)
				{
					printError(db, error);
					return false;
				}
				else
				{
					
					std::string tempStock   = msclr::interop::marshal_as<std::string>(StockSymbol->Text);
					std::string doesitexist = "SELECT * FROM '" + tempStock + "'";
					
					char *error = "";
					rc = sqlite3_exec(db, doesitexist.c_str(), NULL, NULL, &error);

					InformationBox->Text += msclr::interop::marshal_as<System::String ^>(callBackMethod.getTextUpdate());
					
					if(rc)
					{
						InformationBox->Text +="\nNew table needed, Creating new table..." ;
						std::string createTable = "CREATE TABLE " + tempStock + " (date DATE PRIMARY KEY, Open FLOAT, Close FLOAT, High FLOAT, Low FLOAT );";
						rc = sqlite3_exec(db, createTable.c_str(), &callBackMethod.callback_Tester, (void*)data, &error);
						if (rc)
						{
							printError(db, error);
							return false;
							
						}

						//THIS NEED TO BE MOVED. Determine if we have any dates less than the minimum.. or just get all...
						callPython();
				    }
				    else
				    {
					   InformationBox->Text +="Table Already Exist, Checking for dates..." ;
					}

					/*Get and print information in Table*/
					//
					DateTime tempStartDate = dateTimePicker1->Value;
					DateTime tempEndDate = dateTimePicker2->Value;
					while(tempStartDate <= tempEndDate)
					{
						std::string StartDate = msclr::interop::marshal_as<std::string>(tempStartDate.ToString("MM/dd/yyyy"));
						std::string selectall = "SELECT * from " + tempStock + " WHERE date ='" + StartDate + "'" ;
						rc = sqlite3_exec(db, selectall.c_str(), &callBackMethod.callback_Tester, NULL , &error);
						if (rc)
						{
						    printError(db, error);
							return false;
						}
						InformationBox->Text += msclr::interop::marshal_as<System::String ^>(callBackMethod.getTextUpdate());
						callBackMethod.ClearTextUpdate();
						tempStartDate = tempStartDate.AddDays(1);
					       
					}
					   
				    
				}

				sqlite3_close(db);
				if(error != "") sqlite3_free(error);
				return true;
			 }

	private: void printError(  sqlite3 * db, char * error)
			 {
					/*
					@if this is called. A return must follow because the database is closed here.
					*/
				    InformationBox->Text += "\nError Detected...";
					sqlite3_close(db);
					sqlite3_free(error);
			 }

	private: bool callPython()
			 {
				 /* 
				  1 Renamed python to python3 in order to get this to work with two python version on the same system.
				  2 Moved the Chrome driver to C:\Python36\ 
				  3 Added python to the variable path
				 */
				 std::string argument ("python3 " + 
					 std::string("..\\..\\PSR\\nasdaq.py") + 
					 std::string(" https://www.nasdaq.com/symbol/") + msclr::interop::marshal_as<std::string>(StockSymbol->Text) + ("/historical") + 
					 std::string(" //*[@id=\\\"ddlTimeFrame\\\"]/option[1]") + //update time option
					 std::string(" ") + msclr::interop::marshal_as<std::string>(StockSymbol->Text)  + std::string(" ") +
					 databaseName.c_str() + 
					 " pause");
			     //std::string argument (std::string("..\\PSR\\PSR.py; pause;"));
				 system(argument.c_str());

			     return true;
			 }
	
};

	
}

