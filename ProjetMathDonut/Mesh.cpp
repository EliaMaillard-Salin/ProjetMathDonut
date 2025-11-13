#include "Mesh.h"

#include <iostream>
#include <cmath>

#define PI 3.14159


Mesh::Mesh(std::vector<Vertex> vertices) : m_vertices(vertices)
{}

Mesh::Mesh(int _resolution): m_vertices(std::vector<Vertex>(_resolution* _resolution)), m_resolution(_resolution)
{
}

Mesh& Mesh::CreateSector(float radius, float angle)
{
    for (int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution);
            Vertex v;
            m_vertices[m_resolution * i + j].x = radius * std::cos(theta);
            m_vertices[m_resolution * i + j].y = radius * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
    return *this;
}

Mesh Mesh::CreateCircle(float radius, int resolution)
{
    Mesh mesh = Mesh(resolution);
    return mesh.CreateSector(radius, 2 * PI);
}

std::vector<Mesh::Vertex> Mesh::GetVertices()
{
    return m_vertices;
}

Mesh Mesh::DefaultMesh()
{
    Mesh mesh = Mesh({{1.0f,-1.0f,0.0f}});
    return mesh;
}


void Mesh::Debug()
{
    std::cout << "Vertices : \n";

    for (int i = 0; i < m_vertices.size(); i++)
    {
        std::cout << "X : " << m_vertices[i].x << "; Y : "<< m_vertices[i].y << "; Z : " << m_vertices[i].z << std::endl;
    }
}
