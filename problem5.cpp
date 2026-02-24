#include <iostream>
#include <string>

void reverseString(std::string& s){
    std::string temp_s = s;
    int n = s.size();

    for (int i = 0; i < n; i++){
        temp_s[i] = s[n-i-1];
    }

    s = temp_s;
}

int main(){
    
    std::string myName = "Luke";
    std::cout << myName << std::endl;
    reverseString(myName); // Reverse the name using pointers
    std::cout << myName << std::endl;
}