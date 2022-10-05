#include <pybind11/pybind11.h>
#include "decomp_util_interface.cpp"

namespace py = pybind11;
PYBIND11_MODULE(interface, m)
{
    py::class_<Interface>(m, "Interface")
        .def(py::init<int, int>())
        .def("numpy2eigen", &Interface::numpy2eigen)
        .def("getObs", &Interface::getObs);
}