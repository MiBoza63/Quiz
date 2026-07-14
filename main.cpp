#include <iostream>
#include <nlohmann/json.hpp> // This header becomes available via FetchContent

using json = nlohmann::json;

int main() {
    // Create a simple JSON object
    json j;
    j["project"] = "CMake FetchContent";
    j["status"] = "Success at CMake Time!";
    j["version"] = 1.0;

    // Print it out neatly
    std::cout << j.dump(4) << std::endl;
    return 0;
}