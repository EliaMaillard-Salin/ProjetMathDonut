#pragma once

#include "Mesh.h"
#include "Settings.h"
#include <vector>

class Light;

class Screen
{
	int m_width;
	int m_height;

	float m_centerX;
	float m_centerY;

	float m_zPosition;
    char m_background;
    char m_meshProjection;
    float m_meshZPosition;

	std::vector<std::vector<char>> m_pixels;
	std::vector<std::vector<float>> m_oozBuffer;
	bool _IsVertexInScreen(int u, int v);
	char _CheckDeph(float vertexZ, float currentDeph);

public:
	Screen(Settings& settings);
	Screen(int width, int height, char meshProjection, char screenProjection);
	void ResetScreen();
	void Display();
	void Draw(Mesh& mesh, Light const& light);
};

