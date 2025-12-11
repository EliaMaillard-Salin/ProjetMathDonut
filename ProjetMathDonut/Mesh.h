#pragma once

#include <vector>


enum Axis {
	X, Y, Z
};

class Mesh
{
public:

	struct Vertex
	{
		float x;
		float y;
		float z;
		char value;
		void Rotate(float angle, Axis axis);
	};

private:

	std::vector<Mesh::Vertex>& CreateSector(float radius, float angle);
	Mesh& CreateRect(float width, float height);
	int m_resolution;

	float posX = 0;
	float posY = 0;
	float posZ = 0;

public:
	std::vector<Vertex> m_vertices;

	Mesh(std::vector<Vertex> vertices);
	Mesh(int _resolution);

	std::vector<Vertex> GetVertices();
	void Rotate(float angle, Axis axis);

	static Mesh DefaultMesh();
	static Mesh CreateCircle(float radius, int resolution = 40);
	static Mesh CreateHalfCircle(float radius = 32.0f,int resolution = 10);
	static Mesh CreateSquare(float size = 32.0f,int resolution = 10);
	static Mesh CreateRectangle(float width,float height, int resolution = 10);
	static Mesh CreateTorus(float majorRadius, float minorRadius, int resolution = 50);
	void SetPosition(float x, float y, float z) { posX = x; posY = y; posZ = z; }

	float GetPosX() { return posX; }
	float GetPosY() { return posY; }
	float GetPosZ() { return posZ; }

	//Mesh CreateSquare(float radius = 32.0f,int resolution = 10);

	//Mesh& CreateCustom(std::vector<Vertex>);
	//Mesh& GenerateCircle(float radius);
	//Mesh& GenerateHalfCircle(float radius);
	//Mesh& GenerateRectangle(float width, float height);
	//Mesh& GenerateSquare(float size);

	void Debug();
};

