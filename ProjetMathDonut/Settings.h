#pragma once

#include "Mesh.h"

class Settings
{
	int m_width;
	int m_height;
	int resolution;

public:
	Mesh currentMesh;

	Settings();
	
	bool HandleSettings(int argC, char** argV);
	
	void GenerateCircle(float radius);
	void GenerateHalfCircle(float radius);
	void GenerateSquare(float size);
	void GenerateRectangle(float width, float height);
	int GetHeight();
	int GetWidth();

};

