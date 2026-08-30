#include "EventControl.h"
#include "EventComponent.h"
#include "Notice.h"

EventControl::EventControl(EventComponent* root):root(root){}

void EventControl::issueNotice(const Notice& notice){
    notify(notice);
}

EventControl::~EventControl(){
}