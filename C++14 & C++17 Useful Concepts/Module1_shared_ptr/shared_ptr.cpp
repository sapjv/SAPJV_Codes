
#include <iostream>
#include <memory>
using namespace std;

// A Sample class with prints in constructor and destructor, so that we can track when the memory
// is allocated and deallocated

class Sample {
public:
	Sample() { cout << "Sample Constructor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
	void publicFn() { cout << "This is public function of class" << endl; }
};

// Test to confirm that shared pointers do release memory without explicitely calling
// the delete
void  TestSharedPtr_ReleaseMemory() {
	shared_ptr<Sample> sp(new Sample{});
	sp->publicFn();
	return;
}

// A helper function which returns a shared pointer
shared_ptr<Sample> AFunc() {
	cout << "Enter AFunc" << endl;
	shared_ptr<Sample> sp(new Sample{});
	cout << "Exit AFunc" << endl;
	return sp;
}

// Test to confirm that shared pointers does use reference counts 
void TestSharedPtr_ReferenceCount() {
	cout << "Enter TestSharedPtr_ReferenceCount" << endl;
	shared_ptr<Sample> retSp = AFunc();
	cout << "Exit TestSharedPtr_ReferenceCount" << endl;
	return;
}
// Test to confirm that shared pointers does use reference counts and use it smartly
void TestSharedPtr_ReferenceCount_Assignments() {
	cout << "Enter TestSharedPtr_ReferenceCount_Assignments" << endl;
	AFunc();
	cout << "Exit TestSharedPtr_ReferenceCount_Assignments" << endl;
	return;
}

// Test for using inbuilt Make_Shared to create a shared pointer
void TestSharedPtr_MakeShared() {
	shared_ptr<Sample> sp = make_shared<Sample>();
	return;
}

int main() {
	TestSharedPtr_ReleaseMemory();
	cout << "------------------------------------------------" << endl;
	TestSharedPtr_ReferenceCount();
	cout << "------------------------------------------------" << endl;
	TestSharedPtr_ReferenceCount_Assignments();
	cout << "------------------------------------------------" << endl;
	TestSharedPtr_MakeShared();
	return 0;
}
