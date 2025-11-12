#pragma once

#include <vector>

class Mesh
{
	struct Vertex
	{
		float x;
		float y;
		float z;
		char value;
	};


public:
	std::vector<Vertex> m_vertices;

	Mesh(std::vector<Vertex> vertices);
	Mesh(float radius = 32.0f);

	//Mesh& CreateCustom(std::vector<Vertex>);
	//Mesh& GenerateCircle(float radius);
	//Mesh& GenerateHalfCircle(float radius);
	//Mesh& GenerateRectangle(float width, float height);
	//Mesh& GenerateSquare(float size);

	void Debug();
};

