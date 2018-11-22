#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dictSize = 256;

vector<string> explodeLine(const string &s, const string &del){
    static bool dict[dictSize] = {false};
    vector<string> res;
    string token("");

    for (int i = 0; i < del.size(); ++i) dict[del[i]] = true;
    for (auto &i : s){
        if (dict[i]){
            if (!token.empty()) {
                res.push_back(token);
                token.clear();
            }           
        }
        else token += i;
    }
    if (!token.empty()) res.push_back(token);
    
    return res;
}

int main(){
    string test("Name: mahdi mohammad shibli, id: 1712784642, school: dhaka residential model college");
    vector<string> output = explodeLine(test, " :,");

    for(unsigned i = 0; i < output.size(); i++) cout << output[i] << endl;
}