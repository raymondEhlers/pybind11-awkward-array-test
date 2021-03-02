
import awkward as ak
import pybind11_awkward as pba

def test_numpy_array() -> None:
    pba.awkward_test_numpy_array(ak.Array([1,2,3]).layout)

def test_awkward_array() -> None:
    pba.awkward_test(ak.Array([1,2,3]).layout)

if __name__ == "__main__":
    # Without pytest
    test_numpy_array()
    test_awkward_array()
