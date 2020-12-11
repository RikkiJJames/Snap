#pragma once
#include "Deck.h"
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <Card.h>
#include <thread>
#include <conio.h>

//make snap game an inheritance of DECK
using std::deque;
using std::string;
class Snap{
private:
char key;
char key2;
int width;
char difficulty {};
char num_players{};
int num_deck{}; 
public:
void introduction();
int computer(Deck player,Deck com);
void player_counter(Deck deck);
void com_counter(Deck deck);
void split_deck();
string center(string input , int &width);
Snap();
void game_start();
int snap(Deck player, Deck com);
};
