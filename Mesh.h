#pragma once

#include <vector>

class Mesh
{
	struct Vertex
	{
		int x;
		int y;
		char value;
	};

	std::vector<Vertex> vertices;

	Mesh CreateCustom(std::vector<Vertex>);
	Mesh GenerateCircle(float radius);
	Mesh GenerateHalfCircle(float radius);
	Mesh GenerateRectangle(float width, float height);
	Mesh GenerateSquare(float size);

	void Debug();
};

