#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>>stop_to_bus;
map<string, vector<string>>bus_to_stop;

void new_bus() {
    string bus;
    int stop_count;
    cin >> bus >> stop_count;

    for (int i = 0; i < stop_count; ++i) {
        string stop;
        cin >> stop;

        bus_to_stop[bus].push_back(stop);
        stop_to_bus[stop].push_back(bus);
    }
}

void buses_for_stop() {
    string stop;
    cin >> stop;

    if (stop_to_bus.count(stop) == 0)
        cout << "No stop" << endl;
    else {
        for (auto bus: stop_to_bus[stop])
            cout << bus << " ";
        cout << endl;
    }
}

void stops_for_bus() {
    string bus;
    cin >> bus;

    if (bus_to_stop.count(bus) == 0)
        cout << "No bus" << endl;
    else {
        for (auto stop: bus_to_stop[bus]) {
            cout << "Stop " << stop << ":";

            if (stop_to_bus[stop].size() == 1)
                cout << " no interchange" << endl;
            else {
                for (auto change_bus: stop_to_bus[stop])
                    if (bus != change_bus)
                        cout << " " << change_bus;
                cout << endl;
            }
        }
    }
}

void all_buses() {
    if (bus_to_stop.empty()) {
        cout << "No buses" << endl;
        return;
    }
    for (const auto& [bus, stops_vector]: bus_to_stop) {
        cout << "Bus " << bus << ":";

        for (auto stop: stops_vector) {
            cout << " " << stop;
        }
        cout << endl;
    }
}

int main() {
    int Q;
    cin >> Q;

    while(Q --) {
        string command;
        cin >> command;

        if (command == "NEW_BUS")
            new_bus();
        else if (command == "BUSES_FOR_STOP")
            buses_for_stop();
        else if (command == "STOPS_FOR_BUS")
            stops_for_bus();
        else if (command == "ALL_BUSES")
            all_buses();
    }

    return 0;
}
