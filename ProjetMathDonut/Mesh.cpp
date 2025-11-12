#include "Mesh.h"

#include <iostream>
#include <cmath>

#define PI 3.14159


Mesh::Mesh(std::vector<Vertex> vertices) : m_vertices(vertices)
{}

Mesh::Mesh(float radius) : m_vertices()
{

    for (float theta = 0; theta < PI * 2; theta += 0.01f)
    {
        Vertex v;
        v.x = radius * std::cos(theta);
        v.y = radius * std::sin(theta);
        v.z = 0;
        m_vertices.push_back(v);
    }
}

void Mesh::Debug()
{
    std::cout << "Vertices : \n";

    for (int i = 0; i < m_vertices.size(); i++)
    {
        std::cout << "X : " << m_vertices[i].x << "; Y : "<< m_vertices[i].y << "; Z : " << m_vertices[i].z << std::endl;
    }
}
