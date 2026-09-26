#include <iostream>
#include <ctime>
#include "./Game/Game.cpp"
int main()
{
    int t = static_cast<int>(time(NULL));
    std::srand(t);
    Game myGame(630, 480, "mygame");
    myGame.run();
    return 0;
}
