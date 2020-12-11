#include "Deck.h"
#include <chrono>
#include <random>
#include <algorithm>
#include <deque>

void Deck::fill_deck(int start,int finish) {
    for (int i{};i<13;i++){
        for (int j{start};j<finish;j++){
            deck.push_back(Card (i,j));
        }
    }
}
Deck::Deck(int start, int finish){
    fill_deck(start,finish);
}
Deck::Deck(){
}
void Deck::play_deck(){
    for (size_t i{} ;i<deck.size();i++){
        deck.at(i).display_card(i,0,0);
    }
}
void Deck::shuffle_deck(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(deck.begin(), deck.end(),e);
}
void Deck::play_cards(int i,int x,int y){
    
    for (int a{};a<i;a++){
    deck.front().display_card(a,x,y);
    }
}

void Deck::next_card(){
    deck.pop_front();
}
Card Deck::get_card(){
    return deck.at(0);
}
int Deck::num_cards(){
    return deck.size();
}
void Deck::add_card(Card a){
    deck.emplace_back(a);
}
std::deque <Card> Deck::get_deck(){
    return deck;
}
void Deck::add_cards(std::deque <Card> a){
    
    for (auto i:a){
        deck.emplace_back(i);
    }
}
void Deck::empty_deck(){
    deck.clear();
}
Deck::~Deck(){
}