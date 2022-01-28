#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "vector.h"
void print_vec(const vector<int>& vec)
{
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}
void display_sizes(char const* comment,
                   const vector<int>& nums1,
                   const vector<int>& nums2,
                   const vector<int>& nums3)
{
    std::cout << comment
              << " nums1: " << nums1.size() << ','
              << " nums2: " << nums2.size() << ','
              << " nums3: " << nums3.size() << '\n';
}

void display(char const* comment, const vector<int>& v)
{
    std::cout << comment << "{ ";
    for (int e : v) {
        std::cout << e << ' ';
    }
    std::cout << "}\n";
}
int main () {
    // c++11 initializer list syntax:
    vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';

    // words3 == words1
    vector<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';

    // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
    vector<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';

    vector<int> nums1 {3, 1, 4, 6, 5, 9};
    vector<int> nums2;
    vector<int> nums3;

    display_sizes("Initially:\n", nums1, nums2, nums3);

    // copy assignment copies data from nums1 to nums2
    nums2 = nums1;

    display_sizes("After assignment:\n", nums1, nums2, nums3);

    // move assignment moves data from nums1 to nums3,
    // modifying both nums1 and nums3
    nums3 = std::move(nums1);

    display_sizes("After move assignment:\n", nums1, nums2, nums3);

    display("Now nums3 = ", nums3);

    // copy assignment of an initializer_list copies data to nums3
    nums3 = {1, 2, 3};

    display("After assignment of initializer_list \n nums3 = ", nums3);

    std::cout << '\n';
    vector<int> nums {1, 2, 4, 8, 16};
    vector<std::string> fruits {"orange", "apple", "raspberry"};
    vector<char> empty;
 
    // Print vector.
    std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
 
    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
 
    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';
 
    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";
    
    vector<int> c = {1, 2, 3};
    std::cout << "The vector holds: ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';

    vector<std::string> letters;

    letters.push_back("abc");
    std::string s = "def";
    letters.push_back(std::move(s));

    std::cout << "vector holds: ";
    for (auto&& i : letters) std::cout << std::quoted(i) << ' ';
    std::cout << "\nMoved-from string holds " << std::quoted(s) << '\n';

    vector<int> vec(3,100);
    print_vec(vec);

    auto it = vec.begin();
    it = vec.insert(it, 200);
    print_vec(vec);

    vec.insert(it,300);
    vec.insert(it,300);
    print_vec(vec);

    return 0;
}
