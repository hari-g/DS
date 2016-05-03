#ifndef GARRAGEDOOR_H
#define GARRAGEDOOR_H

/*
 * Using State Pattern to solve the garrage door problem *
 * Just skeleton code
 */

#include <string>
#include <vector>
#include <iostream>
class State;

class GarrageDoor
{
public:
    State *currentState;
    GarrageDoor();
    void ButtonClicked();
    void CycleComplete();
    std::string printState();
};

class State{
private:
    std::string stringName;
public:
    virtual void ButtonClicked(GarrageDoor &) {}
    virtual void CycleComplete(GarrageDoor &){}
    virtual std::string printState(){ return "";}
    virtual ~State(){}
};

class Opening : public State {
 public:
    void ButtonClicked(GarrageDoor &);
    void CycleComplete(GarrageDoor &);
    std::string printState();
};

class Closing : public State {

};

class Opened : public State{

};

class Closed: public State {

};

class StoppedWhileOpening : public State {

};

class StoppedWhileClosing : public State {

};

#endif // GARRAGEDOOR_H
