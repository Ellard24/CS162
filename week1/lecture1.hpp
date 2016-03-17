

int swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;

	return;
}

std::string swap(std::string &a, std::string &b)
{


	std::string tmp = a;
	a = b;
	b = tmp;

	return;
}
