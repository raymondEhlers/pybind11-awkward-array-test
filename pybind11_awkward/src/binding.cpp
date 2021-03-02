#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include <awkward/array/NumpyArray.h>
#include <awkward/builder/ArrayBuilder.h>
#include <awkward/builder/ArrayBuilderOptions.h>
#include <awkward/kernel-dispatch.h>

namespace py = pybind11;
// Shorthand for literals
using namespace pybind11::literals;

// Convenience for awkward.
namespace ak = awkward;

std::shared_ptr<ak::Content> awkwardTest(const std::shared_ptr<ak::Content> & arr)
{
    std::cout << "In function\n";
    return arr;
}

std::shared_ptr<ak::NumpyArray> awkwardTestNumpyArray(const std::shared_ptr<ak::NumpyArray> & arr)
{
    std::cout << "In function for NumpyArray\n";
    return arr;
}

PYBIND11_MODULE(_src, m) {
  // Awkward array
  // Ensure dependencies are loaded.
  py::module::import("awkward");

  m.def("awkward_test", &awkwardTest, "arr"_a, "...");
  m.def("awkward_test_numpy_array", &awkwardTestNumpyArray, "arr"_a, "...");
}
