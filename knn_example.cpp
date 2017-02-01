#include <mlpack/core.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>

using namespace mlpack;
using namespace mlpack::neighbor; // NeighborSearch and NearestNeighborSort
using namespace mlpack::metric; // ManhattanDistance

typedef NeighborSearch<NearestNeighborSort, metric::EuclideanDistance>
        KNN;

int main(int argc, char** argv)
{
    CLI::ParseCommandLine(argc, argv);
    // Load the data from data.csv (hard-coded).  Use CLI for simple command-line
    // parameter handling.
    arma::mat data;
    data::Load("dataset.csv", data, true);


    KNN a(data, true);
    // The matrices we will store output in.
    arma::Mat<size_t> resultingNeighbors;
    arma::mat resultingDistances;
    a.Search(2, resultingNeighbors, resultingDistances);

    // Write each neighbor and distance using Log.
    for (size_t i = 0; i < resultingNeighbors.n_elem; ++i)
    {
        Log::Info << "Nearest neighbor of point " << i << " is point "
                  << resultingNeighbors[i] << " and the distance is " << resultingDistances[i] << ".\n";
    }
}
