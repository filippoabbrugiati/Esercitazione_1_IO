#include <iostream>
#include <fstream>
#include <iomanip>


double map_values(double x)
{
	return (3.0/4)*x-7.0/4;
}

int main()
{
	std::ifstream fsrt("data.txt");
	if (fsrt.fail())
	{
		std::cerr << "File not found" << std::endl;
		return 1;
	}
	
	double val;
	
	unsigned int i=0;
	double sum=0;
	std::ofstream out("result.txt");
	out << std::scientific << std::setprecision(16);
	if (!out) {
		std::cerr << "File not found" << std::endl;
		return 1;
	}
	
	out << "# N Mean\n";
	
	while (fsrt >> val)
	{
		double mapped_value = map_values(val);	
		sum+= mapped_value;
		i++;
		double mean = sum/i;
		out <<i<<" "<< mean << std::endl;
	}
	out.close();
	
    return 0;
}
