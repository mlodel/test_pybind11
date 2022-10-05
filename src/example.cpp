#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


PYBIND11_MAKE_OPAQUE(std::vector<int>);

using VecInt = std::vector<int>;

int add(int i, int j)
{
    return i + j;
}

void append_1(VecInt &v) {
   v.push_back(1);
}

namespace py = pybind11;
PYBIND11_MODULE(example, m)
{
    m.doc() = "example function";
    py::class_<VecInt>(m, "VecInt")
        .def(py::init<>());
    // py::bind_vector<VecInt>(m, "VecInt");
    // py::implicitly_convertible<py::list, VecInt>();
    m.def("add", &add, "Add function");
    m.def("append_1", &append_1, py::arg("vec"));
    // m.def("append_1", &append_1, "Append 1");
}