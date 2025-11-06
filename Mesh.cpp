#include "Mesh.h"

#include <iostream>


Mesh Mesh::CreateCustom(std::vector<Vertex>)
{
    return Mesh();
}

Mesh Mesh::GenerateCircle(float radius)
{
    return Mesh();
}

Mesh Mesh::GenerateHalfCircle(float radius)
{
    return Mesh();
}

Mesh Mesh::GenerateRectangle(float width, float height)
{
    return Mesh();
}

Mesh Mesh::GenerateSquare(float size)
{
    return Mesh();
}

void Mesh::Debug()
{
    std::cout << "Vertices : \n";

    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << "X : " << vertices[i].x << " Y : "<< vertices[i].y << std::endl;
    }
}
