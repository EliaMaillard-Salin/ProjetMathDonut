#pragma once

#include "Mesh.h"
#include "Settings.h"
class Screen
{
	int m_width;
	int m_height;

	float m_zPosition;
    char m_background;
    char m_meshProjection;
    float m_meshZPosition;

	std::vector<char> m_pixels;
	std::vector<float> m_oozBuffer;
	bool _IsVertexInScreen(int u, int v);
	void _ProjectInCenterScreenSpace(Mesh::Vertex& vertex);
	void _ProjectInTopLeftScreenSpace(Mesh::Vertex& vertex);

public:
	Screen(Settings& settings);
	void Display();
	void Draw(Mesh& mesh);
};

