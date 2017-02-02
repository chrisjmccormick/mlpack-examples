# mlpack-examples
Some ready-to-run C++ examples for mlpack

Compile:
{% highlight text %}
$ g++ knn_example.cpp -o knn_example -std=c++11 -larmadillo -lmlpack -lboost_serialization
{% endhighlight %}

Run:
{% highlight text %}
$ ./knn_example
{% endhighlight %}

Expected output:
{% highlight text %}
Nearest neighbor of point 0 is point 7 and the distance is 1.
Nearest neighbor of point 1 is point 2 and the distance is 0.
Nearest neighbor of point 2 is point 1 and the distance is 0.
Nearest neighbor of point 3 is point 10 and the distance is 1.
Nearest neighbor of point 4 is point 11 and the distance is 1.
Nearest neighbor of point 5 is point 12 and the distance is 1.
Nearest neighbor of point 6 is point 12 and the distance is 1.
Nearest neighbor of point 7 is point 10 and the distance is 1.
Nearest neighbor of point 8 is point 9 and the distance is 0.
Nearest neighbor of point 9 is point 8 and the distance is 0.
Nearest neighbor of point 10 is point 9 and the distance is 1.
Nearest neighbor of point 11 is point 4 and the distance is 1.
Nearest neighbor of point 12 is point 9 and the distance is 1.
{% endhighlight %}

