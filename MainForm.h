#pragma once
#include "Manager.h"
#include "PopObject.h"
#include "Ball.h"
#include "Rect.h"
#include "Triangle.h"
#include "Star.h"
#include "Bullet.h"
#include "Hunter.h"
#include "Zombie.h"
#include "House.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Pictures.h"
#include<iostream>
#include<cstdlib>
#define MAX_OBJECTS 1000
using namespace System::Windows::Forms;
using namespace System;
using namespace System::Drawing;
using namespace System::Resources;
Manager* manager;

namespace PopBallGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: static MainForm^ form;
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			form = this;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ frame;
	public: System::Windows::Forms::TextBox^ bulletsTxtBox;
	public: System::Windows::Forms::TextBox^ zombiesLeftTxtBox;
	public: System::Windows::Forms::TextBox^ zombiesShotTxtBox;
	protected:



	public:


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ startBtn;
	private: System::Windows::Forms::Timer^ drawTimer;
	public: System::Windows::Forms::Timer^ moveTimer;
	private: System::Windows::Forms::Timer^ appTimer;
	public:
	private:



	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			this->bulletsTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->zombiesLeftTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->zombiesShotTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startBtn = (gcnew System::Windows::Forms::Button());
			this->drawTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->moveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->appTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(15, 13);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(670, 603);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			this->frame->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseMove);
			this->frame->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MainForm::frame_PreviewKeyDown);
			// 
			// bulletsTxtBox
			// 
			this->bulletsTxtBox->Location = System::Drawing::Point(105, 33);
			this->bulletsTxtBox->Name = L"bulletsTxtBox";
			this->bulletsTxtBox->ReadOnly = true;
			this->bulletsTxtBox->Size = System::Drawing::Size(100, 22);
			this->bulletsTxtBox->TabIndex = 1;
			// 
			// zombiesLeftTxtBox
			// 
			this->zombiesLeftTxtBox->Location = System::Drawing::Point(105, 76);
			this->zombiesLeftTxtBox->Name = L"zombiesLeftTxtBox";
			this->zombiesLeftTxtBox->ReadOnly = true;
			this->zombiesLeftTxtBox->Size = System::Drawing::Size(100, 22);
			this->zombiesLeftTxtBox->TabIndex = 2;
			// 
			// zombiesShotTxtBox
			// 
			this->zombiesShotTxtBox->Location = System::Drawing::Point(105, 122);
			this->zombiesShotTxtBox->Name = L"zombiesShotTxtBox";
			this->zombiesShotTxtBox->ReadOnly = true;
			this->zombiesShotTxtBox->Size = System::Drawing::Size(100, 22);
			this->zombiesShotTxtBox->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->zombiesShotTxtBox);
			this->groupBox1->Controls->Add(this->zombiesLeftTxtBox);
			this->groupBox1->Controls->Add(this->bulletsTxtBox);
			this->groupBox1->Location = System::Drawing::Point(703, 18);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(217, 184);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Game state";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Zombies shot";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Zombies left";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Bullets left";
			// 
			// startBtn
			// 
			this->startBtn->Location = System::Drawing::Point(717, 561);
			this->startBtn->Name = L"startBtn";
			this->startBtn->Size = System::Drawing::Size(178, 31);
			this->startBtn->TabIndex = 5;
			this->startBtn->Text = L"Start game";
			this->startBtn->UseVisualStyleBackColor = true;
			this->startBtn->Click += gcnew System::EventHandler(this, &MainForm::startBtn_Click);
			// 
			// drawTimer
			// 
			this->drawTimer->Enabled = true;
			this->drawTimer->Interval = 50;
			this->drawTimer->Tick += gcnew System::EventHandler(this, &MainForm::drawTimer_Tick);
			// 
			// moveTimer
			// 
			this->moveTimer->Enabled = true;
			this->moveTimer->Interval = 50;
			this->moveTimer->Tick += gcnew System::EventHandler(this, &MainForm::moveTimer_Tick);
			// 
			// appTimer
			// 
			this->appTimer->Enabled = true;
			this->appTimer->Interval = 50;
			this->appTimer->Tick += gcnew System::EventHandler(this, &MainForm::appTimer_Tick);
			// 
			// MainForm
			// 
this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
this->ClientSize = System::Drawing::Size(920, 632);
this->Controls->Add(this->startBtn);
this->Controls->Add(this->groupBox1);
this->Controls->Add(this->frame);
this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
this->KeyPreview = true;
this->Name = L"MainForm";
this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
this->Text = L"PopBalls V6: Game";
this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MainForm::MainForm_PreviewKeyDown);
(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
this->groupBox1->ResumeLayout(false);
this->groupBox1->PerformLayout();
this->ResumeLayout(false);

		}
#pragma endregion
		bool playing = false;
		int bulletsCount = 20;
		int zombiesShot = 0;

		private: System::Void startBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			srand(time(NULL));
			manager->destroyAll(frame->Width, frame->Height);
			bulletsCount = 20;
			zombiesShot = 0;
			this->appTimer->Enabled = true;
			for (int i = 0; i < 10; i++) {
				manager->add(new House(frame->Width, frame->Height));
			}
			for (int i = 0; i < 5; i++) {
				manager->add(new Ball(frame->Width, frame->Height));
				manager->add(new Rect(frame->Width, frame->Height));
				manager->add(new Star(frame->Width, frame->Height));
				manager->add(new Triangle(frame->Width, frame->Height));
				manager->add(new Zombie(frame->Width, frame->Height));
			}
			manager->add(new Hunter(frame->Width, frame->Height));
			float x = manager->findObject(&typeid(Hunter))->getX();
			float y = manager->findObject(&typeid(Hunter))->getY();
			manager->add(new Weapon(frame->Width, frame->Height, x, y));
			playing = true;
		}

		private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

			Graphics^ grp = e->Graphics;
			grp->DrawImage(Pictures::background, 0, 0, frame->Width, frame->Height);
			manager->drawFrame(grp);
		}

		private: System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			frame->Invalidate();
		}

		private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			manager->move();
		}

		private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left && playing &&
				manager->countOf(&typeid(Weapon)) > 0 && bulletsCount > 0) {
				float x1 = manager->findObject(&typeid(Weapon))->getX();
				float y1 = manager->findObject(&typeid(Weapon))->getY();
				manager->add(new Bullet(frame->Width, frame->Height, x1, y1, e->X, e->Y));
				bulletsCount--;
			}
		}

		private: System::Void frame_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
			e->IsInputKey = true;
		}
		private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Up) manager->doCommand(cmdStartUp);
			if (e->KeyCode == Keys::Down) manager->doCommand(cmdStartDown);
			if (e->KeyCode == Keys::Right) manager->doCommand(cmdStartRight);
			if (e->KeyCode == Keys::Left) manager->doCommand(cmdStartLeft);
		}
		private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Up) manager->doCommand(cmdStopUp);
			if (e->KeyCode == Keys::Down) manager->doCommand(cmdStopDown);
			if (e->KeyCode == Keys::Right) manager->doCommand(cmdStopRight);
			if (e->KeyCode == Keys::Left) manager->doCommand(cmdStopLeft);
		}

		private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (playing && manager->findObject(&typeid(Weapon)) > 0)
				manager->findObject(&typeid(Weapon))->setDirection(e->X, e->Y);
		}

		private: System::Void MainForm_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
			e->IsInputKey = true;
			//this->KeyPreview = true;
		}
		private: System::Void appTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			bulletsTxtBox->Text = bulletsCount.ToString();
			zombiesLeftTxtBox->Text = manager->countOf(&typeid(Zombie)).ToString();
			zombiesShot = 5 - manager->countOf(&typeid(Zombie));
			zombiesShotTxtBox->Text = zombiesShot.ToString();

			if (playing && manager->countOf(&typeid(Zombie)) <= 0) {
				this->appTimer->Enabled = false;
				MessageBox::Show("YOU WON!\nYou shot all zombies :)", "Game end", MessageBoxButtons::OK);
			}
			else if (playing && bulletsCount <= 0){
					this->appTimer->Enabled = false;
					MessageBox::Show("YOU LOST!\nYou are out of bullets :(", "Game end", MessageBoxButtons::OK);
				}
			else if (playing && manager->countOf(&typeid(Hunter)) <= 0) {
				this->appTimer->Enabled = false;
				MessageBox::Show("YOU LOST!\nYou were eaten by zombie :(", "Game end", MessageBoxButtons::OK);
			}
		}
};
}

