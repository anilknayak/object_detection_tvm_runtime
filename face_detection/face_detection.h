#if defined(_WIN32)
#  if defined(EXPORTING_FACEDETECTION)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

#include <dlpack/dlpack.h>
#include <tvm/runtime/module.h>
#include <tvm/runtime/registry.h>
#include <tvm/runtime/packed_func.h>

#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>

namespace facedetection {
    double DECLSPEC sqrt(double x);
}
