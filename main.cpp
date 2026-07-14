#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    json j;
    j["project"] = "Enterprise Quiz Platform";
    j["status"] = "Production Ready";
    j["version"] = 2.0;
    j["environment"] = "PROD";

    std::cout << j.dump(4) << std::endl;
    return 0;
}