#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

template<typename Type>
class smart_point {
	Type *value;
public:
	smart_point(Type *&&value) :
			value(value) {
	}
	~smart_point() {
		delete value;
	}
	Type& operator*() {
		return *(this->value);
	}
	Type* operator->() {
		return this->value;
	}
};

class Example {
	vector<string> type_names;
	vector<string> values;
public:
	Example() {
		this->type_names.push_back("int");
		this->type_names.push_back("int*");
		this->type_names.push_back("float");
		this->type_names.push_back("bool");
		this->values.push_back("1");
		this->values.push_back("00000000FA10DEAD");
		this->values.push_back("true");
		this->values.push_back("false");
		this->values.push_back("-1.01");
	}
	void start() {
		string type1 = this->type_names[rand() % this->type_names.size()],
				type2 = this->type_names[rand() % this->type_names.size()];
		string val1 = this->values[rand() % this->values.size()], val2 =
				this->values[rand() % this->values.size()];
		char var1 { 10 + rand() % 100 }, var2 { 10 + rand() % 100 };
		printf("%s %c = %s\n", type1.c_str(), var1, val1.c_str());
		printf("%s %c = %s\n", type2.c_str(), var2, val2.c_str());
	}
};

int main() {
//	Example ex;
//	ex.start();
	srand(time(0));
	smart_point<Example> sm_ex(new Example);
	sm_ex->start();
	return 0;
}
