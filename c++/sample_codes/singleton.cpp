#include <iostream>
#include <memory>

class ConfigManager
{
  public:
    static ConfigManager& get_instance();
    int get_value() { return value; }
    void set_value(int val) { value = val; }
    // Delete copy and assignment to eliminate accidental singleton copying
    ConfigManager(const ConfigManager&) = delete;
    void operator=(const ConfigManager&) = delete;
    ~ConfigManager() { std::cerr << "Destructed" << std::endl; }

  private:
    ConfigManager() : value(0) { std::cout << "Constructed" << std::endl; }
    int value;
};

// This has potential memory leak -
// ConfigManager* instance_ptr;
// ConfigManager& ConfigManager::get_instance()
// {
//     if (instance_ptr == nullptr)
//     {
//         instance_ptr = new ConfigManager();
//     }
//     // Below code can also be used without the global variable instance_ptr
//     // static ConfigManager* instance_ptr = new ConfigManager();

//     return *instance_ptr;
// }

ConfigManager& ConfigManager::get_instance()
{
    static ConfigManager instance;
    return instance;
}

int main()
{
    ConfigManager& cm = ConfigManager::get_instance();
    std::cout << "getval: " << cm.get_value() << std::endl;
    cm.set_value(7);
    std::cout << "getval: " << cm.get_value() << std::endl;

    ConfigManager& cm1 = ConfigManager::get_instance();
    std::cout << "getval: " << cm1.get_value() << std::endl;
    cm1.set_value(10);
    std::cout << "getval: " << cm1.get_value() << std::endl;

    return 0;
}
