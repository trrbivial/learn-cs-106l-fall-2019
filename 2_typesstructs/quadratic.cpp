#include<bits/stdc++.h>
using std::cin;using std::cout;
std::pair<bool, std::pair<double, double>> sol(double a, double b, double c){
    double dt = b*b - 4*a*c;
    if(dt < 0)return {0, {0, 0}};
    dt = sqrt(dt);
    double rt1 = (-b-dt) / (2*a);
    double rt2 = (-b+dt) / (2*a);
    return {1, {rt1, rt2}};
}
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    auto [exists, res] = sol(a, b, c);
    if(!exists){
        cout << "No solutions exixt!" << '\n';
    } else {
        auto [rt1, rt2] = res;
        cout << "Solutions are:" << rt1 << ' ' << rt2 << '\n';
    }
    return 0;
}
