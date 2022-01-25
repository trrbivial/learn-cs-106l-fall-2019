#!/bin/bash
{
    cat ~/gitignore_files/C++.gitignore
} > .gitignore

find -name "*.cpp" > findfile.tmp

{
    echo "#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen(\"findfile.tmp\",\"r\",stdin);
    freopen(\"findfile.ttmp\",\"w\",stdout);
    string s;
    while(cin>>s){
        string t=\"\";
        for(int i=2;i+4<s.length();i++)t+=s[i];
        cout<<t<<'\n';
    }
    return 0;
}"
} > gen_gitignore.cpp

g++ -std=c++17 gen_gitignore.cpp -o gen_gitignore

./gen_gitignore

{
    echo ''
    echo '# *.cpp file'
    cat findfile.ttmp
} >> .gitignore

rm -f findfile.tmp findfile.ttmp
rm -f gen_gitignore.cpp gen_gitignore

{
    echo "*.zip"
} >> .gitignore
