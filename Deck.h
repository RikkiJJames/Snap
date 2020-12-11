#include "Card.h"
#include <deque>
#pragma once
class Deck{
private:
    std::deque<Card> deck {};
public:
void fill_deck(int start,int finish);
Deck(int start,int finish);
Deck();
void play_deck();
void shuffle_deck();
void play_cards(int i,int x,int y);
int num_cards();
void next_card();
Card get_card();
void add_card(Card a);
void empty_deck();
std::deque <Card> get_deck();
void add_cards(std::deque <Card> a );
~Deck();
};