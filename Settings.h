#pragma once
class Settings
{
	int m_width;
	int m_height;

public:
	Settings(int argC, char** argV);

	int GetHeight();
	int GetWidth();

};

