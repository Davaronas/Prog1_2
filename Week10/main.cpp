#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
void print_val(T temp)
{
    for(auto lm : temp)
        cout<<lm<<" ";
        cout<<endl;
}

template<typename T>
void increase_val(T& temp, const int val)
{
    for(auto& lm : temp)
    {
        lm+=val;
    }
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 p = f1; p!= e1; p++)
    {
        *f2 = *p;
        f2++;
    }

    return f2;
}


int main()
{
    const int size=10;


    array<int, size> ar = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list <int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    array<int, size> ar2 = ar;
    vector<int> v2 = v;
    list <int> l2 = l;


    cout<<"Array before increase: "<<endl;
    print_val(ar);
    
    increase_val(ar, 2);
    
    cout<<"Array after increase: "<<endl;
    print_val(ar);
    cout << endl;
    
    
    
    cout<<"Vector before increase: "<<endl;
    print_val(v);
    
    increase_val(v, 3);
    
    cout << "Vector after increase: "<<endl;
    print_val(v);
    cout << endl;
    
    
    cout << "List before increase: "<<endl;
    print_val(l);
    
    increase_val(l,5);
    
    cout<<"List: after increase: "<<endl;
    print_val(l);
    cout << endl;




    my_copy(ar.begin(), ar.end(), v.begin());
    my_copy(l.begin(), l.end(), ar.begin());





    vector<int>::iterator vfind;
    vfind = std::find(v2.begin(), v2.end(), 3);
    if(vfind != v2.end())
    {
        cout<<"3 can be found in this position in the vector: "<<distance(v2.begin(), vfind)<<endl;
    }
    else
    {
        cout<<"3 is not inside the vector"<<endl;
    }
    
    
    

    list<int>::iterator lfind;
    lfind=std::find(l2.begin(), l2.end(), 27);
    if(lfind == l2.end())
    {
        cout<<"27 is not inside the list"<<endl;
    }
    else
    {
        cout<<"27 can be found in this position in the list: "<<distance(l2.begin(), lfind)<<endl;
    }


    return 0;
}
