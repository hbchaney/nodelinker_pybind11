#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "extras/NodeMap.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(NodeLinker, m) {
    m.doc() = R"pbdoc(
        Pybind11 plugin for fast nearest neighbors algorithm
        -----------------------

        .. currentmodule:: NodeLinker

        .. autosummary::
           :toctree: _generate


    )pbdoc";

    py::class_<NodeMap>(m,"NodeMap")
        .def(py::init<>())
        .def("Setup",&NodeMap::NodeMap_setup)
        .def("SetNode",&NodeMap::SetNode)
        .def("CreateNeighborhoods",&NodeMap::CreateNeighborhoods)
        .def("print_connections",&NodeMap::print_connections)
        .def("PullMolecules",&NodeMap::PullMolecules);

    py::class_<Node>(m,"Node")
        .def_readonly("atom_id",&Node::id)
        .def_readonly("atom_type",&Node::type); 

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
