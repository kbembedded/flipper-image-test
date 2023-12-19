#ifndef __IMAGE_APP_H__
#define __IMAGE_APP_H__

#pragma once
#include <furi.h>
#include <furi_hal_light.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <gui/view_dispatcher.h>
#include <gui/icon.h>
#include <imagetest_icons.h>

#define TAG "imagetest"

struct App {
    Gui* gui;
    ViewDispatcher* view_dispatcher;
    View* display;
};

typedef enum {
    AppViewDisplay,
    AppViewExitConfirm,
} AppView;

#endif /* __IMAGE_APP_H__ */
