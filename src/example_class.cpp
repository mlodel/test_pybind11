#include <pybind11/pybind11.h>
#include "pet.cpp"

namespace py = pybind11;

PYBIND11_MODULE(example_class, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);
}