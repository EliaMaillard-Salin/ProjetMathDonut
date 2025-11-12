#pragma once
class Settings
{
	int m_width;
	int m_height;

	float radius;

public:
	Settings(int argC, char** argV);

	int GetHeight();
	int GetWidth();
	float GetRadius();

};

