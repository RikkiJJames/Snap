#include "Snap.h"
#include <conio.h>
#include <Windows.h>
using std::cout;
using std::endl;

string Snap::center(string input , int &width){
    
    int diff = width - input.length();
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + input + string(pad2, ' ');
}
void Snap::introduction(){
    cout<<std::setw(width);
    cout<<center("Welcome to Snap",width)<<endl;
    cout<<center("In this game, you and the computer will take turns playing a card",width);
    cout<<center("If the card played has the same suit Or the same value as the ",width);
    cout<<center("next card then press 's' to call snap.",width)<<endl; 
    cout<<center("Be careful, if you're too slow, the computer may call snap instead!!",width);
    cout<<center("If you run out of cards the game is over",width);
    cout<<string(width,'-')<<endl;
    cout<<center("Press '1' for 1 Player or '2' for 2 Player",width);
    num_players = getch();
    if (num_players=='1'){
    cout<<center("Select a difficulty",width);
    cout<<center("Press 'e' for easy, 'm' for medium or 'h' for hard",width);
    difficulty=getch();
    if (difficulty=='e'){
        cout<<center("Easy mode selected",width);
    }
    else if (difficulty=='m'){
        cout<<center("Medium mode selected",width);
    }
    else if (difficulty=='h'){
        cout<<center("Hard mode selected",width);
    }
    }
    else if (num_players=='2'){
        cout<<center("Player 2: press 'P' to call snap",width);
    }
    std::this_thread::sleep_for (std::chrono::seconds(1));
    system("cls");
    cout<<center("3",width);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    system("cls");
    cout<<center("2",width);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    system("cls");
    cout<<center("1",width);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    system("cls");
    
}
void Snap::game_start(){
    Deck player(0,2);
    Deck com (2,4);
    Deck main_deck;
    player.shuffle_deck();
    com.shuffle_deck();
    while (player.num_cards()!=0 and com.num_cards()!=0){
            player_counter(player);
            com_counter(com);
            player.play_cards(1,40,0);
            main_deck.add_card(player.get_card());
            player_counter(player);
            com.play_cards(1,120-17-40,0);
            main_deck.add_card(com.get_card());
            com_counter(com);
            if (difficulty=='e'){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            else if (difficulty=='m'){
            std::this_thread::sleep_for (std::chrono::milliseconds(750));
            }
            else if (difficulty=='h'){
            std::this_thread::sleep_for (std::chrono::milliseconds(400));
            }
            if (num_players=='1'){
                int result = snap(player,com);
                if(result==1){
                    player.add_cards(main_deck.get_deck());
                    main_deck.empty_deck();
                    player.shuffle_deck();
                }
                else if(result==-1 and player.num_cards()!=1){
                    com.add_card(player.get_card());
                    player.next_card();
                    com.shuffle_deck();
                    player.shuffle_deck();
                }
                else if (computer(player,com)==1){
                    com.add_cards(main_deck.get_deck());
                    main_deck.empty_deck();
                    com.shuffle_deck();
                }
            }
            if (num_players=='2'){
                std::this_thread::sleep_for (std::chrono::milliseconds(1000));
                int result = snap(player,com);
                
                if(result==1){
                    player.add_cards(main_deck.get_deck());
                    main_deck.empty_deck();
                    player.shuffle_deck();
                }
                else if(result==-1 and player.num_cards()!=1){
                    com.add_card(player.get_card());
                    player.next_card();
                    com.shuffle_deck();
                    player.shuffle_deck();
                }
                else if(result==-2 and player.num_cards()!=1){
                    player.add_card(com.get_card());
                    com.next_card();
                    player.shuffle_deck();
                    com.shuffle_deck();
                }
                else if (result==2){
                    com.add_cards(main_deck.get_deck());
                    main_deck.empty_deck();
                    com.shuffle_deck();
                }
                else if(result==0){
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            }
            system("cls");
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            player.next_card();
            com.next_card();
//            Re-clear the buffer
            while(kbhit())     
                getch();
            if (player.num_cards()!=1 or com.num_cards()!=1){
            system("cls");
            }else {
                break;
            }
    }
    if (player.num_cards()==0){
        cout<<center("Sorry, you lost",width);
    }
    else{
        cout<<center("Yay, you won!!!",width);
    }
}
int Snap::snap(Deck player, Deck com) {
    if (_kbhit()){
        char input = _getch();
        COORD coord;
        if (input==key and (player.get_card().get_value()==com.get_card().get_value() or player.get_card().get_suit()==com.get_card().get_suit())){
                string q {"Player 1 Snap!!"};    
                coord.Y = 10,coord.X =(width-q.length())/2;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
                cout<<q<<endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                return 1;
        }
        else if (input==key2 and (player.get_card().get_value()==com.get_card().get_value() or player.get_card().get_suit()==com.get_card().get_suit())){
            string q {"Player 2 Snap!!"};    
            coord.Y = 10,coord.X =(width-q.length())/2;
            SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
            cout<<q<<endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            return 2;
        }
        else if (input==key and (player.get_card().get_value()!=com.get_card().get_value() or player.get_card().get_suit()!=com.get_card().get_suit())){
            string q {"Player 1 Snap Error"};    
            coord.Y = 10,coord.X =(width-q.length())/2;
            SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
            cout<<q<<endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            return -1;
        }
        else if (input==key2 and (player.get_card().get_value()!=com.get_card().get_value() or player.get_card().get_suit()!=com.get_card().get_suit())){
            string q {"Player 2 Snap Error"};    
            coord.Y = 10,coord.X =(width-q.length())/2;
            SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
            cout<<q<<endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            return -2;
        }
    }
            return 0;
}
int Snap::computer (Deck player,Deck com){
    string q {"Computer Snap"};
    COORD coord;
    coord.Y = 10,coord.X =(width-q.length())/2;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
    int pass{30};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    srand( time(NULL));
    int percentage = rand()%100+1;
    if (difficulty=='m'){
        pass-=10;
    }
    else if (difficulty=='h'){
        pass-=25;
    }
    std::this_thread::sleep_for (std::chrono::milliseconds(100));    
    if (snap(player,com)!=1 and percentage>pass and (player.get_card().get_value()==com.get_card().get_value() or player.get_card().get_suit()==com.get_card().get_suit())){
        cout<<q<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return 1;
    }
    else {
        return -1;
    }
}
void Snap::player_counter(Deck deck){
    COORD coord;
    coord.Y = 4,coord.X =5 ;  // first pass entry
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
    num_deck=deck.num_cards();
    cout<<"|Cards remaining your deck: " + std::to_string(num_deck)+"|";
}
void Snap::com_counter(Deck deck){
    COORD coord;
    coord.Y = 4,coord.X =width-36 ;  // first pass entry
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
    num_deck=deck.num_cards();
    cout<<"|Cards remaining your deck: " + std::to_string(num_deck)+"|";
}
Snap::Snap()
:key{'s'},key2{'p'},width{120}
{
    Deck player(0,2);
    Deck com (2,4);
    Deck main_deck;
    introduction();
    game_start();
}

