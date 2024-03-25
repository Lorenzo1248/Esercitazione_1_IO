#include <iostream>
#include <fstream>
#include <vector>
#include "Eigen/Eigen"

using namespace Eigen;
using namespace std;

int main()
{
    std::string inputfileName = "data.csv"; // file name
    std::ifstream ifstr(inputfileName); // create istream object and open file

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    std::string outputfileName = "result.csv"; // file name
    std::ofstream ofstr(outputfileName); // create ofstream object and open file

    if(ofstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 2;
    }

    double sum = 0.0;
    int count = 0;
    double value;
    std::vector<double> means;
    int N = 1200;

    //int numLines = 0;
    //std::string line;

    ofstr << "# N Mean" << std::endl;

    // Read the number of lines in the file
    //for (numLines = 0; std::getline(ifstr, line); ++numLines) {

    while (ifstr >> value) {

        // Map value to the interval [-1, 2]
        double mappedValue = -1.0 + (value - 1.0) * (2.0 - (-1.0)) / (5.0 - 1.0);

        sum += mappedValue;
        count++;

        if (count <= N) {
            means.push_back(sum / count);
            ofstr << count << " " << means.back() << std::endl;
        }

        if (count == N)
            break;
    }

    ifstr.close();
    ofstr.close();

    return 0;
}
