//#include <iostream>
//using namespace std;
//
//class BaseA
//{
//public:
//	int mun;
//public:
//	BaseA( ):mun(0)
//		{ cout << "BaseA()" << endl; }
//	virtual ~BaseA()
//		{ cout << "~BaseA()" << endl; }
//
//	void fu()
//	{
//		mun = 20;
//	}
//	virtual void FuncA( )
//	{ cout << "BaseA():funcA" << endl; }
//};
//
//class BaseB :public BaseA
//{
//
//public:
//	BaseB()
//		{ cout << "BaseB()" << endl; }
//	virtual ~BaseB()
//		{ cout << "~BaseB()" << endl; }
//
//	virtual void FuncA( )
//	{ cout << "BaseB():funcA" << endl; }
//
//};
//
//int main( )
//{
//	BaseB* b = new BaseB( );
//	b->FuncA( );
//	cout << b->mun <<endl;
//	b->fu( );
//	cout << b->mun <<endl;
//	delete b;
//	//BaseB b1 = BaseB( );
//
//	system( "pause" );
//}