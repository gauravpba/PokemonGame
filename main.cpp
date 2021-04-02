#include  "Game.h"

using namespace std;

int main(int argc, char **argv)
{
	 
    Game game("data.txt");
    
    game.LoadFile();
    
    int finalResult = game.Start();
       
    return 0;
}
