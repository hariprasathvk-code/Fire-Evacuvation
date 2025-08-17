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


// main function
int main() {
    cout << "      FIRE EVACUATION ASSISTANT      \n";
    cout << "Stay calm. Direct fire/smoke and prepare to act.\n";

    // Process (FSD -> AH -> PE -> DSC -> EP/SRP)
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
