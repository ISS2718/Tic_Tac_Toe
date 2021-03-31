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

	private:
		void OnNewGame(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
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


	Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
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