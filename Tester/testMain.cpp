//
//  testMain.cpp
//  
//
//  Created by Gavin Scheele on 10/15/15.
//
//


#include "MinHeap.h"

template <typename T>
void printMenu(MinHeap<T> *mh, int input){
    
    if (std::cin >> input) {
        if (input > 5 || input < 1) {
            std::cerr << "Input was not a number form 1-5!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            printMenu(mh, input);
        }
        
        switch (input) {
            case 1:{
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
                //won't print the tree for tests, mostly for personal visualization.
                break;
            case 5:
                std::cout << "Goodbye." << std::endl;
                return;
            default:
                break;
        }
    }else{
        std::cerr << "Input was not a number from 1-5!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
}

int main(int argc, const char * argv[]) {
    
    
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
