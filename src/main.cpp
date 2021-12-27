#include <iostream>

using namespace std;

template<typename... Args>
bool all(Args... args) { return (... && args); }
 

int main(){
    bool b = all(true, true, true, false);
    cout<<"Here\n is b: "<<b;
}