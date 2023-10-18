#pragma once
class UISystem
{
public:
	struct PlayerUI{
		std::vector<UIWindow*> playerUIWindows;
		std::vector<UIWindow*> Hearts;
	};


	UISystem(float _leftTitlePosition, float _topTitlePosition, int _titleSpacing);
	static UISystem* UISystemPointer;
	static UISystem GetUISystem();
	static UISystem GetUISystem(float _leftTitlePosition, float _topTitlePosition, int _titleSpacing);
	void UpdateUIInput();
	static void OpenMainMenu();
	static void CloseMainMenu();
	static void QuitGame();
	PlayerUI GetPlayerUI(int _playerIndex);

	//Table of all UiWindows currently in game.
	std::vector<UIWindow*> UIWindows;
	std::vector<UIWindow*> GameUIWindows;
	std::vector<PlayerUI> playerUIs;
	UIWindow* selectedWindow;

	UIWindow* mainMenu;
	float leftTitlePosition;
	float topTitlePosition;
	int titleSpacing;
private:

	void MakeMainMenu();
	void MakeInGameUI();
	UIWindow* MakeHeartUI(UIWindow* _parent, int _heartNum, int _spacing);
	UIWindow* MakeTitleLetter(char _letter, int _letterNum);
	PlayerUI MakePlayerUI(float _posX, float _posY, int _playerNum);

	UIWindow* GetNextSelect(int _dir);
	UIWindow* GetNextSelectLeft();
	UIWindow* GetNextSelectUp();
	UIWindow* GetNextSelectDown();
};

