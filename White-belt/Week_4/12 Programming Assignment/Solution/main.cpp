#include <iostream>
#include <exception>
#include <string>

using namespace std;

string AskTimeServer() {
	//throw runtime_error("Other exception");
    //throw system_error();
    return "01:01:01";
}

class TimeServer
{
public:
	string GetCurrentTime() {
        try {
            LastFetchedTime = AskTimeServer();
        }
        catch (system_error& se) {}
        catch (runtime_error& ex) {
            throw ex;
        }
        return LastFetchedTime;
	}
private:
	string LastFetchedTime = "00:00:00";
};

int main() {
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	} catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}