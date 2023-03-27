/*
static singleton factory for all kinds of parameters
better to make param an aggregation class of common types including standard
containers
*/
#pragma once
#include <string>
#include <unordered_map>

namespace PocketToyTemplates {

template <typename T> class PocketParamGen {
public:
  //   template <T *x>
  struct Register {
    Register(const std::string &key, T *x) {
      PocketParamGen::Instance().warehouse_.emplace(key, x);
    }
  };

  inline T *Get(const std::string &key) {
    if (warehouse_.find(key) == warehouse_.end()) {
      return nullptr;
    }
    return warehouse_[key];
  }

  inline static PocketParamGen &Instance() {
    static PocketParamGen instance;
    return instance;
  }

protected:
  PocketParamGen(){};
  PocketParamGen(const PocketParamGen &) = delete;
  PocketParamGen &operator=(const PocketParamGen &) = delete;
  PocketParamGen(PocketParamGen &&) = delete;
  std::unordered_map<std::string, T *> warehouse_;
};
} // namespace PocketToyTemplates

#define PFG_CONNECTION(text1, text2) text1##_##text2
#define PFG_CONNECT(text1, text2) PFG_CONNECTION(text1, text2)
#define PFG_REGISTER_NAME(TYPE_NAME, TYPE_VAR) PFG_CONNECT(TYPE_NAME, TYPE_VAR)
#define PFG_REGISTER(TYPE_NAME, TYPE_VAR, KEY)                                 \
  static PocketParamGen<TYPE_NAME>::Register PFG_REGISTER_NAME(                \
      TYPE_NAME, TYPE_VAR)(KEY, &(TYPE_VAR))
