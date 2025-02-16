#pragma once

#include "view.h"
#include "display_task.h"
#include "proto_gen/smartknob.pb.h"

class MessageView: public View {
    public:
        MessageView(lv_obj_t * screen, DisplayTask* display_task) {
            display_task_ = display_task;
            screen_ = screen;
        }
        ~MessageView() {}

        void setupView(PB_SmartKnobConfig config) override;
        void updateView(PB_SmartKnobState state) override;

    private:
        DisplayTask* display_task_;
        lv_obj_t * screen_;
        lv_obj_t * label_message;
};
