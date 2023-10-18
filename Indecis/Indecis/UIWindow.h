#pragma once
#include <windows.h>
#include <string>

class UIWindow
{
public:
	//Data structs :
	struct UIDim {
		int xPx = 0;
		int yPx = 0;
		float xScale = 0;
		float yScale = 0;
		UIDim() :xPx(0), yPx(0), xScale(0), yScale(0) {}
		UIDim(float _xScale, float _yScale) : xScale(_xScale), yScale(_yScale) {}
		UIDim(int _xPx, int _yPx) : xPx(_xPx), yPx(_yPx) {}
	};
	enum HoriAlignment {
		Left,
		HMiddle,
		Right,
	};
	enum VertAlignment {
		Top,
		VMiddle,
		Bottom,
	};

	//Methods

	UIWindow();
	UIWindow(float _xPos, float _yPos, float _xSize, float _ySize, int _zPosition);
	UIWindow(int _xPos, int _yPos, int _xSize, int _ySize, int _zPosition);
	void FormatText();
	std::string DisplayWindow();
	UIWindow* MoveWindow();
	UIWindow* ReSizeWindow();
	UIWindow* AddWindowChild(UIWindow* _window);
	UIWindow* CloseWindow();
	UIWindow* OpenWindow();
	int Destroy();

	//	Getters/Setters

	//Set horizontal alignement (and update spacing automatically)
	void SetTextHorAlignment(HoriAlignment _horizontal);
	//Set vertical alignement (and update spacing automatically)
	void SetTextVerAlignment(VertAlignment _vertical);
	//Set window horizontal alignment (is it placed from left middle or right)
	void SetWindowHorAlignment(HoriAlignment _horizontal);
	//Set wintow vertical alignement (is it placed from top middle or bottom)
	void SetWindowVerAlignment(VertAlignment _vertical);

	void SetText(std::string _text);
	
	int GetXWindowPosition(UIWindow& _window);
	int GetYWindowPosition(UIWindow& _window);
	int GetXWindowSize(UIWindow& _window);
	int GetYWindowSize(UIWindow& _window);

	//Member Variables

	UIDim position;
	UIDim size;
	int xCurrentSize = 0;
	int yCurrentSize = 0;
	int zPosition = 0;
	bool isImage = false;
	std::string spriteName;
	
	int maxCharByLines = 20;

	HoriAlignment textHoriAlignment;
	VertAlignment textVertAlignment;
	HoriAlignment WindowHoriAlignment;
	VertAlignment WindowVertAlignment;

	//part of the line's size to sub to the x position of a line
	float xSubOffset = 0;
	//number of space to add before a line to take border into account
	float xCharOffset = 0;
	//part of the paragraph's size to sub to the y position of the paragraph
	float ySubOffset = 0;
	//number of space to add before a paragraph to take border into account
	float yLineOffset = 0;
	
	//part of the window's size to sub to x position
	float xWindowSub = 0;
	//part of the window's size to sub to y position
	float yWindowSub = 0;

	//the text that will be displayed by the window
	std::vector<std::string> lines;
	std::vector<UIWindow*> windowChilds;
	UIWindow* parent;


	//Is the window visible
	bool isOpened = false;
	bool isSelectable = false;
	bool isSelected = false;

	void (*CallBack)();
	
	WORD normalColor = 0x0007 + 0x0000;
	WORD selectedColor = 0x0000 + 0x0070;

private:
	
	//private methods :
	int GetLastSpaceOfLine(int pos, int charCount);


	int leftTextSpacing;
	int topTextSpacing;
	std::string text;


};

