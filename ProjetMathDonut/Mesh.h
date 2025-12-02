#pragma once

#include <vector>

class Mesh
{

public:
	struct Vertex
	{
		float x;
		float y;
		float z;
		char value;
	};

private:

	Mesh& CreateSector(float radius, float angle);
	Mesh& CreateRect(float width, float height);
	int m_resolution;
	int posX = 0;
	int posY = 0;

public:
	std::vector<Vertex> m_vertices;

	Mesh(std::vector<Vertex> vertices);
	Mesh(int _resolution);

	std::vector<Vertex> GetVertices();

	void Rotate(float rotationMatrix[]);

	static Mesh DefaultMesh();
	static Mesh CreateCircle(float radius, int resolution = 40);
	static Mesh CreateHalfCircle(float radius = 32.0f,int resolution = 10);
	static Mesh CreateSquare(float size = 32.0f,int resolution = 10);
	static Mesh CreateRectangle(float width,float height, int resolution = 10);
	//Mesh CreateSquare(float radius = 32.0f,int resolution = 10);

	//Mesh& CreateCustom(std::vector<Vertex>);
	//Mesh& GenerateCircle(float radius);
	//Mesh& GenerateHalfCircle(float radius);
	//Mesh& GenerateRectangle(float width, float height);
	//Mesh& GenerateSquare(float size);

	void Debug();
};

