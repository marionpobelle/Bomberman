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
	const int x = size.xScale * SCREEN_WIDTH + size.xPx ;
	const int y = size.yScale * SCREEN_HEIGHT + size.yPx ;
	std::string stringDisplayed;

	for (int j = 0; j < x * (y * ySubOffset - lines.size() * ySubOffset + yLineOffset); j++)
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

UIWindow UIWindow::MoveWindow() {
	UIWindow Yes;
	return Yes;
}

UIWindow UIWindow::ReSizeWindow() {
	UIWindow Yes;
	return Yes;
}

UIWindow UIWindow::AddButton() {
	UIWindow Yes;
	return Yes;
}

UIWindow UIWindow::CloseWindow() {
	UIWindow Yes;
	return Yes;
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