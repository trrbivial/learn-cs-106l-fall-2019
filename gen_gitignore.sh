#!/bin/bash
{
    cat ~/gitignore_files/C++.gitignore
} > .gitignore

{
    echo "#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        string t=\"\";
        for(size_t i=2;i+4<s.length();i++)t+=s[i];
        cout<<t<<'\n';
    }
    return 0;
}"
} > gen_gitignore.cpp

g++ -std=c++17 -Wall gen_gitignore.cpp -o gen_gitignore
{
    echo ''
    echo '# *.cpp file'
    find -name "*.cpp" | ./gen_gitignore
} >> .gitignore

rm -f gen_gitignore.cpp gen_gitignore

{
    echo "*.zip"
} >> .gitignore
