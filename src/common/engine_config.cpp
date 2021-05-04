#include "engine_config.h"

namespace common {
YAML::Node get_yaml_config(const char* filename) {
    std::ifstream file(filename);
    YAML::Node node = YAML::Load(file);

    return node;
}
}
