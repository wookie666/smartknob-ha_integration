#include "message_view.h"
#include "styles.h"
#include "view_util.h"

void MessageView::setupView(PB_SmartKnobConfig config) {
    // Create centered message label
    label_message = lv_label_create(screen_);
    
    // Set up label properties
    lv_obj_set_style_text_font(label_message, &roboto_light_24, LV_PART_MAIN);
    lv_obj_set_style_text_color(label_message, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_text_align(label_message, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    
    // Enable text wrapping
    lv_label_set_long_mode(label_message, LV_LABEL_LONG_WRAP);
    
    // Set width to 80% of screen width
    lv_obj_set_width(label_message, (TFT_WIDTH * 8) / 10);
    
    // Center the label
    lv_obj_align(label_message, LV_ALIGN_CENTER, 0, 0);
    
    // Set initial text if available
    if (config.view_config.description[0] != '\0') {
        lv_label_set_text(label_message, config.view_config.description);
    }
}

void MessageView::updateView(PB_SmartKnobState state) {
    if (state.config.view_config.description[0] != '\0') {
        lv_label_set_text(label_message, state.config.view_config.description);
        lv_obj_align(label_message, LV_ALIGN_CENTER, 0, 0);
    }
}
