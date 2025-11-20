#include "Screen.h"

#include <iostream>
#include <string>


Screen::Screen(int width, int height) : m_width(width*2), m_height(height), centerX(width*0.5f), centerY(height *0.5f)
{
    m_pixels = std::vector<char>(m_width * m_height, '.');
}

void Screen::Display()
{
    std::cout << "\033[?25l";
    std::cout << "\033[2J";
    std::cout << "\033[H";

    for (int h = 0; h < m_height; h++)
    {
        for (int w = 0; w < m_width; w++)
        {
            std::cout << m_pixels[m_width * h + w];
        }
        std::cout << ".\n";
    }

    std::cout << "\033[?25h";

}

void Screen::Draw(Mesh& mesh)
{
    for (int index = 0; index < mesh.m_vertices.size(); index++)
    {

        int width = (centerX + mesh.m_vertices[index].x)*2;
        int height = centerY + mesh.m_vertices[index].y;
        m_pixels[m_width * height + width] = 'X';
        //std::cout << "x : " << y << " y: " << x << std::endl;
    }
}
