#include "Screen.h"

#include <iostream>
#include <string>


Screen::Screen(int width, int height) : m_width(width), m_height(height), centerX(width*0.5f), centerY(height *0.5f)
{}

void Screen::Display()
{
    std::cout << "\033[?25l";
    std::cout << "\033[2J";
    std::cout << "\033[H";

    for (int h = 0; h < m_height; h++)
    {
        for (int w = 0; w < m_width; w++)
        {
            std::cout << '.';
        }
        std::cout << '\n';
    }

    std::cout << "\033[?25h";

}

void Screen::Draw(Mesh& mesh)
{
    std::cout << "\033[?25l";
    std::cout << "\033[2J";

    std::cout << "\033[0;0H";

    for (int index = 0; index < mesh.m_vertices.size(); index++)
    {
        std::cout << "\033[0;0H";

        int column = centerX + mesh.m_vertices[index].x;
        int line = centerY + mesh.m_vertices[index].y;

        std::cout << "\033[" << line << ";" << column*2 << "H";
        //std::cout << "x : " << y << " y: " << x << std::endl;
        std::cout << "O";
    }

    std::cout << "\033[?25h";
}
