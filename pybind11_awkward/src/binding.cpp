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

std::shared_ptr<ak::Content> findJetsAwkwardTest(const std::shared_ptr<ak::Content> & arr)
{
    return arr;
}

PYBIND11_MODULE(_src, m) {
  // Awkward array
  // Ensure dependencies are loaded.
  py::module::import("awkward1");

  m.def("find_jets_awkward_test", &findJetsAwkwardTest, "events"_a, "Find jets awkward test for the given events according to the provided settings.");
}
