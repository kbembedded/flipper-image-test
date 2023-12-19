#include "../imagetest_app.h"
#include "display.h"

static void display_render_callback(Canvas* canvas, void* context) {
    UNUSED(context);

    canvas_draw_icon(canvas, 0, 0, &I_image);
}

static bool display_input_callback(InputEvent* event, void* context) {
    struct App *app = context;
    bool consumed = false;

    if(event->type == InputTypePress && event->key == InputKeyBack) {
        view_dispatcher_switch_to_view(app->view_dispatcher, VIEW_NONE);
        consumed = true;
    }
    /* Can add more checks here later if needed for navigation through multiple images */

    return consumed;
}

void display_enter_callback(void* context) {
    furi_assert(context);
    UNUSED(context);
}

View* display_alloc(struct App* app) {
    View *view;
    view = view_alloc();
    view_set_context(view, app);

    view_set_draw_callback(view, display_render_callback);
    view_set_input_callback(view, display_input_callback);
    view_set_enter_callback(view, display_enter_callback);

    return view;
}

void display_free(struct App* app) {
    furi_assert(app->display);
    view_free(app->display);
}
