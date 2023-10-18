#include <windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "Definitions.h"
#include "UIWindow.h"

UIWindow::UIWindow() {
	return;
}

// Init Window with scale parameter
UIWindow::UIWindow(float _xPos, float _yPos, float _xSize, float _ySize, int _zPosition) : position(_xPos, _yPos), size(_xSize, _ySize), zPosition(_zPosition) {

}

// Init Window with pixel parameter
UIWindow::UIWindow(int _xPos, int _yPos, int _xSize, int _ySize, int _zPosition) : position(_xPos, _yPos), size(_xSize, _ySize), zPosition(_zPosition) {

}


int UIWindow::GetLastSpaceOfLine(int pos, int charCount) {
	int nextSpace = (int)text.find_first_of(' ', pos);
	if (nextSpace == -1 || (nextSpace - charCount > maxCharByLines-1)) {
		return pos;
	}
	return GetLastSpaceOfLine(nextSpace+1, charCount);
}

void UIWindow::FormatText() {
	int linesMax = floor(text.length() / maxCharByLines)+1;
	int cursorPos = 0;
	for (int i = 0; i < linesMax; i++)
	{
		if (i == linesMax-1) {
			lines.push_back(text.substr(cursorPos, text.length()- cursorPos));
			break;
		}
		int nextSpace = GetLastSpaceOfLine(cursorPos, cursorPos);
		lines.push_back(text.substr(cursorPos, nextSpace - cursorPos));
		cursorPos = nextSpace ;
	}
}

std::string UIWindow::DisplayWindow() {
	const int x = GetXWindowSize(*this);
	const int y = GetYWindowSize(*this);
	std::string stringDisplayed;

	for (int j = 0; j < x * (y * ySubOffset - ceilf(lines.size() * ySubOffset) + yLineOffset); j++)
	{
		stringDisplayed += " ";
	}
	for (int i = 0; i < lines.size(); i++)
	{
		int xStartPos = x * xSubOffset - lines[i].size() * xSubOffset + xCharOffset;
		int xEndPos = x * (1-xSubOffset) - lines[i].size() * (1-xSubOffset) + xCharOffset*-1;
		for (int j = 0; j < xStartPos; j++)
		{
			stringDisplayed += " ";
		}
		for (int j = 0; j < lines[i].size(); j++)
		{
			stringDisplayed += lines[i][j];
		}
		for (int j = 0; j < xEndPos; j++)
		{
			stringDisplayed += " ";
		}
	}

	return stringDisplayed;
}

UIWindow* UIWindow::MoveWindow() {
	return this;
}

UIWindow* UIWindow::ReSizeWindow() {
	return this;
}

UIWindow* UIWindow::AddWindowChild(UIWindow* _window) {
	windowChilds.push_back(_window);
	_window->parent = this;
	return this;
}

UIWindow* UIWindow::CloseWindow() {
	this->isOpened = false;
	for (auto i = windowChilds.begin(); i != windowChilds.end(); ++i)
	{
		UIWindow* child = *i;
		child->CloseWindow();
	}
	return this;
}

UIWindow* UIWindow::OpenWindow() {
	this->isOpened = true;
	for (auto i = windowChilds.begin(); i != windowChilds.end(); ++i)
	{
		UIWindow* child = *i;
		child->OpenWindow();
	}
	return this;
}

int UIWindow::Destroy() {
	int Yes = 1;
	return Yes;
}


//Getters/Setters

void UIWindow::SetTextHorAlignment(HoriAlignment _horizontal) {
	textHoriAlignment = _horizontal;
	switch (textHoriAlignment)
	{
	case UIWindow::Left:
		xSubOffset = 0;
		xCharOffset = 1;
		break;
	case UIWindow::HMiddle:
		xSubOffset = 0.5;
		xCharOffset = 1;
		break;
	case UIWindow::Right:
		xSubOffset = 1;
		xCharOffset = -1;
		break;
	default:
		leftTextSpacing = 1;
		break;
	}
}

void UIWindow::SetTextVerAlignment(VertAlignment _vertical) {
	textVertAlignment = _vertical;
	switch (textVertAlignment)
	{
	case UIWindow::Top:
		ySubOffset = 0;
		yLineOffset = 1;
		break;
	case UIWindow::VMiddle:
		ySubOffset = 0.5;
		yLineOffset = 0;
		break;
	case UIWindow::Bottom:
		ySubOffset = 1;
		yLineOffset = -1;
		break;
	default:
		leftTextSpacing = 1;
		break;
	}
}


void UIWindow::SetWindowHorAlignment(HoriAlignment _horizontal) {
	WindowHoriAlignment = _horizontal;
	switch (WindowHoriAlignment)
	{
	case UIWindow::Left:
		xWindowSub = 0;
		break;
	case UIWindow::HMiddle:
		xWindowSub = 0.5;
		break;
	case UIWindow::Right:
		xWindowSub = 1;
		break;
	default:
		break;
	}
}


void UIWindow::SetWindowVerAlignment(VertAlignment _vertical) {
	WindowVertAlignment = _vertical;
	switch (WindowVertAlignment)
	{
	case UIWindow::Top:
		yWindowSub = 0;
		break;
	case UIWindow::VMiddle:
		yWindowSub = 0.5;
		break;
	case UIWindow::Bottom:
		yWindowSub = 1;
		break;
	default:
		break;
	}
}


void UIWindow::SetText(std::string _text) {
	text = _text;
	FormatText();
}

int UIWindow::GetXWindowSize(UIWindow& _window) {
	if (_window.isImage) {
		int width = GRID_RATIO * 2;
		return width;
	}
	if (_window.parent) {
		return _window.size.xScale * GetXWindowSize(*_window.parent) + _window.size.xPx;
	}
	return _window.size.xScale * SCREEN_WIDTH + _window.size.xPx;
}

int UIWindow::GetYWindowSize(UIWindow& _window) {
	if (_window.isImage) {
		int height = GRID_RATIO;
		return height;
	}
	if (_window.parent) {
		return _window.size.yScale * GetYWindowSize(*_window.parent) + _window.size.yPx;
	}
	return _window.size.yScale * SCREEN_HEIGHT + _window.size.yPx;
}

int UIWindow::GetXWindowPosition(UIWindow& _window) {
	int xWindowCharSize = _window.GetXWindowSize(_window);
	if (_window.parent) {
		int xParentWindowCharSize = _window.GetXWindowSize(*_window.parent);
		int parentPos = GetXWindowPosition(*_window.parent);
		int xPos = parentPos + _window.position.xScale * xParentWindowCharSize + _window.position.xPx - _window.xWindowSub * xWindowCharSize;
		//clamp pos of the window in the console
		xPos = std::fmaxf(0, std::fminf(xPos, SCREEN_WIDTH - xWindowCharSize));
		return xPos;
	}
	int xPos = _window.position.xScale * SCREEN_WIDTH + _window.position.xPx - _window.xWindowSub * xWindowCharSize;
	//clamp pos of the window in the console
	xPos = std::fmaxf(0, std::fminf(xPos, SCREEN_WIDTH - xWindowCharSize));
	return xPos;
}

int UIWindow::GetYWindowPosition(UIWindow& _window) {
	int yWindowCharSize = _window.GetYWindowSize(_window);
	if (_window.parent) {
		int yParentWindowCharSize = _window.GetYWindowSize(*_window.parent);
		int parentPos = GetYWindowPosition(*_window.parent);
		int yPos = parentPos + _window.position.yScale * yParentWindowCharSize + _window.position.yPx - _window.yWindowSub * yWindowCharSize;
		//clamp pos of the window in the console
		yPos = std::fmaxf(0, std::fminf(yPos, SCREEN_HEIGHT));
		return yPos;
	}
	int yPos = _window.position.yScale * SCREEN_HEIGHT + _window.position.yPx - _window.yWindowSub * yWindowCharSize;
	//clamp pos of the window in the console
	yPos = std::fmaxf(0, std::fminf(yPos, SCREEN_HEIGHT));
	return yPos;
}