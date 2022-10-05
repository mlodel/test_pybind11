#include <vector>
#include <iostream>
#include <Eigen/Geometry>
#include <Eigen/StdVector>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

/// Eigen 1D float vector
template <int N>
using Vecf = Eigen::Matrix<double, N, 1>;
/// Eigen 1D int vector of size 2
typedef Vecf<2> Vec2f;

class Interface
{
    int dims[2];
    std::vector<Vec2f> obs;
    Vec2f getPosFromIdx(int ind)
    {
        Vec2f pos;
        pos(0) = 1;
        pos(1) = 2;
        return pos;
    }

public:
    Interface(int rows, int cols)
    {
        dims[0] = rows;
        dims[1] = cols;
    };
    void numpy2eigen(Eigen::Ref<Eigen::VectorXi> map)
    {
        for (int i = 0; i < map.size(); i++)
        {
            if (*(map.data() + i) > 0)
            {
                obs.push_back(getPosFromIdx(i));
            }
        }
    };
    std::vector<Vec2f> getObs()
    {
        return obs;
    }
};