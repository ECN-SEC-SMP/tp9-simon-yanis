#include <iostream> 
#include <iterator>
#include <algorithm>
#include <list>
#include <cstdlib>

using namespace std;
int main(){

    list<int> L;

    std::list<int>::iterator it =L.begin();
    for (int i=1; i<=7; ++i) L.push_back(i);
    for(it = L.begin(); it != L.end(); it++){
            std::cout << *it << "";
            } 
    std::cout <<"\n";

    it = L.begin();
    it ++;
    it ++;
    it ++;

    L.erase(it);
    
    for(it = L.begin(); it != L.end(); it++){
            std::cout << *it << "";
            } 
    std::cout <<"\n";
}




