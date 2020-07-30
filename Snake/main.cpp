#include <iostream>
#include <thread>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include "game_engine.h"

class Snake:public console_game_engine{
    const char c_snake = '%';
    const char c_apple = '*';
    int points = 0;
    std::vector<std::pair<int,int> > snake_tail;
    enum direction{STOP=0,LEFT,UP,RIGHT,DOWN};
    static direction snake_direction;
    static bool* _is_game;
private:
    void Logic() override;
    static void GetKey();
    void spawn_apple();
public:
    Snake(int width, int height): console_game_engine(width, height){
        std::pair<int,int> start = std::make_pair(width/2,height/2);
        snake_tail.push_back(start);
        field[height/2*field_w+width/2] = c_snake;
        snake_direction=UP;
        _is_game = &is_game;
        srand((int)field_h*field_w);
        spawn_apple();
    }

    void Game() override;
};

void Snake::Logic() {
    std::pair<int,int> new_pos = snake_tail[0];
    switch (snake_direction) {
        case(LEFT):
            new_pos.first--;
            break;
        case UP:
            new_pos.second--;
            break;
        case RIGHT:
            new_pos.first++;
            break;
        case DOWN:
            new_pos.second++;
            break;
        case STOP:
            is_game=false;
            break;
    }
    if (field[new_pos.second*field_w+new_pos.first]==c_border ||
            std::find(snake_tail.begin(),snake_tail.end(),new_pos)!=snake_tail.end())
        snake_direction=STOP;
    snake_tail.insert(snake_tail.begin(),new_pos);
    if (field[new_pos.second*field_w+new_pos.first]==c_apple){
        spawn_apple();
    }
    else {
        field[(snake_tail.end()-1)->second*field_w+(snake_tail.end()-1)->first] = c_empty;
        snake_tail.pop_back();
    }
    field[new_pos.second*field_w+new_pos.first] = c_snake;
    Sleep(100);
}

void Snake::GetKey() {
    while(*_is_game) {
        switch (_getch()) {
            case 'w':
                if (snake_direction != DOWN) snake_direction = UP;
                break;
            case 's':
                if (snake_direction != UP) snake_direction = DOWN;
                break;
            case 'a':
                if (snake_direction != RIGHT) snake_direction = LEFT;
                break;
            case 'd':
                if (snake_direction != LEFT) snake_direction = RIGHT;
                break;
            case 'x':
                snake_direction = STOP;
                break;
        }
    }
    Sleep(100);
}

void Snake::Game() {
    std::thread KeyThread(GetKey);
    while (is_game)
    {
        Draw();
        Logic();
    }
    KeyThread.join();
}

Snake::direction Snake::snake_direction = UP;

void Snake::spawn_apple() {
    size_t x=0,y=0;
    while(field[y*field_w+x]!=c_empty) {
        x = rand() % (field_w - 2) + 1;
        y = rand() % (field_h - 2) + 1;
    }
    field[y*field_w+x] = c_apple;
}

bool* Snake::_is_game;

int main() {
    Snake _snake(20, 20);
    _snake.Game();
    return 0;
}
