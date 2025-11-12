#include "Settings.h"

#include <iostream>

#include <Windows.h>

Settings::Settings(int argC, char** argV) : m_width(0), m_height(0)
{
    for (int i = 1; i + 1 < argC; i++)
    {
        if (std::string(argV[i]) == "-w")
            m_width = std::atoi(argV[i + 1]);
        if (std::string(argV[i]) == "-h")
            m_height = std::atoi(argV[i + 1]);
        if (std::string(argV[i]) == "-r")
            radius = std::atof(argV[i + 1]);
    }

    if (m_width == 0 || m_height == 0)
        std::cout << "Error with Width or Height Value \n";

}

int Settings::GetHeight()
{
	return m_height;
}

int Settings::GetWidth()
{
	return m_width;
}

float Settings::GetRadius()
{
    return radius;
}
