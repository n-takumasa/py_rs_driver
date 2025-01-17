#include <pybind11/functional.h>
#include "rs_driver_wrapper.hpp"

namespace py = pybind11;

PYBIND11_MODULE(rs_driver_wrapper, m) {
    py::class_<RSDriverWrapper>(m, "PyRSDriver")
        .def(py::init<>())
        .def("init", &RSDriverWrapper::init, py::arg("py_param"))
        .def("start", &RSDriverWrapper::start, py::call_guard<py::gil_scoped_release>())
        .def("stop", &RSDriverWrapper::stop, py::call_guard<py::gil_scoped_release>())
        .def("regPointCloudCallback", &RSDriverWrapper::regPointCloudCallback, py::arg("fn"))
        .def("regExceptionCallback", &RSDriverWrapper::regExceptionCallback, py::arg("fn"))
        .def("getLidarTemperature", &RSDriverWrapper::getLidarTemperature)
        .def("displayNativeMsg", &RSDriverWrapper::displayNativeMsg, py::arg("flag"));
}
