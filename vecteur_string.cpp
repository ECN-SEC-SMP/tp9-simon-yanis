#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void print_vec(vector<string> &vec);

string concatene(vector<string> &vec) {
    ostringstream os;
    for (string &st : vec)
    {
        os << st << " ";
    }

    return os.str();
}

void ajouter_virgule(vector<string> &vec) {
    for_each(vec.begin(), vec.end(), [](string &a){a = a.append(",");});
}

int main()
{
    vector<string> vec;

    vec.push_back("Bonjour");
    vec.push_back("Comment");
    vec.push_back("allez");
    vec.push_back("vous");
    vec.push_back("?");

    cout << "Taille: " << vec.size() << " Capacite: " << vec.capacity() << endl;

    vec.push_back("Test");
    
    cout << "Taille: " << vec.size() << " Capacite: " << vec.capacity() << endl;

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    for (string &st : vec)
    {
        cout << st << " ";
    }
    cout << endl;

    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    swap(vec[1], vec[3]);
    
    print_vec(vec);

    vec.insert(vec.begin()+1, "à tous");

    print_vec(vec);

    vector<string>::iterator res = find(vec.begin(), vec.end(), "?");
    if(res == vec.end()) {
        cout << "Missing ?" << endl;
        return 1;
    }

    *res = "???";

    print_vec(vec);

    for (string &st : vec)
    {
        cout << st << ",";
    }
    cout << endl;
    sort(vec.begin(), vec.end());

    print_vec(vec);

    string result = concatene(vec);
    cout << result << endl;

    ajouter_virgule(vec);

    print_vec(vec);

}

void print_vec(vector<string> &vec) {
    for (string &st : vec)
    {
        cout << st << " ";
    }
    cout << endl;
}