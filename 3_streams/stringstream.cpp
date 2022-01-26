#include<iostream>
#include<sstream>
using namespace std;
int stringTointeger(const string& str){
    istringstream iss(str);
    int res;
    iss >> res;
    if (iss.fail()) throw domain_error("114514");
    char tmp;
    iss >> tmp;
    if (!iss.fail()) throw domain_error("1919810");
    return res;
}
int main(){
	ostringstream oss("Ito En Green Tea");
    cout << oss.str() << '\n';

    string s;
    cin >> s;
    int res = stringTointeger(s);
    cout << res << '\n';
	return 0;
}
