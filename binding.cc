#include "processor.h"

#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>

EMSCRIPTEN_BINDINGS(my_module) {
  emscripten::class_<Processor>("Processor")
      .constructor<std::string>()
      .function("Verbalize", &Processor::Verbalize);
}