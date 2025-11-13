#include <iostream>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

#include <Windows.h>

// Clear : [2J
// SetCursor 0,0 : [H
// Cursor Invisible : [?25l
// Cursor Visible : [?25h

// ANSI Command : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797


int main(int argc, char** argv)
{

    Settings settings = Settings(argc, argv);
    Screen screen = Screen(settings.GetWidth(), settings.GetHeight());

    screen.Draw(settings.currentMesh);
    screen.Display();
    while (true)
    {
    }

    return 0;
}
