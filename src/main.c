#include <pebble.h>
	
Window *my_window;
TextLayer *my_text_layer;

void window_load(Window *my_window) {
	// Itt adunk tartalmat az ablaknak.
	my_text_layer = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(my_text_layer, GColorClear);
	text_layer_set_text_color(my_text_layer, GColorBlack);
 
	layer_add_child(window_get_root_layer(my_window), (Layer*) my_text_layer);
	text_layer_set_text(my_text_layer, "Mit igyak?");
}

void window_unload(Window *my_window) {
	// Itt szabadítjuk fel a memóriát az ablakban.
	text_layer_destroy(my_text_layer);
}

void init() {
	// Itt inicializáljuk az appot.
	my_window = window_create();
	window_set_window_handlers(my_window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	
	window_stack_push(my_window, true);
}

void deinit() {
	// Itt deinicializáljuk az appot.
	window_destroy(my_window);
}
	
int main(void) {
	init();
	app_event_loop();
	deinit();
}