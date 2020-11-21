#include "../../../std_lib_facilities.h"

class My_vector {
	long unsigned int sz;
	double* elem;

	void debug(const string& s)
	{
		cerr << this << "->" << s << "; elem pointer: " << elem << endl;
	}
public:
	explicit My_vector(int s): sz(s), elem{new double[s]}
	{
		//debug("(int s) constructor");
		for (int i = 0; i < s; ++i) elem[i] = 0;
	}
	
	My_vector(initializer_list<double> lst): sz{lst.size()}, elem{new double[sz]}
	{
		//debug("(initializer_list<double> lst) constructor");
		copy(lst.begin(), lst.end(), elem);
	}

	My_vector(const My_vector& arg): sz{arg.sz}, elem{new double[arg.sz]}
	{
		//debug("copy constructor");
		copy(arg.elem, arg.elem+arg.sz, elem);
	}

	My_vector& operator=(const My_vector& arg)
	{
		//debug("copy assignment");
		double *p = new double[arg.sz];
		copy(arg.elem, arg.elem+arg.sz, p);
		delete[] elem;
		elem = p;
		sz = arg.sz;
		return *this;
	}

	My_vector(My_vector&& arg): sz{arg.sz}, elem{arg.elem}
	{
		//debug("move constructor");
		arg.sz = 0;
		arg.elem = nullptr;
	}

	My_vector& operator=(My_vector&& arg)
	{
		//debug("move assignment");
		delete[] elem;
		elem = arg.elem;
		sz = arg.sz;
		arg.elem = nullptr;
		arg.sz = 0;
		return *this;
	}
	
	~My_vector() 
	{
		//debug("destructor"); 
		delete[] elem; 
	}

	//double get(int n) const { return elem[n]; }
	//void set(int n, double val) { elem[n] = val; }

	double& operator[](int n) { return elem[n]; }
	double operator[](int n) const { return elem[n]; }

	int size() const { return sz; }
};
/*
My_vector fill()
{
	My_vector res = {21.2, 23.4, 2.2};
	
	return res;
}
*/
//My_vector glob(10);

int main()
{
	My_vector v1 {12.2, 23.3, 34.4};
	
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << endl;

	for (int i = 0; i < v1.size(); ++i)
		v1[i] = 100;

	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << endl;

	const My_vector v2 {100, 20.4, 123.1};

	for (int i = 0; i < v2.size(); ++i)
		cout << v2[i] << endl;

	return 0;
}