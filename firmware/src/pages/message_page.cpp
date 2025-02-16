#include "message_page.h"

PB_SmartKnobConfig* MessagePage::getPageConfig() {
    return &config_;
}

void MessagePage::handleUserInput(input_t input, int input_data, PB_SmartKnobState state) {
    if (input == INPUT_FORWARD || input == INPUT_BACK) {
        if (completion_callback_) {
            completion_callback_();
        }
    }
}

void MessagePage::setMessage(const char* message) {
    strncpy(config_.view_config.description, message, sizeof(config_.view_config.description) - 1);
    config_.position_nonce++; // Force UI update
}
