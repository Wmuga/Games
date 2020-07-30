/*
 * Simpliest 2d game engine. Will be updated, when I'll have any ideas
 */
#include <vector>
#include <iostream>

class console_game_engine
{
protected:
    virtual void Draw();

    virtual void Logic();
    bool is_game;
    const char c_empty = ' ';
    const char c_border = '#';
    unsigned int field_w;
    unsigned int field_h;
    std::vector<char> field{};
public:
    console_game_engine(unsigned int,unsigned int);
    virtual void Game();
};

console_game_engine::console_game_engine(unsigned int width, unsigned int heigth):
        field_h(heigth),field_w(width),is_game(true)
{
    field.resize(field_w*field_h);
    for (size_t j = 0 ;j<field_h;j++) for (size_t i = 0 ;i<field_w;i++)
        {
        field[j*field_w+i] = ((i==0 || i==field_w-1 || j==0 || j==field_h-1) ? c_border : c_empty);
        }
    field.shrink_to_fit();
}
#ifndef _WINDOWS_
//simple field draw
void console_game_engine::Draw() {
    system("cls");
    for (size_t j = 0 ;j<field_h;j++) {
        for (size_t i = 0; i < field_w; i++)
            std::cout << field[j*field_w+i] << " ";
    std::cout<<std::endl;
    }
}
#endif

#ifdef _WINDOWS_
//On Windows libr field draw
void console_game_engine::Draw() {

    COORD position = {0,0}; //позиция x и y
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);

    for (size_t j = 0 ;j<field_h;j++) {
        for (size_t i = 0; i < field_w; i++)
            std::cout << field[j*field_w+i] << " ";
        std::cout<<std::endl;
    }
}
#endif
//Just waiting for pressing - everything should be in game itself
void console_game_engine::Logic() {
    if (getchar()) is_game = false;
}

//Game loop
void console_game_engine::Game() {
    while (is_game)
    {
        Draw();
        Logic();
    }
}