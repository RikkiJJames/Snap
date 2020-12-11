#include <vector>
#include <string>
#pragma once
class Card{
private:
std::vector <std::string> values {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
std::vector <std::string> suits {"\u2665","\u2666","\u2663","\u2660"};
std::vector<std::string> lines {} ;
std::string value{};
std::string suit {};
std::string t{"\u2550"};
std::string tcr {"\u2557"};
std::string tcl {"\u2554"};
std::string s {"\u2551"};
std::string bcl{"\u255A"};
std::string bcr{"\u255D"};
double width {17};
public:
Card(int a,int b);
Card();
void display_card(int num,int x, int y);
std::string get_value();
std::string get_suit();
};