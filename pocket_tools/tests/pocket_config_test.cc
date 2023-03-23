#include "pocket_config.hpp"
#include <iostream>
#include <string>

using namespace pocket_tools;

int testConfig(PocketConfig cfg) {
  std::cout << cfg.getRawStr() << std::endl;
  return 0;
}

int test_set() {
  PocketConfig cfg;

  // std::cout << std::stoi(std::string{"ad244"}) << std::endl;

  cfg["mybool"] = false;
  cfg["myint"] = 42;
  cfg["mydouble"] = 42.42;
  cfg["player"]["health"]["current"] = 42;
  cfg["player"]["health"]["max"] = 100.05;

  bool mybool = cfg["mybool"];
  int myint = cfg["myint"];
  double mydouble = cfg["mydouble"];
  int current_player_health = cfg["player"]["health"]["current"];
  double max_player_health = cfg["player"]["health"]["max"];

  std::cout << "Value of 'mybool' : '" << mybool << "'" << std::endl;
  std::cout << "Value of 'myint' : '" << myint << "'" << std::endl;
  std::cout << "Value of 'mydouble' : '" << mydouble << "'" << std::endl;
  std::cout << "Value of 'current_player_health' : '" << current_player_health
            << "'" << std::endl;
  std::cout << "Value of 'max_player_health' : '" << max_player_health << "'"
            << std::endl;

  testConfig(cfg);

  std::cout << "Done." << std::endl;
  return 0;
}

int main() {
  test_set();
  return 0;
}