#include <fstream>
#include <vector>
#include <string>


bool fileExist(const char* fileName);

int main(int argc, char **argv) 
{
	std::string arguments;
	for (auto itr : std::vector<char*>(argv + 1, argv + argc)) {
		arguments += arguments.empty() ? "" : " "; // spacing
		arguments += itr;
	}

	if (fileExist(arguments.c_str()))
	{
		std::ifstream ifile(arguments.c_str(), std::ifstream::binary);

		std::vector<uint8_t> ifileBytes;

		while (ifile.good()) {
			ifileBytes.push_back(ifile.get());
		}

		std::ofstream ofile("fileBinaryOutput");
		ofile.unsetf(std::ostream::dec);
		ofile.setf(std::ostream::hex);
		auto lines = 0;
		for (auto byte : ifileBytes) {
			ofile << "0x";

			if (byte != 0)
				ofile << (unsigned)byte;
			else
				ofile << "00";
			
			ofile << ", ";
			++lines;
			if (lines > 8) {
				ofile << std::endl;
				lines = 0;
			}
		}
	}

	return 0;
	
}




bool fileExist(const char* fileName) {
	return std::fstream(fileName).good();
}
