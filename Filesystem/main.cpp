#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

int main(int argc, char *argv[])
{
    basic_string <char> dir, str;
    cout << "Input directory and extension:" << endl;
    cin >> dir >> str;

    auto recursiveGetFileNamesByExtension =
        [](filesystem::path path, const string extension)
    {
        bool ch = true;
        for(auto& p: filesystem::recursive_directory_iterator(path))
        {
            if(extension == p.path().extension())
            {
                cout << p.path() << endl;
                ch = false;
            }
        }
        if(ch)
            cerr << "Extension not found" << endl;
        else
            cout << "Complete" << endl;
    };

    try
    {
        recursiveGetFileNamesByExtension(dir, str);
    }
    catch(exception&)
    {
        cerr << "Incorrect directory" << endl;
    }

    return 0;
}
