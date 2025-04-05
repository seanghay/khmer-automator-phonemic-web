#pragma once

#include <memory>
#include <string>

#include "fst/fstlib.h"

using fst::StdArc;
using fst::StdVectorFst;
using fst::StringCompiler;
using fst::StringPrinter;

class Processor {
public:
  Processor(const std::string &verbalizer_path);
  std::string Verbalize(const std::string &input);

private:
  std::string ShortestPath(const StdVectorFst &lattice);
  std::string Compose(const std::string &input, const StdVectorFst *fst);

  std::shared_ptr<StdVectorFst> verbalizer_ = nullptr;
  std::shared_ptr<StringCompiler<StdArc>> compiler_ = nullptr;
  std::shared_ptr<StringPrinter<StdArc>> printer_ = nullptr;
};
