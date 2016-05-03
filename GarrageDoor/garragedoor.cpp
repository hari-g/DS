#include "garragedoor.h"

GarrageDoor::GarrageDoor()
{
    currentState = new Opening();
}

void GarrageDoor::ButtonClicked()
{
 currentState ->ButtonClicked(*this);
}

void GarrageDoor::CycleComplete()
{
    currentState->CycleComplete(*this);
}

std::string GarrageDoor::printState()
{
    return currentState->printState();
}

void Opening::ButtonClicked(GarrageDoor & gd)
{
    gd.currentState = new StoppedWhileOpening();
    delete(this);
}

void Opening::CycleComplete(GarrageDoor &gd)
{
    gd.currentState = new Opened();
    delete(this);
}

std::string Opening::printState() {
    return "Opening";
}
