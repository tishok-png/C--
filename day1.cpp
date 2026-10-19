// day one is a refersher to what i have learnt 
// develop a random number  predction game
// inmport libs to be use 
#include <iostream> // input and output streaming 
#include <random>   //generate random values 
#include <string>    // module for strings
#include <thread>   //this_thread for delay
#include <chrono>   //setting number of delay seconds
#include <utility> 

void delay(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

int level(){
    //user chooses level to play 
    std::cout<<"choose Level to play game :"<<'\n';
    std::cout<<"1 :  (1-25)"<<'\n';
    std::cout<<"2 :  (1-50)"<<'\n';
    std::cout<<"3 :  (1-100)"<<'\n';

    int x ;
    std::cin>>x;
    if (x >= 1 && x <= 3 ){
        std::cout<<"Levvel has being choosen"<<'\n';
        return x;
    }
    else{
        std::cout<<"Wrong values entered";
        return 0;
    }
}

int user_input(int level){
    //user enters prediction  and return range of prediction 
    std::string low {"1- 25"};
    std::string med {"1 - 50"};
    std::string high {"1 - 100"};

    if (level == 1 ){
        std::cout<<"Enter perdiction btw"<<low<<'\n';
        return 25;
    }
    else if(level == 2){
        std::cout<<"Enter perdiction btw"<<med<<'\n';
        return 50;
    }
    else if(level == 3){
        std::cout<<"Enter perdiction btw"<<high<<'\n';
        return 100;
    }
    else{
        std::cout<<"invalid level"<<'\n';
        return 0;
    }
}

int random_setup (int x , int y){
    // setup up random generation module 
    std::random_device seed;  //uses device to generte random number
    std::mt19937 engine{seed()};
    std::uniform_int_distribution<int> dist(x,y);

    int number = dist(engine);
    return number;
}


int main (){
    //main loop for the program 
    std::cout<<"Welcome to my program";  //starting program
    for (int i=0;i<11;++i){
        std::cout<<".";
        delay(500);
    }
    std::cout<<"DONE"<<std::endl;
    //select level of complexity
    int level = level();  //function to choose level
    user_level = user_input(level);  //return of level to generate random numbers
    int number = random_setup(1 , user_level);
    int attempt = 0;
   
    while (true){ // loop though 
       
        int guess ;
        // get user input and compare it to the randomly generated number 
        std::cout<<"ENTER PREDICTION  :  :  "<<"\n";
        std::cin>>guess; 
        if (guess < 1 || guess > user_input){
            std::cout<<"Guess is within range"<<"\n";
            coninue;
        }
        else if (guess == number){
                std::cout<<"YOU have guessed it correctly"<<"\n";
                break;
            }
        else {
            std::cout<<"You have guess it wrong ....."<<"\n";
            std::cout<<"Try Again"<<"\n";
            
            ++attempt;

            if (attempt == 5){
                std::cout<<"you have Failed";
                break;
            }
            }
        }
    }






