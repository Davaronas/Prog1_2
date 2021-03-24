#include<iostream>
using namespace std;

class B1 {

public:
 	virtual void const vf()
	{
		cout << "B1::vf\n";
	}

	void const f()
	{
		cout << "B1::f\n";
	}

	virtual void const pvf()=0;
};

class D1 : public B1 {

private:

	
public:

	D1(){};

	D1(B1& b1_) {
		b1_.vf();
		b1_.f();
	}


	void const vf()
	{
		cout << "D1::vf\n";
	}

	
	void const f()
	{
		cout << "D1::f\n";
	}

};

class D2 : public D1 {

public:
	void const pvf()
	{
		cout << "D2::pvf\n";
	}

};






class B2 {
	
public: 
	virtual void const pvf()=0;
};



class D21 : public B2 {

private: 
	string text = "HELLO";

public:

	void const f(B2& b2_) {
		b2_.pvf();
	} 	

	void const pvf() 
	{
		cout << text << endl;
	}
};

class D22 : public B2 {

private: 
	int text = 5;

public:

	void const f(B2& b2_) {
		b2_.pvf();
	} 	
	
	void const pvf() 
	{
		cout << text << endl;
	}


};


int main()
{
	//B1 b1;
	//b1.vf();
	//b1.f();
	//cout << endl;
	//D1 d1;
	//d1.vf();
	//d1.f();
	//cout << endl;
	//D2 d2;
	//d2.f();
	//d2.vf();
	//d2.pvf();

	D21 d21;
	d21.f(d21);
	D22 d22;
	d22.f(d22);
	


	return 0;
}
