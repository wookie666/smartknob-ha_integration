#pragma once

#include <nvs_flash.h>
#include <nvs.h>

class StorageManager {
public:
    StorageManager();
    ~StorageManager();

    bool init();
    
    // State storage methods
    bool saveState(const char* key, int value);
    bool loadState(const char* key, int& value);

private:
    nvs_handle_t nvs_handle;
    const char* NVS_NAMESPACE = "smartknob";
    bool initialized = false;
};
