#!/bin/bash
{
    cat ~/gitignore_files/C++.gitignore
} > .gitignore

{
    echo "#include<bits/stdc++.h>
using namespace std;
int main () {
    string s;
    while (getline(cin, s)) {
        if (s.length() < 6) continue;
        assert(s[0]=='.' && s[1]=='/');
        int p=(int)s.length()-4;
        assert(s.substr(p,4) == \".cpp\");
        cout << s.substr(2, p-2) << '\n';
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
    echo ".DS_Store"
} >> .gitignore
