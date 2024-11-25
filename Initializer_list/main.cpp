#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Array
{
private:
    vector<int> data;

public:
    Array(const initializer_list<int> &list)
    {
        for(auto &element : list)
            data.push_back(element);
    }

    vector<int>getData()
    {
        return data;
    }
};

int main(int argc, char *argv[])
{
    Array array { 1, 2, 3, 4, 5 };

    for(auto& element : array.getData())
        cout << element << ' ';

    return 0;
}
