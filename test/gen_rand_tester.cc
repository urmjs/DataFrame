/*
Copyright (c) 2019-2022, Hossein Moein
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of Hossein Moein and/or the DataFrame nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <DataFrame/RandGen.h>

#include <cassert>
#include <iostream>

using namespace hmdf;

// -----------------------------------------------------------------------------

int main(int argc, char *argv[]) {

    {
        RandGenParams<long> p;

        p.min_value = 0;
        p.max_value = 1000000;

        auto    r = gen_uniform_int_dist<long>(1024, p);
    }

    {
        RandGenParams<double> p;

        p.min_value = 0;
        p.max_value = 2.0;
        p.seed = 23;

        auto    r = gen_uniform_real_dist<double>(1024, p);
    }

    {
        auto    r = gen_bernoulli_dist(1024);
    }

    {
        RandGenParams<int>  p;

        p.t_dist = 1000;

        auto    r = gen_binomial_dist<int>(1024, p);
    }

    {
        RandGenParams<int>  p;

        p.t_dist = 1000;

        auto    r = gen_negative_binomial_dist<int>(1024, p);
    }

    {
        auto    r = gen_geometric_dist<int>(1024);
    }

    {
        RandGenParams<int>  p;

        p.mean = 4.0;

        auto    r = gen_poisson_dist<int>(1024, p);
    }

    {
        RandGenParams<double>   p;

        p.lambda = 1.5;

        auto    r = gen_exponential_dist<double>(1024, p);
    }

    {
        RandGenParams<double>   p;

        p.alpha = 1.5;
        p.beta = 1.5;

        auto    r = gen_gamma_dist<double>(1024, p);
    }

    {
        RandGenParams<double>   p;

        p.alpha = 1.5;
        p.beta = 1.5;

        auto    r = gen_weibull_dist<double>(1024, p);
    }

    {
        RandGenParams<double>   p;

        p.alpha = 1.5;
        p.beta = 1.5;

        auto    r = gen_extreme_value_dist<double>(1024, p);
    }

    {
        RandGenParams<double>   p;

        p.mean = 1.0;  // Default
        p.std = 0.005;

        auto    r = gen_normal_dist<double>(1024, p);

        r = gen_normal_dist<double>(1024);
        for (auto citer : r)
            assert(citer == 1.0);
    }

    {
        auto    r = gen_lognormal_dist<double>(1024);
    }

    {
        RandGenParams<double>   p;

        p.n = 4.0;

        auto    r = gen_chi_squared_dist<double>(1024, p);
    }

    {
        auto    r = gen_cauchy_dist<double>(1024);
    }

    {
        auto    r = gen_fisher_f_dist<double>(1024);
    }

    {
        auto    r = gen_student_t_dist<double>(1024);

        for (auto citer : r)
            std::cout << citer << ", ";
        std::cout << std::endl;
    }

    return (0);
}

// -----------------------------------------------------------------------------

// Local Variables:
// mode:C++
// tab-width:4
// c-basic-offset:4
// End:
