#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector> //includes a better type of array variable, which is fast and can access files too
#include <fstream> //includes command lines that can be used to access files
using namespace std;


int main(){
    string play = "y";
    while (play == "y" || play == "yes"){
        //get random seed from the PCs clock
        srand(time(0));
        
        //Makes a dymaic vector to hold all the words in the text file
        vector<string>words; 
        
        //opens the textfile 
        ifstream fileInput("words.txt");
        
        //Reads the whole document until it reaches the end of the file then chooses a word
        string tempWord;
        while (fileInput >> tempWord){
            words.push_back(tempWord);
        }
        //closes the file 
        fileInput.close();
        
        
        //chooses a random word and sets underscores for the secret word
        string secretword = words[rand() % words.size()];
        string displayword(secretword.length(), '_');
        
        //lives and letting you write words + graveyard 
        int tries = 8;
        string guess;
        string graveyard =""; 
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Welcome to hangman, you have 8 attempts to guess the secret word"<<endl;
        
        //creates underscores for the word chosen and has the game logic
        while (tries > 0 && displayword != secretword){
            cout<<"---------------------------------------------------"<<endl;
            cout<<"Graveyard: [ "<< graveyard <<" ] "<<endl;
            for (int i = 0; i < displayword.length(); i++){
                cout<< displayword[i]<<" ";
            }
            cout<<"\nYour guess: ";
            cin>>guess;
            
            //Only allows underscore letters
            for (int i = 0; i < guess.length(); i++ ){
                guess[i] = tolower(guess[i]);
            }
            // If you try to guess the whole word you either win or lose 2 lives
            if (guess.length() > 1){
                if (guess == secretword){
                    cout<<"Wow you got the whole word!"<<endl;
                    displayword = secretword;
                    cout<< secretword <<endl;
                }
                else {
                    cout<<"Wrong! You lose two attempts for trying to write more letters and failing to guess the word"<<endl;
                    tries -= 2;
                    cout<< tries <<" attempts left!"<<endl;
                }
            }
            //Here if you try to write only one letter 
            else if (guess.length() == 1){
                char letterguess = guess[0];
                bool matchfound = false; 
                //Shows you letters you already used
                if (graveyard.find(letterguess) != string::npos){
                    cout<<"You have already guessed "<< letterguess <<endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                graveyard += letterguess; 
                graveyard += " ";
                //checks if a letter matches
                for (int p = 0; p < secretword.length(); p++ ){
                    if (secretword[p] == letterguess){
                        displayword[p] = letterguess;
                        matchfound = true;

                    }
                }
                if(matchfound == true){
                    cout<<"The letter "<< letterguess <<" is part of the secret word"<<endl;
                }
                else {
                    tries -= 1;
                    cout<<"Wrong! You have "<< tries <<" attempts left!"<<endl;
                }
            }
            system("pause");
            system("cls");
        }
        
        //When you win or lose 
        cout<<"\n---------------------------------------------------"<<endl;
        if (displayword == secretword){
            cout<<"The word was: "<< secretword <<endl;
            cout<<"Congrats! You got won with "<< tries <<" lives left!"<<endl;
        }
        else {
            cout<<" You lost! The word was " << secretword <<endl;
        }
        //play again? type yes for yes, anything else will stop the game 
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Do you want to play again? Type yes or no"<<endl;
        cin>>play;
        if (play == "yes"){
            cout<<"New round started!"<<endl;
            continue;
        }
        else {
            cout<<"Game terminated"<<endl;
            system("pause");
            return 0;
        }
    }

    
}