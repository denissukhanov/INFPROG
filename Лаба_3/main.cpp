#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;

void myfunction(string & i)
{
    for(auto idx = i.find("ab"); idx != string::npos; idx = i.find("ab"))
        i.replace(idx,2,"ccc");
}
int main()
{
    vector<string> v;
    v.push_back("about");
    v.push_back("ambulance");
    v.push_back("abroad");
    v.push_back("they");
    v.push_back("say");
    v.push_back("ababa");
    vector<string> v1;
    for (int i=0; i<v.size(); i++)
        v1.push_back(v[i]);

    ostream_iterator<string> printit(cout, " ");

    cout << "Before replacing" << endl;
    copy(v1.begin(), v1.end(), printit);

    for_each(v1.begin(), v1.end(), myfunction);

    cout << endl;
    cout << "After replacing" << endl;
    copy(v1.begin(), v1.end(), printit);
    cout << endl;

    for(string& word : v1)
    {
      int size = word.size();
      if(size > 3)
      {
        word.erase(size - 1);
        word.erase(size - 2);
      }
    }
    vector<string> v2;
    for (int i=0; i<v1.size(); i++)
        v2.push_back(v1[i]);


    for(int i = 0; i < v2.size(); i++)
    cout<<v2[i]<< endl;

    for (int i=0; i<v2.size(); i++)
    {
     if ( std::find( v.begin(), v.end(), v2[i] ) != v.end())
        {
            std::cout << v2[i] << " is present in the vector" << std::endl;
        }
        else
        {
            std::cout << v2[i] << " is not present in the vector" << std::endl;
        }
    }

    system("pause");
    return 0;
}
