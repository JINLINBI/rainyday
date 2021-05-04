#pragma once
#include <fstream>
#include <string>
#include <yaml-cpp/yaml.h>

namespace common {
YAML::Node get_yaml_config(const char* filename); 
}