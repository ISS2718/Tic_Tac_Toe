#include <wx/wxprec.h>
#include <string.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

short int board[3][3], gameRound, victorios, scorePlayer1, scorePlayer2, gameMatchs, gameTied;

void startBoard() {

	int i, j;

	gameRound = 0;
	victorios = 0;
	
	if (gameMatchs == 0) {

		scorePlayer1 = 0; 
		scorePlayer2 = 0;
		gameTied = 0;
	
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}

	return;
}

int verifyBoard() {

	short int i, j, forPlayer1win, forPlayer2win;

	for (i = 0; i < 3; i++) {
		forPlayer1win = 0;
		forPlayer2win = 0;

		for (j = 0; j < 3; j++) {
			if (board[i][j] == 1) {
				forPlayer1win++;
			}
			else if (board[i][j] == 2) {
				forPlayer2win++;
			}

		}

		if (forPlayer1win == 3) {
			return 1;

		}
		else if (forPlayer2win == 3) {
			return 2;
		}

	}


	for (j = 0; j < 3; j++) {
		forPlayer1win = 0;
		forPlayer2win = 0;

		for (i = 0; i < 3; i++) {
			if (board[i][j] == 1) {
				forPlayer1win++;
			}
			else if (board[i][j] == 2) {
				forPlayer2win++;
			}
		}

		if (forPlayer1win == 3) {
			return 1;
		}
		else if (forPlayer2win == 3) {
			return 2;
		}
	}

	forPlayer1win = 0;
	forPlayer2win = 0;

	for (i = 0; i < 3; i++) {
		if (board[i][i] == 1) {
			forPlayer1win++;
		}
		else if (board[i][i] == 2) {

			forPlayer2win++;
		}
	}

	if (forPlayer1win == 3) {
		return 1;
	}
	else if (forPlayer2win == 3) {
		return 2;
	}

	forPlayer1win = 0;
	forPlayer2win = 0;

	for (i = 0; i < 3; i++) {
		if (board[i][2 - i] == 1) {
			forPlayer1win++;
		}
		else if (board[i][2 - i] == 2) {
			forPlayer2win++;
		}
	}

	if (forPlayer1win == 3) {
		return 1;
	}
	else if (forPlayer2win == 3) {
		return 2;
	}

	if (gameRound >= 9) {
		return 3;
	}

	return 0;
}

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
		wxMenu* m_menuResults;

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

		char m_msgStatusBar[200];

	private:
		void OnNewGame(wxCommandEvent& event);
		void OnShowScoreboard(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

		void EnableButtons();
		void DisableButtons();
		void EndGame();
		
		void OnBtnUpLeftClick(wxCommandEvent& event);
		void OnBtnUpMidClick(wxCommandEvent& event);
		void OnBtnUpRightClick(wxCommandEvent& event);

		void OnBtnMidLeftClick(wxCommandEvent& event);
		void OnBtnMidMidClick(wxCommandEvent& event);
		void OnBtnMidRightClick(wxCommandEvent& event);

		void OnBtnLowLeftClick(wxCommandEvent& event);
		void OnBtnLowMidClick(wxCommandEvent& event);
		void OnBtnLowRightClick(wxCommandEvent& event);
		
		void OnBtnUpLeftEnterWindow(wxCommandEvent& event);
		void OnBtnUpMidEnterWindow(wxCommandEvent& event);
		void OnBtnUpRightEnterWindow(wxCommandEvent& event);

		void OnBtnMidLeftEnterWindow(wxCommandEvent& event);
		void OnBtnMidMidEnterWindow(wxCommandEvent& event);
		void OnBtnMidRightEnterWindow(wxCommandEvent& event);

		void OnBtnLowLeftEnterWindow(wxCommandEvent& event);
		void OnBtnLowMidEnterWindow(wxCommandEvent& event);
		void OnBtnLowRightEnterWindow(wxCommandEvent& event);

		void OnBtnUpLeftLeaveWindow(wxCommandEvent& event);
		void OnBtnUpMidLeaveWindow(wxCommandEvent& event);
		void OnBtnUpRightLeaveWindow(wxCommandEvent& event);

		void OnBtnMidLeftLeaveWindow(wxCommandEvent& event);
		void OnBtnMidMidLeaveWindow(wxCommandEvent& event);
		void OnBtnMidRightLeaveWindow(wxCommandEvent& event);

		void OnBtnLowLeftLeaveWindow(wxCommandEvent& event);
		void OnBtnLowMidLeaveWindow(wxCommandEvent& event);
		void OnBtnLowRightLeaveWindow(wxCommandEvent& event);

};

bool TicTacToe::OnInit() {
	MainFrame* frame = new MainFrame();
	frame->SetIcon(wxIcon("small.ico", wxBITMAP_TYPE_ICO));
	frame->Show();
	
	gameMatchs = 0;
	startBoard();

	return true;
}

enum {
	ID_NewGame = 1,
	ID_ScoreBoard =2
};


MainFrame::MainFrame() :wxFrame(NULL, wxID_ANY, "Tic Tac Toe") {
	
	this->SetSizeHints(600, 600);
	this->SetBackgroundColour(wxColour(204, 255, 255));

	m_mainMenuBar = new wxMenuBar(0);
	m_menuGame = new wxMenu();
	m_menuHelp = new wxMenu();
	m_menuResults = new wxMenu();

	m_mainMenuBar->Append(m_menuGame, "Game");
	m_mainMenuBar->Append(m_menuHelp, "Help");

	m_menuGame->Append(ID_NewGame, _("&New Game\tCtrl+N"), "Start a new mach");
	m_menuGame->AppendSeparator();
	m_menuGame->Append(ID_ScoreBoard,_("&Scoreboard\tCtrl+S"), "Show game scoreboard");
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
	m_btnUpLeft->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnUpLeft, 0, wxALL | wxEXPAND, 5);

	m_btnUpMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpMid->SetFont(font);
	m_btnUpMid->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnUpMid, 0, wxALL | wxEXPAND, 5);

	m_btnUpRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpRight->SetFont(font);
	m_btnUpRight->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnUpRight, 0, wxALL | wxEXPAND, 5);

	m_btnMidLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidLeft->SetFont(font);
	m_btnMidLeft->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnMidLeft, 0, wxALL | wxEXPAND, 5);

	m_btnMidMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidMid->SetFont(font);
	m_btnMidMid->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnMidMid, 0, wxALL | wxEXPAND, 5);

	m_btnMidRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidRight->SetFont(font);
	m_btnMidRight->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnMidRight, 0, wxALL | wxEXPAND, 5);

	m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowLeft->SetFont(font);
	m_btnLowLeft->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);

	m_btnLowMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowMid->SetFont(font);
	m_btnLowMid->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnLowMid, 0, wxALL | wxEXPAND, 5);

	m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowRight->SetFont(font);
	m_btnLowRight->SetBackgroundColour(wxColor(204, 204, 255));
	m_gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);
	//---------
	

	this->SetSizer(m_gBoard);
	this->Layout();

	m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	DisableButtons();
	SetStatusText("Go to New Game for start a match.");

	Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &MainFrame::OnShowScoreboard, this, ID_ScoreBoard);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

	
	m_btnUpLeft->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnUpLeftClick), NULL, this);
	m_btnUpMid->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnUpMidClick), NULL, this);
	m_btnUpRight->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnUpRightClick), NULL, this);

	m_btnMidLeft->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnMidLeftClick), NULL, this);
	m_btnMidMid->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
	m_btnMidRight->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);

	m_btnLowLeft->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
	m_btnLowMid->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
	m_btnLowRight->Connect(wxEVT_BUTTON, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);

	m_btnUpLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpLeftEnterWindow), NULL, this);
	m_btnUpMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpMidEnterWindow), NULL, this);
	m_btnUpRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpRightEnterWindow), NULL, this);

	m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftEnterWindow), NULL, this);
	m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidEnterWindow), NULL, this);
	m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightEnterWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftEnterWindow), NULL, this);
	m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidEnterWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightEnterWindow), NULL, this);

	m_btnUpLeft->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpLeftLeaveWindow), NULL, this);
	m_btnUpMid->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpMidLeaveWindow), NULL, this);
	m_btnUpRight->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpRightLeaveWindow), NULL, this);

	m_btnMidLeft->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftLeaveWindow), NULL, this);
	m_btnMidMid->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidLeaveWindow), NULL, this);
	m_btnMidRight->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightLeaveWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftLeaveWindow), NULL, this);
	m_btnLowMid->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidLeaveWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightLeaveWindow), NULL, this);
	
}

wxIMPLEMENT_APP(TicTacToe);

void  MainFrame::EnableButtons() {
	m_btnUpLeft->Enable();
	m_btnUpMid->Enable();
	m_btnUpRight->Enable();
	
	m_btnMidLeft->Enable();
	m_btnMidMid->Enable();
	m_btnMidRight->Enable();
	
	m_btnLowLeft->Enable();
	m_btnLowMid->Enable();
	m_btnLowRight->Enable();

	m_btnUpLeft->SetLabelText("");
	m_btnUpMid->SetLabelText("");
	m_btnUpRight->SetLabelText("");

	m_btnMidLeft->SetLabelText("");
	m_btnMidMid->SetLabelText("");
	m_btnMidRight->SetLabelText("");

	m_btnLowLeft->SetLabelText("");
	m_btnLowMid->SetLabelText("");
	m_btnLowRight->SetLabelText("");

	m_btnUpLeft->SetBackgroundColour(wxColor(204, 204, 255));
	m_btnUpMid->SetBackgroundColour(wxColor(204, 204, 255));
	m_btnUpRight->SetBackgroundColour(wxColor(204, 204, 255));

	m_btnMidLeft->SetBackgroundColour(wxColor(204, 204, 255));
	m_btnMidMid->SetBackgroundColour(wxColor(204, 204, 255));
	m_btnMidRight->SetBackgroundColour(wxColor(204, 204, 255));

	m_btnLowLeft->SetBackgroundColour(wxColor(204, 204, 255));
	m_btnLowMid->SetBackgroundColour(wxColor(204, 204, 255));
	m_btnLowRight->SetBackgroundColour(wxColor(204, 204, 255));
}

void  MainFrame::DisableButtons() {
	m_btnUpLeft->Disable();
	m_btnUpMid->Disable();
	m_btnUpRight->Disable();

	m_btnMidLeft->Disable();
	m_btnMidMid->Disable();
	m_btnMidRight->Disable();

	m_btnLowLeft->Disable();
	m_btnLowMid->Disable();
	m_btnLowRight->Disable();

	m_btnUpLeft->SetLabelText("");
	m_btnUpMid->SetLabelText("");
	m_btnUpRight->SetLabelText("");

	m_btnMidLeft->SetLabelText("");
	m_btnMidMid->SetLabelText("");
	m_btnMidRight->SetLabelText("");

	m_btnLowLeft->SetLabelText("");
	m_btnLowMid->SetLabelText("");
	m_btnLowRight->SetLabelText("");

	m_btnUpLeft->SetBackgroundColour(wxColor(147, 147, 237));
	m_btnUpMid->SetBackgroundColour(wxColor(147, 147, 237));
	m_btnUpRight->SetBackgroundColour(wxColor(147, 147, 237));

	m_btnMidLeft->SetBackgroundColour(wxColor(147, 147, 237));
	m_btnMidMid->SetBackgroundColour(wxColor(147, 147, 237));
	m_btnMidRight->SetBackgroundColour(wxColor(147, 147, 237));

	m_btnLowLeft->SetBackgroundColour(wxColor(147, 147, 237));
	m_btnLowMid->SetBackgroundColour(wxColor(147, 147, 237));
	m_btnLowRight->SetBackgroundColour(wxColor(147, 147, 237));
}

void  MainFrame::EndGame() {
	char message[200] = "";

	gameMatchs++;

	if (victorios == 1) {
		strcpy(message, "Player 1 ( X ) WIN!\n");
		scorePlayer1++;
	}
	else if (victorios == 2){
		strcpy(message, "Player 2 ( O ) WIN!\n");
		scorePlayer2++;
	}
	else if (victorios == 3) {
		strcpy(message, "Tied match!\n");
		gameTied++;
	}

	strcat(message, wxString::Format("Matchs: %i.\nPlayer 1 wins: %i.\nPlayer 2 wins: %i.\nTied matchs: %i.\n", gameMatchs, scorePlayer1,
		scorePlayer2, gameTied));

	strcat(message, "Play again?");

	if (wxMessageBox(message, "End of Match", wxYES_NO | wxICON_INFORMATION) == wxYES) {
		startBoard();
		EnableButtons();
	}
	else {
		Close(true);
	}


}

void MainFrame::OnNewGame(wxCommandEvent& event) {
	startBoard();
	EnableButtons();
	SetStatusText("It's player 1 turn.");
}

void MainFrame::OnExit(wxCommandEvent& event){
	Close(true);
}

void MainFrame::OnShowScoreboard(wxCommandEvent& event) {
	wxMessageBox(wxString::Format("Matchs: %i.\nPlayer 1 wins: %i.\nPlayer 2 wins: %i.\nTied matchs: %i.\n", gameMatchs, scorePlayer1, 
		scorePlayer2, gameTied), "Scoreboard", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("This is Tic Tac Toe example in C/C++", "About Tic Tac Toe", wxOK | wxICON_INFORMATION);
}


void MainFrame::OnBtnUpLeftClick(wxCommandEvent& event) {
	if (m_btnUpLeft->IsEnabled()) {
		if (gameRound%2 == 0) {
			board[0][0] = 1;
			m_btnUpLeft->SetLabelText("X");
		}
		else {
			board[0][0] = 2;
			m_btnUpLeft->SetLabelText("O");
		}

		m_btnUpLeft->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnUpMidClick(wxCommandEvent& event) {
	if (m_btnUpMid->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[0][1] = 1;
			m_btnUpMid->SetLabelText("X");
		}
		else {
			board[0][1] = 2;
			m_btnUpMid->SetLabelText("O");
		}

		m_btnUpMid->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnUpRightClick(wxCommandEvent& event) {
	if (m_btnUpRight->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[0][2] = 1;
			m_btnUpRight->SetLabelText("X");
		}
		else {
			board[0][2] = 2;
			m_btnUpRight->SetLabelText("O");
		}

		m_btnUpRight->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event) {
	if (m_btnMidLeft->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[1][0] = 1;
			m_btnMidLeft->SetLabelText("X");
		}
		else {
			board[1][0] = 2;
			m_btnMidLeft->SetLabelText("O");
		}

		m_btnMidLeft->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnMidMidClick(wxCommandEvent& event) {
	if (m_btnMidMid->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[1][1] = 1;
			m_btnMidMid->SetLabelText("X");
		}
		else {
			board[1][1] = 2;
			m_btnMidMid->SetLabelText("O");
		}

		m_btnMidMid->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnMidRightClick(wxCommandEvent& event) {
	if (m_btnMidRight->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[1][2] = 1;
			m_btnMidRight->SetLabelText("X");
		}
		else {
			board[1][2] = 2;
			m_btnMidRight->SetLabelText("O");
		}

		m_btnMidRight->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event) {
	if (m_btnLowLeft->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[2][0] = 1;
			m_btnLowLeft->SetLabelText("X");
		}
		else {
			board[2][0] = 2;
			m_btnLowLeft->SetLabelText("O");
		}

		m_btnLowLeft->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnLowMidClick(wxCommandEvent& event) {
	if (m_btnLowMid->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[2][1] = 1;
			m_btnLowMid->SetLabelText("X");
		}
		else {
			board[2][1] = 2;
			m_btnLowMid->SetLabelText("O");
		}

		m_btnLowMid->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}

void MainFrame::OnBtnLowRightClick(wxCommandEvent& event) {
	if (m_btnLowRight->IsEnabled()) {
		if (gameRound % 2 == 0) {
			board[2][2] = 1;
			m_btnLowRight->SetLabelText("X");
		}
		else {
			board[2][2] = 2;
			m_btnLowRight->SetLabelText("O");
		}

		m_btnLowRight->Disable();
	}

	gameRound++;
	victorios = verifyBoard();

	if (victorios != 0) {
		EndGame();
	}
}


void MainFrame::OnBtnUpLeftEnterWindow(wxCommandEvent& event) {
	if (m_btnUpLeft->IsEnabled()) {
		m_btnUpLeft->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnUpLeftLeaveWindow(wxCommandEvent& event) {
	if (m_btnUpLeft->IsEnabled()) {
		m_btnUpLeft->SetBackgroundColour(wxColor(204, 204, 255));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");
		
		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnUpMidEnterWindow(wxCommandEvent& event) {
	if (m_btnUpMid->IsEnabled()) {
		m_btnUpMid->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnUpMidLeaveWindow(wxCommandEvent& event) {
	if (m_btnUpMid->IsEnabled()) {
		m_btnUpMid->SetBackgroundColour(wxColor(204, 204, 255));

		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnUpRightEnterWindow(wxCommandEvent& event) {
	if (m_btnUpRight->IsEnabled()) {
		m_btnUpRight->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnUpRightLeaveWindow(wxCommandEvent& event) {
	if (m_btnUpRight->IsEnabled()) {
		m_btnUpRight->SetBackgroundColour(wxColor(204, 204, 255));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnMidLeftEnterWindow(wxCommandEvent& event) {
	if (m_btnMidLeft->IsEnabled()) {
		m_btnMidLeft->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidLeftLeaveWindow(wxCommandEvent& event) {
	if (m_btnMidLeft->IsEnabled()) {
		m_btnMidLeft->SetBackgroundColour(wxColor(204, 204, 255));
			strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnMidMidEnterWindow(wxCommandEvent& event) {
	if (m_btnMidMid->IsEnabled()) {
		m_btnMidMid->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidMidLeaveWindow(wxCommandEvent& event) {
	if (m_btnMidMid->IsEnabled()) {
		m_btnMidMid->SetBackgroundColour(wxColor(204, 204, 255));
			strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnMidRightEnterWindow(wxCommandEvent& event) {
	if (m_btnMidRight->IsEnabled()) {
		m_btnMidRight->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidRightLeaveWindow(wxCommandEvent& event) {
	if (m_btnMidRight->IsEnabled()) {
		m_btnMidRight->SetBackgroundColour(wxColor(204, 204, 255));
			strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnLowLeftEnterWindow(wxCommandEvent& event) {
	if (m_btnLowLeft->IsEnabled()) {
		m_btnLowLeft->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowLeftLeaveWindow(wxCommandEvent& event) {
	if (m_btnLowLeft->IsEnabled()) {
		m_btnLowLeft->SetBackgroundColour(wxColor(204, 204, 255));
			strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnLowMidEnterWindow(wxCommandEvent& event) {
	if (m_btnLowMid->IsEnabled()) {
		m_btnLowMid->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowMidLeaveWindow(wxCommandEvent& event) {
	if (m_btnLowMid->IsEnabled()) {
		m_btnLowMid->SetBackgroundColour(wxColor(204, 204, 255));
			strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnLowRightEnterWindow(wxCommandEvent& event) {
	if (m_btnLowRight->IsEnabled()) {
		m_btnLowRight->SetBackgroundColour(wxColor(147, 147, 237));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowRightLeaveWindow(wxCommandEvent& event) {
	if (m_btnLowRight->IsEnabled()) {
		m_btnLowRight->SetBackgroundColour(wxColor(204, 204, 255));
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n)");

		if (gameRound % 2 == 0) {
			strcat(m_msgStatusBar, " X!");
		}
		else {
			strcat(m_msgStatusBar, " O!");
		}
	}
	SetStatusText(m_msgStatusBar);
}

