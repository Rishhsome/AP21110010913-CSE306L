#include <bits/stdc++.h>
using namespace std;

class SymbolTableLinearSorted
{
    private:
        vector<pair<string, int>> entries;

    public:
        void insert(const string &identifier, int value)
        {
            entries.push_back(make_pair(identifier, value));
            sort(entries.begin(), entries.end(),[](const auto &a, const auto &b)
            {
                return a.first < b.first;
            });
        }

        int lookup(const string &identifier)
        {
            for (const auto &entry : entries)
                if (entry.first == identifier)
                    return entry.second;
            return -1;
        }
};

int main()
{
    SymbolTableLinearSorted symbol_table_linear;
    symbol_table_linear.insert("variable1", 42);
    symbol_table_linear.insert("function1", 100);
    symbol_table_linear.insert("variable2", 30);
    symbol_table_linear.insert("function2", 200);
    symbol_table_linear.insert("variable3", 60);
    symbol_table_linear.insert("function3", 300);

    cout << symbol_table_linear.lookup("variable1") << endl;  // 42
    cout << symbol_table_linear.lookup("function1") << endl;  // 100
    cout << symbol_table_linear.lookup("variable2") << endl;  // 30
    cout << symbol_table_linear.lookup("function2") << endl;  // 200
    cout << symbol_table_linear.lookup("variable3") << endl;  // 60
    cout << symbol_table_linear.lookup("function3") << endl;  // 300

    return 0;
}
