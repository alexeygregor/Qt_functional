#include <iostream>
#include <memory>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

template<typename T>
void output(T ptr)
{
    cout << "\nUnique ptr: ";
    for(auto i : *ptr)
        cout << i << ' ';
}

int main(int argc, char *argv[])
{
    vector<int> vec = {6, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 1};

    auto lambda = [](vector<int> vec)
    {
        unordered_set<int> set;
        unique_ptr<vector<int>> ptr;

        for(auto i : vec)
            set.insert(i);
        sort(vec.begin(), vec.end());

        cout << "Set count: ";
        for(auto it = 0; it < vec.size(); ++it)
        {
            auto count = 0;
            for(auto a : set)
            {
                if(vec[it] == a)
                {
                    for(auto b : vec)
                    {
                        if(vec[it] == b)
                            ++count;
                    }
                }
            }
            for(auto ti = 0; ti < vec.size(); ++ti)
            {
                if(vec[ti] == vec[it] && ti != it)
                    vec.erase(vec.begin() + ti);
            }
            cout << vec[it] << "*(" << count << ") ";
        }

        vec.clear();
        for(auto i : set)
            vec.push_back(i);
        ptr = make_unique<vector<int>>(vec);

        return ptr;
    };

    output(lambda(vec));
    return 0;
}
