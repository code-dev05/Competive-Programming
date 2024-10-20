#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int x = 0; x < T; x++) {
        string inp;
        cin >> inp;
        string arr[2] = {"", ""};
        int count = 0;
        for (int i = 0; i < inp.size(); i++) {
            if (inp[i] == ':') {
                count++;
                continue;
            } 
            
            arr[count] += inp[i];
        }

        string period;
        int hour = stoi(arr[0]);
        if (hour >= 12) {
            period = "PM";
            if (hour > 12) {
                hour -= 12;
            }
        } else if (hour == 0) {
            hour = 12;
            period = "AM";
        } else {
            period = "AM";
        }

        string str = to_string(hour);

        if (str.size() == 1) {
            str = "0" + str;
        }

        cout << str << ":" << arr[1] << " " << period << endl;
    }
}