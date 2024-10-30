#include <iostream.h>
#include <fstream.h>
#include <string.h>

void my_read();

int main()
{
	int
		score[10],
		i,
		siz = 10;

	char name[25][10];

	ofstream out("top.bin");
	if(!out)
	{	cout << "cannot open top.bin for output\n";
		return 1;
	}

	for(i = 0; i < siz; i++) {
		strcpy(name[i], "Bill West");
		score[i] = 100 + i;
	}

	for(i = 0; i < siz; i++) {
		out.write( name[i], 20 );
		out.write( (char *) &score[i], sizeof(int) );
	}

	out.close();

	my_read();
cout << "returned\n";

	return 0;
}

void my_read()
{
	int
		score[10],
		i,
		siz = 10;

	char name[25][10];

	ifstream in("top.bin");
	if(!in)
	{	cout << "cannot open top.bin for input\n";
		return;
	}

	for(i = 0; i < siz; i++)
	{	in.read( name[i], 20 );
		in.read( (char *) &score[i], sizeof(int) );
	}
	for(i = 0; i < siz; i++)
		cout << name[i] << " " << score[i] << "\n";

	cout << "closing file\n";
	in.close();
	cout << "closed file\n";
}
