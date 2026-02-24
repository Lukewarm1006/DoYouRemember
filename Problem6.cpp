#include <iostream>
#include <vector>

void removeOddNums(std::vector<int>& v){
    int n = v.size();

    for (int i = 0; i < n; i++){
        if (v[i] % 2 != 0){  
            v.erase(v.begin()+i);
            i--;
            n--;
        }        
    }
};

int main(){
    std::vector<int> vector = {1,2,3,4,5,5,6,7,8,9,10};

    for (auto& x : vector) std::cout << x << " ";
    std::cout << std::endl;

    removeOddNums(vector);
    for (auto& x : vector) std::cout << x << " ";
    std::cout << std::endl;
}