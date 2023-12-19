#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <furi.h>
#include <gui/view.h>
#include <gui/view_dispatcher.h>

#include <gui/elements.h>

#include "../imagetest_app.h"

View* display_alloc(struct App *app);

void display_free(struct App *app);

#endif /* __DISPLAY_H__ */
