# mlpack-examples
Some ready-to-run C++ examples for mlpack

(In Progress...)

Compile:
g++ test.cpp -o test -std=c++11 -larmadillo -lmlpack -lboost_serialization

Run with logs:
./test --verbose

Expected output:
{% highlight text %}
[INFO ] Loading 'dataset.csv' as CSV data.  Size is 5 x 13.
[INFO ] Nearest neighbor of point 0 is point 7 and the distance is 1.
[INFO ] Nearest neighbor of point 1 is point 3 and the distance is 1.
[INFO ] Nearest neighbor of point 2 is point 2 and the distance is 0.
[INFO ] Nearest neighbor of point 3 is point 9 and the distance is 1.
[INFO ] Nearest neighbor of point 4 is point 1 and the distance is 0.
[INFO ] Nearest neighbor of point 5 is point 9 and the distance is 1.
[INFO ] Nearest neighbor of point 6 is point 10 and the distance is 1.
[INFO ] Nearest neighbor of point 7 is point 2 and the distance is 1.
[INFO ] Nearest neighbor of point 8 is point 11 and the distance is 1.
[INFO ] Nearest neighbor of point 9 is point 2 and the distance is 2.
[INFO ] Nearest neighbor of point 10 is point 12 and the distance is 1.
[INFO ] Nearest neighbor of point 11 is point 2 and the distance is 1.
[INFO ] Nearest neighbor of point 12 is point 12 and the distance is 1.
[INFO ] Nearest neighbor of point 13 is point 9 and the distance is 1.41421.
[INFO ] Nearest neighbor of point 14 is point 10 and the distance is 1.
[INFO ] Nearest neighbor of point 15 is point 0 and the distance is 1.
[INFO ] Nearest neighbor of point 16 is point 9 and the distance is 0.
[INFO ] Nearest neighbor of point 17 is point 12 and the distance is 1.
[INFO ] Nearest neighbor of point 18 is point 8 and the distance is 0.
[INFO ] Nearest neighbor of point 19 is point 12 and the distance is 1.
[INFO ] Nearest neighbor of point 20 is point 9 and the distance is 1.
[INFO ] Nearest neighbor of point 21 is point 8 and the distance is 1.
[INFO ] Nearest neighbor of point 22 is point 4 and the distance is 1.
[INFO ] Nearest neighbor of point 23 is point 9 and the distance is 2.
[INFO ] Nearest neighbor of point 24 is point 9 and the distance is 1.
[INFO ] Nearest neighbor of point 25 is point 8 and the distance is 1.
[INFO ]
[INFO ] Execution parameters:
[INFO ]   help: false
[INFO ]   info: ""
[INFO ]   verbose: true
[INFO ]   version: false
[INFO ]
[INFO ] Program timers:
[INFO ]   computing_neighbors: 0.000063s
[INFO ]   loading_data: 0.000140s
[INFO ]   total_time: 0.000425s
{% endhighlight %}
