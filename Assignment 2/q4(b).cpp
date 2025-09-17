#include <iostream>
#include <algorithm> // For std::reverse
#include <string>
using namespace std;

int main() {
    std::string str = "Hello, world!";
    
    std::reverse(str.begin(), str.end());
    
    std::cout << "Reversed string: " << str << std::endl;
    
    return 0;
}
