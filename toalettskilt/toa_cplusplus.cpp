#include <iostream>
using namespace std;

int minutter = 2;
int nummer = 1;

// C++
int main() {
    bool dametoalett = true;
    bool herretoalett = false;

    if (minutter > 2) {
      herretoalett = false;
    } else {
      if (nummer == 2) {
        herretoalett = false;
      } else if (nummer == 1) {
        herretoalett = true;
      } else {
        cout << "Hva driver du med...";
      }
    }
    
    cout << herretoalett;

    return 0;
}
