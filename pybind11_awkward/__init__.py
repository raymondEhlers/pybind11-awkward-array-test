""" Test package for awkward with pybind11

.. codeauthor:: Raymond Ehlers <raymond.ehlers@cern.ch>, ORNL
"""

#import awkward as ak

from pybind11_awkward._src import *

#def find_jets_test(events: ak.Array, settings: JetFinderSettings) -> ak.Array:
#    #import IPython; IPython.embed()
#    #return ak.Array(_find_jets(events=events.layout, settings=settings))
#    return _find_jets(events=events.layout, settings=settings)

def my_func() -> str:
    print("I'm in __init__!")
