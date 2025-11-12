#pragma once

#include "Mesh.h"

class Screen
{
	int m_width;
	int m_height;

	int centerX;
	int centerY;

public:
	Screen(int width, int height);
	void Display();
	void Draw(Mesh& mesh);
};

