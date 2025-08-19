#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool yesNo(const string& q) {
    while (true) {
        cout << q << " (y/n): ";
        string s;
        if (!(cin >> s)) exit(0);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s == "y" || s == "yes") return true;
        if (s == "n" || s == "no")  return false;
        cout << "Please answer y or n.\n";
    }
}

void AlarmHandling() {
    bool inside = yesNo("Are you inside the building?");
    if (inside) {
        cout << "-> Push the nearest manual fire alarm trigger.\n";
        return;
    }
    bool outside = yesNo("Are you outside the building?");
    if (outside) {
        cout << "-> Contact the fire department immediately.\n";
        return;
    }
    bool autoTrig = yesNo("Has the automatic smoke/fire alarm triggered?");
    if (autoTrig) {
        cout << "-> Alarm auto triggered, follow evacuation instructions.\n";
        return;
    }
}

void FireSmokeDetection() {
    cout<< "\n Fire/Smoke Detection \n";
    if (yesNo("Do YOU see fire/smoke?")) {
        AlarmHandling();
        return;
    }
    if (yesNo("Did someone else see fire/smoke?")) {
        AlarmHandling();
        return;
    }
    if (yesNo("Did smoke detector trigger?")) {
        AlarmHandling();
        return;
    }
    cout << "-> No detection at this stage.\n";
}

void PrepareToExit() {
    cout << "\nPrepare to Exit \n";
    cout << "Collect items if reachable:\n";
    cout << "- Keys\n- Wallet/ID\n- Phone\n- Wet towels/cloths\n";
}

bool SafeRoomProcedure() {
    cout << "\n Safe Room Procedure \n";
    cout << "-> Enter a safe room with window if possible.\n";
    cout << "-> Seal cracks with wet towels.\n";
    cout << "-> Call emergency services and signal from window.\n";
    cout << "-> Wait for rescue.\n";
    return false; // could not escape
}

bool EvacuationPath() {
 cout << "\nEvacuation Path \n";
 cout << "Use stairs only (never elevators).\n";

 // Check downstairs path
 if (!yesNo("Do you see strong fire/smoke blocking the downstairs path?")) {
     cout << "-> Go DOWNSTAIRS and exit the building.\n";
     if (yesNo("Have you completely exited the building?")) {
         cout << "You are SAFE outside. ✅\n";
         return true; // escaped successfully
     } else {
         cout << "-> Could not exit, fallback to Safe Room Procedure.\n";
         return SafeRoomProcedure();
     }
 } 
 else {
     // Path blocked, go upstairs
     cout << "-> Path is blocked. Go UPSTAIRS and head to a BALCONY.\n";
     if (yesNo("Did you reach a balcony?")) {
         cout << "-> Balcony reached. WAIT for rescue there. \n";
         return false; // waiting
     } else {
         cout << "-> Balcony not accessible. Switch to Safe Room Procedure.\n";
         return SafeRoomProcedure();
     }
 }
}

bool DoorSafetyCheck() {
    cout << "\n Door Safety Check (DSC) \n";
    if (yesNo("Is the door HOT or is smoke seeping in?")) {
        cout << "-> Do NOT open the door.\n";
        cout << "-> Seal all cracks with wet towels.\n";
        cout << "-> Call fire department, wave from window.\n";
        cout << "-> Wait for rescue.\n";
        return false; // blocked, cannot proceed to EP
    } else {
        cout << "-> Door is safe. Proceed to Evacuation Path (EP).\n";
        return true;
    }
}

// main function
int main() {
    cout << "      Fire Evacuation Assiatant      \n";
    cout << "Stay calm. Direct fire/smoke and prepare to act.\n";

    FireSmokeDetection();
    PrepareToExit();

    bool doorOk = DoorSafetyCheck();
    bool escaped = false;

    if (doorOk) {
        escaped = EvacuationPath();
    } else {
        escaped = false; // waiting for rescue
    }

    // Termination

    if (escaped) {
        cout << "-> Move to safe assembly point outside.\n";
    } else {
        cout << "-> Stay in safe room / balcony and WAIT for rescue.\n";
    }
    return 0;
}
