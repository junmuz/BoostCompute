//---------------------------------------------------------------------------//
// Copyright (c) 2013 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://kylelutz.github.com/compute for more information.
//---------------------------------------------------------------------------//

#include <iostream>

#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/algorithm/transform.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/functional/operator.hpp>

namespace compute = boost::compute;
const int SIZE = 1000;

// this example demonstrates how to use Boost.Compute's STL
// implementation to add two vectors on the GPU
int main()
{
    // setup input arrays
    float a[SIZE];
    float b[SIZE];


    // make space for the output
    float c[SIZE];

    // initialize arrays with random values
    // create vectors and transfer data for the input arrays 'a' and 'b'

    std::generate(a, a + SIZE, rand);
    std::generate(b, b + SIZE, rand);

    compute::vector<float> vector_a(a, a + SIZE);
    compute::vector<float> vector_b(b, b + SIZE);

    // create vector for the output array
    compute::vector<float> vector_c(SIZE);

    // add the vectors together
    compute::transform(
        vector_a.begin(),
        vector_a.end(),
        vector_b.begin(),
        vector_c.begin(),
        compute::plus<float>()
    );

    // transfer results back to the host array 'c'
    compute::copy(vector_c.begin(), vector_c.end(), c);


    return 0;
}
