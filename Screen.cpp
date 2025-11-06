#include "Screen.h"

#include <iostream>


Screen::Screen(int width, int height) : m_width(width), m_height(height)
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
