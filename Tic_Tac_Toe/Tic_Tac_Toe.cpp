#include <wx/wxprec.h>
#include <string.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class TicTacToe : public wxApp
{
	public:
		virtual bool OnInit();
};

class MainFrame : public wxFrame
{
	public:
		MainFrame();

	protected:
		wxMenuBar* m_mainMenuBar;
		wxMenu* m_menuGame;
		wxMenu* m_menuHelp;

		wxGridSizer* m_gBoard;
		
		wxButton* m_btnUpLeft;
		wxButton* m_btnUpMid;
		wxButton* m_btnUpRight;
		
		wxButton* m_btnMidLeft;
		wxButton* m_btnMidMid;
		wxButton* m_btnMidRight;

		wxButton* m_btnLowLeft;
		wxButton* m_btnLowMid;
		wxButton* m_btnLowRight;
		
		wxStatusBar* m_statusBar;
		char msgSatutsBar[200];

	private:
		void OnNewGame(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

		void OnBtnUpLeftClick(wxCommandEvent& event);
		void OnBtnUpMidClick(wxCommandEvent& event);
		void OnBtnUpRightClick(wxCommandEvent& event);

		void OnBtnMidLeftClick(wxCommandEvent& event);
		void OnBtnMidMidClick(wxCommandEvent& event);
		void OnBtnMidRightClick(wxCommandEvent& event);

		void OnBtnLowLeftClick(wxCommandEvent& event);
		void OnBtnLowMidClick(wxCommandEvent& event);
		void OnBtnLowRightClick(wxCommandEvent& event);


};

bool TicTacToe::OnInit() {
	MainFrame* frame = new MainFrame();
	frame->Show();

	//[ALTERAR] Na Etapa 3, vamo inicializar o tabuleiro

	return true;
}

enum {
	ID_NewGame = 1
};


MainFrame::MainFrame() :wxFrame(NULL, wxID_ANY, "Tic Tac Toe") {
	this->SetSizeHints(600, 600);

	m_mainMenuBar = new wxMenuBar(0);
	m_menuGame = new wxMenu();
	m_menuHelp = new wxMenu();

	m_mainMenuBar->Append(m_menuGame, "Game");
	m_mainMenuBar->Append(m_menuHelp, "Help");

	m_menuGame->Append(ID_NewGame, "&New Game\tCtrl+N", "Start a new mach");
	m_menuGame->AppendSeparator();
	m_menuGame->Append(wxID_EXIT);

	m_menuHelp->Append(wxID_ABOUT);

	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	this->SetMenuBar(m_mainMenuBar);

	m_gBoard = new wxGridSizer(3, 3, 0, 0);
	m_gBoard->SetMinSize(500, 500);
	
	//---------Creating All Button
	m_btnUpLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpLeft->SetFont(font);
	m_gBoard->Add(m_btnUpLeft, 0, wxALL | wxEXPAND, 5);

	m_btnUpMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpMid->SetFont(font);
	m_gBoard->Add(m_btnUpMid, 0, wxALL | wxEXPAND, 5);

	m_btnUpRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpRight->SetFont(font);
	m_gBoard->Add(m_btnUpRight, 0, wxALL | wxEXPAND, 5);

	m_btnMidLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidLeft->SetFont(font);
	m_gBoard->Add(m_btnMidLeft, 0, wxALL | wxEXPAND, 5);

	m_btnMidMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidMid->SetFont(font);
	m_gBoard->Add(m_btnMidMid, 0, wxALL | wxEXPAND, 5);

	m_btnMidRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidRight->SetFont(font);
	m_gBoard->Add(m_btnMidRight, 0, wxALL | wxEXPAND, 5);

	m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowLeft->SetFont(font);
	m_gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);

	m_btnLowMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowMid->SetFont(font);
	m_gBoard->Add(m_btnLowMid, 0, wxALL | wxEXPAND, 5);

	m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowRight->SetFont(font);
	m_gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);
	//---------

	this->SetSizer(m_gBoard);
	this->Layout();

	m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

	m_btnUpLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpLeftClick), NULL, this);
	m_btnUpMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpMidClick), NULL, this);
	m_btnUpRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpRightClick), NULL, this);

	m_btnMidLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidLeftClick), NULL, this);
	m_btnMidMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
	m_btnMidRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);

	m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
	m_btnLowMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
	m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);
}

wxIMPLEMENT_APP(TicTacToe);

void MainFrame::OnNewGame(wxCommandEvent& event) {
	wxMessageBox("Test... New Game!", "New Game...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent& event){
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("This is Tic Tac Toe example in C/C++", "About Tic Tac Toe", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnUpLeftClick(wxCommandEvent& event) {
	wxMessageBox("Button: Up Left", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnUpMidClick(wxCommandEvent& event) {
	wxMessageBox("Button: Up Mid", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnUpRightClick(wxCommandEvent& event) {
	wxMessageBox("Button: Up Right", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event) {
	wxMessageBox("Button: Mid Left", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnMidMidClick(wxCommandEvent& event) {
	wxMessageBox("Button: Mid Mid", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnMidRightClick(wxCommandEvent& event) {
	wxMessageBox("Button: Mid Right", "Test...", wxOK | wxICON_INFORMATION);
}


void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event) {
	wxMessageBox("Button: Low Left", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnLowMidClick(wxCommandEvent& event) {
	wxMessageBox("Button: Low Mid", "Test...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBtnLowRightClick(wxCommandEvent& event) {
	wxMessageBox("Button: Low Right", "Test...", wxOK | wxICON_INFORMATION);
}