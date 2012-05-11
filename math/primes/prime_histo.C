{
	#include <iostream>
	#include <fstream>
	using namespace std;

	ifstream inFile("prime_table_1000", ios::in);

	int primes[1000];	//List of all primes read
	int prime;		//Current prime being read
	int num_primes=0;	//Current index in list of primes

	/*-1 used as the integer to denote end of line,
	to take advantage of the >> operator for ints*/
	while(inFile >> prime  &&  prime!=-1) 
	{
		primes[num_primes++]=prime;
	}

	/*After loop, num_primes holds last index of a prime;
	i.e. num_primes = #primes - 1*/
	num_primes++;

	int ppowers[1000+1][num_primes]; //Two dimensional list of the prime powers of each number, from 0 to N
	for(int i=0; i<num_primes; i++) 
		{ ppowers[0][i]=0; ppowers[1][i]=0; } //0 and 1 have no prime powers

	for(int n=2; inFile.peek() != EOF; n++)
	{
		int pindex=0;
		int ppower;
		while(inFile >> ppower  &&  ppower!=-1)
		{
			ppowers[n][pindex++]=ppower;
		}
	}

	TH1I *total_h = new TH1I("total", "Total Histogram", num_primes, 0, num_primes - 1);
	for(int n=0; n<=1000; n++)
	{
		for(int pindex=0; pindex<num_primes; pindex++)
		{
			total_h->Fill(pindex, ppowers[n][pindex]);
		}
	}
	total_h->Draw();

	/*Debugging code which may still prove useful:

	cout << "Prime at index 0 is "   << primes[  0] << "." << endl;
	cout << "Prime at index 5 is "   << primes[  5] << "." << endl;
	cout << "Prime at index 57 is "  << primes[ 57] << "." << endl;
	cout << "Prime at index 100 is " << primes[100] << "." << endl;

	cout << "Power of 2 in 1000 is " << ppowers[1000][0] << "." << endl;
	cout << "Power of 5 in 600 is "  << ppowers[ 600][2] << "." << endl;
	*/
}
