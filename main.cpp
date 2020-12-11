#include <Snap.h>
#include <Windows.h>
#include "Deck.h"
#include <chrono>
#include <iostream>
//    Snap();
int main(){
    
UINT oldcp = GetConsoleOutputCP();
SetConsoleOutputCP(CP_UTF8);
//auto start = std::chrono::high_resolution_clock::now();

Snap();
//auto stop = std::chrono::high_resolution_clock::now(); 
//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//std::cout<<duration.count()<<std::endl;
SetConsoleOutputCP(oldcp);
}