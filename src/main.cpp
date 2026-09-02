#include <iostream>
#include "EventComponent.h"
#include "EventGroup.h"
#include "EventControl.h"
#include "Notice.h"


#include "ConsoleStation.h"
#include "SwitchStation.h"
#include "PCStation.h"
#include "FoodVendor.h"
#include "MerchVendor.h"

#include "MobileStation.h"
#include "TournamentDesk.h"
#include "InfoDesk.h"
#include "TicketBooth.h"
#include "VRBooth.h"

using namespace std;

int main() {
    cout << "Building PixelCon" << endl;
    EventGroup* pixelCon = new EventGroup("PixelCon");
    EventGroup* pcHall = new EventGroup("PC Hall");
    EventGroup* tournamentZone = new EventGroup("Tournament Zone");
    EventGroup* consoleHall = new EventGroup("Console Hall");
    EventGroup* outdoorPlaza = new EventGroup("Outdoor Plaza");

    PCStation*  pcStation1 = new PCStation("PC Station 1", 1, "Valorant");
    PCStation*  pcStation2 = new PCStation("PC Station 2", 1, "Valorant");
    TournamentDesk* tourneyDesk = new TournamentDesk("Tournament Desk", 32, 1);

    ConsoleStation* consoleStation = new ConsoleStation("Console Station 1", 4);
    SwitchStation*  switchStation  = new SwitchStation("Switch Station 1", 4, true);

    FoodVendor*  foodVendor  = new FoodVendor("Taco Vendor", 10);
    MerchVendor* merchVendor = new MerchVendor("Merch Stand", 15, 200);
    MobileStation* mobileStation = new MobileStation("Roaming Help Cart", 5);
    InfoDesk*    infoDesk    = new InfoDesk("Main Info Desk", 20, "Welcome to PixelCon!");
    TicketBooth* ticketBooth = new TicketBooth("Front Ticket Booth", 25);
    VRBooth*     vrBooth     = new VRBooth("VR Demo Booth", 1);

    pcHall->addChildren(pcStation1);
    pcHall->addChildren(pcStation2);
    tournamentZone->addChildren(tourneyDesk);
    pcHall->addChildren(tournamentZone);  
    consoleHall->addChildren(consoleStation);
    consoleHall->addChildren(switchStation);
    
    outdoorPlaza->addChildren(foodVendor);
    outdoorPlaza->addChildren(merchVendor);
    outdoorPlaza->addChildren(mobileStation);
    outdoorPlaza->addChildren(infoDesk);
    outdoorPlaza->addChildren(ticketBooth);
    outdoorPlaza->addChildren(vrBooth);

    pixelCon->addChildren(pcHall);
    pixelCon->addChildren(consoleHall);
    pixelCon->addChildren(outdoorPlaza);

    
    EventControl control(pixelCon);
    control.attach(pixelCon);

    
    pixelCon->attach(pcHall);
    pixelCon->attach(consoleHall);
    pixelCon->attach(outdoorPlaza);

    pcHall->attach(pcStation1);
    pcHall->attach(pcStation2);
    pcHall->attach(tournamentZone);
    tournamentZone->attach(tourneyDesk);

    consoleHall->attach(consoleStation);
    consoleHall->attach(switchStation);

    outdoorPlaza->attach(foodVendor);
    outdoorPlaza->attach(merchVendor);
    outdoorPlaza->attach(mobileStation);
    consoleHall->attach(infoDesk);
    outdoorPlaza->attach(ticketBooth);
    pcHall->attach(vrBooth);

    pixelCon->open();
    mobileStation->joinQueue();
    mobileStation->joinQueue();
    ticketBooth->open();
    vrBooth->open();

    cout << "\n===== Composite traversal/query =====" << endl;
    pixelCon->reportStatus();
    cout << "Total live capacity across PixelCon: " << pixelCon->getCapacity() << endl;

    // ---- Notice 1: ordinary operational change, cascades from root ----
    cout << "\n===== Notice: SCHEDULE_CHANGE (cascading from EventControl) =====" << endl;
    control.issueNotice(Notice(NoticeType::SCHEDULE_CHANGE,
                                "Bracket matches pushed back 30 minutes", 1));

    //  Notice 2: capacity-related change ----
    cout << "\n===== Notice: CAPACITY_ALERT =====" << endl;
    control.issueNotice(Notice(NoticeType::CAPACITY_ALERT,
                  "Outdoor Plaza nearing capacity", 5));

    // Notice 3: safety-related change, issued directly to a zone ----
    cout << "\n===== Notice: WEATHER_ALERT (issued directly to Outdoor Plaza) =====" << endl;
    outdoorPlaza->update(Notice(NoticeType::WEATHER_ALERT,
                      "Thunderstorm approaching the venue", 0));

    //  Registration change: InfoDesk stops receiving Outdoor Plaza notices ----
    cout << "\n===== Registration change: detaching InfoDesk from Outdoor Plaza =====" << endl;
    outdoorPlaza->detach(infoDesk);
    control.issueNotice(Notice(NoticeType::PAUSE, "Brief pause for cleanup", 0));
    cout << "(InfoDesk did not react - it is no longer a registered observer.)" << endl;
    outdoorPlaza->attach(infoDesk); // re-register it for the rest of the demo

    // Runtime reorganisation: move the mobile station to Console Hall 
    cout << "\n===== Runtime reorganisation: moving Roaming Help Cart to Console Hall =====" << endl;
    EventComponent* relocated = outdoorPlaza->removeChildren(mobileStation); // also detaches it
    consoleHall->addChildren(relocated);
    consoleHall->attach(mobileStation);
    mobileStation->joinQueue();

    // Notice 4: safety-related change - full evacuation
    cout << "\n Notice: EVACUATE" << endl;
    control.issueNotice(Notice(NoticeType::EVACUATE, "Fire alarm triggered", 0));

    cout << "\n Post-evacuation status" << endl;
    pixelCon->reportStatus();

    // Evacuation-locked booth refuses to reopen until RESUME.
    ticketBooth->open();

    //  Notice 5: all clear 
    cout << "\n Notice: RESUME" << endl;
    control.issueNotice(Notice(NoticeType::RESUME, "All clear, resuming normal operations", 0));
    ticketBooth->open();
    vrBooth->open();

    cout << "\n Final status" << endl;
    pixelCon->reportStatus();
    cout << "Total live capacity across PixelCon: " << pixelCon->getCapacity() << endl;

    cout << "\n Shutting down PixelCon" << endl;
    pixelCon->close();
    delete pixelCon; // recursively releases the entire owned subtree exactly once

    cout << "PixelCon shut down cleanly." << endl;
    return 0;
}
