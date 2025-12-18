#include <iostream>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "Light.h"

#include <Windows.h>

#include <signal.h>

#define PI 3.14159

// Clear : [2J
// SetCursor 0,0 : [H
// Cursor Invisible : [?25l
// Cursor Visible : [?25h

// ANSI Command : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

void OnKill(int param)
{
    std::cout << "\n";
    std::cout << "\033[2J";
    std::cout << "\033[?25h";
    std::cout << "End" << std::endl;
    exit(param);
}

int main(int argc, char** argv)
{
    signal(SIGINT, OnKill);
    Settings settings = Settings();
    if (settings.HandleSettings(argc, argv) == false)
        return 0;
    Screen screen = Screen(settings);

    //Screen screen = Screen(75, 25, 'X', ' ');
    Mesh donut = settings.currentMesh;
    //Mesh SecondCircle = Mesh::CreateCircle(10, 30);

    donut.SetPosition(donut.GetPosX(), donut.GetPosY() + 10.0f, donut.GetPosZ());
    Light light(settings);

    //donut.Debug();
    //SecondCircle.SetPosition(12.5f, 0.0f, 0.0f);

    //screen.Draw(SecondCircle);
    while (true)
    {
        screen.ResetScreen();
        screen.Draw(donut,light);
        screen.Display();
        donut.Rotate(0.08f, Axis::X);
        donut.Rotate(0.02f, Axis::Y);
    }

    return 0;
}
