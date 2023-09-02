#include <bits/stdc++.h>
using namespace std;

class SymbolTableHashTable
{
    private:
        static const int size = 100;
        vector<pair<string, int>> table[size];

        int hash(const string &identifier)
        {
            int sum = 0;
            for (char c : identifier)
                sum += c;
            return sum % size;
        }

    public:
        void insert(const string &identifier, int value)
        {
            int index = hash(identifier);
            table[index].push_back(make_pair(identifier, value));
        }

        int lookup(const string &identifier)
        {
            int index = hash(identifier);
            for (const auto &entry : table[index])
                if (entry.first == identifier)
                    return entry.second;
            return -1;
        }
};

int main()
{
    SymbolTableHashTable symbol_table_hash;
    symbol_table_hash.insert("variable1", 42);
    symbol_table_hash.insert("function1", 100);
    symbol_table_hash.insert("variable2", 30);
    symbol_table_hash.insert("function2", 200);
    symbol_table_hash.insert("variable3", 60);
    symbol_table_hash.insert("function3", 300);

    cout << symbol_table_hash.lookup("variable1") << endl;  // 42
    cout << symbol_table_hash.lookup("function1") << endl;  // 100
    cout << symbol_table_hash.lookup("variable2") << endl;  // 30
    cout << symbol_table_hash.lookup("function2") << endl;  // 200
    cout << symbol_table_hash.lookup("variable3") << endl;  // 60
    cout << symbol_table_hash.lookup("function3") << endl;  // 300

    return 0;
}
