#include <iostream>
#include <fstream>
#include <vector>
#include "Map.h"

using namespace std;

int main()
{
   // Map world("JedenKontinent.txt");
   // Map world("VodniSvet.txt");
    Map world("Mapa12x12.txt");
    std::cout << "Number of continents: " << world.countContinents() << std::endl;
    return 0;
}


