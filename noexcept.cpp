// #include <>
void my_function noexcept { throw std::runtime_error("lolilol"); }

int main(int argc, char const *argv[])
{
	my_function();
	return 0;
}