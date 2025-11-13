#pragma once

#include "Mesh.h"

class Settings
{
	int m_width;
	int m_height;

public:
	Mesh currentMesh;

	Settings(int argC, char** argV);
	void GenerateCircle(float radius);
	void GenerateHalfCircle(float radius);
	void GenerateSquare(float radius);
	void GenerateRectangle(float radius);
	int GetHeight();
	int GetWidth();

};

