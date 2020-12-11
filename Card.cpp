#include "Card.h"
#include <iostream>
#include <string>
#include "Windows.h"


using std::string;
using std::cout;
using std::endl;

Card::Card(int a,int b){

string z{};
value=values.at(a);
suit=suits.at(b);
    for (int i{0};i<width-2;i++){
        z+=t;
    }
        if (a!=9){
        lines.push_back(tcl+z+tcr);
        lines.push_back(s+value+string(width-3, ' ')+s);  
        lines.push_back(s+string(width-2, ' ')+s);
        lines.push_back(s+string(width-2, ' ')+s);
        lines.push_back(s+string((width-3)/2, ' ')+suit+string((width-2)/2, ' ')+s);
        lines.push_back(s+string(width-2, ' ')+s);
        lines.push_back(s+string(width-2, ' ')+s);
        lines.push_back(s+string((width-3), ' ')+value+s);
        lines.push_back(bcl+z+bcr);
        }
    else{
    lines.push_back(tcl+z+tcr);
    lines.push_back(s+values[a]+string(width-4, ' ')+s);  
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string((width-3)/2, ' ')+suits[b]+string((width-2)/2, ' ')+s);
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string((width-4), ' ')+values[a]+s);
    lines.push_back(bcl+z+bcr);    
    }
}
Card::Card(){
    string z{}; 
    
    for (int i{0};i<width-2;i++){
        z+=t;
    }
    lines.push_back(tcl+z+tcr);
    lines.push_back(s+values[0]+string(width-3, ' ')+s);  
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string((width-3)/2, ' ')+suits[0]+string((width-2)/2, ' ')+s);
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string(width-2, ' ')+s);
    lines.push_back(s+string((width-3), ' ')+values[0]+s);
    lines.push_back(bcl+z+bcr);

}

void Card::display_card(int num,int x, int y){
    COORD coord;
    coord.Y = y,coord.X =x ;  // first pass entry
    if (num%2!=0){
    coord.X = 120-width-40;
            
    }
        for (auto p:lines){
            SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
            cout<<p<<endl;
            coord.Y++;
        }
}
string Card::get_value(){
    return value;
}
string Card::get_suit(){
    return suit;
}
