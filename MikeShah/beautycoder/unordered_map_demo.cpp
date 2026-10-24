#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    std::cout << "=== Unordered Map Demo ===" << std::endl;
    
    // 1. Declaration and Initialization
    std::cout << "\n1. Declaration and Initialization:" << std::endl;
    std::unordered_map<std::string, int> map1;  // Empty map
    std::unordered_map<std::string, int> map2 = {{"apple", 5}, {"banana", 3}, {"orange", 8}};  // Initialize with values
    std::unordered_map<std::string, int> map3(map2);  // Copy constructor
    
    std::cout << "map2 initialized with {\"apple\", 5}, {\"banana\", 3}, {\"orange\", 8}" << std::endl;
    
    // 2. Insertion
    std::cout << "\n2. Insertion:" << std::endl;
    map1.insert({"grape", 12});
    map1.insert({"kiwi", 7});
    map1["mango"] = 9;  // Assignment operator (creates if doesn't exist)
    map1["apple"] = 15;  // Overwrites existing value
    
    std::cout << "After insertions:" << std::endl;
    for (const auto& pair : map1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 3. Accessing Elements
    std::cout << "\n3. Accessing Elements:" << std::endl;
    // Using operator[]
    std::cout << "apple: " << map1["apple"] << std::endl;  // Returns value, creates key if not exists
    
    // Using at() - throws exception if key doesn't exist
    try {
        std::cout << "banana: " << map2.at("banana") << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Key 'banana' not found" << std::endl;
    }
    
    // Using find() - returns end() if key doesn't exist
    auto it = map2.find("orange");
    if (it != map2.end()) {
        std::cout << "Found orange: " << it->second << std::endl;
    } else {
        std::cout << "orange not found" << std::endl;
    }
    
    // 4. Checking Existence
    std::cout << "\n4. Checking Existence:" << std::endl;
    if (map1.count("kiwi") > 0) {
        std::cout << "kiwi exists in map1" << std::endl;
    }
    
    if (map1.find("grape") != map1.end()) {
        std::cout << "grape exists in map1" << std::endl;
    }
    
    // 5. Size and Empty Check
    std::cout << "\n5. Size and Empty Check:" << std::endl;
    std::cout << "Size of map1: " << map1.size() << std::endl;
    std::cout << "Is map2 empty? " << (map2.empty() ? "Yes" : "No") << std::endl;
    
    // 6. Iteration
    std::cout << "\n6. Iteration:" << std::endl;
    std::cout << "Using range-based for loop:" << std::endl;
    for (const auto& pair : map2) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 7. Erasing Elements
    std::cout << "\n7. Erasing Elements:" << std::endl;
    map1.erase("kiwi");
    map1.erase(map1.find("grape"));  // Erase using iterator
    
    std::cout << "After erasing kiwi and grape:" << std::endl;
    for (const auto& pair : map1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 8. Clearing the Map
    std::cout << "\n8. Clearing the Map:" << std::endl;
    map1.clear();
    std::cout << "Size after clear: " << map1.size() << std::endl;
    
    // 9. Using different data types
    std::cout << "\n9. Using Different Data Types:" << std::endl;
    std::unordered_map<int, std::vector<std::string>> studentGrades;
    studentGrades[1] = {"Math", "Physics", "Chemistry"};
    studentGrades[2] = {"Biology", "English"};
    
    for (const auto& pair : studentGrades) {
        std::cout << "Student " << pair.first << " courses: ";
        for (const auto& course : pair.second) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }
    
    // 10. Hash Function and Bucket Info
    std::cout << "\n10. Hash Information:" << std::endl;
    std::cout << "map2 bucket count: " << map2.bucket_count() << std::endl;
    std::cout << "map2 load factor: " << map2.load_factor() << std::endl;
    
    return 0;
}