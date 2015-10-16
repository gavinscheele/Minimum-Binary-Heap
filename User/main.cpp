//
//  main.cpp
//  Binary Min Heap
//
//  Created by Gavin Scheele on 10/11/15.
//  Copyright (c) 2015 Gavin Scheele. All rights reserved.
//

#include "MinHeap.h"

template <typename T>
void printMenu(MinHeap<T> *mh, int input){
    std::cout << "1. Insert new element" << std::endl;
    std::cout << "2. Print minimum element" << std::endl;
    std::cout << "3. Print and remove minimum element" << std::endl;
    std::cout << "4. Print the tree" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "Please enter a number from 1-5" << std::endl;
    
    if (std::cin >> input) {
        if (input > 5 || input < 1) {
            std::cerr << "Input was not a number form 1-5!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            printMenu(mh, input);
        }
        
        switch (input) {
            case 1:{
                std::cout << "Data to insert:";
                T insertData;
                if(std::cin >> insertData)
                    mh->insert(insertData);
                else{
                    std::cerr << "Not a string" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 2:
                mh->printMin();
                break;
            case 3:
                mh->removeMin();
                break;
            case 4:
                mh->printMH();
                break;
            case 5:
                std::cout << "Goodbye." << std::endl;
                return;
            default:
                break;
        }
        std::cout << "---------------------\n\n\n";
    }else{
        std::cerr << "Input was not a number from 1-5!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

}

int main(int argc, const char * argv[]) {
    std::cout << "Welcome to Minimum Binary Heap. What would you like to do?" << std::endl;
    std::cout << "Please note that all inserted elements must be of the same data type" << std::endl;
    
    std::cout << "Which data type would you like to fill the heap with?" << std::endl;
    std::cout << "1. string" << std::endl;
    std::cout << "2. char" << std::endl;
    std::cout << "3. int" << std::endl;
    std::cout << "4. double" << std::endl;
    std::cout << "5. float" << std::endl;
    
    
    int inputType = 0;
    int input = 0;
    bool error = true;
    while (error) {
        
        if (std::cin >> inputType) {
            if (inputType > 5 || inputType < 1) {
                std::cerr << "Input was not a number form 1-5!\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        
            switch (inputType) {
                case 1:{
                    MinHeap<std::string> *mh = new MinHeap<std::string>;
                    while (input != 5) {
                        printMenu(mh, input);
                    }
                    error = false;
                    break;
                }
                case 2:{
                    MinHeap<char> *mh = new MinHeap<char>;
                    while (input != 5) {
                        printMenu(mh, input);
                    }
                    error = false;
                    break;
                }
                case 3:{
                    MinHeap<int> *mh = new MinHeap<int>;
                    while (input != 5) {
                        printMenu(mh, input);
                        
                    }
                    error = false;
                    break;
                }
                case 4:{
                    MinHeap<double> *mh = new MinHeap<double>;
                    while (input != 5) {
                        printMenu(mh, input);
                    }
                    error = false;
                    break;
                }
                case 5:{
                    MinHeap<float> *mh = new MinHeap<float>;
                    while (input != 5) {
                        printMenu(mh, input);
                    }
                    error = false;
                    break;
                }
                default:
                    break;
            }
        
        }else{
            std::cerr << "Input was not a number from 1-5!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    
    
    
    
    return 0;
}
