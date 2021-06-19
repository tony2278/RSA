
#include<stdio.h>
#include "write2file.h"
#include <string>

#define LENGTH 3

void write2file()
{
	long long num[LENGTH] = { 12345678912345, 12345678912346, 1234567891234567 };
	std::string path = "500w.txt";

	FILE *fp = fopen(path.c_str(), "w");
	if (fp)
	{
		for (int i = 0; i < LENGTH; i++)
		{
			std::string s = std::to_string(num[i]) + "\n";
			fputs(s.c_str(), fp);
		}
	}

	fclose(fp);
}

void readfromfile()
{
	long long num[LENGTH] = { 0 };
	std::string path = "500w.txt";
	char buf[1024] = { 0 };

	FILE *fp = fopen(path.c_str(), "r");
	if (fp)
	{
		for (int i = 0; i < LENGTH; i++)
		{
			fgets(buf, 1024, fp);
			std::string str(buf);
			long long nn = atoll(str.c_str());
			printf("%lld\n", nn);
		}
	}
	fclose(fp);
}
