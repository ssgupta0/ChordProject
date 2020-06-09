//
//  main.cpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <iostream>

#include "chordFactory.hpp"
#include "chordDecorator.hpp"
#include "chordVisitor.h"


void printC(chord* c) {
    std::cout << "Your chord is currently:"<<std::endl;
    c->printChord();
}

int main(int argc, const char * argv[]) {
    
    bool corInput = false;
    chord* base;
    
    std::cout<<"=========================\n===--Create a chord!--===\n=========================\n\n"<<std::endl;
    
    
    while(!corInput) {
        
        std::cout << "Choose a base key for your chord:\n (Default octave is 0 unless specified EX: C4 )"<<std::endl;
        std::string in;
        std::cin >> in;
        base = new chord(in);
        if(base->note1==-2) {
            corInput=false;
        }
        else {
            corInput=true;
        }
    }
    printC(base);
    
    std::cout<<"\nwhat type of chord?\n\tMajor(a)\tMinor(b)"<<std::endl;
    std::string choice = "";
    std::cin>>choice;
    
    chord* current = base;
    chord* prev = current;
    
    corInput = false;
    
    while(!corInput) {
        corInput=true;
        if(choice=="a") {
            prev=current;
            current = base->chordFactory(maj);
        }
        else if(choice=="b") {
            prev=current;
            current = base->chordFactory(min);
        }
        else {
            corInput=false;
        }
    }
    
    choice="";
    bool first = true;
    std::cout<<"\nOptions:\n\tView Chord\t\t\t\t\t(v)\n\tView Previous Chord\t\t\t(p)\n\tChange Chord Type\t\t\t(c)\n\tMove/Remove Notes\t\t\t(m)\n\tRevert to Previous Chord\t(r)\n\tQuit\t\t\t\t\t\t(q)"<<std::endl;
    while(true) {
        
        std::cin>>choice;
        if(choice=="v") {
            printC(current);
        }
        else if(choice=="p") {
            printC(prev);
        }
        else if (choice=="c") {
            corInput=false;
            while(!corInput) {
                corInput=true;
                std::cout<<"Select which chord type to change to:\n\t6 Chord(a)\t7 Chord(b)"<<std::endl;
                std::cin>>choice;
                if(choice=="a") {
                    if(current->dec==1) {
                        std::cout<<"This is already a 6 Chord!"<<std::endl;
                    }
                    else if (current->dec==2) {
                        std::cout<<"Cannot Change Chord Types!"<<std::endl;
                    }
                    else {
                        prev=current;
                        current=new sixChord(current);
                    }
                }
                else if(choice=="b") {
                    if(current->dec==2) {
                        std::cout<<"This is already a 7 Chord!"<<std::endl;
                    }
                    else if (current->dec==1) {
                        std::cout<<"Cannot Change Chord Types!"<<std::endl;
                    }
                    else {
                        prev=current;
                        current=new sevenChord(current);
                    }
                }
            }
        }
        else if(choice=="m") {
            corInput=false;
            while(!corInput) {
                corInput=true;
                std::cout<<"Do you want to Move or Remove Notes?\n\tMove(a)\tRemove(b)"<<std::endl;
                std::cin>>choice;
                
                chord* ptr;
                
                if(current->type==1) {
                    MajChord* rMove = static_cast<MajChord*>(current);
                    ptr=rMove;
                }
                else if(current->type==2) {
                    MinChord* rMove = static_cast<MinChord*>(current);
                    ptr=rMove;
                }
                else {
                    std::cout<<"ERROR CURRENT CHORD IS INVALID (neither major nor minor)"<<std::endl;
                }
                
                
                if(choice=="a") {
                    corInput=false;
                    std::cout<<"Select what to Move:\n\tDrop Root (a)\tRaise Soprano (b)"<<std::endl;
                    std::cin>>choice;
                    while(!corInput) {
                        corInput=true;
                        if(choice=="a") {
                            ptr->Accept(new dropRootVisitor);
                        }
                        else if(choice=="b") {
                            ptr->Accept(new RaiseSopVisitor);
                        }
                        else {
                            corInput=false;
                        }
                    }
                }
                
                else if (choice=="b") {
                    std::cout<<"Select what to Remove:\n\tremove root\t\t(a)\n\tremove 3rd\t\t(b)\n\tremove 5th\t\t(c)\n\t";
                    
                    if(current->dec==2) {
                        std::cout<<"remove seventh\t(d)"<<std::endl;
                    }
                    else {
                        std::cout<<"remove octave\t(d)"<<std::endl;
                    }
                    std::cin>>choice;

                    corInput=false;
                    while(!corInput) {
                        corInput=true;
                        if(choice=="a") {
                            ptr->Accept(new remove1Visitor);
                        }
                        else if(choice=="b") {
                            ptr->Accept(new remove2Visitor);
                        }
                        else if(choice=="c") {
                            ptr->Accept(new remove3Visitor);
                        }
                        else if(choice=="d") {
                            ptr->Accept(new remove4Visitor);
                        }
                        else {
                            corInput=false;
                        }
                    }
                }
                else {
                    corInput=false;
                }
            }
        }
        else if(choice=="r") {
            if(first) {
                std::cout<<"Cannot revert yet"<<std::endl;
            }
            else {
                chord* tmp = current;
                current=prev;
                prev=tmp;
            }
        }
        else if(choice=="q") {
            return 1;
        }
        
        if(first&&choice=="r") {
        }
        else {
            first=false;
        }
        std::cout<<"\nOptions:\n\tView Chord\t\t\t\t\t(v)\n\tView Previous Chord\t\t\t(p)\n\tChange Chord Type\t\t\t(c)\n\tMove/Remove Notes\t\t\t(m)\n\tRevert to Previous Chord\t(r)\n\tQuit\t\t\t\t\t\t(q)"<<std::endl;
    }
    
    return 0;
}


