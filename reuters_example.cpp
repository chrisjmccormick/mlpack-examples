/*
 * ======== reuters_example.cpp =========
 *
 * mlpack documentation is here:
 * http://www.mlpack.org/docs/mlpack-2.0.2/doxygen.php
 */

#include <mlpack/core.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>

using namespace std;
using namespace mlpack;
using namespace mlpack::neighbor; // NeighborSearch and NearestNeighborSort
using namespace mlpack::metric; // SquaredEuclideanDistance


int main()
{
    // Armadillo is a C++ linear algebra library; mlpack uses its matrix data type.
    arma::mat X_train;
    arma::mat y_train;
    arma::mat X_test;
    arma::mat y_test;

    cout << "Loading Reuters Dataset..." << endl;

    X_train.load("./reuters_dataset/X_train.mat");
    y_train.load("./reuters_dataset/y_train.mat");
    X_test.load("./reuters_dataset/X_test.mat");
    y_test.load("./reuters_dataset/y_test.mat");

    /*
    data::Load("./reuters_dataset/X_train.csv", X_train, true);
    data::Load("./reuters_dataset/y_train.csv", y_train, true);    
    data::Load("./reuters_dataset/X_test.csv", X_test, true);
    data::Load("./reuters_dataset/y_test.csv", y_test, true);
    
    X_train.save("./reuters_dataset/X_train.mat");
    y_train.save("./reuters_dataset/y_train.mat");
    X_test.save("./reuters_dataset/X_test.mat");
    y_test.save("./reuters_dataset/y_test.mat");
    */

    cout << "Number of training vectors: " << y_train.n_elem << ", test vectors: " << y_test.n_elem << endl;

    cout << "Training set size [" << X_train.n_rows << " x " << X_train.n_cols << "]" << endl;
    cout << "Test set size     [" << X_test.n_rows << " x " << X_test.n_cols << "]" << endl;
    

    /* 
     * Create a NeighborSearch model. The parameters of the model are specified
     * with templates:
     *  - Sorting method: "NearestNeighborSort" - This class sorts by increasing
     *    distance.
     *  - Distance metric: "ManhattanDistance" - The L1 distance, sum of absolute
     *    distances.
     *
     * Pass the reference dataset (the vectors to be searched through) to the
     * constructor.
     */
    NeighborSearch<NearestNeighborSort, SquaredEuclideanDistance> nn(X_train);

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

    cout << endl << "Performing 1-NN classification...  ";

    // Find the nearest neighbor for each test vector.
    int k = 1;
    nn.Search(X_test, k, neighbors, distances);

    // Use the results to make classifications. Track how many are correct.
    int numRight = 0;

    for (int i = 0; i < neighbors.n_elem; i++) {
        // Predict the label for this query vector.
        // Look up the label of the closest matching training sample.
        int p = y_train[neighbors[i]];

        // Track the number of correct predictions.
        if (p == y_test[i]) {
            numRight++;
        }
    }
    
    cout << "Done!" << endl;

    // Calculate classification accuracy.
    float accuracy = (float) numRight / (float) y_test.n_elem * 100.0;

    printf("\n%d of %d correct (%.2f%%)\n\n", numRight, (int) y_test.n_elem, accuracy);


  
}
