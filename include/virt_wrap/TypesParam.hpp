//
// Created by _as on 2019-01-31.
//

#pragma once

#include <string>
#include <variant>
#include <gsl/gsl>
#include <libvirt/libvirt.h>

#include "fwd.hpp"

namespace virt {
  struct TypedParameter {
    using ValueType = std::variant<int, unsigned, long long, unsigned long long, double, bool, std::string>; // warning: 3x heavier
    std::string name;
    ValueType val;
  };

  class TypedParams {
    friend Domain;
    friend Connection;

    virTypedParameterPtr underlying = nullptr;
    int size = 0;
    int capacity = 0;

  public:
    inline ~TypedParams() noexcept;

    void add(gsl::czstring<> name, int);
    void add(gsl::czstring<> name, unsigned);
    void add(gsl::czstring<> name, long long);
    void add(gsl::czstring<> name, unsigned long long);
    void add(gsl::czstring<> name, double);
    void add(gsl::czstring<> name, bool);
    void add(gsl::czstring<> name, gsl::czstring<>);
    void add(const TypedParameter& );
  };

}