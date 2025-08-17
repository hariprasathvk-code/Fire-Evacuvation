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
";
    return 0;
}
