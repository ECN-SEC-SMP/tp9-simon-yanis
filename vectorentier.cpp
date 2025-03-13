#include <iostream> 
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // for(int i=0; i < 3;i ++){
    //     cout << v[i];
    // }

    // int a[] = {0, 1, 2};
    // for (int n : a){
    //     cout << v[n];
    // }


    for(std::vector<int>::iterator it =v.begin();
        it != v.end();it++){
            std::cout << *it << "";
            } 
        std::cout <<"\n";
    
    v.push_back(4);
    cout << "taille de v : " << v.size() << "";

    vector<int> copie(4);
    copy(v.begin(),v.end(), copie.begin() );
    std::cout <<"\n";


    for(std::vector<int>::iterator it3 =copie.begin() ; it3 != copie.end() ; it3++){
            std::cout << *it3 << "";
            } 
        std::cout <<"\n";

}

