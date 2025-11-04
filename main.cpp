#include <iostream>

#include <Windows.h>

// Clear : [2J
// SetCursor 0,0 : [H
// Cursor Invisible : [?25l
// Cursor Visible : [?25h

// ANSI Command : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797


int main(int argc, char** argv)
{
    std::cout << "\033[?25l";
    std::cout << "Hello World!\n";
    
    std::cout << "\033[2J";
    std::cout << "\033[H";
    std::cout << "Hello world\n";
    std::cout << "\033[?25h";

    return 0;
}
