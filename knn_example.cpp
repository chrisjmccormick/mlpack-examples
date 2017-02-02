#include <mlpack/core.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>
using namespace mlpack;
using namespace mlpack::neighbor; // NeighborSearch and NearestNeighborSort
using namespace mlpack::metric; // ManhattanDistance
int main()
{
  // Load the data from data.csv (hard-coded).  Use CLI for simple command-line
  // parameter handling.
  arma::mat data;
  data::Load("data.csv", data, true);
  // Use templates to specify that we want a NeighborSearch object which uses
  // the Manhattan distance.
  NeighborSearch<NearestNeighborSort, ManhattanDistance> nn(data);
  // Create the object we will store the nearest neighbors in.
  arma::Mat<size_t> neighbors;
  arma::mat distances; // We need to store the distance too.
  // Compute the neighbors.
  nn.Search(1, neighbors, distances);
  // Write each neighbor and distance using Log.
  for (size_t i = 0; i < neighbors.n_elem; ++i)
  {
    std::cout << "Nearest neighbor of point " << i << " is point "
        << neighbors[i] << " and the distance is " << distances[i] << ".\n";
  }
}
