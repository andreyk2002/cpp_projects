#include "Deque.cpp"
#pragma warning(disable:4996)
int main()
{
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Int: " << endl;
		Deque <int> IntDeque;

		IntDeque.Push_back(1);
		IntDeque.Push_back(5);
		IntDeque.Push_front(3);
		IntDeque.Push_back(2);
		IntDeque.Push_back(7);
		IntDeque.Push_front(10);
		IntDeque.Push_back(4.676);
		IntDeque.Push_back(8);
		IntDeque.Push_front(12);

		/*for (unsigned i = 0; i < 36779825; i++)//366
		{
			IntDeque.Push_back(i);
			if (i == 36779750)
				cout << "yyy";
		}*/
		Deque <int> CopyInt = IntDeque;
		cout << "Copy:" << endl;
		CopyInt.Print(cout);

		IntDeque.Sort();
		cout << "Sort:" << endl;
		IntDeque.Print(cout);

		cout <<"Size before deleting:"<< IntDeque.GetSize() << endl;
		
		IntDeque.Print(cout);
		cout <<"Size after deleting:"<< IntDeque.GetSize() << endl;

		cout << "=================================="<<endl;
		
	}
	catch (My_Deque_exception & ex)
	{

		cout << ex.what()<<endl;
	}
	catch (bad_alloc&)
	{
		cout << "You reached the memory limit" << endl;

	}
	catch (...)
	{
		cout << "System exception was called" << endl;
		return 1;
	}
	try {
		cout << "Double: " << endl;
		Deque <double> DoubleDeque;
		DoubleDeque.Push_back(1.2);
		DoubleDeque.Push_back(5.15);
		DoubleDeque.Push_back(3.14);
		DoubleDeque.Push_back(2.0);
		DoubleDeque.Push_back(7.18);
		DoubleDeque.Push_front(10.189);
		DoubleDeque.Push_back(4.32);
		DoubleDeque.Push_back(8.1896);
		DoubleDeque.Push_front(12.2156);

		Deque <double> CopyDouble = DoubleDeque;
		cout << "Copy:" << endl;
		CopyDouble.Print(cout);

		DoubleDeque.Sort();
		cout << "Sort:" << endl;

		DoubleDeque.PrintReverse(cout);
		cout << "Size before deleting:" << DoubleDeque.GetSize() << endl;
		for (unsigned i = 0; i < DoubleDeque.GetSize() / 2; i++)
		{
			DoubleDeque.Pop_back();
		}
		
		DoubleDeque.Print(cout);
		cout << "Size after deleting:" << DoubleDeque.GetSize() << endl;

		cout<<"======================" << endl;
	}

	catch (My_Deque_exception & ex)
	{

		cout << ex.what() << endl;

	}
	catch (bad_alloc&)
	{
		cout << "You reached the memory limit" << endl;

	}
	catch (...)
	{
		cout << "Sys" << endl;
	}
	try
	{
	cout << "Char* : " << endl;
	Deque<const char*> CharDeque;
	
	CharDeque.Push_back("dsfd");
	CharDeque.Push_back("AAb");
	CharDeque.Push_back("afds");
	CharDeque.Push_front("Ave");
	CharDeque.Push_back("ABa");
	CharDeque.Push_back("dsdf");
	CharDeque.Push_back("dsfscsdf");
	CharDeque.Push_front("sdfds");
	CharDeque.Push_front("Aa");
	
	for (unsigned i = 0; i < 7823050; i++)//366
	{
		CharDeque.Push_back("dshadihgpiagrosdhfgahddgpieutpihrdgfifg;fhgiuaugpojslhgiuaygupshfbkuuahfpgjsifbgiuaey");
		
	}
	Deque <const char*> CopyChar(CharDeque);
	CopyChar.Print(cout);
	CharDeque.Sort();
	cout << endl;
	CharDeque.Print(cout);
	cout << endl;

	char* phrase = new char[100];
	strcpy(phrase, "Hello");
	Deque <const char*> JustForSmallTest;
	JustForSmallTest.Push_front(phrase);
	JustForSmallTest.Push_front("fg");
	delete[] phrase;
	JustForSmallTest.Print(cout);

	}
	
	catch (My_Deque_exception & ex)
	{

		cout << ex.what() << endl;
	}
	catch (bad_alloc&)
	{
		cout << "You reached the memory limit" << endl;

	}
	catch (...)
	{
		cout << "System exception" << endl;
	}





	return 0;
}

