#include <iostream>
#include <nlohmann/json.hpp> 

using json = nlohmann::json;

int main() {
    json j;
    
    // Check if CMake passed the APP_ENV macro as "prod"
    #ifdef APP_ENV
        std::string env = APP_ENV;
    #else
        std::string env = "unknown";
    #endif

    if (env == "prod") {
        // Production specific JSON layout
        j["project"] = "Enterprise Quiz Platform";
        j["status"] = "Production Ready";
        j["version"] = 2.0;
        j["environment"] = "PROD";
        j["optimization"] = "Fully Enabled";
    } else {
        // Fallback / Dev layout (Your original code)
        j["project"] = "CMake FetchContent";
        j["status"] = "Success at CMake Time!";
        j["version"] = 1.0;
        j["environment"] = "DEV";
    }

    // Print it out neatly
    std::cout << j.dump(4) << std::endl;
    return 0;
}