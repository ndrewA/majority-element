#include <iostream>
#include <vector>

int getMajority(std::vector<int> v)
{
    if(v.empty()) return -1;

    int curMajority = v[0];
    int curFreq = 1;
    size_t subStart = 0;

    for(size_t i = 1; i < v.size(); i++)
    {
        if(v[i] == curMajority) ++curFreq;
        else if((unsigned)curFreq <= (i-subStart)/2) {
                curMajority = v[i];
                subStart = i;
        }
    }

    curFreq = 0;
    for(const auto& i : v)
        if(i == curMajority)
            ++curFreq;

    if((unsigned)curFreq > v.size()/2) return curMajority;
    else return -1;
}

int main()
{
    int res = getMajority({1, 2, 5, 9, 5, 9, 5, 5, 5});
    std::cout << "res = " << res << '\n';
    return 0;
}
