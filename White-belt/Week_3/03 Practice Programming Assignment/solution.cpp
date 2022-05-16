#include <iostream>
#include <vector>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        // используется сортировка вставками
        for (int i = 0; i < Strings.size(); ++i) {
            if (Strings[i] > s){
                Strings.insert(begin(Strings) + i, s);
                return;
            }
        }
        Strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        return Strings;
    }
private:
    vector<string>Strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  return 0;
}