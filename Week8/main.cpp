#include <iostream>
#include <vector>

// g++ main.cpp -o a.out

using namespace std;

template <typename T>
struct S
{
    private:
    T val;

    public:
    explicit S(T v=0) : val{v} {};

    const T& get();
    S& operator= (const T& new_val);

};

template <typename T>
const T& S<T>:: get()
    {
        return val;
    }
    
    
template <typename T>
S<T>& S<T>::operator= (const T& new_val)
{
    val=new_val;
    return *this;
}





template <typename T>
void read_val(T& value)
{
    cin>>value;
}


template <typename T>
ostream& operator<< (ostream& os, vector<T>& v)
{
    os<<"{";

    for(auto lm : v)
        os<<lm<<(lm==v[v.size()-1] ? "" : ", ");
    os<<"}";

    return os;
}


template <typename T>
istream& operator>> (istream& is, vector<T>& v)
{
    char brackets;
    is>>brackets;
    
    if(brackets!='{')
        is.clear();
        
    int val;
    
    while(is>>val)
    {
        v.push_back(val);
        is>>brackets;
        if(brackets!=',')
            break;
    }

    return is;
}



int main()
{
    S<int> sint (1);
    int i;
    cout<<"Type an integer: "<<endl;
    read_val(i);
    sint=i;

    S<char> schar ('a');
    char c;
    cout<<"Type a character: "<<endl;
    read_val(c);
    schar=c;


    S<double> sdouble (1.1);
    double d;
    cout<<"Type a double: "<<endl;
    read_val(d);
    sdouble=d;

    S<string> sstring ("kacsa");
    string s;
    cout<<"Type a string: "<<endl;
    read_val(s);
    sstring=s;

    S<vector<int>> svector (vector<int> {1, 2, 3, 4, 5, 6});

    cout<<"int: "<<sint.get()<<"\n"
        <<"char: "<<schar.get()<<"\n"
        <<"double: "<<sdouble.get()<<"\n"
        <<"string: "<<sstring.get()<<endl << endl;

    cout<<"Type an int vector with this format {value, value, value, value}"<<endl;
    vector<int> int_vector;
    read_val(int_vector);
    cout<<int_vector<<endl;

    return 0;
}
