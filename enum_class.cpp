
// Compile error, two enum won't have same type
/*
enum Options {
	None, One, All
};

enum UnscopeOptions
{
	None, One, All
};
*/

enum class Options {
	None, One, All
};

enum UnscopeOptions
{
	None, One, All
};

int main(int argc, char const *argv[])
{
	Options o = Options::All;

	UnscopeOptions uo = UnscopeOptions::All;

	// int p = o;
	int p = uo;

	return 0;
}
