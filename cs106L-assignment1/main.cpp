#include <iostream>     	// for cout, cin
#include <fstream>      	// for ifstream
#include <sstream>      	// for stringstream
#include <filesystem>   	// making inputting files easier
#include <unordered_set>	// containers for the wikiscraper
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"    // wikiscraper methods

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;
using std::pair;            using std::domain_error;

int Getint(ifstream& fil) {
    string tmp;
    getline(fil, tmp);
    stringstream iss(tmp);
    int x;char ch;
    if (iss >> x && !(iss >> ch)) return x;
    throw domain_error("can't read an int");
    return -1;
}

pair<string, string> Getpair(ifstream& fil) {
    string tmp;
    getline(fil, tmp);
    stringstream iss(tmp);
    string st,ed;char ch;
    if (iss >> st && iss >> ed && !(iss >> ch)) return {st, ed};
    throw domain_error("can't read two strings");
    return {"", ""};
}
int main() {
    // a quick working directory fix to allow for easier filename inputs
    auto path = std::filesystem::current_path() / "res/";
    std::filesystem::current_path(path);
    std::string filenames = "Available input files: ";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path().string();
        filename = filename.substr(filename.rfind("/") + 1);
        filenames += filename + ", ";
    }
    // omit last ", ".
    cout << filenames.substr(0, filenames.size() - 2) << "." << endl;

    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name: ";
    string filename;
    getline(cin, filename);

    ifstream iss(filename.c_str());
    int n = Getint(iss);
    while (n--) {
        auto [st, ed] = Getpair(iss);
        auto p = findWikiLadder(st, ed);
        outputLadders.push_back(p);
        for (auto x : p) {
            cout << x << ' ';
        } cout << '\n';
    }
    /* 
        TODO: Create a filestream from the filename.
        For each pair {start_page, end_page} in the input file,
        retrieve the result of findWikiLadder(start_page, end_page)
        and append that vector to outputLadders.
    */
    // Write code here

    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    // Write code here

    return 0;
}




