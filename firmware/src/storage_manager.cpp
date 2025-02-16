#include "storage_manager.h"

StorageManager::StorageManager() {}

StorageManager::~StorageManager() {
    if (initialized) {
        nvs_close(nvs_handle);
    }
}

bool StorageManager::init() {
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);

    err = nvs_open(NVS_NAMESPACE, NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        return false;
    }
    
    initialized = true;
    return true;
}

bool StorageManager::saveState(const char* key, int value) {
    if (!initialized) return false;
    esp_err_t err = nvs_set_i32(nvs_handle, key, value);
    if (err != ESP_OK) return false;
    
    err = nvs_commit(nvs_handle);
    return (err == ESP_OK);
}

bool StorageManager::loadState(const char* key, int& value) {
    if (!initialized) return false;
    esp_err_t err = nvs_get_i32(nvs_handle, key, &value);
    return (err == ESP_OK);
}
