//
//  main.cpp
//  C++ Project
//
//  Created by Alice Zhang on 7/17/19.
//  Copyright © 2019 Alice Zhang. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ufo_functions.hpp"
using namespace std;

int main() {
    //variables
    string codeword = "mochi", answer = "_____";
    int misses = 0;
    //print game title and instructions
    greeting();
    vector<char> incorrect;
    bool guess = false;
    char letter;
    
    //check
    while (answer != codeword && misses < 7) {
        display_misses(misses);
        display_status(incorrect, answer);
        
        cout << "\n\nPlease enter your guess: ";
        cin >> letter;
        
        for (int i = 0; i < codeword.length(); i++) {
            if (letter == codeword[i]) {
                
                answer[i] = letter;
                guess = true;
                
            }
            
        }
        
        if (guess) {
            
            std::cout << "\nCorrect!\n";
            
        } else {
            
            std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(letter);
            misses++;
            
        }
        
        guess = false;
        
    }
    
    //end
    end_game(answer, codeword);
    
    return 0;
}
