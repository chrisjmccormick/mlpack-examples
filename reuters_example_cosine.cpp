/*
 * ======== reuters_example.cpp =========
 * This example performs 1-NN classification on a portion of the Reuters 
 * text classification dataset. 
 *
 * The Reuters articles have already been converted into vector representations
 * using Latent Dirichlet Allocation (LDA) with 128 topics. 
 * 
 * mlpack documentation is here:
 * http://www.mlpack.org/docs/mlpack-2.0.2/doxygen.php
 */

#include <mlpack/core.hpp>
#include <mlpack/core/kernels/cosine_distance.hpp>
#include <mlpack/core/metrics/ip_metric.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>

//using namespace std;
using namespace mlpack;
using namespace mlpack::neighbor; // NeighborSearch and NearestNeighborSort
using namespace mlpack::metric; // IPMetric
using namespace mlpack::kernel; // CosineDistance


int main()
{
    // Load the dataset using Armadillo.
    arma::mat X_train;
    arma::mat y_train;
    arma::mat X_test;
    arma::mat y_test;

    std::cout << "Loading Reuters Dataset..." << std::endl;

    // The data is stored in Armadillo's default binary format.
    X_train.load("./reuters_dataset/X_train.mat");
    y_train.load("./reuters_dataset/y_train.mat");
    X_test.load("./reuters_dataset/X_test.mat");
    y_test.load("./reuters_dataset/y_test.mat");   

    // Display properties of the dataset.
    std::cout << "Number of training vectors: " << y_train.n_elem << ", test vectors: " << y_test.n_elem << std::endl;

    std::cout << "Training set size [" << X_train.n_rows << " x " << X_train.n_cols << "]" << std::endl;
    std::cout << "Test set size     [" << X_test.n_rows << " x " << X_test.n_cols << "]" << std::endl;
    

    /* 
     * Create a NeighborSearch model from the training vectors, and set the 
     * distance metric to Cosine.
     */
    NeighborSearch<NearestNeighborSort, IPMetric<CosineDistance>, arma::mat, tree::BallTree> nn(X_train, NAIVE_MODE);

    /*
     * Create the matrices to hold the results of the search. 
     *   neighbors [k  x  n] - Indeces of the nearest neighbor(s). 
     *                         One column per data query vector and one row per
     *                        'k' neighbors.
     *   distances [k  x  n] - Calculated distance values.
     *                         One column per data query vector and one row per
     *                        'k' neighbors.
     */
    arma::Mat<size_t> neighbors;
    arma::mat distances;     

    std::cout << std::endl << "Performing 1-NN classification...  ";

    // Find the single nearest neighbor for each test vector.
    int k = 1;
    nn.Search(X_test, k, neighbors, distances);

    // Use the results to make classifications. Track how many are correct.
    int numRight = 0;

    for (int i = 0; i < neighbors.n_elem; i++) {
        // Predict the label for this query vector by looking up the label
        // of the closest matching training sample.
        int p = y_train[neighbors[i]];

        // Track the number of correct predictions.
        if (p == y_test[i]) {
            numRight++;
        }
    }
    
    std::cout << "Done!" << std::endl;

    // Calculate classification accuracy.
    float accuracy = (float) numRight / (float) y_test.n_elem * 100.0;

    printf("\n%d of %d correct (%.2f%%)\n\n", numRight, (int) y_test.n_elem, accuracy);
  
}
