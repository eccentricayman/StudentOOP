
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class NoNegative : public exception {
public:
    NoNegative(int n)
        : badnum(n)
    {
    }

    const char* what() const throw() {
        string s = "Argument canot be negative: " + to_string(badnum);
        return s.c_str();
    }

private:
    int badnum;
};

class Sin {
    public:
        double operator()(double r) {
            return sin(r);
        }
};

class Fib {
    public:
        Fib() {
			for (int i = 0; i < MAX_FIB; i++) {
                arr[i] = NOT_CALCED;
			}
		}

        long long int operator()(long long int n) {
			if (n < 0) {
				throw (NoNegative(n));
			}
			
			if (arr[n] != NOT_CALCED) {
				return arr[n];
			}

            int result = 0;
            if (n <= 1) {
				result = 1;
			}
            else {
				result = (operator()(n - 1) + operator()(n - 2));
			}

            arr[n] = result;
            return result;
        }

        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;
    private:
	int* arr = new int[MAX_FIB];
};


double your_func(double d, function<double(double)> f) {
    return pow(f(d), d);
}


double square_func(double d, function<double(double)> f) {
    return f(d) * f(d);
}


int main() {
	const long long int FIB_NUM = -46;

    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    Fib fib = Fib();
    try {
        long long int f = fib(FIB_NUM);
        cout << "fib(" << FIB_NUM << ") == " << f << endl;
    }
	catch (NoNegative& e) {
		cerr << "Got a negative argument for fib: " << e.what() << endl;
    }

    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
    cout << "Square of sin 1 = " << d << endl;

    // you're call here!
	d = square_func(1, [](double arg) {return cos(arg);});
    cout << "Square of cos 1 = " << d << endl;
    // you're call here!
	d = square_func(0, [](double arg) {return tan(arg);});
    cout << "Square of tan 0 = " << d << endl;
    // you're call here!

	d = your_func(1, [](double arg) {return pow(arg,arg);});
    cout << d << endl;
}
