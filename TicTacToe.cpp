/*
!If you use windows please replace system("clear") to system("cls")

*/
#include <iostream>
#include <ctime>

using namespace std;

char board[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; //! All Board Position
int i,mode = 0,count = 0, YesNo = 2,choice,x_player_win,o_player_win,draw_match;
string x_player_name,o_player_name;

void Play_Game(); 
void Start_Game();
void clear_function(); //? Set board[] array empty
void show_board();
int count_board(char symbol);
void Player_Turn(char X_Or_O);
void Computer_Turn();
char chk_winner();

int main(){

    Play_Game();
    return 0;   
}

void clear_function(){
    for(i = 0; i < 9; i++){
        board[i] = ' ';
    }
}

void Play_Game(){
    while(true){
        system("clear");
        clear_function();
        if(count > 0){ //! If play 1 or more times then this is working
            cout<<x_player_name<<" win : " <<x_player_win<< " match" <<endl;

            mode == 1 ? cout<<"Computer win : " <<o_player_win<< " match" <<endl:
                        cout<<o_player_name<<" win : " <<o_player_win<< " match" <<endl;

            cout<<"Draw: " <<draw_match <<endl;

            cout<< "Are you want to play again" <<endl;
            cout<< "1. Yes" <<endl;
            cout<< "2. Back" <<endl;
            cout<< "3. Exit" <<endl;
            
            while(true){
                cin>> YesNo;
                if(YesNo == 2 || YesNo == 3 || YesNo == 1) break;
                else cout<< "Please select a valid number: ";
            }
        }
        if(YesNo == 3) break;
        if(YesNo == 2){ //! YesNo = 2 is defualt becuse frist time need to show this message for choose option then if user want to play again this meessage not show.
        
            cout<< "Choose a option" <<endl;
            cout<< "1. Computer Vs Player" <<endl;
            cout<< "2. Player Vs Player" <<endl;
            cout<< "3. Exit" <<endl;

            while(true){    
                cin>> mode;
                if(mode < 1 || mode > 3) cout<< "Please select a valid number: ";
                else break;
            } 
        }

        if(mode == 1 || mode == 2) Start_Game(); //! Select Player mode
        else if(mode == 3) break; 
    }

}

void Start_Game(){
    count++; // ! Play 1 or more time save this information
    
    if(YesNo == 2){ //! 2 is defualt value
        if(mode == 1) { //! Mode 1 need 1 Player info other player is Computer
        cout<< "Enter your name: ";
        cin>> x_player_name;
        }else if( mode == 2){ //! Mode 2 need 2 players info
            cout<< "Enter 'X' player name: ";
            cin>> x_player_name;
            cout<< "Enter 'O' player name: ";
            cin>> o_player_name;
        }
    }

    while(true){
        system("clear");
        show_board();
        if(mode == 2 || mode == 1){ //! If play 1 time and then back (YesNo = 2 means back ) so reset all winning and draw information
            if(YesNo == 2) x_player_win = 0; o_player_win = 0; draw_match = 0;
        }
        if(count_board('X') == count_board('O')){ //! Check for player X Turn's
            cout<< x_player_name<<"'s Turn" <<endl;
            Player_Turn('X'); //! Pass X 
        }else{ //! Check for player O Turn's Or Computer turn's if O Turn's Pass (O)
            if(mode == 2) cout<< o_player_name<<"'s Turn"<<endl;
            mode == 1 ? Computer_Turn():Player_Turn('O');
        }

        char winner = chk_winner(); //! Winning Logic check

        if(winner == 'X'){
            system("clear");
            show_board();
            cout<< x_player_name<< " Won The Game!! " <<endl;
            x_player_win++; //! Store how many time win
            break;
        }else if(winner == 'O'){
            system("clear");
            show_board();
            mode == 1 ? cout<< "Computer Won The Game" <<endl:cout<< o_player_name<< " Won The Game" <<endl;
            o_player_win++; //! Store how many time win
            break;
        }else if(winner == 'D'){
            system("clear");
            show_board();
            cout<< "Game is Draw" <<endl;
            draw_match++; //! Store how many time draw
            break;
        }
    }
}


void Computer_Turn(){ //! Logic for Computer Turn
    srand(time(0));
    do{
        choice = rand()%10;
    }while(board[choice] != ' ');
    board[choice] = 'O';
}

void Player_Turn(char X_Or_O){ //! Player Turn Logic (X or O)
    while(true){
        cout<< "Select your possition (1-9): ";
        cin>> choice;
        choice--; //! Array Start from 0

        if(choice < 0 || choice > 8){ //! Validation
            cout<< "Please choice (1 to 9): " <<endl;
        }else if(board[choice] != ' '){
            cout<< "Please select an empty position" <<endl;
        }else{
            board[choice] = X_Or_O;
            break;
        }
    }
}

int count_board(char symbol){ //! Count Board Position
    int total = 0;
    for(i = 0; i < 9; i++){
        if(board[i] == symbol) total++;
    }
    return total;
}

char chk_winner(){
    //! cheaking for row
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ') return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ') return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ') return board[6];

    //! cheaking for col
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ') return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ') return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ') return board[2];
 
    //! cheaking for diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ') return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ') return board[2];

    if(count_board('X') + count_board('O') < 9){
        return ' '; 
    }else return 'D'; //! D for Drow
}


void show_board(){
    cout<< "|   "<< "    |   "<< "    |       |" <<endl;
    cout<< "|   "<< board[0] << "   |   "<< board[1]<< "   |   "<< board[2] <<"   |"<<endl;
    cout<< "|   "<< "    |   "<< "    |       |" <<endl;
    cout<< "|________________________" <<endl;
    cout<< "|   "<< "    |   "<< "    |       |" <<endl;
    cout<< "|   "<< board[3] << "   |   "<< board[4]<< "   |   "<< board[5] <<"   |"<<endl;
    cout<< "|   "<< "    |   "<< "    |       |" <<endl;
    cout<< "|________________________" <<endl;
    cout<< "|   "<< "    |   "<< "    |       |" <<endl;
    cout<< "|   "<< board[6] << "   |   "<< board[7]<< "   |   "<< board[8] <<"   |"<<endl;
    cout<< "|   "<< "    |   "<< "    |       |" <<endl;
}