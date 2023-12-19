#include "imagetest_app.h"

uint32_t imagetest_exit_confirm_view(void* context) {
    UNUSED(context);
    return AppViewExitConfirm;
}

struct App* imagetest_alloc() {
    struct App* app = (struct App*)malloc(sizeof(struct App));

    furi_record_open(RECORD_GUI);

    // View dispatcher
    app->view_dispatcher = view_dispatcher_alloc();

    view_dispatcher_enable_queue(app->view_dispatcher);
    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_attach_to_gui(app->view_dispatcher, furi_record_open(RECORD_GUI), ViewDispatcherTypeFullscreen);

    app->display = display_alloc(app);
    view_set_previous_callback(app->display, imagetest_exit_confirm_view);
    view_dispatcher_add_view(
        app->view_dispatcher, AppViewDisplay, app->display);

    view_dispatcher_switch_to_view(app->view_dispatcher, AppViewDisplay);

    return app;
}

void free_app(struct App* app) {
    furi_assert(app);

    view_dispatcher_remove_view(app->view_dispatcher, AppViewDisplay);
    display_free(app);

    furi_record_close(RECORD_GUI);

    free(app);
}

int32_t imagetest_app(void* p) {
    UNUSED(p);
    struct App* app = imagetest_alloc();

    view_dispatcher_run(app->view_dispatcher);

    free_app(app);
    furi_record_close(RECORD_GUI);

    return 0;
}
