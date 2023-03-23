#pragma once

#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>

namespace pocket_tools {
class PocketConfig {
public:
  class ConfigUnit {
  public:
    enum Status { ValueMap, PureValue };

  public:
    ConfigUnit() {}
    ConfigUnit(std::string const &value)
        : _status(PocketConfig::ConfigUnit::PureValue), _value(value) {}
    ConfigUnit(const std::unordered_map<std::string, ConfigUnit> &map)
        : _status(PocketConfig::ConfigUnit::ValueMap), _map(map) {}

    template <typename T> inline ConfigUnit &operator=(T value) {
      _status = PureValue;
      _value = std::to_string(value);
      return (*this);
    }

    // template specializations for string and char[]
    inline ConfigUnit &operator=(std::string const &value) {
      _status = PureValue;
      _value = value;
      return (*this);
    }
    inline ConfigUnit &operator=(const char value[]) {
      _status = PureValue;
      _value = value;
      return (*this);
    }
    //

    inline ConfigUnit &operator=(bool value) {
      _status = PureValue;
      _value = value ? "true" : "false";
      return (*this);
    }
    inline ConfigUnit &operator=(char value) {
      _status = PureValue;
      _value = std::to_string(value);
      return (*this);
    }
    inline ConfigUnit &operator=(short value) {
      _status = PureValue;
      _value = std::to_string(value);
      return (*this);
    }
    inline ConfigUnit &operator=(int value) {
      _status = PureValue;
      _value = std::to_string(value);
      return (*this);
    }
    inline ConfigUnit &operator=(long value) {
      _status = PureValue;
      _value = std::to_string(value);
      return (*this);
    }
    inline ConfigUnit &operator=(double value) {
      _status = PureValue;
      _value = std::to_string(value);
      return (*this);
    }

    operator bool() const { return (_value == "true"); }
    template <typename T> operator T() const {
      if (_status == PocketConfig::ConfigUnit::ValueMap)
        throw std::runtime_error("Current index is not a valid value");
      return (std::stoi(_value));
    }
    operator long() const {
      if (_status == PocketConfig::ConfigUnit::ValueMap)
        throw std::runtime_error("Current index is not a valid value");
      return (std::stol(_value));
    }
    operator double() const {
      if (_status == PocketConfig::ConfigUnit::ValueMap)
        throw std::runtime_error("Current index is not a valid value");
      return (std::stod(_value));
    }
    operator float() const {
      if (_status == PocketConfig::ConfigUnit::ValueMap)
        throw std::runtime_error("Current index is not a valid value");
      return (static_cast<float>(std::stod(_value)));
    }
    operator std::string() const {
      if (_status == PocketConfig::ConfigUnit::ValueMap)
        throw std::runtime_error("Current index is not a valid value");
      return (_value);
    }

    ConfigUnit &operator[](const std::string &key) {
      if (_map.find(key) == _map.end()) {
        _map.insert(std::unordered_map<std::string, ConfigUnit>::value_type(
            key, ConfigUnit("")));
      }

      _status = PocketConfig::ConfigUnit::ValueMap;

      return (_map.find(key)->second);
    }

    ConfigUnit &operator[](const char key[]) {
      return (this->operator[](std::string(key)));
    }

    Status getStatus() const { return _status; }
    std::string getRawStr() const {
      if (_status == PureValue) {
        return _value;
      }
      // recursive get raw value
      std::string val = "{";
      for (auto iter = _map.begin(); iter != _map.end(); ++iter) {
        val += iter->first + ":" + iter->second.getRawStr();
        // second last element
        if (std::next(iter) != _map.end()) {
          val += ",";
        }
      }
      val += "}";
      return val;
    }

  private:
    ConfigUnit::Status _status;
    std::string _value;
    std::unordered_map<std::string, ConfigUnit> _map;
  };

public:
  PocketConfig() : _params() {}
  virtual ~PocketConfig() {}

  std::string getRawStr() const {

    std::string val = "{";

    for (auto iter = _params.begin(); iter != _params.end(); ++iter) {
      val += iter->first + ":" + iter->second.getRawStr();
      // second last element
      if (std::next(iter) != _params.end()) {
        val += ",";
      }
    }
    val += "}";
    return val;
  }

  ConfigUnit &operator[](std::string const &key) {
    if (_params.find(key) == _params.end()) {
      _params.insert(std::unordered_map<std::string, ConfigUnit>::value_type(
          key, ConfigUnit("")));
    }

    return (_params.find(key)->second);
  }

  ConfigUnit &operator[](const char key[]) {
    { return (this->operator[](std::string(key))); }
  }

private:
  std::unordered_map<std::string, ConfigUnit> _params;
};
} // namespace pocket_tools
