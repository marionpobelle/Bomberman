#include <vector>
#include <cmath>
#include "UIWindow.h"
#include "UISystem.h"

UISystem* UISystem::UISystemPointer = nullptr;

UISystem::UISystem(float _leftTitlePosition, float _topTitlePosition, int _titleSpacing) : leftTitlePosition(_leftTitlePosition), topTitlePosition(_topTitlePosition), titleSpacing(_titleSpacing) {
    MakeMainMenu();
    MakeInGameUI();

}

UISystem UISystem::GetUISystem() {
    if (UISystemPointer == nullptr) {
        UISystemPointer = new UISystem(0,0,0);
    }
    return *UISystemPointer;
}

UISystem UISystem::GetUISystem(float _leftTitlePosition, float _topTitlePosition, int _titleSpacing) {
    if (UISystemPointer == nullptr) {
        UISystemPointer = new UISystem(_leftTitlePosition, _topTitlePosition, _titleSpacing);
    }
    return *UISystemPointer;
}

UIWindow* UISystem::MakeHeartUI(UIWindow* _parent, int _heartNum, int _spacing) {
    UIWindow* Heart = new UIWindow(0.25f, 0.5f, 0.5f, 0.5f, 6);
    Heart->position.xPx = _spacing * _heartNum;
    Heart->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    Heart->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    Heart->spriteName = "HEART";
    Heart->isImage = true;
    Heart->isOpened = false;
    _parent->AddWindowChild(Heart);
    GameUIWindows.push_back(Heart);
    UIWindows.push_back(Heart);
    return Heart;
}

UISystem::PlayerUI UISystem::MakePlayerUI(float _posX, float _posY, int _playerNum) {
    UIWindow* player = new UIWindow(_posX, _posY, 0.35f, 1.f, 5);
    player->SetText("Player " + std::to_string(_playerNum));
    player->SetTextHorAlignment(UIWindow::HoriAlignment::HMiddle);
    player->SetTextVerAlignment(UIWindow::VertAlignment::Top);
    player->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    player->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    player->isOpened = false;

    UIWindow* HealthBar = new UIWindow(0.5f, 0.4f, 1.f, 0.2f, 5);
    HealthBar->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    HealthBar->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    HealthBar->isOpened = false;
    
    UIWindow* Heart1 = MakeHeartUI(HealthBar, 1, 8);
    UIWindow* Heart2 = MakeHeartUI(HealthBar, 2, 8);
    UIWindow* Heart3 = MakeHeartUI(HealthBar, 3, 8);
    UIWindow* Heart4 = MakeHeartUI(HealthBar, 4, 8);


    UIWindow* ControlTips = new UIWindow(0.5f, 0.75f, 1.f, 0.45f, 5);
    player->SetText("Player " + std::to_string(_playerNum));
    player->SetTextHorAlignment(UIWindow::HoriAlignment::HMiddle);
    player->SetTextVerAlignment(UIWindow::VertAlignment::VMiddle);
    ControlTips->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    ControlTips->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    ControlTips->isOpened = false;

    player->AddWindowChild(HealthBar);
    player->AddWindowChild(ControlTips);
    GameUIWindows.push_back(player);
    GameUIWindows.push_back(HealthBar);
    GameUIWindows.push_back(ControlTips);
    UIWindows.push_back(player);
    UIWindows.push_back(HealthBar);
    UIWindows.push_back(ControlTips);

    PlayerUI playerUI;
    playerUI.playerUIWindows.push_back(player);
    playerUI.playerUIWindows.push_back(HealthBar);
    playerUI.playerUIWindows.push_back(ControlTips);
    playerUI.Hearts.push_back(Heart1);
    playerUI.Hearts.push_back(Heart2);
    playerUI.Hearts.push_back(Heart3);
    playerUI.Hearts.push_back(Heart4);
    return playerUI;
}


void UISystem::MakeInGameUI() {
    playerUIs.push_back(MakePlayerUI(0.f, 0.5f, 1));
    playerUIs.push_back(MakePlayerUI(1.f, 0.5f, 2));
}

UISystem::PlayerUI UISystem::GetPlayerUI(int _playerIndex) {
    return playerUIs[_playerIndex];
}

UIWindow* UISystem::MakeTitleLetter(char _letter, int _letterNum) {
    UIWindow* Letter = new UIWindow(leftTitlePosition, topTitlePosition, 0.5f, 0.5f, 6);
    Letter->position.xPx = titleSpacing * _letterNum;
    Letter->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    Letter->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    Letter->spriteName = _letter;
    Letter->isImage = true;
    Letter->isOpened = true;
    return Letter;
}

void UISystem::MakeMainMenu() {
    UIWindow* MainMenu = new UIWindow(0.5f, 0.5f, 1.f, 1.f, 5);
    MainMenu->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    MainMenu->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    MainMenu->isOpened = true;


    //MAKING THE TITLE
    UIWindow* B = MakeTitleLetter('B', 1);
    UIWindow* O = MakeTitleLetter('O', 2);
    UIWindow* M = MakeTitleLetter('M', 3);
    UIWindow* B1 = MakeTitleLetter('B', 4);
    UIWindow* E = MakeTitleLetter('E', 5);
    UIWindow* R = MakeTitleLetter('R', 6);


    UIWindow* PlayButton = new UIWindow(0.5f, 0.45f, 0.2f, 0.1f, 5);
    PlayButton->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    PlayButton->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    PlayButton->SetText("PLAY");
    PlayButton->SetTextHorAlignment(UIWindow::HoriAlignment::HMiddle);
    PlayButton->SetTextVerAlignment(UIWindow::VertAlignment::VMiddle);
    PlayButton->isSelectable = true;
    PlayButton->isSelected = true;
    selectedWindow = PlayButton;
    PlayButton->CallBack = CloseMainMenu;
    PlayButton->isOpened = true;

    UIWindow* QuitButton = new UIWindow(0.5f, 0.55f, 0.2f, 0.1f, 5);
    QuitButton->SetWindowHorAlignment(UIWindow::HoriAlignment::HMiddle);
    QuitButton->SetWindowVerAlignment(UIWindow::VertAlignment::VMiddle);
    QuitButton->SetText("QUIT");
    QuitButton->SetTextHorAlignment(UIWindow::HoriAlignment::HMiddle);
    QuitButton->SetTextVerAlignment(UIWindow::VertAlignment::VMiddle);
    QuitButton->isSelectable = true;
    QuitButton->CallBack = QuitGame;
    QuitButton->isOpened = true;

    MainMenu->AddWindowChild(PlayButton);
    MainMenu->AddWindowChild(QuitButton);
    MainMenu->AddWindowChild(B);
    MainMenu->AddWindowChild(O);
    MainMenu->AddWindowChild(M);
    MainMenu->AddWindowChild(B1);
    MainMenu->AddWindowChild(E);
    MainMenu->AddWindowChild(R);

    UIWindows.push_back(MainMenu);
    UIWindows.push_back(PlayButton);
    UIWindows.push_back(QuitButton);
    UIWindows.push_back(B);
    UIWindows.push_back(O);
    UIWindows.push_back(M);
    UIWindows.push_back(B1);
    UIWindows.push_back(E);
    UIWindows.push_back(R);
    mainMenu = MainMenu;
}

void UISystem::CloseMainMenu() {
    UISystemPointer->mainMenu->CloseWindow();

    for (auto i = UISystemPointer->GameUIWindows.begin(); i != UISystemPointer->GameUIWindows.end(); i++)
    {
        UIWindow* gameWindow = *i;
        gameWindow->isOpened = true;
    }
}
void UISystem::OpenMainMenu() {
    UISystemPointer->mainMenu->OpenWindow();
    for (auto i = UISystemPointer->GameUIWindows.begin(); i != UISystemPointer->GameUIWindows.end(); i++)
    {
        UIWindow* gameWindow = *i;
        gameWindow->isOpened = false;
    }
}
void UISystem::QuitGame() {
    PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
}


//UI INPUT

UIWindow* UISystem::GetNextSelect(int _dir) {
    std::vector<UIWindow*> openedUIWindows;
    for (auto windowIter = UIWindows.begin(); windowIter != UIWindows.end(); windowIter++)
    {
        UIWindow* window = *windowIter;
        if (!window->isOpened || !window->isSelectable || window == selectedWindow) {
            continue;
        }
        openedUIWindows.push_back(window);
    }
    UIWindow* nextSelect = nullptr;
    int nextSelectPos = 1000000;
    for (auto windowIter = openedUIWindows.begin(); windowIter != openedUIWindows.end(); windowIter++) {
        UIWindow* compWindow = *windowIter;
        int dirPos = 1;
        if (_dir == VK_DOWN || _dir == VK_UP) {
            dirPos = compWindow->GetYWindowPosition(*compWindow) - selectedWindow->GetYWindowPosition(*selectedWindow);
        }
        if (_dir == VK_RIGHT || _dir == VK_LEFT) {
            dirPos = compWindow->GetXWindowPosition(*compWindow) - selectedWindow->GetXWindowPosition(*selectedWindow);
        }
        if (dirPos < 0 && (_dir == VK_DOWN || _dir == VK_RIGHT) || dirPos > 0 && (_dir == VK_UP || _dir == VK_LEFT)) {
            continue;
        }
        if (nextSelectPos != 1000000 && (nextSelectPos < dirPos && (_dir == VK_DOWN || _dir == VK_RIGHT) || nextSelectPos > dirPos && (_dir == VK_UP || _dir == VK_LEFT)) ) {
            continue;
        }
        nextSelect = compWindow;
        nextSelectPos = dirPos;
    }
    return nextSelect;
}



void UISystem::UpdateUIInput() {
    if (GetAsyncKeyState(VK_DOWN)) {
        UIWindow* nextSelect = GetNextSelect(VK_DOWN);
        if (!nextSelect) {
            return;
        }
        selectedWindow->isSelected = false;
        nextSelect->isSelected = true;
        selectedWindow = nextSelect;
    }
    if (GetAsyncKeyState(VK_UP)) {
        UIWindow* nextSelect = GetNextSelect(VK_UP);
        if (!nextSelect) {
            return;
        }
        selectedWindow->isSelected = false;
        nextSelect->isSelected = true;
        selectedWindow = nextSelect;
    }
    if (GetAsyncKeyState(VK_LEFT)) {
        UIWindow* nextSelect = GetNextSelect(VK_LEFT);
        if (!nextSelect) {
            return;
        }
        selectedWindow->isSelected = false;
        nextSelect->isSelected = true;
        selectedWindow = nextSelect;
    }
    if (GetAsyncKeyState(VK_RIGHT)) {
        UIWindow* nextSelect = GetNextSelect(VK_RIGHT);
        if (!nextSelect) {
            return;
        }
        selectedWindow->isSelected = false;
        nextSelect->isSelected = true;
        selectedWindow = nextSelect;
    }

    if (GetAsyncKeyState(VK_RETURN)) {
        selectedWindow->CallBack();
    }
}